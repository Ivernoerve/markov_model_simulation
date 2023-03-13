#include "markov.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>




int test_input_integrity(int n_arg){
	int div_test, mod_test, row_size;

	row_size = (int)sqrt(n_arg -2);

	div_test = (n_arg - 2) / row_size == row_size;
	mod_test = (n_arg - 2) % row_size == 0;
	
	if (div_test && mod_test && (n_arg - 2 ) >= 4){
		return 0;
	}

	printf("not passed");
	return 1;
}





int main(int argc, char **argv){

	test_input_integrity(argc);
	srand(time(NULL));

	int iterations, row_size;
	mm_t *model;

	row_size = (int)sqrt(argc -2);
	iterations = (int)atol(argv[1]);

	model = model_create(row_size, argv, 0);
		
	int i;
	printf("running for %d iterations", iterations);
	for (i=0; i < iterations; i++){
		model_step(model);
	}
	
	printf("\n\n-------\n");

	int *visits = get_state_visits(model);
	for (i=0; i < row_size; i++){
		printf("%d - %f\n", i, (float)visits[i] / iterations);
	}

	model_destroy(model);

	/*
	float p;
	srand(0);
	p = (float)rand() / RAND_MAX;

	printf("p -- %f\n", p);

	int curr, closest;
	closest = 1;
	for(i = 0; i < row_size; i++){
		printf("%f --  ", fabsf(p_arr[i] - p));

		if (p_arr[i] - p < closest)
			curr = i;
			closest = p_arr[i] - p;
	}



	for (i = 0; i < row_size; i++){
		state_destroy(states[i]);
	}

	*/
	return 0;
}
