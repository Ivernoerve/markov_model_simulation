#include <stdlib.h>
#include <stdio.h>
#include "markov.h"


struct markov_state;
typedef struct markov_state state_t;

struct markov_state {
	int identifier;
	float *p_vec;

};

struct markov_model{
	int n_states;
	int current;
	int *n_visits;
	state_t **states;

};


static state_t *state_create(int identifier, float* p_vec) {
	state_t *state = malloc(sizeof(state_t));

	if (state == NULL)
		return NULL;

	state -> identifier = identifier;
	state -> p_vec = p_vec;

	return state;
}


mm_t *model_create(int n_states, char **argv, int init_state){
	int i, j;
	float *p_arr;

	mm_t *model = malloc(sizeof(mm_t));

	state_t **states = (state_t **)malloc(sizeof(state_t) * n_states);

	for (i=0; i < n_states; i++){
		p_arr = malloc(n_states * sizeof(float));
		for (j=0; j < n_states; j++){
			p_arr[j] = (float)atof(argv[2 + i * n_states + j]);
		}
		states[i] = state_create(i, p_arr);
	}

	model -> n_states = n_states;
	model -> current = init_state;
	model -> states = states;
	model -> n_visits = calloc(n_states, sizeof(int));

	return model;
}


void model_destroy(mm_t *model){
	int i;

	state_t *state;
	for (i=0; i < model->n_states; i++){
		state = model -> states[i];
		free(state->p_vec);
		free(state);
	}
	free(model->states);
	free(model->n_visits);
	free(model);
}


int model_step(mm_t *model){
	
	float p, last_p;
	int i, next_state;

	p = (float)(rand() % 101) / 100;
	
	last_p = 0;
	float *p_vec = model->states[model->current]->p_vec;
	for (i=0; i < model->n_states; i++){

		if (p > last_p && p < last_p + p_vec[i]){
			next_state = i;
		}
		
		last_p += p_vec[i];
	}

	model -> n_visits[next_state] += 1;
	model ->current = next_state;
	return next_state;
}


int *get_state_visits(mm_t *model){
	return model->n_visits;
}



