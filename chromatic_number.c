#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int color_vect[10];

void  chromatic_number(int k){
    int **adjacency_matrix;
    int line;
    int column;
    int color=1;

   // color_vect[k]=malloc(sizeof(int));
    color_vect[k]=1;
    for(line = 0; line < k; line++){
        if(adjacency_matrix[line][k]==1 && color_vect[k]!= adjacency_matrix[line]){
          //  color_vect[k]=malloc(sizeof(int));
            color_vect[k]=adjacency_matrix[line]+1;
        }
    }


  /*  for (line = 0; line < no_vertices-1; line++){
        k=line;
        for (column = line; column < no_vertices-1; column++){
            if (adjacency_matrix[line][k+1] == 1 && adjacency_matrix[k+1][column] == 1){
                printf("\n%d, %d", line, column);
                color++;
            }
        }
    }

    return color_vect;
*/
}
