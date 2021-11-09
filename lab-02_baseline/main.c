#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>
#include "led.h"
#include "serial.h"
#include "timer.h"

/*
	Jag siktar på Godkänt
	Jag valde att köra den röda leden och därför använder jag timer2 för att PB3 är kopplad till OC2A
*/


void main (void) {
	//timer0_init(); // Setup uppgift 1
	//blinkLED_init(); // Starta LED för uppgift 1
	//blink(); // Uppgift 1
	
	//LED_init(); // Starta LED för uppgift 2
	//timer2_init(); // Setup Uppgift 2
	while(1){
	//fade(); // Uppfift 2
		
	}
	//uart_init();
}

