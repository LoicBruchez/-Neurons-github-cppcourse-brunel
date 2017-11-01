#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "constants.hpp"
#include "Neuron.hpp"
#include <iomanip>
#include <random>

using namespace std;

/**
 * Connexion of all neurons 
 * made step by step, connect one neuron with an other 
 * and iterate for 12500 neurons
 * run the simulation
 */

class Network {
	
	public :

	int ext_clock;
	vector<Neuron*> all_neurons_;
	
	Network();
	void connectNeurons();
	void runSimulation(int ext_clock);
	~Network();

};

#endif
