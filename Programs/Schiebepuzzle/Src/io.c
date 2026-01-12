/**
 ******************************************************************************
 * @file    io.c
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.0
 5
 * @date    10. Jan. 2026
 * @brief   GPIO Modul der Schiebepuzzle Klausuraufgabe.
 ******************************************************************************
 */
 
#include "io.h"
#include "delay.h"
#include "stm32f429xx.h"

#define BOUNCE_TIME_IN_MS           50   // debounce time
#define NO_RETRIES                  5    // maximum number of debounce attempts

uint8_t debounced_buttons_pressed(void){
   uint32_t mask = 0xFF;
   uint8_t v1 = (uint8_t) (GPIOF->IDR & mask);
   for (int i = 0; i < NO_RETRIES; i++){
       delay(BOUNCE_TIME_IN_MS);
       uint8_t v2 = (uint8_t) (GPIOF->IDR & mask);
       if (v1 == v2) {
          return ~v1;
       }
       v1 = v2;
   }    
   return 0x00;
}
// EOF