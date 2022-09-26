# About This Project
Control systems form the basis for ensuring that every automatic system performs its ordained task accurately, efficiently and quickly (optimally) despite being subjected to varying environmental conditions.
In this project, we explore these control systems, by considering the classical problem of an inverted pendulum on cart, which is used as a benchmark for testing control strategies.

We implement the [LQR (Linear Quadratic Regulator)](https://github.com/vrnimje/Inverted-LQR-Bot-Eklavya/edit/develop/Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md#lqr-control-for-the-inverted-pendulum-on-a-cart), which is a type of controller in which we try to minimise a cost function by optimising the various states of the physical system.

### 1. Research Topics
* **Linear Algebra**, for representation of various aspects of our physical systems, like, current state, stability, etc.. ([Notes for the same](../Notes/Mahesh/LA_Notes_Mahesh.md))
* A thorough understanding of **Control Systems**. ([Notes for the same](../Notes/Mahesh/ControlBootcamp_Notes_Mahesh.md))

### 2. List of Software Used
* [GNU Octave, version 7.1.0](https://octave.org/) for modelling and simulating the inverted pendulum. 
* [SOLIDWORKS](https://www.solidworks.com/), for designing custom components.
* C language

### 3. List of Hardware Used
* NEMA-17 Stepper Motor ([Notes for the same](../Notes/Mahesh/Controlling_Stepper_Motor.md))
* Rails. on which the cart moves
* Timing belt
* Custom-designed laser-cut cart, made of acrylic, and has screw-holes for the wheels (bearings) ([Drawing file for the plates](../Cart_design/side_plate.pdf)
* [ESP32 microcontroller](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
* MPU6050, for measuring the deviation of the pendulum from the normal
* 9 ball bearings, 8 in the cart (acting as wheels), and one inserted in the pendulum 
* Pendulum rod, having comparable weight to the cart
