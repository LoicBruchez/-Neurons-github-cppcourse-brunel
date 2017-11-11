#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std; 

/**constants for all the simulation
 * all the times are in steps
 */
 
const size_t D = 15;							//!< delay in steps until a post-synaptic neuron can receive a PSP 
const double t_ref =20;							//!< time of rest until the neuron can receive a new input
const double theta = 20.0;						//!< limit of the membrane potential. When potential > theta => spike
const double etha = 2;							//!< ratio nu_ext/nu_theta, variable to include in poisson distribution
const double h = 0.1;							//!< value of one step of the simulation (in ms)
const double tau = 20.0;						//!< membrane time constant
const double C = 1.0;							//!< membrane capacity
const double R = (tau/C);						//!< resistance of the membrane of a neuron to receive an input
const int t_start = 0;							//!< beginning of simulation
const int t_stop = 10000;						//!< end time of the simulation (in steps)
const int step =1;								//!< one step 
const double c1 = (exp(-h/tau));				//!< constant for the equation which define the change of the membrane potential
const double c2 = (R*(1.0-(exp(-h/tau))));		//!< second constant for the equation
const double J_i = (-0.5);						//!< inhibitory input signal of a neuron
const double J = 0.1;							//!< weight of both external and excitatory input signal of a neuron
const double g = J_i/J; 						//!< constant to set the weight of inhibitory input signal of a neuron
const size_t N = 12500;							//!< total number of neurons
const int N_ex = 10000;							//!< number of excitatory neurons
const int N_inh = 2500;							//!< number of inhibitory neurons
const int C_excit = 1000;						//!< number of connections of an excitatory neuron 
const int C_inhibit = 250;						//!< number of connections of an inhibitory neuron
const double nu_theta = 10;						//!< threshold rate
const double nu_ext = 20;						//!< background rate : nu_ext = etha*theta/(J*tau)

#endif
