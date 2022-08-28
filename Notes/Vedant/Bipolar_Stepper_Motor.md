## Stepper Motor

<p>
A stepper motor, also known as step motor or stepping motor, is a brushless DC electric motor that divides a full rotation into a number of equal steps. 
The motor's position can be commanded to move and hold at one of these steps without any position sensor for feedback (an open-loop controller), 
as long as the motor is correctly sized to the application in respect to torque and speed. 

<image src="assets\StepperMotor.gif"></image><br>

A unipolar stepper motor has one winding with center tap per phase. Each section of windings is switched on for each direction of magnetic field. 
Since in this arrangement a magnetic pole can be reversed without switching the polarity of the common wire, the commutation circuit can be simply a 
single switching transistor for each half winding. Typically, given a phase, the center tap of each winding is made common: three leads per phase and six 
leads for a typical two phase motor. Often, these two phase commons are internally joined, so the motor has only five leads. 

<image src="assets\Unipolar.png"><br>

Bipolar motors have a pair of single winding connections per phase. The current in a winding needs to be reversed in order to reverse a magnetic pole, 
so the driving circuit must be more complicated, typically with an H-bridge arrangement (however there are several off-the-shelf driver chips available 
to make this a simple affair). There are two leads per phase, none is common. 
Static friction effects using an H-bridge have been observed with certain drive topologies.
Dithering the stepper signal at a higher frequency than the motor can respond to will reduce this "static friction" effect. 
 
<image src="assets\bipolar.png"><br>

Because windings are better utilized, they are more powerful than a unipolar motor of the same weight. This is due to the physical space occupied by 
the windings. A unipolar motor has twice the amount of wire in the same space, but only half used at any point in time, hence is 50% efficient (or 
approximately 70% of the torque output available). Though a bipolar stepper motor is more complicated to drive, the abundance of driver chips means this 
is much less difficult to achieve. 
  </p> 
 
## Stepping angle
  
The step angle is the basis of the movement of a stepping motor.
The step angle depends on the total number of magnetic poles of the motor.
The step angle is determined by the formula:

    Step angle = 360 degrees / N  where N = (NPH x PH)

    NPH: Number of magnetic poles for each phase
    PH: Number of phases
    N: Total number of magnetic poles in all phases

The motor types are usually referenced as “PH-phase / N-pole motor” (e.g. 2-phase / 4-pole on the left side and 3-phase / 6-pole on the right side)
 
 <image src="assets\stepping angle.png"></image><br>
  
**For Nema-17, the stepping angle is 1.8 or 0.9 degrees, depending on the model.**
 
## Microstepping
 
Microstepping is a method of controlling stepper motors, typically used to achieve higher resolution or smoother motion at low speeds.
Stepper motors move in discrete steps, or fractions of a revolution. This discrete motion means the motor’s rotation isn’t perfectly smooth, and the slower the rotation, the less smooth it is due to the relatively large step size. One way to alleviate this lack of smoothness at slow speeds is to reduce the size of the motor’s steps. This is where microstepping comes in.

Microstepping control divides each full step into smaller steps to help smooth out the motor’s rotation, especially at slow speeds. For example, a 1.8 degree step can be divided up to 256 times, providing a step angle of 0.007 degrees (1.8 ÷ 256), or 51,200 microsteps per revolution.
 
Microstepping is achieved by using pulse-width modulated (PWM) voltage to control current to the motor windings. The driver sends two voltage sine waves, 90 degrees out of phase, to the motor windings. While current increases in one winding, it decreases in the other winding. This gradual transfer of current results in smoother motion and more consistent torque production than full- or half-step control.
 
(Pulse-width modulation (PWM), or pulse-duration modulation (PDM), is a method of reducing the average power delivered by an electrical signal, by effectively chopping it up into discrete parts. The average value of voltage (and current) fed to the load is controlled by turning the switch between supply and load on and off at a fast rate. The longer the switch is on compared to the off periods, the higher the total power supplied to the load.)
 
While the smoothness of torque delivery, low-speed motion, and resonance are improved with microstepping, limitations in control and in motor design prevent them from reaching their ideal characteristics. This is primarily because microstepping drives can only approximate a true sine wave, so some torque ripple, resonance, and noise remains, although each one is greatly reduced in comparison to full- and half-stepping modes. In addition, torque production from a stepper motor with microstepping control is only about 70 percent of the torque produced with full-step control.
 
 ![image](https://user-images.githubusercontent.com/103848930/186476906-008624e7-3664-40fc-bc86-871ebd0fb4ca.png)
 
 **DRV8823**: https://www.ti.com/lit/ds/symlink/drv8823.pdf?ts=1661361828977&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FDRV8823

**A4988**: https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/
 
 ### Torque Characteristics
 
 The Speed-Torque graph indicates the characteristic relationship between the speed and torque when the stepping motor is driven. The torque vs speed characteristics are the key to selecting the right motor and drive method for a specific application. These characteristics are dependent upon (change with) the motor, excitation mode and type of driver or drive method. On the graph, the horizontal axis is the speed at the motor’s output shaft while the vertical axis is the torque.
 
  1.Maximum Holding Torque<br>
The holding torque is the maximum holding power (torque) the stepping motor has when power (rated current) is being supplied but the motor is not rotating (with consideration given to the permissible strength of the gear when applicable).

 2.Pull-in Curve<br>
The pull-in curve defines a area refered to as the start stop region. This is the maximum frequency at which the motor can start/stop instantaneously, with a load applied, without loss of synchronism.
 
 3.Pullout Torque Curve<br>
Pullout torque is the maximum torque that can be output at a given speed. When selecting a motor, be sure the required torque falls within this curve.

 4.Maximum Starting Frequency<br>
This is the maximum pulse speed at which the hybrid stepping motor can start or stop instantaneously (without an acceleration or deceleration time) when the frictional load and inertial load of the stepping motor are 0. Driving the motor at greater than this pulse speed requires gradual acceleration or deceleration. This frequency drops when thereis an inertial load on the motor.

5. Maximum Slew Rate<br>
The maximum operating frequency of the motor with no load applied.
 
 ![image](https://user-images.githubusercontent.com/103848930/186489288-fc48a6e7-8738-4318-9c5c-af55a36b69d8.png)

 
For NEMA-17: [Specifications](https://www.motioncontrolproducts.com/electric-motors/stepper-motors/hybrid-stepper-motors/nema-17-high-torque-stepper-motors/)

 

 
 
 






  


