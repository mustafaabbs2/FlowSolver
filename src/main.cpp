#include "Grid.hpp"
#include "LinearConvection.hpp"

#include <iostream>
#include <vector>

int main()
{
	// Create the solver object
	Grid mesh(10, 0);
	LinearConvection solver(0.1, 20, mesh);

	// Solve for multiple time steps
	for(int timestep = 0; timestep < 5; timestep++)
	{
		std::cout << "-----------------------" << std::endl;
	}

	return 0;
}