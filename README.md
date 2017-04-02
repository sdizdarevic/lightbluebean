# lightbluebean
Lightblue-Bean photoresistor project
In this project I am going to show you how to use photoresistor with lightblue bean with analog voltage reading method. The connection diagram of photosensor connecton to microcontroller is actually simple, and it is shown below:

![img](https://hackster.imgix.net/uploads/attachments/283025/light_cdsanasch_av297y5KL5.gif?auto=compress%2Cformat&w=680&h=510&fit=max)


What do I need?

A LightBlue Bean, of course! This is the bit that reads the light intensity value, and later, you can send those values to your phone. You will also need a photoresistor and a pulldown resistor with 10K resistance.

Software part

I've been used PlatformIO for a while, and all I can say is that is simple, wonderfull open source ecosystem for IoT development which is built on top of GitHub's Atom text editor.

The people behind the LightBlue Bean and Bean+ boards, released their new Bean Loader, the application that allows you to build and upload new sketches to your beans. You can use Bean Loader with latest version of Arduino IDE, but I used PlatformIO IDE. The great news about this is that the Bean Loader is cross-platform and also supports Linux.

Installing the Bean Loader CLI

It's simple to install Bean Loader CLI. First, you need to make sure you have installed Node.js and npm (by typing in the command line node -- version and npm --version). Now type: npm install -g bean-sdk.

To check if the bean SDK is installed type bean -v. You can find more info at: https://punchthrough.com/bean/docs/guides/getting-started/cli-loader/

Since LightBlue Bean is based on Atmel AVR chip (Atmel 328P - the same chip which uses Arduino Uno), you need to make sure that platformio has installer armel AVR platform. In command line now type:

platformio platform install atmelavr

Now you just need to run these two commands to setup and compile a sketch for the Bean:

platformio init -b lightblue-bean

platformio run -e lightblue-bean

Now you can build a sketch for the Bean, but how can you upload it?

The Bean Loader CLI provides a command to upload sketches. If you use the Arduino IDE the upload button actually just build and copies the sketch binary to “~/.beansketches/bean/”. This is the folder the list_compiled_sketches command of the CLI reads to output available firmwares. So if you have a firmware file there called “led.hex” you can upload it to your Bean with:

bean program_sketch led -n bean01



Ok, but actually you need only to parse a path to HEX file to bean command which actually uploads hex file to the lightblue-bean. So, PlatformIO generates also a hex file, which you can find in .pioenvs/lightblue-bean/firmware.hex project folder. So, to upload HEX file generated from PlatformIO you need to type the command:

bean program_sketch .pioenvs/lightblue-bean/firmware.hex -n bean01
![img](https://hackster.imgix.net/uploads/attachments/283040/untitled_AAdcevV5gs.png?auto=compress%2Cformat&w=1280&h=960&fit=max)

The code with generated ready-to-upload hex file is located on my github repository (link below). It is really simple now to send data from photosensor to your Android-based phone.

![img](https://www.dropbox.com/s/0lxev3ypk4y9xu1/Untitled1.png?dl=0)
