#include "../pcg/pcg_basic.h"
#include "graphs.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <time.h>

// calculates one step of the dispersion process on the fully connected graph
// graph_representation: the array representation of the graph, where an index
//                       is a node and the value at that index is the amount of
//                       particles on the node
// destinations: array of indeces (nodes). Every index represents where a
//               one particle will move
int step_fully_connected(int **graph_representation, int *graph_size,
                         int capacity, int *maxp, int *destinations,
                         pcg32_random_t *rngptr, bool debug_info) {

  int destinations_count = 0;
  int unhappy_count = 0;

  // show graph_representation
  if (debug_info) {
    printf("[ ");
    for (int i = 0; i < *graph_size; i++) {
      printf("%d ", (*graph_representation)[i]);
    }
    printf("]\n");
  }

  for (int i = 0; i < *graph_size; i++) {
    // iterate over nodes of the graph
    int value = (*graph_representation)[i];
    // count of particles on a node
    if (value > capacity) {
      printf("\n");
      // case where particles on node are unhappy
      for (int j = 0; j < value; j++) {
        unhappy_count++;
        // generate a new destination node for every unhappy particle
        int random_index = pcg32_boundedrand_r(rngptr, *graph_size);
        if (debug_info) {
          printf("Move to node %d\n", random_index);
        }
        destinations[destinations_count++] = random_index;
      }
    } else if (value != 0) {
      // happy particles just stay at their current node
      for (int j = 0; j < value; j++) {
        destinations[destinations_count++] = i;
      }
    }
  }
  if (debug_info) {
    printf("\n\n\n");
  }

  memset(*graph_representation, 0,
         *graph_size * sizeof(int)); // clear the graph representation
  *maxp = 0; // points to the maximum amount of particles on node
  for (int i = 0; i < destinations_count; i++) {
    int destination = destinations[i];
    (*graph_representation)[destination]++;
    // build the graph representation from the array of destinations
    if ((*graph_representation)[destination] > *maxp) {
      *maxp = (*graph_representation)[destination];
    }
  }

  return unhappy_count;
}
