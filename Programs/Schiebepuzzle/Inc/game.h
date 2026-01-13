#ifndef _GAME_H
#define _GAME_H

/**
 ******************************************************************************
 * @file    game.h
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Interface des Moduls, das das Spiel speichert und die Funktionen zum
 *          Handling des Schiebepuzzles beinhaltet.
 ******************************************************************************
 */

#include "main.h"
#include <stdbool.h>

/**
 * @brief Diese Funktion initialisiert das Modul.
 *
 * Ein Feld ist frei. Die restlichen Felder sind mit Spielsteinen, die die Werte
 * 0 bis 7 haben, belegt. Die Spielsteine haben paarweise unterschiedliche Werte.
 *
 * Mit Hilfe eines Zufallszahlengenerators werden die Position des freien Felds
 * und die Werte der Spielsteine auf den anderen Feldern bestimmt. 
 *
 * Nachdem init_board ausgeführt wurde, werden beim darauf folgenden Aufruf der 
 * Funktion draw_board alle Felder des Spielfelds neu gezeichnet.
 */
void init_board(void);

/**
 * @brief Diese Funktion platziert einen Spielstein mit dem Wert piece
 *        auf das durch row und col definierte Feld des Spielfelds.
 *        Hat piece den Wert NO_PIECE, wir das Feld als freies Feld
 *        dargestellt.
 *
 * @param  row Spalte des Felds
 * @param  col Zeile des Felds
 * @param  piece Wert des Spielsteins
 */
void place_piece(uint8_t row, uint8_t col, PieceType piece);

/**
 * @brief Diese Funktion bewegt den Spielstein mit dem Wert piece in
 *        das freie Feld, das horizontal oder vertikal neben dem 
 *        Spielstein liegen muss. Somit ist das Feld, in dem der Spielstein 
          bisher lag, anschließend frei. 
 *
 * Liegt neben dem Spielstein kein freies Feld oder hat piece den Wert NO_PIECE, 
 * führt die Funktion move keine Veränderungen durch.
 *
 * @param  piece Wert des Spielsteins, der verschoben werden soll.
 */
void move(PieceType piece);

/**
 * @brief Diese Funktion zeigt das aktuelle Spielfeld auf dem Display an.
 *
 * Damit das Display nicht flackert, werden nur die Felder gezeichnet,
 * deren Spielstein / Wert sich seit dem letzten Aufruf dieser Funktion 
 * geändert hat.
 */
void draw_board(void);

/**
  * @brief Diese Funktion überprüft, ob die Spielsteine in der Reihenfolge,
  *        die zum Spielende vorliegen muss, angeordnet sind.
  *
  * Somit liefert die Funktion gdw. true zurück, wenn die Spielsteine wie folgt
  * angeordnet sind:
  *       0  1  2
  *       3  4  5
  *       6  7  
  *        
  * @retval s. Beschreibung der Funktion.
  */
bool game_over(void);

#endif
// EOF