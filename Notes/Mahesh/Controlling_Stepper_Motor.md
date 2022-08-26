# Controlling Stepper Motor

**Table of contents**
1. [What is Stepper Motor](#what-is-stepper-motor)
1. [Microstepping](#microstepping)
1. [Torqe Characteristics of stepper motor](#torqe-characteristics-of-stepper-motor)
1. [Motor Drivers](#motor-drivers)


## What is Stepper Motor
It is a DC motor used in places where precision is important. It divides its rotation into smaller
parts called 'steps'. A typical stepper motor is designed to have 200 steps. That means it will
need 200 steps or 200 electric pulses for a complete rotation. One step will be of 360/200 = 1.8°.
This is called 'Stepping Angle'.


Depending of whether the coils have 2 or 3 connections, the motors are differentiated as bipolar 
or unipolar.

<img src = "https://i.postimg.cc/nc0RzG8v/Unipola-bipolar.png" alt = "Difference between Bipolar and unipolar" widht = 400>

---

<br>

## Microstepping
Microstepping control divides each full step into smaller steps to help smooth out the
motor’s rotation.For example, a 1.8 degree step can be divided up to 256 times, providing a
step angle of 0.007 degrees (1.8 ÷ 256), or 51,200 microsteps per revolution.

Microstepping is achieved by using pulse-width modulated (PWM) voltage to control current to
the motor windings. The driver sends two voltage sine waves, 90 degrees out of phase, to the
motor windings. While current increases in one winding, it decreases in the other winding
This gradual transfer of current results in smoother motion and more consistent torque
production than full- or half-step control.

<img src = "https://doc.ingeniamc.com/wiki/files/60167310/60167309/1/1487234409059/MicroStepping.png" alt = "Microstepping" width = 400> 

---

<br>

## Torqe Characteristics of stepper motor

<img src = "https://www.linearmotiontips.com/wp-content/uploads/2019/09/Torque-Curves.png" alt = "Torque vs Pulse Rate" width = 400>


1. Pull-in torque curve: 
    The pull-in torque curve shows the range of conditions (maximum torques at given speeds
    under which the motor can start and stop in synchronism with the input pulses — in other
    words, without losing steps. At any point on or below this curve — referred to as the
    “start/stop” or “self-start” region — the motor can start or stop instantly (that is,
    without accelerating or decelerating) without losing steps.

1. Pull-out torque curve: 
    Also referred to as “running torque” or “dynamic torque,” pull-out torque is the maximum
    load (torque) a stepper motor can produce while it’s rotating, without losing steps. If
    operated at a point beyond the pull-out torque curve, the motor can stall.

1. Slew Range: 
    The area between the pull-in and pull-out curves is often referred to as the “slew
    range.” In this range, the motor cannot be immediately stopped or started — it must be
    started in the start/stop region and accelerated to the slew range, or it must be
    decelerated from the slew range to the start/stop region and then stopped.

1. Holding Torque:
    Stepper motor can hold a place when motor coils are energized due to attraction between
    rotor and stator. Holding torque is amount of torque motor can exert when it is
    energised. A stepper motor’s holding torque is higher than its running torque and is
    limited primarily by the amount of current the motor can withstand.

1. Detent Torque: It is amount of torque motor has when it is not envergised. Also called as
Residual Torque. It occurs because of the attractive forces between the magnets in the
motor’s rotor and the stator.Detent torque is often given in the motor’s data sheet and is an
important factor in stepper motor sizing and selection because it must be overcome before the
motor will move.

Data Sheet for [Nema 17](https://components101.com/sites/default/files/component_datasheet/NEMA17.pdf)

---

<br>

## Motor Drivers
Direction of rotation and speed of stepper motor is controlled by sequence of electric pulses
and there frequency. Alhough it can be done by microprocessor, it
is best done with special circuit called motor drivers. 

Motor driver is used to adjust rotation and speed of motor. It is
also used to  achieve microstepping.

More information about motor drivers:

[A4988](https://www.pololu.com/file/0J450/a4988_DMOS_microstepping_driver_with_translator.pdf)

[DRV8823](https://www.ti.com/lit/ds/symlink/drv8823.pdf?ts=1661503746623&ref_url=https%253A%252F%252Fwww.google.com%252F)