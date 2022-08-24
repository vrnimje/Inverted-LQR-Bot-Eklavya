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
  
**For Nema-17, the stepping angle is 1.8 degrees.**

  


