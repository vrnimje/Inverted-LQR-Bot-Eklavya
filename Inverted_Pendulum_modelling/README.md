## Inverted Pendulum Modelling
The Octave [file](.\Inverted_Pendulum_modelling\Inverted_Pendulum.m) consists of all the state-space equations and the A and B matrices. This file is used to model the system and also to simulate our system.

The following are the some of the important functions used along with their working
1. ss(): Defines the system by using the A and B matrices
2. c2d(): Converts a continuous system into a linear one
3. dlqr(): Returns the feedback matrix by applying LQR for the discretised system
4. step(): Plots the step response of the system
   
Step Response of system <br>
![Step Response](.\Notes\../Notes/Vedant/assets/step_response.png)


