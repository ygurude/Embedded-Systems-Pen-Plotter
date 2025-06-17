# ECE4180_Project
Our final project for ECE 4180 is essentially a pen plotting system in car form. The robot we created takes an input from an app on any smartphone, connected via the bluetooth module, and then able to autonomously write the letter or word on the ground. It has car-like movement, meaning it uses motors and wheels to move around to write the input.

Going into each peripheral, the robot has eight peripherals that each have a task and work together to create the whole system.

The first peripheral is the bluetooth module, Adafruit Bluefruit LE UART. The bluetooth module was the first step in creating the car as it helped us to connect the whole system via the prebuilt Adafruit app. With the app we were able to implement the ON/OFF switch for energy efficiency and pass in an input so the car would write it. 

Next is the H-Bridge Motor Driver with the two DC Motors. These were very crucial peripherals since no movement would have been possible without them. One concern was how we were going to rotate them using only 2 motors/wheels, but we essentially made one motor spin forward and the other spin backward to rotate the car in place.  The H-Bridge Motor Driver takes data from the microcontroller and sends it to the motors, telling them how much to spin and in what direction. The DC Motors then follow these instructions and move the actual car in whatever way is needed. 

Then we have the 2 battery packs along with the 2 barrel jacks. Initially, we only had one of each to power the whole system, providing about 6 V for the system. But we ran into issues where the system crashed on some letters as the Motor Driver was not receiving enough energy to move the motors for a longer period of time so we introduced another battery pack and barrel jack dedicated to powering the Motor Driver. This helped us a lot as we never ran into the system crashing error after that. We then changed the first battery pack and barrel jack to power the mbed, bluetooth module, IMU, and RGB LEDs. 

This leads to the next peripheral, the RGB LEDs. The LEDs had a very simple purpose: to show the status of the system. When you power it on, the LEDS slowly turn white. When it gets ready for input, they flash green, and while the robot is writing, they show red, signaling that it is still writing. 

Lastly the final peripheral we used is the IMU (ICM-20948). This was a last minute addition to the robot because of poor turning consistency. Originally we would spin the motors for a certain amount of seconds to get our desired 90 degree turn but this was very inconsistent. So a couple of days before our demo we decided to implement an IMU for the gyroscope, hoping it would measure the actual degrees instead of relying on time. This greatly improved accuracy and consistency but still not the best in terms of turning.
A big problem that we encountered in our project was turning issues After each letter was drawn there would be an offset function to set up the robot for the next letter. Because of the inconsistency in turning, the word would curve upwards and this is something we wanted to improve on. So we added in the IMU for this reason, which did help.

Our project is similar to real world embedded system pen plotters, as they both take in inputs and write them onto any material. But the difference is that our system is not limited to how big the letters can be. The other pen plotters are limited by their size and actuator range, while ours could be used in a wider range of situations.

If we had more time and resources, we would have implemented various peripherals and ideas. The first one is something we mentioned in our project proposal, which was using a servo to move the pen up and down. This would have been very useful for letter logic, and leaving gaps between letters and words. Given 1-2 more weeks we would have definitely implemented this feature into the system. Moreover, we would have tested and debugged the issues with the turning consistency, maybe implementing other peripherals to make sure the turning was on point. Lastly, our code has a lot of room for optimization, as it might have been better to create an actual algorithm for writing, instead of hardcoding every letter with helper functions.


![Circuit Diagram](https://github.com/ygurude/ECE-4180-Project/raw/main/circuitdiagram.jpg)

