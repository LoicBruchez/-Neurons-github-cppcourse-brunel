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
	
class Neuron {
	
	private:
	
	double memb_pot_;		//potential of a neuron
	double num_spikes_;		//"count" the number of spikes of the neuron during the simulation
	double time_spikes_;	//time when the neuron spike
	int int_clock_;
	bool spike_;			//boolean, return if the neuron spikes in the function update
	
	public:
	
	double input_;
	double syn_input;
	vector<int> spikers;
	vector<size_t> neighbours_;    //represent all the neurons attached by a connexion
	
	Neuron(double memb_pot, double num_spikes, int time_spikes, int int_clock);
	array<double, 15> buffer;		//buffer = stock of the PSP and release of it at the good time  
	double getMembPot() const;
	double getTimeSpikes() const;
	double getIntClock() const;
	double getInput() const;
	bool getSpike() const;
	double getNumbSpikes() const;
	double setInput(double input1);
	bool update(double steps);						//modify the membrane potential of the neurons and define if they spike
	void connectTwoNeurons(size_t val);
	vector<size_t> getNeighbours() const;				//tab of all the neurons that are connected to the previous neuron
	void setBuffer(unsigned long final_t, double J);
	~Neuron();
};

#endif
