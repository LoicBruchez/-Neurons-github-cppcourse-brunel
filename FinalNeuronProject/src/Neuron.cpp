#include "Neuron.hpp"
#include "constants.hpp"
#include <vector>

using namespace std;

Neuron::Neuron() 
{	
	memb_pot_ = 0.0;
	num_spikes_ = 0;
	time_spikes_ = 0;
	input_ = 0;
	syn_input = 0;
	int_clock_ = 0;
	buffer.resize(D+1, 0.0);
}

double Neuron::getMembPot() const 
{
	return memb_pot_;
}

double Neuron::getTimeSpikes() const
{	
	return time_spikes_;
}

int Neuron::getNumbSpikes() const 
{	
	return num_spikes_;
}

vector<size_t> Neuron::getNeighbours() const
{	
	return neighbours_;
}

void Neuron::setMembPot(double memb_pot)
{
	memb_pot_ = memb_pot;
}

void Neuron::setInput(double input1) 
{	
		input_ = input1;
}

void Neuron::setBuffer(int t, double J_) 
{	
	const auto buff_t_out = (t % (D+1));
	assert(buff_t_out < (buffer.size()));
	buffer[buff_t_out]+= J_;
}

void Neuron::connectTwoNeurons(size_t target) 
{		
	neighbours_.push_back(target);
}

//function that update membrane potential. It's a boolean because it return if the neuron spikes or not
bool Neuron::update(size_t steps, double bg_noise) 
{	
	int buff_t_in = (int_clock_ % (D+1));
	spike_ = false;
	
	for(size_t i(0); i < steps; ++i) 
	{	
		if(memb_pot_ > theta) 
		{	
			time_spikes_ = int_clock_;
			num_spikes_+=1;
			memb_pot_ = 0.0;
			spike_ = true;
		} 	
		if(((int_clock_-time_spikes_) < t_ref) and time_spikes_ > 0)
		{	
			memb_pot_ = 0.0;
			buffer[buff_t_in] = 0.0;
		} 
		else 
		{
			syn_input = buffer[buff_t_in];
			memb_pot_ = (c1*memb_pot_) + (input_ * c2) + syn_input + (bg_noise*J);
			buffer[buff_t_in] = 0.0;
		}
	}
	++int_clock_;
	return spike_;
}		



Neuron::~Neuron() {}

double randomPoisson() {
	
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> noise(etha);
	return noise(gen);
}
