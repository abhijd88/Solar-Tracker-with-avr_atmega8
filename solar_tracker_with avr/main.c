#include  <avr/io.h>

#include<util/delay.h>

int  main(void)
  {
  unsigned  int adc_value0,adc_value1;	// Variable to hold ADC  result
  DDRB=0xff;	// Set Port B for LED output
  PORTB  = 0x00;	// Clear PortB pins

 	
	

 

  while (1)	//Forever 
	{
	 ADCSRA  = (1<<ADEN) | (1<<ADPS2) ; // Set ADCSRA Register with division factor 16
	 ADMUX |=(1<<ADLAR);
	 ADMUX &= ~( (1<<MUX1) | (1<<MUX0) );	//ADC0 SELECTED
  	 ADCSRA  |= (1<<ADSC);	// Start conversion
		while (ADCSRA &  (1<<ADSC));
		// wait until conversion  completes; ADSC=0 means Complete
  	 adc_value0 = ADCH;	//Store ADC result
	 ADCSRA  = 0x00 ;
	 
		 ////////////////////////////
		ADCSRA  = (1<<ADEN) | (1<<ADPS2) ; // Set ADCSRA Register with division factor 16
	 ADMUX |= (1<<MUX0) ;	//ADC1 SELECTED
  	 ADCSRA  |= (1<<ADSC);	// Start conversion
		while (ADCSRA &  (1<<ADSC));
		// wait until conversion  completes; ADSC=0 means Complete
		
  	 adc_value1 = ADCH;	//Store ADC result 
	 
	 ADCSRA  = 0x00 ;
	 
	  if (adc_value0>adc_value1)
	  {
	     PORTB=0x01;
		 _delay_ms(100);
		 PORTB=0x00;
		 
		 }
	  else if (adc_value0<adc_value1)
	  {
	     PORTB=0x02;
		 _delay_ms(100);
		 PORTB=0x00;
		 } 
	  else
	  {
	     PORTB=0x00;
		 } 
		 
		 
	 
		_delay_ms(1000);
		
	 
	 
	 }
 } 