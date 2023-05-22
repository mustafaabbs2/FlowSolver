#pragma once

#include "Grid.hpp"
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
		f_n.assign(nx_, 0);
		f_np1.assign(nx_, 0);
	}

	void solve()
	{
		//doing something
		for(auto i = 1; i < nx_; i++)
		{
			f_np1[i] = f_n[i] - c_ * (deltaT_ / deltaX_) * (f_n[i] - f_n[i - 1]);
		}
	}

private:
	std::vector<double> f_n;
	std::vector<double> f_np1;
};