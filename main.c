#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.h"

/*int ** generator_matrix(int no_vertices){
    int **adjacency_matrix;
    int line;
    int column;

    adjacency_matrix = malloc(no_vertices * sizeof(int*));
    for (line = 0; line < no_vertices; line++){
        adjacency_matrix[line] = malloc(no_vertices * sizeof(int));
    }
    //srand(time(0));
    for (line = 0; line < no_vertices; line++){
        for (column = line; column < no_vertices; column++){
            if (line == column){
               adjacency_matrix[line][column] = 0;
            }else{
                adjacency_matrix[line][column] = rand() % 2;
                adjacency_matrix[column][line] = adjacency_matrix[line][column];
            }
            adjacency_matrix[line][column] = adjacency_matrix[column][line];
        }
    }

    return adjacency_matrix;

}*/

int main(){
    int no_vertices = 6;
    int **adjacency_matrix;
    int line;
    int column;
    int color;
    int k;

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
   for(k=0; k<= no_vertices-1; k++){
    for (line = 0; line < no_vertices-1; line++){
        for (column = 0; column < no_vertices-1; column++){

            if (adjacency_matrix[line][column] == 1 && adjacency_matrix[k][column] == 1 && adjacency_matrix[line][k]){
                printf("\n%d, %d, %d", line, column, k);
                color++;
            }
        }
    }
   }

    printf("\n");
    printf("\nNumarul de culori folosite pentru graful respectiv este %d.", color);



    for (line = 0; line < no_vertices; line++){
        free(adjacency_matrix[line]);
    }
    free(adjacency_matrix);
}
