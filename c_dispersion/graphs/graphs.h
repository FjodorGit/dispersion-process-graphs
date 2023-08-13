#include "../pcg/pcg_basic.h"
#include <sys/types.h>

typedef int (*stepper)(int **graph_representation, int *graph_size,
                       const int capacity, int *maxp, int *destinations,
                       pcg32_random_t *rngptr);

typedef struct {
  int size;
  const int capacity;
  const stepper stepper;
  char graph_type[128];
  int particles_count;
} Graph;

int step_fully_connected(int **graph_representation, int *graph_size,
                         const int capacity, int *maxp, int *destinations,
                         pcg32_random_t *rngptr);

int step_circle(int **graph_representation, int *graph_size, const int capacity,
                int *maxp, int *destinations, pcg32_random_t *rngptr);

int step_line(int **graph_representation, int *graph_size, const int capacity,
              int *maxp, int *destinations, pcg32_random_t *rngptr);

int step_grid(int **graph_representation, int *graph_size, const int capacity,
              int *maxp, int *destinations, pcg32_random_t *rngptr);
