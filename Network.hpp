#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "constants.hpp"
#include "Neuron.hpp"
#include <iomanip>
#include <random>

using namespace std;

/**
 * Connexion of all neurons 
 * connect one neuron with an other step by step
 * and iterate for 12500 neurons
 * run the simulation
 */

class Network {
	
	public :

	vector<Neuron> all_neurons_;			//!< vector containing all the neurons of the simulation
	
	/**constructor of our network
	 * create a tab containing the 12500 neurons
	 */
	Network();
	
	/**
	 * connect neurons together randomly
	 */
	void connectNeurons();
	
	/**
	 * run the whole simulation
	 * produce a file storing when a neuron spikes and his id
	 * @see connectTwoNeurons(size_t val, double w)
	 */
	void runSimulation();
	
	~Network();			//!< destructor of the network

};

#endif
