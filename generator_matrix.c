#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Function.h"

int ** generator_matrix(int no_vertices){
    int **adjacency_matrix;
    int line;
    int column;

    adjacency_matrix = malloc(no_vertices * sizeof(int*));
    for (line = 0; line < no_vertices; line++){
        adjacency_matrix[line] = malloc(no_vertices * sizeof(int));
    }
    srand(time(0));
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
