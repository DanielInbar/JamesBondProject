# **This is "James Bond bomb" project**
> by: Eli Bangiev, Daniel Inbar

this project demonstrates a "bomb" that consist 3 stages of a lock that you need to guess the password

## how to play
this game is played using the potentiometer and a toggle button\
once you start the program you will need to press the toggle button (connected to pin 8)\
then you have 5 seconds for each lock stage; how to know the code?\
by moving the potentiometer you can see a hashtag "#" bar filling up or down, when the bar is full with "#" you need to press the toggle button to confirm the code.\
If you succeed you will see a succes screen and a new code, you need to repeat the previous steps,\
If you dont succeed then you will be greated with a boom screen and a suprise in the background.

Once succeeding 3 stages you will see a DISARMED screen which means you won the game.\
To restart the game press the reset button (connected to pin 7).

## how to build
this project is built with\
  1 Arduino UNO;\
  2 buttons (ports: 7, 8);\
  2 LEDs (green (port 11) & red (port 10));\
  1 buzzer (port 9);\
  1 B10K Potentiometer (A0);\
  1 I2C LiquidCrystal display (SCL: A5, SDA: A4);\
  3 220ohm +-1% resistors | color code for 5 bands resistors: red, red, black, black, brown;

  <img width="1272" height="497" alt="Cool Jaban-Stantia" src="https://github.com/user-attachments/assets/28f35fc2-ee4c-4269-951a-c5fbc1baea3f" />

