/**
 ******************************************************************************
 * @file    test.c
 * @author  Franz Korf
 *
 * @date    20. Jan. 2025
 *
 * @brief  Testfunktionen zur Ueberpruefung der einzelnen Aufgaben.
 *
 ******************************************************************************
 */
 
#include "test.h"
#include "delay.h"
#include "main.h"
#include "stm32f429xx.h"
#include <stdint.h>

#define DELAY    250     // Delay in ms zwischen Teiltests

#ifdef AUFGABE3
#include <stm32f429xx.h>
#include "io.h"

#define BLUE_LEDS_PORT             (GPIOD)

/**
  * @brief Diese Funktion schaltet die blauen LEDs des ITS-Boards
  *        gemäß den Parameter leds_on an/aus.
  *
  * @param  leds_on definiert, welche blauen LEDs an / ausgeschaltet werden.
  *         Für 0 < i < 8: Bit i von leds_on gesetzt gdw LED D(i+8) angeschaltet
  */
void set_blue_LEDs(uint8_t leds_on){
   // erzeuge Maske
   uint32_t v = ((uint32_t) leds_on) & 0xFF;
   // treibe Ports
   BLUE_LEDS_PORT->BSRR = v;
   v = (~v & 0xFF) << 16;
   BLUE_LEDS_PORT->BSRR = v;
}

void test_IO(void){	 
	 // Test der Funktion debounced_buttons_pressed
	 // Die gedrückten Taster werden auf den blauen LEDs 
	 // des ITS-Boards angezeigt. 
	 // 
	 // Für 0 <= i < 8: Si gedrückt gdw LED D(i+8) leuchtet
	 while(1){
		uint8_t v = debounced_buttons_pressed();
		set_blue_LEDs(v);
		delay(DELAY);
   }	 
}
#endif

#ifdef AUFGABE4
#include "display.h"

void test_display(void){
	// Das gesamte LCD Display auf blau gesetzt
	int delta = 4 * DELAY;
	clear_display();
	delay(delta);

	// Auf dem LCD Display werden die Spielsteine aufsteigender Reihenfolge
	// angeordnet. Das Spielfeld unteren rechts ist leer.
	// Belegung des Spielfeld   
	//         0  1  2
	//         3  4  5
	//         6  7  _
	for (int piece = 0; piece <= NO_PIECE; piece++){
		display_piece(piece / GRID_SIZE, piece % GRID_SIZE,  piece);
	}
	delay(delta);

	// Die Spielsteine werden so verschoben, dass das leere Feld 
	// im Uhrzeigersinn (rechts rum) am Spielfeldrand lang 
	// platziert wird.

	display_piece(2, 1,  NO_PIECE);
	display_piece(2, 2,  7);
	delay(delta);

	display_piece(2, 0,  NO_PIECE);
	display_piece(2, 1,  6);
	delay(delta);

	display_piece(1, 0,  NO_PIECE);
	display_piece(2, 0,  3);
	delay(delta);

	display_piece(0, 0,  NO_PIECE);
	display_piece(1, 0,  0);
	delay(delta);

	display_piece(0, 1,  NO_PIECE);
	display_piece(0, 0,  1);
	delay(delta);

	display_piece(0, 2,  NO_PIECE);
	display_piece(0, 1,  2);
	delay(delta);

	display_piece(1, 2,  NO_PIECE);
	display_piece(0, 2,  5);
	delay(delta);

	display_piece(2, 2,  NO_PIECE);
	display_piece(1, 2,  7);
	delay(3*delta);

	// Belegung des Spielfelds
	//         1  2  5
	//         0  4  7
	//         3  6  _

	// Das gesamte LCD Display auf blau gesetzt
	clear_display();
	delay(delta);

	// Alle Spielfelder sind leer - kein Stein ist auf dem Spielfeld

	for (uint8_t piece = 0; piece <= NO_PIECE; piece++){
		display_piece(piece / GRID_SIZE, piece % GRID_SIZE,  NO_PIECE);
	}
	delay(delta);

	// Das Spielfeld in der Mitte wird zyklisch mit den Steinen 0 bis 7 belegt
	PieceType i = 0;
	while(1) {
		display_piece(1 , 1,  NO_PIECE);
		delay(delta);
		display_piece(1 , 1,  i);
		i = (i + 1) % NO_PIECE;
		delay(delta);
	}
}
#endif

#ifdef AUFGABE5 
#include "game.h"
#include "display.h"

void test_game(void){
	int delta = 4 * DELAY;

	// Liege in aufsteigender Reihenfolge die Spielsteine auf
	// das Board und stelle es auf dem Display dar
	// Belegung des Spielfelds
	//         0  1  2
	//         3  4  5
	//         6  7  _

	for (uint8_t piece = 0; piece <= NO_PIECE; piece++){
		place_piece(piece / GRID_SIZE, piece % GRID_SIZE, piece);
	}
	clear_display();
	draw_board();
	delay(delta);

	// Schiebe Stein die Steine am äußeren Rand gegen den Uhrzeigersinn 
	// in die Lücke
	move(5);
	draw_board();
	delay(delta);
	move(2);
	draw_board();
	delay(delta);
	move(1);
	draw_board();
	delay(delta);
	move(0);
	draw_board();
	delay(delta);
	move(3);
	draw_board();
	delay(delta);
	move(6);
	draw_board();
	delay(delta);
	move(7);
	draw_board();
	delay(3*delta);
	// Belegung des Spielfelds
	//         3  0  1
	//         6  4  2
	//         7  _  5

	// Bewege Spielstein 4
	move(4);
	draw_board();
	delay(delta);
	//  3  0  1
	//  6  _  2
	//  7  4  5

	// Das Bewegen der Steine 3, 1, 7 und 5 dürfen den Status des 
	// Spiels nicht verändern
	move(3);
	draw_board();
	delay(delta);
	move(1);
	draw_board();
	delay(delta);
	move(7);
	draw_board();
	delay(delta);
	move(5);
	draw_board();
	delay(delta);

	// Teste game_over
	if (! game_over()){
		// Erzeuge der Ergebnisspielfeld und stelle es auf dem Display dar
		for (uint8_t piece = 0; piece <= NO_PIECE; piece++){
			place_piece(piece / GRID_SIZE, piece % GRID_SIZE, piece);
		}
		draw_board();
	    delay(2*delta);
	}
	// Das Ergebnisspielfeld wird dargestellt

	if (game_over()){
		// gezeuge immer wieder neue Startbelegungen
		while(1){
			init_board();
			draw_board();
			delay(6 * delta);

		}
	}
	while(1);
}
#endif
// EOF
