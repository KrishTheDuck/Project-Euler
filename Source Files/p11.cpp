#include "../Header Files/p11.h"

p11::~p11(void) {
	for (int i = 0; i < p11::N; i++) {
		delete[] p11::matrix[i];
	}
	delete[] p11::matrix;
};

void p11::read(std::string* file)
{

	std::ifstream myfile(*file);
	int i = 0, j = 0;
	for (int i = 0; i < p11::N; i++)
	{
		p11::matrix[i] = new int[20];
		for (int j = 0; j < p11::N; j++)
		{
			myfile >> p11::matrix[i][j];
		}
	}
}

void p11::solve() {
	std::string file = "C:\\Users\\srikr\\Documents\\GitHub\\Project Euler Problem Sets\\Problems\\p11.txt";
	read(&file);

	unsigned int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			//vertical
			if (j < 16)
			{
				unsigned int product = matrix[i][j];
				for (int k = 1; k < 4; k++)
				{
					product *= matrix[i][j + k];
				}
				max = (max < product) ? product : max;
			}

			//horizontal
			if (i < 16)
			{
				unsigned int product = matrix[i][j];
				for (int k = 1; k < 4; k++)
				{
					product *= matrix[i + k][j];
				}
				max = (max < product) ? product : max;
			}

			//diagonal down
			if (i < 16 && j >= 4)
			{
				unsigned int product = matrix[i][j];
				for (int k = 1; k < 4; k++)
				{
					product *= matrix[i + k][j - k];
				}
				max = (max < product) ? product : max;
			}

			//diagonal up
			if (i < 16 && j < 16)
			{
				unsigned int product = matrix[i][j];
				for (int k = 1; k < 4; k++)
				{
					product *= matrix[i + k][j + k];
				}
				max = (max < product) ? product : max;
			}
		}
	}

	std::cout << max << std::endl;
	p11::~p11();
}
