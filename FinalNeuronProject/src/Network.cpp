#include "constants.hpp"
#include "Network.hpp"

using namespace std;

Network::Network() 
{
	all_neurons_.resize(N);
		assert(all_neurons_.size() <= N);
}

void Network::connectNeurons() 
{	
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<int> exc(0, N_ex - 1);
	static uniform_int_distribution<int> inhib(N_ex, N - 1);
	
	for(size_t target(0); target < N; ++ target)
	 {
		for(unsigned int i(0); i < C_excit; ++i) 
		{	
			int value = exc(gen);
			all_neurons_[value].connectTwoNeurons(target);
		}
		
		for(unsigned int i(0); i < C_inhibit; ++i)
		{	
			int value = inhib(gen);
			all_neurons_[value].connectTwoNeurons(target);
		}
	}
}

void Network::runSimulation(int t) 
{
	ofstream file("spikes.txt", ios::trunc);
	bool spike = false;
	
	while(t < t_stop) 
	{	
		for(size_t n(0); n < all_neurons_.size(); ++n) 
		{	
			spike = all_neurons_[n].update(1, randomPoisson());
			
			if(spike) 
			{
				file << t << "\t" << n+1  << '\n';
				
				for(size_t neighbour(0); neighbour < all_neurons_[n].getNeighbours().size(); ++neighbour)
				 {	
					if(n < N_ex) 
					{		
						all_neurons_[neighbour].setBuffer(t+D, J);
					} else if(n >= N_ex) 
					{
						all_neurons_[neighbour].setBuffer(t+D, J_i);
					}
				}
			}	
			
		}
	 ++t;
	}
}

Network::~Network() {}


	

