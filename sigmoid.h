#include <math.h>
#include <vector>
#include <functional>

class Sigmoid{
	private:
		int input_size, ammount_classes;
		double bias, alpha;
		std::vector<double> weights;
		int compute(std::vector<int>);
		std::function<double (double)> activate_funct;
		void correct(std::vector<int>, int);

	public:
		Sigmoid(int size, double b, double a, int classes){
			input_size = size;
			bias = b;
			alpha = a;
			ammount_classes = classes;
			activate_funct = [this] (double z) -> double {
													return 1.0/(1.0+exp(-z));
													};
			}
		Sigmoid(int size, double b, double a, int classes, std::function<double (double)> funct){
			input_size = size;
			bias = b;
			alpha = a;
			ammount_classes = classes;
			activate_funct = funct;
		}
		void init();
		void force_learn(std::vector<int>, int);
		void free_learn(std::vector<int>, int);
};