/**
 ******************************************************************************
 * @file    kniffel.c
 * @author  Franz Korf
 *          HAW-Hamburg
 *          Labor fuer technische Informatik
 *          Berliner Tor  7
 *          D-20099 Hamburg
 * @version 1.1
 *
 * @date    10. Jan. 2026
 * @brief   Dieses Modul implementiert die Spiellogik.
 *
 ******************************************************************************
 */

#include "game.h"
#include "main.h"
#include "random.h"
#include "display.h"
#include <stdbool.h>
#include "error.h"

static PieceType board[GRID_SIZE][GRID_SIZE];
static bool update_field[GRID_SIZE][GRID_SIZE];

void place_piece(uint8_t row, uint8_t col, PieceType val){
    	if ((row > GRID_SIZE) || (col > GRID_SIZE) || (val > NO_PIECE)) {
		Error_Handler();
	}
    board[row][col] = val;
    update_field[row][col] = true;
}

void init_board(void){
    bool used[GRID_SIZE * GRID_SIZE];
    for (int i = 0; i < (GRID_SIZE * GRID_SIZE); i++){
        used[i] = false;
    }
    for (uint8_t row = 0; row < GRID_SIZE; row ++){
        for (uint8_t col = 0; col < GRID_SIZE; col ++){
            PieceType v = nxtRandNumber() % (GRID_SIZE * GRID_SIZE);
            while (used[v]){
                v = nxtRandNumber() % (GRID_SIZE * GRID_SIZE);
            }
            used[v] = true;
            board[row][col] = v;
            update_field[row][col] = true;
        }
    }
}

void draw_board(void){
    for (uint8_t row = 0; row < GRID_SIZE; row ++){
        for (uint8_t col = 0; col < GRID_SIZE; col ++){
            if (update_field[row][col]) {
                display_piece(row, col, board[row][col]);
                update_field[row][col] = false;
            }
        }
    }
}

/**
 * @brief Diese Funktion überprüft, ob zwei Felder horizontal oder 
 *        vertikal auf dem Spielfeld nebeneinander angeordnet sind.
 *
 * @param  row_1 Zeile des ersten Felds
 * @param  col_1 Spalte des ersten Felds
 * @param  row_2 Zeile des zweiten Felds
 * @param  col_2 Spalte des zweiten Felds
 *
 * @retval true gdw die beiden Felder sind horizontal oder vertikal 
 *         nebeneinander angeordnet.
 */
static bool is_neighbor(uint8_t row_1, uint8_t col_1, uint8_t row_2, uint8_t col_2){
    return  ((row_1 == row_2) && (col_1 == (col_2 + 1))) ||
            ((row_1 == row_2) && (col_2 == (col_1 + 1))) ||
            ((col_1 == col_2) && (row_1 == (row_2 + 1))) ||
            ((col_1 == col_2) && (row_2 == (row_1 + 1)));
}

void move(PieceType val){
    for (uint8_t row = 0; row < GRID_SIZE; row ++){
        for (uint8_t col = 0; col < GRID_SIZE; col ++){
            if (board[row][col] == val){
                // if any neighbor field is empty, move piece into this field
                for (int r = 0; r < GRID_SIZE; r ++){
                    for (int c = 0; c < GRID_SIZE; c ++){
                        if (is_neighbor(row, col, r, c) && (board[r][c] == NO_PIECE)){
                            // swap field values
                            place_piece(row, col, NO_PIECE);
                            place_piece(r, c, val);
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool game_over(void){
    bool erg = true;
    for (uint8_t row = 0; row < GRID_SIZE; row ++){
        for (uint8_t col = 0; col < GRID_SIZE; col ++){
            erg = erg && !update_field[row][col];
            erg = erg && (board[row][col] == GRID_SIZE * row + col);
        }
    }
    return erg;
}
// EOF