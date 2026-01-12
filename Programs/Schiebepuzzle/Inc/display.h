#ifndef _DISPLAY_H
#define _DISPLAY_H
/**
 ******************************************************************************
 * @file    display.h
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Interface des Moduls zur Ausgabe des Spielfelds auf dem Display. 
 ******************************************************************************
 */
#include "main.h"

/**
  * @brief Diese Funktion füllt den ganzen Bildschirm mit blau.
  */
void clear_display(void);

/**
  * @brief Diese Funktion zeichnet einen Spielstein auf ein 
  *.       Feld des 3 x 3 Spielfelds.
  *
  * Die Zahl des Spielsteins wird in der Mitte der Steins geschrieben.
  *
  * @param  row Die Nummer der Zeile des Feldes (row == 0 : oberste Zeile)
  * @param  col Die Nummer der Spalte des Feldes (col == 0 : linke Spalte)
	* @param  piece Definiert, was in das Feld gezeichnet wird
  *         piece == NO_PIECE : Das leere Feld wird gezeichnet
  *         piece != NO_PIECE : Der Spielstein mit dem Wert piece wird gezeichnet
  */
void display_piece(uint8_t row, uint8_t col, PieceType piece);

#endif
// EOF
