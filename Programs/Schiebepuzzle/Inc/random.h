#ifndef  _RANDOM_H
#define _RANDOM_H

/**
 ******************************************************************************
 * @file    random.h
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Interface des Standard-Pseudozufallsgenerator fuer die
 *          Schiebepuzzle Klausuraufgabe.
 ******************************************************************************
 */

/**
  * @brief Diese Funktion liefert eine Pseudozufallszahl. Der erste Aufruf der
  *        Funktion initialisiert den Zufallszahlengenerator.
  *
  * @retval Erzeugte Zufallszahl
  */
int nxtRandNumber(void);

#endif
// EOF
