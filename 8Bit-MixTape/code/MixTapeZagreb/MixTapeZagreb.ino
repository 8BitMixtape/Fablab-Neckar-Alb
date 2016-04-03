/* PCrazy shit 8-bit symphony generator                   */
/*     */
 
/*
 * inspired by:
 *  http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html
 */
 
int speakerPin = PB0;
int buttonPin = PB1;
int potiPin3 = A2;
int potiPin4 = A1;
 
int buttonState = 0; 
int lastButtonState = 0;
int count = -1;

unsigned long int pulseWidthOFF = 0;
unsigned long int pulseWidthON = 0;
unsigned long int pulseWidthPart = 0;
  
     unsigned long int newr;
     unsigned char lobit;
     unsigned char b31, b29, b25, b24;

int samplingDelay;
unsigned long int reg;

long t = 0; 
int v = 0; 
unsigned int c3 = 0;
unsigned int c4 = 4;

unsigned int analogValue;
 
void setup () {
  //TCCR0A |= (1<<WGM00)|(1<<WGM01); //Fast pwm
  TCCR0B = TCCR0B & 0b11111001; //no timer pre-scaler, fast PWM
  
  pinMode (speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode (potiPin3, INPUT);
  pinMode (potiPin4, INPUT);

  reg = 0x551155aaL;
 
}
 
 
void loop () {
  // read the state of the switch into a local variable:
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState && buttonState == HIGH) {
    // if the state has changed, increment the counter
      count++;
      t = 0; 
      delay(10000); 
      if (count > 9) {
        count = 0;
      } 
    
  } 
  
  lastButtonState = buttonState;
  
  
 
 //count = 2;

 switch(count) {
   
 case 0: // a classic
     c4 = ((analogRead(potiPin4)>>6) + 1); 
     c3 = (analogRead(potiPin3)>>0);
     v = (t*(t>>8|t>>4))>>(t>>c4);
    analogWrite (speakerPin, v);
    
    delayMicroseconds(c3>>2);
    t++;
 
    break;
    
 case 1: // ding dong
 
     c4 = ((1023-(analogRead(potiPin4))>>6) + 1); 
     c3 = (analogRead(potiPin3)>>0);
     v = t * ((t>>15|t>>c4)&83&t>>(c4>>3));
     analogWrite (speakerPin, v);
     
     delayMicroseconds(c3<<2);
     t++;
 
    break;
    
 case 2: // experimental 8 bit
 
  c4 = ((analogRead(potiPin4)>>6) + 1); 
  c3 = (analogRead(potiPin3)>>0);
  v = t * ((t>>15|t>>c4)&83&t>>(c4>>3));
  analogWrite (speakerPin, v);
  delayMicroseconds(c3<<3);
  t++;
    break;
  
  
 case 3: 
     c4 = ((analogRead(potiPin4)>>2) + 1); 
    c3 = (analogRead(potiPin3)>>0);

 
     b31 = (reg & (1L << 31)) >> 31;
     b29 = (reg & (1L << 29)) >> 29;
     b25 = (reg & (1L << 25)) >> 25;
     b24 = (reg & (1L << 24)) >> 24;
 
    lobit = b31 ^ b29 ^ b25 ^ b24;
 
    newr = (reg << 1) | lobit;
   
    reg = newr;
  
  
  v = t * ((t>>c4|t>>reg)&7&t>>3);
  
  
  //v = t * ((t>>4|t>>7)&c4&t>>(reg));
  //v = t * ((t>>c4|t>>reg)&7&t>>3);
  
  
  digitalWrite (speakerPin, v);
  delayMicroseconds(c3>>0);
  t++;
 
 
     break;
    
 case 4: 
 c4 = ((analogRead(potiPin4)>>2) + 1); 
    c3 = (analogRead(potiPin3)>>0);
  
  
  v = (t|3) * ((t>>1|t>>6)&c4&t>>3);
  
  
  //v = t * ((t>>4|t>>7)&c4&t>>(reg));
  //v = t * ((t>>c4|t>>reg)&7&t>>3);
  
  
  analogWrite (speakerPin, v);
  delayMicroseconds(c3>>0);
  t++;
       
    
    break;
    
    
    
 case 5: 
 
  c4 = ((analogRead(potiPin4)>>6) + 1); 
  c3 = analogRead(potiPin3);

  v = t>>4&1?t>>5:-t>>c4 ;

  analogWrite (speakerPin, v);
  delayMicroseconds(c3>>1);
  t++;
       
    
    break;
 
 
 
 case 6: 
    c4 = ((1023-(analogRead(potiPin4))>>6) + 1);  
    c3 = (analogRead(potiPin3)>>0);

   //v = (t|3) * ((t>>2|t>>83)&13&t>>c4);
   v = (t|c4) * ((t>>c4|t>>11)&47&t>>3);
  
  //v = t * ((t>>4|t>>7)&c4&t>>(reg));
  //v = t * ((t>>c4|t>>reg)&7&t>>3);
  //v = (1 & 17) * (t|83) * ((t>>c4|t>>17)&7&t>>3);
  
  
  analogWrite (speakerPin, v);
  delayMicroseconds(c3>>2);
  t++;
       
    
    break;   
    
    case 7: 
    
      
    c4 = ((1023-(analogRead(potiPin4))>>8) + 1);  
    c3 = (analogRead(potiPin3)>>0);

   //v = (t|3) * ((t>>2|t>>83)&13&t>>c4);
   v = t * ((t>>c4|t>>3)&17&t>>9);
  
  //v = t * ((t>>4|t>>7)&c4&t>>(reg));
  //v = t * ((t>>c4|t>>reg)&7&t>>3);
  //v = (1 & 17) * (t|83) * ((t>>c4|t>>17)&7&t>>3);
  
  
  digitalWrite (speakerPin, v);
  delayMicroseconds(c3>>2);
  t++;
       
    
    break;  
    
    case 8: 
    
    c4 = ((analogRead(potiPin4)>>2) + 1); 
    c3 = (analogRead(potiPin3)>>0);
  
  
  v = t * ((t>>c4|t>>83)&7&t>>5);
  

  
  digitalWrite (speakerPin, v);
  delayMicroseconds(c3>>0);
  t++;
       
    
    break;  
 }

}
