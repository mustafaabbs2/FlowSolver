#pragma once

#include "Grid.hpp"
#include <algorithm>
#include <vector>

//du/dt + c du/dx = 0

// Solver class for Eulerian finite volume method
class LinearConvection
{
public:
	double deltaT_, deltaX_;
	double c_;
	int nx_;

	LinearConvection(double deltaT, double c, Grid& mesh)
		: deltaT_(deltaT)
		, c_(c)
		, deltaX_(mesh.getGridSize().first)
		, nx_(mesh.nx_)
	{
		f_n.assign(nx_, 1);
		f_np1.assign(nx_, 0);

		if(nx_ > 15) //hat function
		{
			std::fill(f_n.begin(), f_n.begin() + 5, 1);
			std::fill(f_n.begin() + 5, f_n.begin() + 15, 2);
			std::fill(f_n.begin() + 15, f_n.end(), 1);
		}
		else
			f_n.assign(nx_, 1);
	}

	void solve(size_t timesteps)
	{
		for(auto t = 0; t < timesteps; t++)
		{
			for(auto i = 1; i < nx_ - 1; i++)
			{
				f_np1[i] = f_n[i] - c_ * (deltaT_ / deltaX_) * (f_n[i] - f_n[i - 1]);
			}
			std::copy(f_np1.begin(), f_np1.end(), f_n.begin());
		}
	}

	std::vector<double> getVector()
	{
		return f_np1;
	}

private:
	std::vector<double> f_n;
	std::vector<double> f_np1;
};