#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int color_vect[10];

// this function will color the array of vertiices with colors represented by digits
void  chromatic_number(int **adjacency_matrix, int k){
    int line;

    color_vect[k]=1;
    for(line = 0; line < k; line++){
        // If between two vertices exists an edge and they have the same color then we assign a higher color
        if(adjacency_matrix[line][k] == 1 && color_vect[k]== color_vect[line]){
            color_vect[k]=color_vect[line]+1;
        }
    }
}
