/*
MIT License

Copyright (c) 2018 Benjamin Nysetvold

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <ctime>

#include "PCG32.h"

int roll(pcg32 *rng) {
	return (rng->nextUInt() % 6) + 1;
}

typedef std::numeric_limits<double> dbl;

int main()
{
	std::printf("Initializing Simulation...");
	pcg32 rng;
	rng.seed(42u, 54u);

	std::clock_t start;
	start = std::clock();

	unsigned long long int sum = 0;
	unsigned long long int trials = 0;
	long double result;
	long double time;
	int rolls[3];
	int random;
	int count;
	std::printf("Complete.\n");
	std::printf("Simulating...\n\n");

	while (true)
	{
		if (trials % 1000000000 == 0 && trials > 0)
		{
			result = static_cast<double>(sum) / trials;
			time = (double)(std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) / 1000;
			std::printf("%.0f simulations run in %.2f seconds.\n", (double)trials, time);
			std::printf("Sum of all simulations: %.0f\n", (double)sum);
			std::printf("Result of all simulations: %.*f\n", dbl::max_digits10, result);
			std::printf("%d Simulations per second\n\n", (int)((double)trials / time));
		}

		for (int i = 0; i <= 2; i++)
		{
			rolls[i] = roll(&rng);

			//rolls.emplace_back(roll(&rng));
		}

		int random = roll(&rng);
		int count = 0;

		for (int i = 0; i <= 3; i++)
		{
			if (rolls[i] == random)
			{
				count++;
			}
		}

		sum += -1 * (count - 1);

		trials++;
	}
}