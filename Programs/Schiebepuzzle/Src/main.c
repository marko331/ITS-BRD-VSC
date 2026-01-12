/**
  ******************************************************************************
  * @file    main.c
  * @author  Franz Korf
  * @brief   Klausuraufgabe Schiebepuzzle WS 25/26.
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "init.h"
#include "io.h"
#include "display.h"
#include "LCD_Touch.h"
#include "game.h"
#include "LCD_GUI.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <test.h>

#define NO_BUTTONS   8

int main(void) {
	initITSboard();    // Initialisierung des ITS Boards
	GUI_init(DEFAULT_BRIGHTNESS);   // Initialisierung des LCD Boards mit Touch
	TP_Init(false);                 // Initialisierung des LCD Boards mit Touch

#ifdef AUFGABE3
   test_IO();
#endif

#ifdef AUFGABE4
   test_display();
#endif

#ifdef AUFGABE5 
	 test_game();
#endif

	// Initialisierung
	clear_display();
	init_board();
	draw_board();

	uint8_t buttons_pressed_old = 0x00;

	// Super loop gemäß DDC
	while(1) {
		// read all buttons
		uint8_t buttons_pressed = debounced_buttons_pressed();

		// update state
		// only one button may be pressed 
		int no_pressed_buttons = 0;
		PieceType piece_to_move = NO_PIECE;
		for (int i = 0; i < NO_BUTTONS; i++){
			uint8_t mask = (0x01 << i);
			if ((buttons_pressed & mask) == mask){
				// button i pressed 
				no_pressed_buttons++;
				if ((buttons_pressed_old & mask) != mask){
					// rising edge on button i
					piece_to_move = i;
				}
			}
		}
		bool valid_input = no_pressed_buttons < 2;
		if (game_over()){
			HAL_Delay(3000);
			init_board();
		}
		if (valid_input){
			buttons_pressed_old = buttons_pressed;
			if (piece_to_move != NO_PIECE){
				move(piece_to_move);
			}
		}
		// calculate output

		// drive_output
		draw_board();
	}
}

// EOF
