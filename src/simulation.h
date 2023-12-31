#include "utils/utils.h"

int *simulate(unsigned int num_simulations, Graph graph);

int *unhappy_process(Graph graph, int *num_steps, double *variance_evaluation);

int *unhappy_process_stopped_early(Graph graph, int *num_steps,
                                   uint step_limit);
