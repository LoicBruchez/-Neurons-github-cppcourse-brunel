#ifndef NEURON_HPP
#define NEURON_HPP

#include "constants.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <cassert>
#include <iomanip>
#include <random>

using namespace std;
	
/** class Neuron
 * used to set all the neurons caracterisctics 
 * when creating the network
 */
	
class Neuron {
	
	private:
	
	double memb_pot_;		//!< membrane potential of a neuron
	int int_clock_;			//!< internal clock of the neuron
	bool spike_;			//!< boolean, return if the neuron spikes in the function update
	
	public:
	
	double num_spikes_;				//!< "count" the number of spikes of the neuron during the simulation
	double time_spikes_;			//!< time when the neuron spike
	double input_;					//!< external input, only useful for tests
	double syn_input;				//!< synaptic input send by a neuron to his neighbour
	vector<size_t> neighbours_;     //!< represent all the neurons attached by a connexion
	vector<double> buffer;			//!< buffer = stock of the synaptic inputs and release of it at the good time  
	vector<double> weights;			//!< store all the synaptic inputs to give them to the buffer
	
	
	/**
	 * constructor of a neuron
	 * @param memb_pot = membrane potential of a neuron
	 * @param num_spikes = number of spikes a neuron make
	 * @param time_spikes
	*/
	Neuron(double memb_pot_, int int_clock);
	
	//####################################getters########################################
	
	//!< all the getters of the neuron class
	
	double getMembPot() const;				//!< return the membrane potential of a neuron
	double getTimeSpikes() const;			//!< return the time when a spike occurs
	double getIntClock() const;				//!< return the internal time of a neuron
	bool getSpike() const;					//!< return if the neuron spikes or not
	double getNumbSpikes() const;			//!< return the number of spikes
	vector<size_t> getNeighbours() const;	//!< return the id of a neighbour neuron			
	
	//####################################setters########################################
	
	void setInput(double input1);			//!< set the external input of a neuron (for tests only)
	
	//###################################other functions#################################
	
	/** update the membrane potential of neurons at each time steps
	 * set the buffer 
	 * @param steps : useful for the tests, define how many times we update a neuron
	 * return a boolean to define if the neuron spikes or not
	 */
	bool update(double steps);	
	
	/** connect	two neurons together (they become neighbours)
	 * store the weight of the input signal, depending on either the neuron is excitatory or inhibitory
	 * @param val : a random value dicted by a uniform distribution, give the id of the neuron making a connection
	 */			
	void connectTwoNeurons(size_t val, double w);
	
	~Neuron();			//!< destructor of the neuron class
};

#endif
