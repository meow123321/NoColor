#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int color_vect[10];

// This function generates a random adjacency matrix of a graph
int ** generator_matrix(int no_vertices){
    int **adjacency_matrix;
    int line;
    int column;

    // we allocate no_vertices places in memory for lines
    adjacency_matrix = malloc(no_vertices * sizeof(int*));
    for (line = 0; line < no_vertices; line++){
        // for each line we allocate another no_vertices places in memory for columns
        adjacency_matrix[line] = malloc(no_vertices * sizeof(int));
    }

    srand(time(0));
    for (line = 0; line < no_vertices; line++){
        for (column = line; column < no_vertices; column++){
            if (line == column){
            // we initialize the elements on the main diagonal so the vertices does not have edge with themselves
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

int main(){
    int no_vertices = 6;
    int **adjacency_matrix;
    int line;
    int column;
    int color;

    //we again allocate memory for the matrix of adjacency
    adjacency_matrix = malloc(no_vertices * sizeof(int*));
    for (line = 0; line < no_vertices; line++){
        adjacency_matrix[line] = malloc(no_vertices * sizeof(int));
    }

    adjacency_matrix = generator_matrix(no_vertices);

    // we print the adjacency matrix
    for (line = 0; line < no_vertices; line++){
            printf("\n");
        for (column = 0; column < no_vertices; column++){
            printf("%d ",  adjacency_matrix[line][column]);
        }
    }

    printf("\n");


    for(line=0; line < no_vertices; line++){
        chromatic_number(adjacency_matrix, line);
   }
    //we print the colored array
    for(line=0; line<no_vertices; line++){
        printf("Vertex[%d] = %d\n", line+1, color_vect[line]);
   }

    // the number of color needed to color the matrix will be the maximum value of the array
    color = color_vect[0];
    for(line = 0; line < no_vertices; line++){
        if(color_vect[line] > color){
            color = color_vect[line];
    }
   }

    printf("\nThe minimum number of colors needed is %d.", color);


    for (line = 0; line < no_vertices; line++){
        free(adjacency_matrix[line]);
    }
    free(adjacency_matrix);

    return 0;
}
