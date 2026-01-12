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
 *          zur Handling des Schiebepuzzles beinhaltet.
 ******************************************************************************
 */

#include "main.h"
#include <stdbool.h>

/**
 * @brief Diese Funktion initialisiert das Modul.
 *
 *        Ein Feld ist frei. Die restlichen Felder sind mit Spielsteinen 
 *        belegt, wobei jeder Spielstein einen Wert aus dem Bereich 0 bis 7
 *        darstellt. Die Spielsteine haben paarweise unterschiedliche Werte.
 *        Mit Hilfe eines Zufallsgenerators werden die Position des 
 *        freien Felds und Werte der Spielsteine auf den anderen Feldern  
 *        bestimmt. 
 *
 *        Alle Felder werden als neu belegt markiert, so dass deren Inhalt 
 *        neu auf dem Display gezeichnet wird.
 */
void init_board(void);

/**
 * @brief Diese Funktion platziert einen Spielstein mit dem Wert piece
 *        auf das durch row und col defnierten Feld des Spielfelds.
 *        Hat piece den Wert NO_PIECE, wir das Feld als leeres Feld
 *.       dargestellt.
 *
 * @param  row Spalte des Felds
 * @param  col Zeile des Felds
 * @param  piece Wert der Spielsteins
 *
 */
void place_piece(uint8_t row, uint8_t col, PieceType piece);

/**
 * @brief Diese Funktion bewegt den Spielstein mit dem Wert piece in
 *        das leere Feld, das horizontal oder vertikal neben dem 
 *        Spielstein liegt.
 *        Somit ist das Feld, in dem der Spielstein bisher lag, 
 *        anschließend leer. 
 *
 *        Liegt neben dem Spielstein kein freies Feld oder hat 
 *        piece den Wert NO_PIECE, führt diese Funktion keine Veränderungen
 *        durch.
 *
 * @param  piece Wert des Spielsteins, der verschoben werden soll.
 */
void move(PieceType piece);

/**
 * @brief Diese Funktion zeichnet das aktuelle Spielfeld auf dem Display.
 *        Damit das Display nicht flackert werden nur die Felder gezeichnet,
 *        die sich verändert haben.
 */
void draw_board(void);

/**
  * @brief Diese Funktion überprüft, ob die Spielsteine in der richtigen Reihenfolge
  *        auf dem Spielfeld angeordnet sind.
  *
  *        Somit liefert die Funktion gdw. true zurück, wenn in der obersten
  *        Zeile die Spielsteine mit den Werten 0 bis 2 liegen und von links nach 
  *        rechts in aufsteigender Reihenfolge angeordnet sind. In der mittleren
  *        Zeile liegen die Spielsteine mit den Werten 3 bis 5 und sind ebenfalls 
  *        von links nach rechts in aufsteigender Reihenfolge angeordnet.
  *        In der unteren Zeile liegen die Spielsteine mit den Werten 6 und 7, die auch 
  *        wieder von links nach rechts in aufsteigender Reihenfolge angeordnet sind.
  *        Insbesondere muss das rechte Feld der unteren Zeile frei sein.
  *        
  * @retval true gdw die Spielsteine sind in der richtigen Reihenfolge angeordnet.
  */
bool game_over(void);

#endif
// EOF