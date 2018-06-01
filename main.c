#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"



int main(){
    int no_vertices = 6;
    int **adjacency_matrix;
    int line;
    int column;
    int color;


    adjacency_matrix = malloc(no_vertices * sizeof(int*));
    for (line = 0; line < no_vertices; line++){
        adjacency_matrix[line] = malloc(no_vertices * sizeof(int));
    }

    adjacency_matrix = generator_matrix(no_vertices);

   for (line = 0; line < no_vertices; line++){
            printf("\n");
        for (column = 0; column < no_vertices; column++){
            printf("%d ",  adjacency_matrix[line][column]);
        }
    }



   color = 1;

    for (line = 0; line < no_vertices-1; line++){
        for (column = line; column < no_vertices-1; column++){

            if (adjacency_matrix[line][column] == 1 && adjacency_matrix[line+1][column] == 1){
                printf("\n%d, %d", line, column);
                color++;
            }
        }
    }


   // color=chromatic_number(adjacency_matrix, no_vertices);

    printf("\n");
    printf("\nNumarul de culori folosite pentru graful respectiv este %d.", color);



    for (line = 0; line < no_vertices; line++){
        free(adjacency_matrix[line]);
    }
    free(adjacency_matrix);
}
