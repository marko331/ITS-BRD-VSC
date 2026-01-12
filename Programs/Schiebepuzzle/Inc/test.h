/**
 ******************************************************************************
 * @file    test.h
 * @author  Franz Korf
 *
 * @date    10. Jan. 2026
 *
 * @brief  Interface des test Moduls.
 *
 ******************************************************************************
 */

#ifndef _TEST_H
#define _TEST_H

// Diese define Anweisungen aktivieren die Tests der 
// entsprechenden Aufgaben.

// #define AUFGABE3
// #define AUFGABE4
#define AUFGABE5

#ifdef AUFGABE3
/**
 * @brief  Test des Moduls io. 
 */
void test_IO(void);
#endif

#ifdef AUFGABE4
/**
 * @brief  Test des Moduls display. 
 */
void test_display(void);
#endif

#ifdef AUFGABE5 
/**
 * @brief  Test des Moduls kniffel. 
 */
void test_game(void);
#endif

#endif
// EOF
