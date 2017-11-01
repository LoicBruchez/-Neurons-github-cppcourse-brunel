#include "constants.hpp"
#include "Network.hpp"

using namespace std;

Network::Network() 
{
	for(size_t i(0); i < N; ++i) {
		
		Neuron n(0,0,0,0);
		all_neurons_.push_back(new Neuron(n));
		assert(all_neurons_.size() <= N);
	}
}

void Network::connectNeurons() {
	
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<int> exc(0, N_ex - 1);
	static uniform_int_distribution<int> inhib(N_ex, N - 1);
	
	for(unsigned int i(0); i < C_excit; ++i) {
		
		auto value = exc(gen);
		all_neurons_[i]->connectTwoNeurons(value);
	}
	
	for(unsigned int i(0); i < C_inhibit; ++i) {
		
		auto value = inhib(gen);
		all_neurons_[i]->connectTwoNeurons(value);
	}
}

void Network::runSimulation(int ext_clock) {
	
	ofstream file("neuron.txt", ios::trunc);
	
	while(ext_clock < t_stop) {
		
		unsigned int final_t = ext_clock+D;
		bool spike = false;
	
	
		for(size_t n(0); n < all_neurons_.size(); ++n) {
			
			spike = all_neurons_[n]->update(1);
			
			
			if(spike) {
				
				file << ext_clock << "   " << n + 1 << '\n';
				for(size_t neighbour; neighbour < all_neurons_[n]->getNeighbours().size(); ++neighbour) {
					
					if(n < N_ex) {
							
						all_neurons_[neighbour]->setBuffer(final_t, J);
					} else if(n > N_ex) {
						
						all_neurons_[neighbour]->setBuffer(final_t, -g*J);
					}
				}
			}
		}
		ext_clock+=step;
	}
}

Network::~Network() {}


	

