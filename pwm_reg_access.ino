
// _BV(pos) (1 << (pos))
void setup() {
//pinMode (6,OUTPUT) ; 
//pinMode (5,OUTPUT) ; 
//pinMode (11,OUTPUT) ; 

// set pwm pins   6 and 5  t ouput 
  DDRD = _BV(DDD6) | _BV(DDD5);  
// set pwm pin 11 to ouput 
DDRB = _BV(DDB3) ; 
//initialize the timer 0 (8 bit) register to 0 
   TCCR0A = 0; 
//initialize the timer 2 (8 bit) register to 0 
TCCR2A = 0 ;  
// configure the the timer 1 to be pwm fast mode non-inverting-mode 
 TCCR0A = _BV(COM0A1) | _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
/*
 *_BV(WGM01) | _BV(WGM00)  set the timer 1 to pwm fast mode 
 *Compare Output Mode, Fast PWM Mode tobe non inverting mode for OC0A(affects pin 6) 
 *_BV(COM0A1)  
 *Compare Output Mode, Fast PWM Mode tobe non inverting mode for OC0B (affects pin 4) 
 *_BV(COM0B1) 
 *
 */
 // configure the the timer 2 to be pwm fast mode non-inverting-mode 

 TCCR2A = _BV(COM2A1) | _BV(WGM21) | _BV(WGM20);
/*
 *_BV(WGM21) | _BV(WGM20)  set the timer 2 to pwm fast mode 
 *Compare Output Mode, Fast PWM Mode tobe non inverting mode for OC2A (affects pin 11) 
 *_BV(COM2A1)  
 *
 */

 // initialize  OUTPUT COMARE registers to 0 ( 0% duty cycle)  
 OCR0A = 0; // pin 6
 OCR0B = 0; // pin 5
OCR2A = 0; // pin 11 
} 

void loop() {
//analogWrite(6,127); 
//analogWrite(5,127); 
//analogWrite(11,127); 
  
  for (int i =0; i < 255; ++i ) 
{
    OCR0A = i;
  OCR0B= i ;
  OCR2A = i ; 
      delay (10) ;       
}
delay(1000);  
  for (int i =255; i >=0; --i ) 
{
    OCR0A = i;
  OCR0B= i ;
  OCR2A = i ; 
      delay (10) ;       
}
    OCR0A = 0;
  OCR0B= 0;
  OCR2A = 0; 

delay(1000); 

}
