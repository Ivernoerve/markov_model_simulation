#ifndef MARKOV_H
#define MARKOV_H


/*
 * The struct for the markov model
*/
struct markov_model;
typedef struct markov_model mm_t;

/*
 * Creates a new model with the given number of states.

 @n_states: The number of states in the model
 @argv: argv containing the probability matrix of the model
*/
mm_t *model_create(int n_states, char **argv, int init_state);

/*
 * destroys the model for cleanup puropses
*/
void model_destroy(mm_t *model);


/*
 * Performs one simulation step for the given model 
 * returns the identifier of the current state after step
*/ 
int model_step(mm_t *model);

/* 
 * returns the array containing the number of visits during the 
 * runtime of the model.
*/
int *get_state_visits(mm_t *model);

#endif
