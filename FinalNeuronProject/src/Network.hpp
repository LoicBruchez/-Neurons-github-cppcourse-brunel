#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "constants.hpp"
#include "Neuron.hpp"
#include <iomanip>
#include <random>
#include <deque>

using namespace std;

/**
 * Connexion of all neurons 
 * connect one neuron with an other step by step
 * and iterate for 12500 neurons
 * run the entire simulation to produce de plots from the Brunel model
 */

class Network {
	
	public :
	
	vector<Neuron> all_neurons_;			//!< table containing all the neurons of the simulation
	
	/**constructor of our network
	 * create a tab containing the 12500 neurons (whole system)
	 */
	Network();
	
	/**
	 * create 1250 random connections between neurons 
	 */
	void connectNeurons();
	
	/**
	 * run the whole simulation
	 * produce a file storing when a neuron spikes and his id
	 * give the synaptic input (excitatory or inhibitory) to the neurons they are connected with
	 * @param t : time of the beginning of the simulation
	 * @see connectTwoNeurons(size_t target)
	 */
	void runSimulation(int t);
	
	~Network();			//!< destructor of the network

};

#endif
