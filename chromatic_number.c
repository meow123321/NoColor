#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int chromatic_number(int **adjacency_matrix, int no_vertices){

    int line;
    int column;
    int color;

       color = 1;

    for (line = 0; line < no_vertices-1; line++){
        for (column = line; column < no_vertices-1; column++){

            if (adjacency_matrix[line][column] == 1 && adjacency_matrix[line+1][column] == 1){
                printf("\n%d, %d", line, column);
                color++;
            }
        }
    }

    return color;

}
