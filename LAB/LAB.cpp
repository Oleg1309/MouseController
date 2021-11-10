#include <iostream>
#include <cmath>

int main() {
	int x;
	std::cout << "Enter X" << std::endl;
	std::cin >> x;
	double result_cur{ 0 }, result_prev{ -1 };

	for (int n = 0; abs(result_cur - result_prev) > 0.001; ++n) {
		int factorial{ 1 };

		for (int j = 1; j <= 2 * n; ++j) {
			factorial *= j;
		}

		result_prev = result_cur;
		result_cur += pow(-1, n) * pow(x, 2 * n) / factorial;

	}

	std::cout << "Result is:	" << result_cur;
	return 0;
}3