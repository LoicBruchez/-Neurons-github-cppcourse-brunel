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

Network network;

int main() {

	int ext_clock = 0;
	
	network.connectNeurons();
	network.runSimulation(ext_clock);
	
	return 0;
}
