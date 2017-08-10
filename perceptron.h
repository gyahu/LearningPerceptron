#include <vector>

class Perceptron{
	private:
		int input_size, ammount_classes;
		double bias, alpha;
		std::vector<double> weights;
		int compute(std::vector<int>);
		void correct(std::vector<int>, int);

	public:
		Perceptron(int size, double b, double a, int classes){
			input_size = size;
			bias = b;
			alpha = a;
			ammount_classes = classes;
		}
		void init();
		void force_learn(std::vector<int>, int);
		void free_learn(std::vector<int>, int);
};