# Esp32CameraRover

This sketch uses an ESP32 CAM (AI Thinker model), a L9110S dc motor controller and a commonly available Robot Car chassis to create a First-Person-View (FPV) robot that can be driven from any web browser.


## Status
- This first iteration does not yet incorporate the optocouplers.  It uses the use the canonical Esp32CameraServer example sketch as the basis for the Esp32CameraRover sketch and adds the rover functionality to it.  However, the results are dissapointing.  The problem is that the webserver is 'polled'; it takes over the ESP32 when handling a single request.  It seems to take several seconds to handle a single request.  This causes real problems trying to drive the rover.  Even worse, it seems that rover commands cannot be handled while video is streaming, which is sort of the whole point of this project.  The good news is that there are other more capable web server libraries for the ESP32 which could solve these problems.  I've tried to keep the rover code de-coupled from the rest of the sketch, which has turned out to be a very good thing.  The next iteration fo this project will use a better web server library and a different way to stream the video.


## Parts
The parts are readily available from many suppliers.  I will provide links to Amazon (fast delivery) and AliExpress (low prices), but there are other suppliers that you may prefer.  Think of these links as a description of what you can get and about how much it will cost, rather than a suggestion for any particular supplier.  You may also choose to buy two at a time as this will also save money if you want spare parts or a second robot.  Also, it is sometimes easier to test code on parts rather than a fully assembled robot, so a second set of parts can be handy that way.

####AI Thinker ESP32 Cam
This is a ESP32-S with an OV2640 camera.
- [Amazon](https://www.amazon.com/SongHe-ESP32-CAM-Development-Bluetooth-Arduino/dp/B07RB2J4XL/ref=sr_1_7)
- [AliExpress]()

#### USB to TTL converter
This is used send the program to the ESP32 Cam and read the output of the serial port.  There are a lot of different variations of this kind of board.
- [Amazon](https://www.amazon.com/HiLetgo-CP2102-Converter-Adapter-Downloader/dp/B00LODGRV8/ref=sr_1_4)
- [AliExpress]()

#### L9110S DC Motor Driver
This is used to control the two motors of the robot chassis.  It is connected to the ESP32 Cam pins to get 'commands' and to the two DC Motors to provide them with power and control signals.  This is a great chip for controlling small DC motors (and stepper motors) and they are cheaper when you buy several, so if you are interested in building with small DC motors, this is a great, inexpensive motor driver.
- [Amazon](https://www.amazon.com/Comimark-H-Bridge-Stepper-Controller-Arduino/dp/B07WZFGS81/ref=sr_1_14)
- [AliExpress]()

#### Smart Robot Car Chassis Kit
These kits can be had from many vendors.  They contain a clear plastic platform with mounting holes, two DC geared motors, two wheels and tires, one omnidirectional caster wheel, two optical encoder disks (for measuring speed; usable if you also get the IR Optocouplers below), a toggle switch, a battery box (which we are not going to use), a little wire and all the necessary mounting hardware.
- [Amazon](https://www.amazon.com/MTMTOOL-Smart-Chassis-Encoder-Battery/dp/B081GYVB6C/ref=sr_1_4)
- [AliExpress]()

#### IR Slotted Optocouplers
These, in combination with the optical encoder discs that come with the Smart Robot Car Chassis Kit, can be used to measure wheel rotation, so you can precisely measure speed and distance travelled.  Note that you can find several differnt kinds of these slotted optocouplers.  The ones with the header pins on the opposite side of the board from the IR detector slots work best because the pins point 'up' while the slots points 'down'.  On some other kinds, the pins also point down and prevent the module from seating propertly.
- [Amazon](https://www.amazon.com/gp/product/B081W4KMHC/ref=ppx_yo_dt_b_asin_title_o06_s00)
- [AliExpress]()
