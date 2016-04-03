// 8Step MixTape Example Code
// Basic Onliner
// Crazy shit 8-bit symphony generator                   
/*
 * inspired by:
 *  http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
 *  http://countercomplex.blogspot.com.es/2011/10/some-deep-analysis-of-one-line-music.html
 *
 *  try it online:
 *  http://wurstcaptures.untergrund.net/music/
 *
 */
 
// ATMEL ATTINY85 / ARDUINO
//
//                      +-\/-+
//  Reset A0 (D 5) PB5 1|    |8  Vcc
//        A3 (D 3) PB3 2|    |7  PB2 (D 2) A1
//   A2 pwm4 (D 4) PB4 3|    |6  PB1 (D 1) pwm1
//                 GND 4|    |5  PB0 (D 0) pwm0
//                      +----+   

int speakerPin = PB0;
int snd = 0; 
long t = 0; 

void setup () {
  pinMode (speakerPin, OUTPUT);
}
 
void loop () {

    snd = t*((t>>12|t>>8)&63&t>>(t>>8));
    digitalWrite (speakerPin, snd);
    
    t++;
    
}
