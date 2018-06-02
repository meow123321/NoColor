#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


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
