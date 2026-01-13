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
 * @brief   Konstanten und Typen fuer die Schiebepuzzle Klausuraufgabe
 ******************************************************************************
 */

#include <stdint.h>

/**
 * @defgroup GEN_TYPES_AND_CONS 
 * @brief Typen und Konstanten für das Schiebepuzzle
 *
 * Diese Gruppe enthält Typen und Konstanten, die das Schiebepuzzle betreffen.
 * 
 * Das Spielfeld besteht aus 3 x 3 Feldern, auf die jeweils ein Spielstein 
 * passt. 
 * Es gibt 8 Spielsteine, die mit den Werten 0 bis 7 markiert sind.
 * Diese liegen auf den 9 Feldern -  ein Feld frei. 
 *
 * Ein freies Feld wird intern durch einen Spielstein mit dem Wert 8 repräsentiert.
 */

/**
 * @ingroup GEN_TYPES_AND_CONS
 * @brief Die Konstante GRID_SIZE definiert die Zeilen- und Spaltenzahl
 *        des Spielfelds.
 */
#define GRID_SIZE			 3

/**
 * @ingroup GEN_TYPES_AND_CONS
 * @brief Der Typ PieceType definiert den Wert eines Spielsteins.
 *
 *        Wert 0 bis 7 : Der entsprechende Spielstein.
 *        Wert 8 : Kein Spielstein. Liegt ein Spielstein mit dem Wert 8 auf einem
 *                 Feld, entspricht dies der Situation, dass das Feld  frei ist.
 */

typedef uint8_t PieceType;    

/**
 * @ingroup GEN_TYPES_AND_CONS
 * @brief Diese Konstante stellt ein freies Spielfeld dar
 */

#define NO_PIECE           8

#endif