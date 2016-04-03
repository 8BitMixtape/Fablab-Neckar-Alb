/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 3 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */
 
// ATMEL ATTINY85 / ARDUINO
//
//                      +-\/-+
//  Reset A0 (D 5) PB5 1|    |8  Vcc
//        A3 (D 3) PB3 2|    |7  PB2 (D 2) A1
//   A2 pwm4 (D 4) PB4 3|    |6  PB1 (D 1) pwm1
//                 GND 4|    |5  PB0 (D 0) pwm0
//                      +----+                  


int ledPin = PB0;    // LED connected to digital pin 9
int PotiPin = A1;

void setup()  { 
  
  //TCCR0B = TCCR0B & B11111000 | B00000001; //no timer pre-scaler, fast PWM
  //TCCR0B = TCCR0B & B11111000 | B00000011; //timer pre-scaler divided by 8
  
pinMode (ledPin, OUTPUT);

} 

void loop()  { 
  
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    int sensor = analogRead(PotiPin);
    delayMicroseconds(sensor*4+1);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    int sensor = analogRead(PotiPin);
    delayMicroseconds(sensor*4+1);                            
  } 
}


