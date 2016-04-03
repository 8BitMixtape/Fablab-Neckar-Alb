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

int pot0 = A1; //PB2
int pot1 = A2; //PB4
 
long t = 0; 

unsigned int p0 = 0;
unsigned int delta_T = 0;

int snd = 0; 


void setup () {

  TCCR0B = TCCR0B & B11111000 | B00000001; //no timer pre-scaler, fast PWM
 
  pinMode (speakerPin, OUTPUT);

  pinMode (pot0, INPUT);
  pinMode (pot1, INPUT);

}
 
void loop () {
 
    p0 = (analogRead(pot0)>>4);
    delta_T = ((analogRead(pot1)));
    
    //snd = t*((t>>12|t>>8)&63&t>>(p0>>3));
    
    snd = t>>3&1?t>>4:-t>>(p0>>3) ; //dubStep
    //snd = (t|4) * ((t>>17|t>>11)&p0&t>>3);
    //snd = t>>3&1?t>>17:-t>>p0;
    //snd = t*t/p0;
    //snd = (t|5) * ((t>>p0|t>>11)&p0&t>>3);
    //snd = t * ((t>>p0|t>>83)&7&t>>5);
    //snd = (t*(t>>8|t>>4))>>(t>>p0);
    
    analogWrite (speakerPin, snd);
    delayMicroseconds((delta_T+1>>0)+1);
    t++;
 
}
