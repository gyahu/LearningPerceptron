#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "sigmoid.h"

void Sigmoid::init(){
	srand(time(NULL));
	for (int i=0; i<input_size; ++i){
		weights.push_back((rand()%10-5)/10.0);
	}
}

int Sigmoid::compute(std::vector<int> input){
	double z = 0;
	for (int i=0; i<input_size; ++i){
		z += ((double) input[i]) * weights[i];
	}
	return activate_funct(z+bias) > 0.0 ? 1 : 0;
}

void Sigmoid::correct(std::vector<int> input, int expected_class){
	double sign = expected_class ? 1.0 : -1.0;
	for (int i=0; i<input_size; ++i){
		weights[i] += sign * ((double) input[i]) *alpha;
	}
}

void Sigmoid::force_learn(std::vector<int> input, int expected){
	while (true){
		if (expected == compute(input)){
			printf("Correct identification, learning finished\n");
			break;
		}
		printf("Wrong identification, weights correction.\n");
		correct(input, expected);
	}
}

void Sigmoid::free_learn(std::vector<int> input, int expected){
	if (expected == compute(input)){
			printf("Correct identification, learning finished\n");
	}
	else{
		printf("Wrong identification, weights correction.\n");
		correct(input, expected);
	}
}