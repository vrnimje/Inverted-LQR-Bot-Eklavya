# Hardware Issues and Solutions

**Table of contents**
1. [Delay in MPU readings](#delay-in-mpu-readings)
1. [Interruption in MPU readings](#interruption-in-mpu-readings)
1. [Varying tension in belt](#varying-tension-in-belt)

---

<br>

## Delay in MPU readings
In initial firmware code reading MPU values and running stepper motor was being done in single task.
This caused delay in MPU readings as delay intended for stepper motor was affecting MPU readings. 
This delay in MPU readings further caused slow response from motor.

To solve this problem reading MPU values and running stepper motor is now split in two different tasks.
This reduces the delay significantly. The delay which remains is inherent in Complementary filter method of 
MPU6050. 
To reduce this delay even further we plan use DMP(Digital Motion Processor) of MPU6050 in future.

More information on DMP and its advantage over complementary filter can be found [here](https://www.youtube.com/watch?v=2t-5CCyPJ74)

---

<br>

## Interruption in MPU readings
MPU works on I2C protocol. It is vulnerable to electromagnetic interfernces. Using high frequency smps will give 
following error.
<pre><code>i2cdev could not read from devices 0x68
</code></pre>

To solve this issue, we used a 12V battery rather than a 12V smps. 

---

<br>

## Varying tension in belt 
Initial hardware setup consisted of timing belt in trapezoidal shape, its top side being the base of cart.
Whenever the cart moved to extreme ends of rails the tension in belt increased. Increase in tension was
enough to break acrylic cart during testing.

<img src="https://i.postimg.cc/d0ph1sr9/broken-cart.jpg" alt="Broken cart :(" width="500"/>


Simple fix to this problem is using belt in a rectangular shape so that movement of cart doesn't change tension 
in belt.
