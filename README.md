# About This Project
Control systems form the basis for ensuring that every automatic system performs its ordained task accurately, efficiently and quickly (optimally) despite being subjected to varying environmental conditions.
In this project, we explore these control systems, by considering the classical problem of an inverted pendulum on cart, which is used as a benchmark for testing control strategies.

We have implemented the [LQR (Linear Quadratic Regulator)](https://github.com/vrnimje/Inverted-LQR-Bot-Eklavya/blob/develop/Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md#lqr-control-for-the-inverted-pendulum-on-a-cart), which is a type of controller in which we try to minimise a cost function by optimising the various states of the physical system.

### 1. Research Topics
* **Linear Algebra**, for representation of various aspects of our physical systems, like, current state, stability, etc.. ([Notes for the same](./Notes/Mahesh/LA_Notes_Mahesh.md))
* A thorough understanding of **Control Systems**. ([Notes for the same](./Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md))

### 2. List of Software Used
* [GNU Octave, version 7.1.0](https://octave.org/) for modelling and simulating the inverted pendulum. 
* [SOLIDWORKS](https://www.solidworks.com/), for designing custom components.
* C language

### 3. List of Hardware Used
* NEMA-17 Stepper Motor ([Notes for the same](./Notes/Mahesh/Controlling_Stepper_Motor.md))
* Rails. on which the cart moves
* Timing belt
* Custom-designed laser-cut cart, made of acrylic, and has screw-holes for the wheels (bearings) ([Drawing file for the plates](./Cart_design/side_plate.pdf)
* [ESP32 microcontroller](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
* MPU6050, for measuring the deviation of the pendulum from the normal
* 9 ball bearings, 8 in the cart (acting as wheels), and one inserted in the pendulum 
* Pendulum rod, having comparable weight to the cart



## Modelling the system in Octave
We first simulate the physical system by considering it's parameters (like mass of cart, pendulum rod, length of rod, etc.) and the dynamics equations. Then, after finding the A and B matrices for the equation, ([reference](./Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md))
$$\dot{x} = Ax + Bu$$ 
for the linearised system, we then define the system using the 'ss()' function. Using the c2d() function, we [discretise the system](https://github.com/vrnimje/Inverted-LQR-Bot-Eklavya/blob/develop/Notes/Vedant/Control_Bootcamp_Vedant.md#3-linearising-around-a-fixed-point), and then we get the feedback matrix K, by using the function 'dlqr()'. [Octave File for reference](./Octave_Tasks/Vedant_Task_1/Inverted_Pendulum.m)<br>

The input,
$$u = -Kx$$
is then applied to the system, so as to minimise the LQR Cost function. The output is: ![Screencast from 26-09-22 02 59 55 PM IST](https://user-images.githubusercontent.com/103848930/192244461-e146e1bc-0291-40d1-aeaf-7fe5bbefa809.gif)




