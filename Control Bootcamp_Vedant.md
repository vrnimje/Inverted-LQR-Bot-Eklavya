# Control Bootcamp
<p> Manipulation of system actively to change its behaviour. Types of controls are:<br>

### - Passive<br>
### - Active<br>
<strong>i. Open loop</strong>: 
Pre-planned tracjectory, but we have to constantly supply energy. <br>

<strong>ii. Closed loop feedback control:</strong>
 Sensor readings are taken from the output and fed to the system as input.<br>


### Why feedback over open loop?<br>
1. Uncertainty: Pre-planned trajectory is sub-optimal. But with feedback, we can improve output even if we have an imperfect model.<br>
2. Instability: Eigenvalues of the system can be changed by adjusting the dynamics of the system, avoiding instability in case of feedback control.
3. Reject disturbances, like gushes of wind
4. Effective feedback control is more **efficient** , as minimum energy is required in that case.
   
</p>

$$ \dot{x}=Ax + Bu $$
This represents an O.D.E. where, x is the input, and u is the control term (knob). B is how u changes the state. We also measure some aspects of the state.
$$ y=Cx $$
Let control law is:
$$  u= -Kx $$<br>
 where (y=x)
$$    \dot{x}=Ax-BKx
           =(A-BK)x
$$

By the eigenvalues of the matrix $(A-BK)$, we can determine whether or not the system is stable or not.

## I. Linear Systems
<p>

$ \dot{x}=Ax $

where x is a matrix

$ x(t)=e^{At}x(0) $
$ e^{At}=I + At + \frac{A^{2}t^{2}} {2!} + \cdots $   .....(i) 

To compute $A^{n}$ easily, we make use of **eigenvalues and eigenvectors**

$$ A \vec{c} = \lambda \vec{c} $$
And, 
$$ T=\begin{bmatrix}
    \vec{c1} & \vec{c2} & \vec{c3} & \cdots\\
    \end{bmatrix} $$
So,
$$ AT = TD $$
where D is a diagonal matrix containing eigenvalues of all the corresponding eigenvectors in T.<br>

$$ T^{-1} A T = D $$
Eqn in MATLAB is
$$ [T,D] = eig(A) $$

Now we map the vector x in the eigenbasis plane
Let $$x=Tz$$
$$ \dot{x} = T \dot{z} = Ax
$$
$$ \dot{z} = T^{-1}ATz = Dz $$

Therefore,
$$ z=D \dot{z}$$

Linear system 1 img

So, solution becomes

Linear system 2 img

But to represent in the original paramters,

$$ A = TDT^{-1} $$
So, $ A^{n} $ becomes,
$$ A^{n} = T D^{n} T^{-1} $$
Hence, calculating eqn (i) becomes easier
$$ e^{At} = T[I + Dt + \frac{D^{2}t^{2}}{2!} + \frac{D^{3}t^{3}}{3!} + \cdots] T^{-1} $$
$$ e^{At} = T e^{Dt} T^{-1} $$

Finally,

Linear system 3 img

The dynamics are simpler in the eigenbasis plane, allowing us to get the state at a future time. 

</p> 

## 2. Stability and Eigenvalues
<p>

#### Stability in continuous time
Stability 1 img <br>
$$ \lambda = a \pm  \iota b $$
So, 
$$ e^{\lambda t} = e^{at}[cos(bt) \pm \iota sin(bt)]$$

Stability 2 img 

If $ a>0 $,

So the system will eventually blow up to infinity, and so will x as well 

Hence, the system is stable if and only if all the eigenvalues are negative. 

Stability 3 img 

So we basically want to make the system stable by making the eigenvalues, which are positive, negative, by using the '$Bu$' term. 

#### Stability in discrete time
It is represented as
$$ x_{k+1} = \tilde{A} x_{k} $$
where $ x_{k} = x(k \triangle t)$

Stability 4 img

So the magintude of the eigenvalues have to be less than 1 , to attain stability, otherwise the term $R^{n} \to \infin$. 

</p>

## 3. Linearising around a fixed point
<p>
Basically converting a non linear system to a linear one, for controlling the former.<br>

$$ \dot{x} = f(x) $$
#### Steps
1. Find fixed points $\bar{x}$ such that 
   $$ f(\bar{x}) = 0 $$
   So we find states where the system is not in motion (fixed)
2. Linearise about $\bar{x}$.
   $$ (\frac{df}{dx})_{\bar{x}} = [\frac{df_{i}}{dx_{j}}] $$

   Calculating the Jacobian of the dynamics

We do this so that when we zoom into these fixed points, the system behaves like a linear one.

Linearising 1 img

Now we fix our origin at $\bar{x}$, so that $x-\bar{x}\approx0$. 

Linearising 2 img

For example, in case of a inverted pendulum, a fixed point is the vertical state of the pendulum. When we consider only the region where the angle of deviation from this state is very small, that region effectively behaves as a linear system. We then control the system such that it stays within that region.<br>
    
    Hartman–Grobman theorem
    The theorem states that the behaviour of a dynamical system in a domain near a hyperbolic equilibrium point is qualitatively the same as the behaviour of its linearisation near this equilibrium point, where hyperbolicity means that no eigenvalue of the linearisation has real part equal to zero.

Linearising 3 img

Linearising 4 img

MATLAB eqns are:
$$ d=0.1 $$
$$ Ad = [0,1;-1,-d] $$
Therefore, eig(Ad) gives
-0.05 - 0.99871i and
-0.05 + 0.99871i

Similarly, for Au, eig(Au) gives one stable and another unstable eigenvalue
</p>

## 4. Controllabiltiy
<p>

$$ \dot{x} = Ax + Bu$$  where
$$ x \in R^n, u \in R^{q}, A\in R^{n\times n} and B \in R^{n\times q} $$

Controllability 1 img
(Assuming full state feedback)

In majority systems, A and B are fixed, we can only adjust u.

In MATLAB,
ctrb(A,B) tells the same

All the vector components should be controllable. Some examples are

Controllability 2 img

Controllability 3 img

Controllability 4 img

ctrb gives this above matrix
</p>

## 5. Reachability and Eigenvalue placemment
<p>

Reachable set 
$ R_{t}$ = {$c \in R^{n} |$ there is an input u(t) such that x(t)=c }

</p>

## 6. Inverted Pendulum on a cart
<p>

Inverted 1 img

We can represent this system as a vector:<br>
$$\vec{x} =  \begin{bmatrix}
            x \\
            \dot{x} \\
            \theta \\
            \dot{\theta}
            \end{bmatrix}
         $$

$$ \frac{d}{dt} x = f(x) $$

Fixed points:
$ \theta = 0,\pi$
$ \dot{x}=0 $

$x$ is free

"u" is a force here, which we can change/ modify. 

The placement of the poles/ eigenvalues should be such that the system comes to the desired equilibrium state quickly, but at the same time not putting any strain on it, i.e., no jerkiness in the system

K in MATLAB is found as
K=place(A,B,eigs)
where eigs are the desired eigenvalues/poles.

(The system becomes more unstable the further it moves into the left hand plane.)

Hence, we need an optimal set of eigenvalues, which can be determined using LQR.

#### Linear Quadratic Regulator (LQR)

We consider a cost function, which tells how much penalty must be there, when a certain component of the vector x deviates from its desired value. We also do the same for the force "u", so that we can reduce the strain on motors, if necessary. This cost function is given by:

Inverted 2 img

where Q is a $n \times n$ matrix, and R is a coefficient. 

We find K which minimises the value J.

Linear: The system is linear
Quadratic: The function J, which is to be minimised, is a quadractic function.
Regulator: Stabilises the system

MATLAB eqn
K= lqr(A,B,Q,R)

Time complexity: O($n^{3}$)
</p>

## 7. Full - State Estimation

In reality, it is impossible to read the full-state measurements; we might only get the readings y, given by

$y = Cx$, where $ y \in R^{p}$, where p<n

Here, we consider the term **Observability**, which tells if we can or cannot estimate any state x from measurements y(t)

MATLAB: rank(obsv(A,C))

if it is equal to n, the system is observable, and vice-versa. 

Full-state 1 img

where $\hat{x}$ is the estimated state, having some disturbances.

#### Observability

Observability matrix, $$O = \begin{bmatrix}
C \\
CA \\
CA^{2}\\
\vdots \\
CA^{n-1}
\end{bmatrix} $$

where C is the controllability matrix, 
$$ C=\begin{bmatrix}
        B & AB & A^{2}B & \cdots & A^{n-1}B
    \end{bmatrix} $$

rank(obsv(A,C)) should be n

#### Developing the estimator (Kalman filter)

Full state 2 img

$$
\dot{\hat{x}} = A\hat{x}+Bu+K_{f}(y-\hat{y})
$$
$
\hat{y}=C\hat{x}
$

where $K_{f}$ is the Kalman filter gain matrix

The term $K_{f}(y-\hat{y})$ is used to update the value of $\dot{\hat{x}}$ based on new values of y

Full state 3 img
Full state 4 img
Full state 5 img













