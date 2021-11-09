#include <avr/io.h>
#include "led.h"
#include <util/delay.h>



#define DUTYMAX 255

void LED_init() {
	DDRB |= (1 << PB3);
}

void blinkLED_init(){
	DDRB |= (1 << PB2);
}

void blink(){
	uint8_t counter = 0;
		while (1) {
		 if(TIFR0 & (1 << OCF0A)){
			 TIFR0 |= (1 << OCF0A);
			 counter++;
		}	
		if (counter == 10){
			PORTB ^= (1 << PB2);
			counter = 0;
		}
	}
}

void fade(){
/*	Se timer.c för vad OCR2A initsierad till */
	_delay_ms(100);
	if(TIFR2 & (1 << OCF2A)){
		TIFR2 |= (1 << OCF2A);
		OCR2A -= 10;
	}
	if (OCR2A == DUTYMAX){ 
		OCR2A = 0;
	}
	
}

