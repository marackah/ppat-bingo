#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip= Adafruit_NeoPixel(7, 6); //number of pixels (zero index) and pin number
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR
  1000 on pin 6. LED_BUILTIN takes care 
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  
  modified 2 Sep 2016
  by Arturo Guadalupi
*/
int ledA = 2;
int ledB = 3;
int ledC = 4;
int ledD = 5;
int ledE = 6;
int ledF = 7;
int ledG = 8;
int ledH = 9;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledA, OUTPUT);  
  pinMode(ledB, OUTPUT);  
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  strip.begin();
  strip.show(); 
  strip.setPixelColor(7, 0, 0, 0);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int card = Serial.read();
  // print out the value you read:
  Serial.println(card);
        // delay in between reads for stability


// the loop function runs over and over again forever
    if(card==122 ) {strip.setPixelColor(0, 0, 255, 0); //red
                 strip.show();} ///pixel #, green, red, blue
    if(card==120 ) {strip.setPixelColor(0, 255, 255, 0); //orange
                  strip.show();}
    if(card==99 ) {strip.setPixelColor(0, 255, 170, 0); //yellow
                  strip.show();} ///pixel #, 
    if(card==118 ) {strip.setPixelColor(0, 255, 0, 0); //green
                  strip.show();} 
    if(card==98 ) {strip.setPixelColor(0, 0, 0, 255); //blue
                  strip.show();}
    if(card==110 ) {strip.setPixelColor(0, 0, 100, 200); //purple
                  strip.show();} ///pixel #, 
    if(card==109 ) {strip.setPixelColor(0, 100, 100, 100); //white
    
                  strip.show();} 
    

 
    if(card == 49){digitalWrite(ledA, HIGH);
        strip.setPixelColor(0, 0, 150, 0); //red
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 50){ digitalWrite(ledA, LOW);
        strip.setPixelColor(0, 0, 0, 0); //green
                  strip.show();}   // turn the LED off by making the voltage LOW
  
    if(card == 51){ digitalWrite(ledB, HIGH);
        strip.setPixelColor(1, 0, 150, 0); //red
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 52){digitalWrite(ledB, LOW);
        strip.setPixelColor(1, 0, 0, 0); //green
                  strip.show();} 
  
    if(card == 53){digitalWrite(ledC, HIGH);
        strip.setPixelColor(2, 0, 150, 0); //red
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 54){digitalWrite(ledC, LOW);
        strip.setPixelColor(2, 0, 0, 0); //green
                  strip.show();}  
  
  
     if(card == 55){digitalWrite(ledD, HIGH);
         strip.setPixelColor(3, 0, 150, 0); //red
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 56){digitalWrite(ledD, LOW);
        strip.setPixelColor(3, 0, 0, 0); //green
                  strip.show();}
  
   if(card == 97){digitalWrite(ledE, HIGH);
        strip.setPixelColor(4, 0, 150, 0); //red
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 115){ digitalWrite(ledE, LOW);
        strip.setPixelColor(4, 0, 0, 0); //green
                 strip.show();} 
                 
  // turn the LED off by making the voltage LOW
    if(card == 100){ digitalWrite(ledF, HIGH);
        strip.setPixelColor(5, 0, 150, 0); //green
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 102){digitalWrite(ledF, LOW);
        strip.setPixelColor(5, 0, 0, 0); //green
                 strip.show();}  
  
    if(card == 103){digitalWrite(ledG, HIGH);
        strip.setPixelColor(6, 0, 150, 0); //green
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 104){digitalWrite(ledG, LOW);
        strip.setPixelColor(6, 0, 0, 0); //green
                 strip.show();}  
  
     if(card == 106){digitalWrite(ledH, HIGH);
        strip.setPixelColor(7, 0, 150, 0); //green
                 strip.show();}   // turn the LED on (HIGH is the voltage level)
  if(card == 107){digitalWrite(ledH, LOW);
        strip.setPixelColor(7, 0, 0, 0); //green
                 strip.show();}
  
  if(card == 57){ digitalWrite(LED_BUILTIN, HIGH); delay(300); digitalWrite(LED_BUILTIN, LOW); delay(100);}
  delay(1000); 
  // wait for a second
}
