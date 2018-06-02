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


   /* color=chromatic_number(adjacency_matrix, no_vertices);

    printf("\n");
    printf("\nThe minimum number of colors needed is %d.", color);
    */

    for(line=0; line < no_vertices; line++){
        chromatic_number(line);
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
