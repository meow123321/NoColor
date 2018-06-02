#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int ** generator_matrix(int no_vertices){
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

}

int chromatic_number(int **adjacency_matrix, int k){
    int * color_vect;
    int line;
    int column;
    int color=1;

    color_vect[k]=malloc(sizeof(int));
    color_vect[k]=1;
    for(line = 0; line < k; line++){
        if(adjacency_matrix[line][k]==1 && color_vect[k]!= adjacency_matrix[line]){
            color_vect[k]=malloc(sizeof(int));
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
    }*/

    return color_vect;

}

int main(){
    int no_vertices = 6;
    int **adjacency_matrix;
    int line;
    int column;
    int color;
    int * color_vect;

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


   /* color=chromatic_number(adjacency_matrix, no_vertices);

    printf("\n");
    printf("\nThe minimum number of colors needed is %d.", color);
    */

    for(line=0; line < no_vertices; line++){
        color_vect=chromatic_number(adjacency_matrix, no_vertices);
   }

   for(line=0; line<no_vertices; line++){
    printf("Vertex[%d] = %d", line+1, color_vect[line]);
   }




    for (line = 0; line < no_vertices; line++){
        free(adjacency_matrix[line]);
    }
    free(adjacency_matrix);

    return 0;
}
