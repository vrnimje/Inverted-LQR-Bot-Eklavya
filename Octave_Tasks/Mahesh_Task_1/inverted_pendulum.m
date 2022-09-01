1;
pkg load control;

## Function : draw_inverted_pendulum()
## ----------------------------------------------------
## Input:   y - State Vector. In case of inverted pendulum system, the state variables
##              are the position x, the velocity x_dot, angular deviation theta and
##              angular velocity theta_dot.
##
## Purpose: Takes the state vector as input. It draws the inverted pendulum system in
##          a 2D plot.
function draw_inverted_pendulum(y)

  l = 0.3;    ## Length of rectangle
  b = 0.3;    ## Breadth of rectangle
  l_p = 2;    ## Length of pendulum
  d = 0.1;    ## Diameter of pendulum

  sin_theta = sin(y(3));
  cos_theta = cos(y(3));

  x_c = y(1); ## x-coordinate of cart
  y_c = 1;    ## y-coordinate of cart

  x_p = x_c-l_p*sin_theta; ## x-coordinate of pendulum
  y_p = y_c-l_p*cos_theta; ## y-coordinate of pendulum


  hold on;
  clf;
  axis equal;
  figure(1, 'position', [100 100 1000 800]);

  ## cart
  rectangle("Position", [x_c - l/2, y_c - b/2, l, b], "Curvature", 0,'FaceColor',[1 0 0]);

  ## rod on which cart moves
  line([-3 3], [1 1], "linestyle", "-", "color", "k");

  ## pendulum rod
  line ([x_c x_p], [y_c y_p], "linestyle", "-", "color", "k");

  ## pendulum bob
  rectangle('Position',[x_p-(d/2), y_p-(d/2), d, d],'Curvature',1,'FaceColor',[1 0 0]);

  xlim([-3 3])
  ylim([-1 4])

  drawnow
  hold off;

endfunction

## Function : inverted_pendulum_dynamics()
## ----------------------------------------------------
## Input:   y - State Vector.
##          m - Mass of pendulum
##          M - Mass of cart
##        l_p - Length of pendulum
##          g - Acceleration due to gravity
##          u - Input to the system
##
## Output:  dy -  Derivative of State Vector. In case of mass spring system they
##                will be the velocity x_dot, acceleration x_dot_dot, angular velocity
##                theta_dot and angular acceleration theta_dot_dot
## Purpose: Calculates the value of the vector dy according to the equations which
##          govern this system.
function dy = inverted_pendulum_dynamics(y, m, M, l_p, g, u)

  sin_theta = sin(y(3));
  cos_theta = cos(y(3));

  dy(1,1) = y(2);
  dy(2,1) = (-m*g*sin_theta*cos_theta - m*(y(4)^2)*l_p*sin_theta + u)/(M + m*sin_theta^2);
  dy(3,1) = y(4);
  dy(4,1) = (dy(2,1)*cos_theta - g*sin_theta)/l_p;
endfunction

## Function : sim_inverted_pendulum()
## ----------------------------------------------------
## Input:   m - Mass of pendulum
##          M - Mass of cart
##          g - Acceleration due to gravity
##        l_P - Length of pendulum
##         y0 - Initial Condition of system
##
## Output:  t - Timestep
##          y - Solution array
##
## Purpose: This function demonstrates the behavior of pendulum on cart without
##          any external input (u)
##          This integrates the system of differential equation from t0 = 0 to
##          tf = 15 with initial condition y0
function [t,y] = sim_inverted_pendulum(m, M, g, l_p, y0)
  tspan = 0:0.1:15;                  ## Initialise time step
  u = 0;                        ## No Input
  [t,y] = ode45(@(t,y)inverted_pendulum_dynamics(y, m, M, l_p, g, u),tspan,y0);
endfunction

## Function : inverted_pendulum_AB_matrix()
## ----------------------------------------------------
## Input:   m - Mass of pendulum
##          M - Mass of cart
##          g - Acceleration due to gravity
##        l_P - Length of pendulum
##
## Output:  A - A matrix of system
##          B - B matrix of system
##
## Purpose: Declare the A and B matrices in this function.
function [A,B] = inverted_pendulum_AB_matrix(m, M, g, l_p)
  A = [0 1 0 0;0 0 -g*m/M 0;0 0 0 1;0 0 g*(m + M)/(M*l_p) 0];
  B = [0; 1/M; 0; -1/(M*l_p)];
endfunction

## Function : lqr_inverted_pendulum()
## ----------------------------------------------------
## Input:   m - Mass of pendulum
##          M - Mass of cart
##          g - Acceleration due to gravity
##        l_P - Length of pendulum
## y_setpoint - Reference Point
##         y0 - Initial Condition
##
## Output:  t - Timestep
##          y - Solution array
##
## Purpose: This function demonstrates the behavior of inverted pendulum with
##          external input using the LQR controller
##          This integrates the system of differential equation from t0 = 0 to
##          tf = 15 with initial condition y0 and input u = -Kx where K is
##          calculated using LQR Controller.
function [t,y] = lqr_inverted_pendulum(m, M, l_p, g, y_setpoint, y0)
  [A, B] = inverted_pendulum_AB_matrix(m, M, g, l_p);
  Q = [100 0 0 0;0 100 0 0;0 0 500 0;0 0 0 500];
  R = 0.0001;
  K = lqr(A,B,Q,R);
  tspan = 0:0.1:15;                  ## Initialise time step
  [t,y] = ode45(@(t,y)inverted_pendulum_dynamics(y, m, M, l_p, g, -K*(y - y_setpoint)),tspan,y0);
endfunction

## Function : inverted_pendulum_main()
## ----------------------------------------------------
## Purpose: Used to simulate system with or without input using respective functions.
##          Constant parameters like mass of cart and pendulum, length of pendulum
##          etc are declared here.
function inverted_pendulum_main ()
  m = 1;
  M = 5;
  l_p = 2;
  g = 9.8;

  y0 = [3;0;3*pi/4;0];
  y_setpoint = [0;0;pi;0];

  ##[t,y] = sim_inverted_pendulum(m, M, l_p, g, y0)
  [t, y] = lqr_inverted_pendulum(m, M, l_p, g, y_setpoint, y0)

 for k = 1:length(t)
    draw_inverted_pendulum(y(k, :));
  endfor
endfunction
