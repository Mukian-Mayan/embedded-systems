#include <avr/io.h>
#include <util/delay.h>

int main (void){

  DDRB |= ~(1 << PB0); //output

  while (1)
    {
      PORTB |= (1 << PB0);  //turn on buzzer
        _delay_ms (1000);

      PORTB &= ~(1 << PB0); //turn of buzzer
        _delay_ms (1000);
    }
}