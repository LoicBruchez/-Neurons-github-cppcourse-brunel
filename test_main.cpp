#include "Neuron.hpp"
#include "constants.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST (TestNeuron, Input) {
	
	Neuron n(0,0);
	n.setInput(1.0);
	
	//First update test for one step
	n.update(1);
	EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)), n.getMembPot());
	
	//Test of the update after a lot of updates
	n.update(10000);
	//expected value : the membrane potential tend to 20 but never reach it
	//=> no spike
	EXPECT_EQ(0, n.getNumbSpikes());
	EXPECT_GT(1E-3, fabs(19.999 - n.getMembPot()));
	
	//if the external input is 0, the membrane potential should
	//tend to 0
	n.setInput(0.0);
	
	n.update(2000);
	EXPECT_NEAR(0, n.getMembPot(), 1e-3);
}

TEST (TestNeuron, SpikeTimes) {

	Neuron n1(0,0);
	n1.setInput(1.01);
	
	n1.update(924);
	EXPECT_EQ(0, n1.getNumbSpikes());
	n1.update(1);
	EXPECT_EQ(1, n1.getNumbSpikes());
	EXPECT_EQ(0.0, n1.getMembPot());
	
	
	n1.update(933);
	EXPECT_EQ(1, n1.getNumbSpikes());
	n1.update(1);
	EXPECT_EQ(2, n1.getNumbSpikes());
}

TEST (twoNeurons, NoJSpikes) {
	
		Neuron n1(0,0), n2(0,0);
		int Delay =15;
		n1.setInput(1.01);
		
		for(int i(0); i<925+Delay; ++i) {
			
			if(n1.update(1)){
			
				n2.update(1);
				EXPECT_EQ(0.0, n1.getMembPot());
			}
			n2.update(1);
		}
		EXPECT_EQ(0.1, n2.getMembPot());
}	

int main(int argc, char **argv) {
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
