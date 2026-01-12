/**
 ******************************************************************************
 * @file    display.c
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Dieses Modul implementiert die LCD Ausgabe des Spielfelds.
 ******************************************************************************
 */

#include "display.h"
#include "fontsFLASH.h"
#include "main.h"
#include "LCD_general.h"
#include "error.h"
#include "LCD_GUI.h"

/**
 * @defgroup DISPLAY_CONS 
 * @brief Die Konstanten dieser Gruppe definieren die Abmasse
 *        der Elemente des Spielfelds in Pixel.
 */

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Kantenlänge der quadratischen Spielsteine.
 */
#define E_S         		90    // Kantenlänge eines Spielsteins
/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert den Abstand zwischen zwei Spielsteinen.
 */
#define GAP                	 5

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Zeile des oberen linken Felds.
 */
#define TL_X 			    95

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Spalte des oberen linken Felds.
 */
#define TL_Y 				15

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Farbe des leeren Felds.
 */
#define CLR_NO_PIECE 	    BLACK

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Farbe eines Spielsteins
 */
#define CLR_PIECE          GREEN

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante definiert die Farbe der Zahlen auf den Spielsteinen
 */
#define CLR_PIECE_FONT		BLUE

/**
 * @ingroup DISPLAY_CONS
 * @brief Diese Konstante den Font der Zahlen auf den Spielsteinen
 */
#define PIECE_FONT		FiraMono60FLASH

/**
 * @ingroup DISPLAY_CONS
 * @brief Dieses Feld definiert die Positionen der 9 Felder. 
 *
 * Die erste Felddimension definiert die Zeile. Die zweite Felddimension
 * definiert die Spalte. Somit liefert feld_pos[0][1] die Bildschirm-
 * position des mittleren Felds der obersten Zeile.
 *
 * Die Position eines Felds wird über die Koordinate der linke obere (tr)
 * und die Koordinate der rechten untere Ecke des Rechtecks, das das Feld 
 * aufspannt, definiert. Diese Koordinaten können direkt an die 
 * GUI_drawRectangle Funktion übergeben werden.
 */

const struct {
	 Coordinate tl;
	 Coordinate br;
	} field_pos[GRID_SIZE][GRID_SIZE]  = {
			{ // obere Zeile
		        // Feld oben links
				{.tl = {.x = TL_X, .y = TL_Y}, 
				 .br = {.x = TL_X + E_S, .y = TL_Y + E_S}},
				// Feld oben mitte
				{.tl = {.x = TL_X + E_S + GAP, .y = TL_Y}, 
				 .br = {.x = TL_X + E_S + GAP + E_S, .y = TL_Y + E_S}},
				// Feld oben rechts
				{.tl = {.x = TL_X + E_S + GAP + E_S + GAP, .y = TL_Y}, 
				 .br = {.x = TL_X + E_S + GAP + E_S + GAP+ E_S, .y = TL_Y + E_S}} },
			{ // mittlere Zeile
		        // Feld mitte links
				{.tl = {.x = TL_X, .y = TL_Y + E_S + GAP}, 
				 .br = {.x = TL_X + E_S, .y = TL_Y + E_S + GAP + E_S}},
				// Feld mitte mitte
				{.tl = {.x = TL_X + E_S + GAP, .y = TL_Y + E_S + GAP}, 
				 .br = {.x = TL_X + E_S + GAP + E_S, .y = TL_Y + E_S + GAP + E_S}},
				// Feld mitte rechts
				{.tl = {.x = TL_X + E_S + GAP + E_S + GAP, .y = TL_Y + E_S + GAP}, 
				 .br = {.x = TL_X + E_S + GAP + E_S + GAP + E_S, .y = TL_Y + E_S + GAP + E_S} } },
			{ // untere Zeile
		        // Feld unten links
				{.tl = {.x = TL_X, .y = TL_Y + E_S + GAP + E_S + GAP}, 
				 .br = {.x = TL_X + E_S, .y = TL_Y + E_S + GAP + E_S + GAP + E_S}},
				// Feld unten mitte
				{.tl = {.x = TL_X + E_S + GAP, .y = TL_Y + E_S + GAP + E_S + GAP}, 
				 .br = {.x = TL_X + E_S + GAP + E_S, .y = TL_Y + E_S + GAP + E_S + GAP + E_S}},
				// Feld unten rechts
				{.tl = {.x = TL_X + E_S + GAP + E_S + GAP, .y = TL_Y + E_S + GAP + E_S + GAP}, 
				 .br = {.x = TL_X + E_S + GAP + E_S + GAP + E_S, .y = TL_Y + E_S + GAP + E_S + GAP + E_S}} }};

void clear_display(void){
	GUI_clear(BLUE);	
}

void display_piece(uint8_t row, uint8_t col, PieceType piece){
	if ((row > GRID_SIZE) || (col > GRID_SIZE) || (piece > NO_PIECE)) {
		Error_Handler();
	}
	if (piece == NO_PIECE) {
		GUI_drawRectangle(field_pos[row][col].tl, field_pos[row][col].br, CLR_NO_PIECE, true, DOT_PIXEL_1X1);
	} else {
		GUI_drawRectangle(field_pos[row][col].tl, field_pos[row][col].br, CLR_PIECE, true, DOT_PIXEL_1X1);
		Coordinate tl = field_pos[row][col].tl;
		tl.x = tl.x + 26;
		tl.y = tl.y + 13;
		GUI_disChar(tl, '0' + piece, &PIECE_FONT, CLR_PIECE, CLR_PIECE_FONT);
	}	
}
// EOF