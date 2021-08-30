# CatTreatDispenser
A 3d-printed cat treat dispenser with Twitch chat connector.

# Content
Arduino holds the source code for the Arduino Uno (many other Arduinos will also work).
Compiling holds and exploded and compiled view of the 3d-printed device.
Node.js holds the code for the anonymous chat bot that connects to the Arduino Uno.
STL holds the stl-files for the 3d-printed device.

#Requirements
Arduino IDE with Arduino Uno connected
STL-slicer for your 3d-printer
Node libraries Serial and tmi
SG-90 micro servo with jumper leads

#How-To
Slice the stl-files and print the three components.
Compile the device and glue it together with epoxy or other strong glue. The hole of the core should be slightly past (higher) than the hole in the base when the micro servo is at 180 degrees.
Install the node libraries.
Compile and upload the Arduino driver.
Connect the micro servo to the Arduino. Brown lead to GND, red lead to +5V, yellow lead to pin 9.
Fill the device with small amount of cat treats.
Make sure the Arduino device show up as COM3, otherwise adjust the chat bot to reflect proper port. Also make sure your channel name is set in the code.
Run the chat bot. The chat bot should connect to the Arduino driver and declare it is ready to use. When !feed is sent in the chat the Arduino should trigger and dispens one cat treat.