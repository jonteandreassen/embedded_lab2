#include <avr/io.h>
#include "timer.h"

void timer0_init() {
/* Uppgift 1 settings Non-pwm */
/* Sätter CTC mode kapitel 19.9.1. TC0 Control Register A */
	TCCR0A |= (1 << COM0A1);
	TCCR0A &= ~(1 << COM0A0);
	TCCR0A |= (1 << WGM01); 
	TCCR0A &= ~(1 << WGM00);
	TCCR0A &= ~(1 << WGM02);
 /* 1024 prescaler kapitel Table 19-10. Clock Select Bit Description */
	TCCR0B = (1 << CS00) | (1 << CS02);
	TCCR0B &= ~(1 << CS01);
/* initilize timer */
	TCNT0 = 0x00; 
/* Duty Cycle */
	OCR0A = 156; //  16000000/1024 = 15625 > 15625/((1/10)*1000) = 156,25 => 156 (10 ms)

}

void timer2_init(){
/* Uppgift 2 settings fast PWM kapitel Table 22-4. Compare Output Mode, Fast PWM*/
// PB3 = OC2A
/* FAST PWM	 kapitel 22.11.1. TC2 Control Register A & Table 22-9. Waveform Generation Mode Bit Description */
	TCCR2A |= (1 << WGM20) | (1 << WGM21) | (1 << COM2A1); 
	TCCR2B &= ~(1 << WGM22);
	TCCR2A &= ~(1 << COM2A0);
/* Initilize time to top */
	TCNT2 = 0xFF;
/* Duty Cycle */
	OCR2A = 4000; // 1600000/64 = 250000 > 250000/((1/16)*1000) = 4000 || OCR2A = 4000; (16 ms)
/* 64 prescalar kapitel 22.11.2. TC2 Control Register B */  
	TCCR2B |= (1 << CS22);
	TCCR2B &= ~(1 << CS21);
	TCCR2B &= ~(1 << CS20);
}
