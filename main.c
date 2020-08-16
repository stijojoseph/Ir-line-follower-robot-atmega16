#include<avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#define sensor1 PA0              
#define sensor2 PA1
void left(void);
void right(void);

int main(void)
{

	DDRA=0x00;
	DDRD=0xFF;
	
	while(1)
	
	{	PINA=0x03;
		
		  
			  
		  
		  PORTD|=(1<<PIND0);
		  PORTD |= (1<<PIND2);
			
		
	
	
     while(bit_is_clear(PINA,sensor1) )
      { 
		  if(bit_is_clear(PINA,sensor2))
		  break;
	      PORTD|=(1<<PIND0);
	      PORTD &=~(1<<PIND2);
	      _delay_ms(10);
	      
      }
	  
	while(bit_is_clear(PINA,sensor2) )
	  {
		  if(bit_is_clear(PINA,sensor1))
		  break;
		  
		  PORTD |=(1<<PIND2);
		  PORTD &=~(1<<PIND0);
		  _delay_ms(10);
	  }
	  
	
	  
	}
	return 0;
}

void left(void)
{
			if(bit_is_clear(PINA,sensor1))
			{
				PORTD|=(1<<PIND0);
			PORTD &=~(1<<PIND2);
			_delay_ms(1000);
			
			}
			else
			PORTD &=~(1<<PIND0);
			
}

void right(void)
{
	if(bit_is_clear(PINA,sensor2))
	{PORTD |=(1<<PIND2);
	PORTD &=~(1<<PIND0);
	_delay_ms(1000);
	}
	else
	{PORTD &=~(1<<PIND2);
	
	}
}