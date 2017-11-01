#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std; 


//constants 
//all the times are in steps

const double V_reset = 10.0; 
const size_t D = 15;			 //delay in steps until a post-synaptic neuron can receive a PSP 
const double t_ref =20;		//time of rest until the neuron can receive a new input
const double theta = 20.0;		//limit of the membrane potential. When potential > theta => spike
const double etha = 2;
const double h = 0.1;			//value of one step (in ms)
const double tau = 20.0;		
const double C = 1.0;			//number of connexion
const double R = (tau/C);		//resistance of the membrane of a neuron to receive an input
const double t_stop = 1000;		//end of the simulation
const int step(1);				//conversion of time to steps
const double c1 = (exp(-h/tau));	//constant for the equation which define the change of the membrane potential
const double c2 = (R*(1.0-c1));	//second constant for the equation
const double J_i = 0.5;			//PSP, intensity of the inhibitory signal send by a neuron to one of his post-synaptical neurons
const double J = 0.1;
const double g = J_i/J; 
const size_t N = 12500;
const int N_ex = 10000;
const int N_inh = 2500;
const int C_excit = 1000;
const int C_inhibit = 250;
const double nu_theta = (10);
const double nu_ext = (etha*nu_theta*h);

#endif
