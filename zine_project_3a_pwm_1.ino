int i=0;
void setup()
{

  TCCR1B |=(1<<WGM12);
  TCCR1B &= ~(1<<WGM13);
  TCCR1A |= (1<<WGM10) | (1<<WGM11); // Fast PWM 10 BIT
  
  TCCR1A |= (1<<COM1A1);
  TCCR1A &= ~(1<<COM1A0); // NON Inverting mode of PWM 
  
  TCCR1B |= (1<<CS10) | (1<<CS11);
  TCCR1B &= ~(1<<CS12);   // system clock is 16MHz when divided
                          // by 64 ( prescaler) 16MHz/64 =250kHz     
  
  DDRB|= (1<<DDB1); // Digital Pin 9 is set  as output 

  OCR1A=0-1023;
}

void loop()
{
  
for(int i=0 ; i<1024;i++)
{
OCR1A=i;
delay(3);
}
delay(1000);

for(int i=1023 ; i>=0 ;i--)
{
OCR1A=i;
delay(3);
}
delay(1000);

}
