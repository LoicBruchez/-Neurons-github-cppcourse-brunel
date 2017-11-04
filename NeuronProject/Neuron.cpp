#include "Neuron.hpp"
#include "constants.hpp"
#include <vector>

using namespace std;

Neuron::Neuron(double memb_pot, int int_clock) {
	
	memb_pot_ = memb_pot;
	int_clock_ = int_clock;
	buffer.resize(D+1, 0.0);
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

int Neuron::getNumbSpikes() const {
	
	return num_spikes_;
}


vector<size_t> Neuron::getNeighbours() const {
	
	return neighbours_;
}

void Neuron::setInput(double input1) {
	
		input_ = input1;
}

void Neuron::connectTwoNeurons(size_t val, double w) {
		
		neighbours_.push_back(val);
		weights.push_back(w);
}

//function that update membrane potential. It's a boolean because it return if there is a spike or not
bool Neuron::update(double steps) {
		
	const auto buff_t_in = (int_clock_ % (D+1));
	spike_ = false;
	
	for(size_t i(0); i < steps; ++i) {
		
		if(memb_pot_ > theta) {
			
			time_spikes_ = int_clock_;
			spike_ = true;
			++num_spikes_;
			memb_pot_ = 0.0;
			
			for(size_t neighbour(0); neighbour < neighbours_.size(); ++neighbour) {
				
				const auto buff_t_out = ((int_clock_+D)%(D+1));
				assert(buff_t_out <= buffer.size());
				buffer[buff_t_out]+= weights[neighbour];
			}
		} 	
		if(((int_clock_-time_spikes_) < t_ref) and time_spikes_ > 0) {
			
			memb_pot_ = 0;
			buffer[buff_t_in] = 0.0;
		} else {
			
			static random_device rd;
			static mt19937 gen(rd());
			static poisson_distribution<> noise(etha);
			
			const auto buff_t_in = (int_clock_ % (D+1));
			syn_input = buffer[buff_t_in];
			buffer[buff_t_in] = 0.0;
			memb_pot_ = (((c1*memb_pot_) + (input_ * c2))+ syn_input + noise(gen));
		}
		int_clock_+= step;
	}
	return spike_;
}

Neuron::~Neuron() {}
