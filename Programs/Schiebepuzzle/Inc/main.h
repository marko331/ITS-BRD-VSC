#ifndef _MAIN_H
#define _MAIN_H

/**
 ******************************************************************************
 * @file    main.h
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Konstanten und Typen für die Schiebepuzzle Klausuraufgabe
 ******************************************************************************
 */

#include <stdint.h>

/**
 * @defgroup GENERAL_TYPES_AND_CONS 
 * @brief Allgemeine Typen und Konstanten für das Schiebepuzzle
 *
 * Diese Gruppe enthält allgemeine Datentypen und Konstanten, die das 
 * Schiebepuzzle betreffen.
 * Das Spielfeld besteht aus 3 x 3 Feldern, auf die jeweils eine Spielstein 
 * passt. 
 * In Summe gibt es 8 Spielsteine, die mit den Werten 0 bis 7 markiert sind.
 * Sie liegen alle auf dem Spielfeld und ein Feld bleibt leer / frei.
 *
 */

/**
 * @ingroup GENERAL_TYPES_AND_CONS
 * @brief Die Konstante GRID_SIZE definiert die Zeilen- und Spaltenzahl
 *.       des Spielfelds.
 */
#define GRID_SIZE			 3

/**
 * @ingroup GENERAL_TYPES_AND_CONS
 * @brief Der Typ PieceType definiert den Wert eines Spielsteins.
 *
 *        Wert 0 bis 7 : Der entsprechende Spielstein.
 *        Wert 8 : Kein Spielstein
 */

typedef uint8_t PieceType;    

/**
 * @ingroup GENERAL_TYPES_AND_CONS
 * @brief Der Wert stellt ein nicht belegtes Spielfeld dar
 */

#define NO_PIECE           8

#endif