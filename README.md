# Esp32CameraRover

This sketch uses an ESP32 Cam, an L9110S dc motor controller and a commonly available Robot Car chassis to create a First-Person-View (FPV) robot that can be driven from any web browser.

This project is no longer maintained.  See the actively updated project https://github.com/Ezward/Esp32CameraRover2


## Status
- This first iteration does not yet incorporate the optocouplers.  It uses the canonical Esp32CameraWebServer example sketch its basis and adds the rover functionality to it.  However, the results are disappointing.  The problem is that the webserver is 'polled'; it takes over the ESP32 when handling a single request.  It seems to take several seconds to handle a single request.  This causes real problems trying to drive the rover.  Even worse, it seems that rover commands cannot be handled while video is streaming, which is sort of the whole point of this project.  The good news is that there are other more capable web server libraries for the ESP32 which could solve these problems.  I've tried to keep the rover code de-coupled from the rest of the sketch, which has turned out to be a very good thing.  The next iteration for this project will use a better web server library and a different way to stream the video.
- This first iteration using simple LOW/HIGH output to control the motors, so speed is zero or 100%.  I attempted using PWM but the results were erratic, probably mostly to do with the web server.
- This first iteration does not yet incorportate the optocouplers.

### TODO
These are somewhat ordered, but priorities can change.  The overall goals are  is first: 
1. FPV Rover with keyboard or web UI control.  
2. UI for recording and playing back a path (limited autonomy).
3. Enhanced FPV Rover with better speed and turn control and game controller input for a more natural user experience.
4. Autonomous lane following.
5. Object recognition and collision avoidance.

- [ ] Change to a more performance web server that will allow simultanous streaming of images and processing of rover commands.
- [ ] Implement websocket protocol and serve images over websocket (may just be part of improving performance, but down the road we want to also use it so send commands to rover).
- [ ] Implement websocket protocol to send commands from browser to rover (rather than HTTP GET api; this forces ordering of commands).
- [ ] Implement authentication so only one person can be driving, but any number of people can be viewing.
- [ ] Implement optocouplers for measuring speed and distance travelled.  Add precision commands, 180 degree turn (turn around), turn 90 degrees right, turn 90 degrees left. 
- [ ] Implement command/time/distance recorder and associated UI so we can record and playback a path that has been driven.
- [ ] Implement PWM control for motor speed (and modify UI to support this).
- [ ] Implement PID algorithm to precisely control speed of motors (and so allow for any turning radius).
- [ ] Implement game controller input (via browser's game control api).
- [ ] Implement CV lane following autopilot running on ESP32 (for Donkeycar kind of track).
- [ ] Implement object detection in browser using TensorFlow.js.  In particular, stop signs, traffic lights, pedestrians and other rovers such that the rover can obey signs and avoid collisions.
- [ ] Implement Neural Network autopilot in browser using Tensorflow.js
- [ ] Implement map and path planning such that rover can use autonomous mode to travel from a specified location to another on the map.  Think simulating a 4 block neighborhood with a perimeter road, 4 3-way intersections and a central 4 way intersections and at least one section of a gradual curve (rather than 90 degrees) so we can test smooth turning.
- [ ] Combine path planning, autonomy, obstacle detection and collision avoidance to implment an autonomous package delivery vehicle in a simulated neighbor hood.  Add a second autonomous rover.

## Parts
The parts are readily available from many suppliers.  I will provide links to Amazon (fast delivery) and AliExpress (low prices), but there are other suppliers that you may prefer.  Think of these links as a description of what you can get and about how much it will cost, rather than a suggestion for any particular supplier.  You may also choose to buy two at a time as this will also save money if you want spare parts or a second robot.  Also, it is sometimes easier to test code on parts rather than a fully assembled robot, so a second set of parts can be handy that way.

#### ESP32 Cam
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
