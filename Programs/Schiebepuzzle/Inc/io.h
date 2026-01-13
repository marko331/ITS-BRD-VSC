#ifndef _IO_H
#define _IO_H
/**
 ******************************************************************************
 * @file    io.h
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 *
 * @date    10. Jan. 2026
 * @brief   Interface des GPIO Moduls der Musterloesung des Schiebepuzzles.
 ******************************************************************************
 */

#include <stdint.h>

/**
  * @brief Diese Funktion liest den Zustand der 8 Taster des ITS_Boards gleichzeitig ein.
  *        Die Taster werden via Software in dieser Funktion entprellt.
  *
  *        Ist die maximale Anzahl der Entprell-Versuche überschritten,
  *        werden alle Taster als nicht gedrückt zurückgegeben.
  *
  * @return uint8_t Bitmaske der gedrückten Taster.
  *         Für 0 <= i < 8: Bit i gesetzt gdw. Taster i gedrückt
  *         Ist die Anzahl der Entprellversuche überschritten: Rückgabewert : 0x00
 */

uint8_t debounced_buttons_pressed(void);

#endif
// EOF