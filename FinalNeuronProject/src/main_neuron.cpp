#include "Neuron.hpp"
#include "constants.hpp"
#include "Network.hpp"

#include <iostream>

using namespace std;

/**main programm :
 * 
 * Is responsible to update the membrane potential of all
 * the neurons at each steps of the simulation
 */

int main() 
{	
	Network network;					//!< create all the neurons without the connections
	network.connectNeurons();			//!< connect the neurons randomly		
	network.runSimulation(t_start);		//!< run of the simulation, update and spikes of all the neurons
	
	return 0;
}
