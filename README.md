# About This Project
Control systems form the basis for ensuring that every automatic system performs its ordained task accurately, efficiently and quickly (optimally) despite being subjected to varying environmental conditions.

In this project, we explore one of these control systems, i.e., **[LQR (Linear Quadratic Regulator)](../Notes/Vedant/Control_Bootcamp_Vedant.md) Controller**, which is a type of controller in which we try to minimise a cost function by optimising the various states of the physical system. 
We apply LQR to the classical problem of an **Inverted Pendulum on Rails**, which is used as a benchmark for testing control strategies, both in simulation and hardware.

[Image of setup goes here]

### 1. Research Topics
* **Linear Algebra**, for representation of various aspects of physical systems, like, current state, stability, etc.. ([Notes for the same](./Notes/Mahesh/LA_Notes_Mahesh.md))
* A thorough understanding of **Control Systems**. ([Notes for the same](./Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md))

### 2. List of Software Used
* [GNU Octave, version 7.1.0](https://octave.org/) for modelling and simulation of inverted pendulum. 
* [SOLIDWORKS](https://www.solidworks.com/), for designing custom components.
* Embedded C

### 3. List of Hardware Used
* NEMA-17 Stepper Motor ([Notes for the same](./Notes/Mahesh/Controlling_Stepper_Motor.md))
  ![NEMA-17 img](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.amazon.in%2FSTEPPERONLINE-Stepper-Bipolar-4-lead-Printer%2Fdp%2FB00PNEQKC0&psig=AOvVaw1W668wSFzZsjS5xG2cZCIx&ust=1664538395200000&source=images&cd=vfe&ved=0CAwQjRxqFwoTCLDllvP2ufoCFQAAAAAdAAAAABAP)
* Rails, on which the cart moves
* Timing belt
* Custom-designed laser-cut cart, made of acrylic, and has screw-holes for the wheels (bearings) ([Drawing file for the plates](./Cart_design/side_plate.pdf)
* [ESP32 microcontroller](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
* MPU6050, for measuring the deviation of the pendulum from the normal
* 9 ball bearings
  * 8 in the cart (acting as wheels)
  * 1 inserted in the pendulum 
* Pendulum rod, having comparable weight to the cart


## Modelling the system in Octave
We first simulate the physical system by considering it's parameters (like mass of cart, pendulum rod, length of rod, etc.) and the dynamics equations. Then, after finding the A and B matrices for the equation, ([reference](./Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md))
$$\dot{x} = Ax + Bu$$ 
for the linearised system, we then define the system using the 'ss()' function. Using the 'c2d()' function, we [discretise the system](https://github.com/vrnimje/Inverted-LQR-Bot-Eklavya/blob/develop/Notes/Vedant/Control_Bootcamp_Vedant.md#3-linearising-around-a-fixed-point), and then we get the feedback matrix K, by using the function 'dlqr()'. [Octave File for reference](./Octave_Tasks/Vedant_Task_1/Inverted_Pendulum.m)<br>

The input,
$$u = -Kx$$
is then applied to the system, so as to minimise the LQR Cost function. The output is: ![Screencast from 26-09-22 02 59 55 PM IST](https://user-images.githubusercontent.com/103848930/192244461-e146e1bc-0291-40d1-aeaf-7fe5bbefa809.gif)

Using the 'step()' function, this is the plot generated for the step response of the linearised system in terms of the state variables, i.e., 
$$ [\theta, \dot{\theta}, x, \dot{x}] $$
with respect to time.

![Step Response](/Notes/assets/step_response.png)




