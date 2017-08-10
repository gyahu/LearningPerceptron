#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include "perceptron.h"

void Perceptron::init(){
	srand(time(NULL));
	for (int i=0; i<input_size; ++i){
		weights.push_back((rand()%10-5)/10.0);
	}
}

int Perceptron::compute(std::vector<int> input){
	double output = 0.0;
	for (int i=0; i<input_size; ++i){
		output += ((double) input[i]) * weights[i];
	}
	return output + bias > 0.0 ? 1 : 0;
}

void Perceptron::correct(std::vector<int> input, int expected_class){
	double sign = expected_class ? 1.0 : -1.0;
	for (int i=0; i<input_size; ++i){
		weights[i] += sign * ((double) input[i]) *alpha;
	}
}

void Perceptron::force_learn(std::vector<int> input, int expected){
	while (true){
		if (expected == compute(input)){
			printf("Correct identification, learning finished\n");
			break;
		}
		printf("Wrong identification, weights correction.\n");
		correct(input, expected);
	}
}

void Perceptron::free_learn(std::vector<int> input, int expected){
	if (expected == compute(input)){
			printf("Correct identification, learning finished\n");
	}
	else{
		printf("Wrong identification, weights correction.\n");
		correct(input, expected);
	}
}