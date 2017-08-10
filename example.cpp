#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "perceptron.h"

using namespace std;

int main(){

	int value, expected, learning;
	int size = 2;
	double bias = 1.0;
	int ammount_classes = 2;
	double alpha = 0.001;
	Perceptron unit(size, bias, alpha, ammount_classes);
	unit.init();
	std::vector<int> input;
	printf("Choose between 'repetitive learning' (0) or 'balanced learning' (1)\n");
	scanf("%d", &learning);
	while (true){
		for (int i=0; i<2; ++i){
			printf("Enter value number %d: ", i+1);
			scanf("%d", &value);
			input.push_back(value);

		}
		printf("Enter vector's class: ");
		scanf("%d", &expected);
		if (learning)
			unit.free_learn(input, expected);
		else
			unit.force_learn(input, expected);
	}

	return 0;
}
