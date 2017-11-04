#include "constants.hpp"
#include "Network.hpp"

using namespace std;

Network::Network() 
{
		Neuron n(0,0);
		all_neurons_.resize(N, n);
		assert(all_neurons_.size() <= N);
}

void Network::connectNeurons() {
	
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<int> exc(0, N_ex - 1);
	static uniform_int_distribution<int> inhib(N_ex, N - 1);
	
	for(unsigned int i(0); i < C_excit; ++i) {
		
		auto value = exc(gen);
		all_neurons_[i].connectTwoNeurons(value, J);
	}
	
	for(unsigned int i(0); i < C_inhibit; ++i) {
		
		auto value = inhib(gen);
		all_neurons_[i].connectTwoNeurons(value, -g*J);
	}
}

void Network::runSimulation() {
	
	int ext_clock = 0;
	ofstream file("neuron.txt", ios::trunc);
	bool spike = false;
	
	while(ext_clock < t_stop) {
		
		for(size_t n(0); n < all_neurons_.size(); ++n) {
			
			spike = all_neurons_[n].update(1);
			
			if(spike) {
				
				file << ext_clock << "\t" << n  << '\n';
			}
		}
		ext_clock+=step;
	}
}

Network::~Network() {}


	

