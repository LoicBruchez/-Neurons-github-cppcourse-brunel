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
#include <deque>

using namespace std;
	
/** class Neuron
 * used to set all the neurons caracterisctics 
 * when creating the network
 */
	
class Neuron {
	
	public:
	
	double memb_pot_;				//!< membrane potential of a neuron
	bool spike_;					//!< boolean, return if the neuron spikes in the function update
	int num_spikes_;				//!< "count" the number of spikes of the neuron during the simulation
	double time_spikes_;			//!< time when the neuron spike
	double input_;					//!< external input, only useful for tests
	double syn_input;				//!< synaptic input send by a neuron to his neighbour
	int int_clock_;					//!< internal clock of a neuron
	vector<size_t> neighbours_;     //!< represent all the neurons attached by a connexion
	vector<double> buffer;			//!< buffer = stock of the synaptic inputs and release of it at the good time  
	
	/**
	 * constructor of a neuron
	 * set all the attributes of the neurons
	*/
	Neuron();
	
	//####################################getters########################################
	
	//!< all the getters of the neuron class to acces the important values needed
	
	double getMembPot() const;				//!< return the membrane potential of a neuron
	double getTimeSpikes() const;			//!< return the time when a spike occurs
	bool getSpike() const;					//!< return if the neuron spikes or not
	int getNumbSpikes() const;				//!< return the number of spikes
	vector<size_t> getNeighbours() const;	//!< return the id of a neighbour neuron			
	
	//####################################setters########################################
	
	//!< all the setters of the neuron class 
	
	/** set the membrane potential
	 * @param memb_pot : value of the membrane potential that is needed (useful for tests)
	 */
	void setMembPot(double memb_pot);		
	
	/** set a constant external input 	
	 * @param input1 : the external input (useful for the tests)
	 */
	void setInput(double input1);
							
	/** set the buffer with a weight of synaptic input J_ (depending if the neuron is excitatory or inhibitory)
	 * @param t : the time of the simulation when a neuron spikes and give an input to his neighbours
	 * @param J_ : the weight of the input
	 */
	void setBuffer(int t, double J_);					
	
	//###################################other functions#################################
	
	/** update the membrane potential of neurons at each time steps
	 * when the membrane potential is higher than the threshold => spike and membrane potential is reset to 0
	 * After a spike, a neuron can't receive any input during 2ms (refractory time)
	 * @param steps : useful for the tests, define how many times we update a neuron
	 * @param bg_noise : represents the background noise induced by the outside of the network
	 * return a boolean to define if the neuron spikes or not
	 */
	bool update(size_t steps, double bg_noise);	
	
	/** connect	two neurons together (they become neighbours)
	 * store the weight of the input signal, depending on either the neuron is excitatory or inhibitory
	 * @param target : is the target of the neuron that will be connected to it
	 */			
	void connectTwoNeurons(size_t target);
	
	~Neuron();			//!< destructor of the neuron class
};

/** generate a random value which correspond to the background noise of the network
 * it's easier for the tests to create an external method 
 */
double randomPoisson();

#endif
