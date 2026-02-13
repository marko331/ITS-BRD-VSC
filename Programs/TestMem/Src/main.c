/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Kleines Testprogramm, mit dem man Memory Map Aufgaben testen kann.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "init.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "lcd.h"
#include "fontsFLASH.h"
#include "additionalFonts.h"
#include "error.h"
#include <stdio.h>
#include <stdint.h>

// Die struct sorgt dafür, dass die Variablen gemäß alignment im Speicher 
// hintereinander abgelegt werden.
// buf am Anfang sorgt dafür, dass die erste Variable auf einer leicht 
// lesbaren und auf die Aufgabenstellung übertragene Adresse liegt.
// Die memory Map kann man sich dann im memory View anschauen.
struct Mem {
	int8_t buf[104];
	uint16_t a[5];
	char b; 
	uint16_t *c[2]; 
	uint16_t **d; 
};

struct Mem mem;

int main(void) {
	initITSboard();    // Initialisierung des ITS Boards

	mem.a[0] = 1;
	mem.a[1] = 2;
	mem.a[2] = 3;
	mem.a[3] = 4;
	mem.a[4] = 5;

	mem.c[0] = mem.a;
	mem.c[1] = &((mem.a)[3])-1;
	mem.d = (mem.c) + 1;



	printf("a = 0x%x\n", (uint32_t) mem.a);
	printf("&b = 0x%x\n", (uint32_t) &(mem.b));
	printf("c = 0x%x\n", (uint32_t) mem.c);
	printf("&d = 0x%x\n", (uint32_t) &(mem.d));

	printf("Es geht los 0x%x = \n",(uint32_t) &mem);

	printf("0x%x 0x%x\n", sizeof(mem.a), sizeof(mem.b));
	printf("0x%x 0x%x 0x%x\n", (int) (mem.b), (int) &(mem.b), (int) (mem.c));
	printf("0x%x 0x%x 0x%x 0x%x\n", (mem.a)[0], *((mem.a)+1), (mem.a)[2]+1, (int)(*(mem.d)+1));
	printf("0x%x 0x%x 0x%x\n", *(mem.c)[1] - 1, (int)(&(mem.c)[1]-1), (int)(*(&(mem.c)[1]-1)));
	printf("0x%x\n", **(mem.d)+1);
	// Test in Endlosschleife
	while(1) {
		HAL_Delay(10000);
	}


}

// EOF
