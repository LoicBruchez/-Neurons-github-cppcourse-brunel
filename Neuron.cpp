#include "Neuron.hpp"
#include "constants.hpp"
#include <vector>

using namespace std;

Neuron::Neuron(double memb_pot, double num_spikes, int time_spikes, int int_clock) {
	
	memb_pot_ = memb_pot;
	num_spikes_ = num_spikes;
	time_spikes_ = time_spikes;
	int_clock_ = int_clock;
}

double Neuron::getMembPot() const {
	
	return memb_pot_;
}

double Neuron::getTimeSpikes() const {
	
	return time_spikes_;
}

double Neuron::getIntClock() const {
	
	return int_clock_;
}

void Neuron::connectTwoNeurons(size_t val) {
		
		neighbours_.push_back(val);
}

//function that update membrane potential. It's a boolean because it return if there is a spike or not
bool Neuron::update(double steps) {
		
		const auto buff_t_in = (int_clock_ % (D+1));
		spike_ = false;
		
		for(int i(0); i < steps; ++i) {
			if(memb_pot_ > theta) {
				
				time_spikes_ = int_clock_;
				spike_ = true;
				++ num_spikes_;
				memb_pot_ = 0.0;
			} 	
			if(((int_clock_-time_spikes_)<t_ref) and time_spikes_ > 0) {
				
				memb_pot_ = 0.0;
			} else {
				
				random_device rd;
				mt19937 gen(rd());
				poisson_distribution<> noise(nu_ext);
				
				syn_input = buffer[buff_t_in];
				memb_pot_ = (((c1*memb_pot_) + (input_ * c2))+ syn_input + noise(gen));
				buffer[buff_t_in] = 0;
			}
			int_clock_+= 1;		
	}
	return spike_;
}
	
double Neuron::setInput(double input1) {
	
		return input_ = input1;
}

double Neuron::getInput() const {
	
	return input_;
}

double Neuron::getNumbSpikes() const {
	
	return num_spikes_;
}

//receive a PSP at a time t and return it after a delay D
void Neuron::setBuffer(unsigned long final_t, double J) {
	
	const auto buff_t_out = ((final_t)%(D+1));
	assert(buff_t_out <= buffer.size());
	buffer[buff_t_out]+=J;
}

vector<size_t> Neuron::getNeighbours() const {
	
	return neighbours_;
}

Neuron::~Neuron() {}
