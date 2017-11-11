#include "Neuron.hpp"
#include "constants.hpp"
#include "gtest/gtest.h"

using namespace std;

TEST (TestNeuron1, Input) 
{
	Neuron n;
	n.setInput(1);
	
	//First update test for one step
	n.update(1, 0);
	EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0)), n.getMembPot());
	
	//Test of the update after a lot of updates
	n.update(10000, 0);
	
	//expected value : the membrane potential tend to 20 but never reach it => no spike
	EXPECT_EQ(0, n.getNumbSpikes());
	EXPECT_GT(1E-3, fabs(19.999 - n.getMembPot()));
	
	//if the external input is 0, the membrane potential should
	//tend to 0
	n.setInput(0.0);
	
	n.update(2000, 0);
	EXPECT_NEAR(0, n.getMembPot(), 1e-3);
}

TEST (TestNeuron2, NoInput)
{
	Neuron n;
	n.setInput(0);
	n.setMembPot(20);
	
	//After we set a defined potential, the potential will decrease without external current
	n.update(2000, 0);
	EXPECT_NEAR(0, n.getMembPot(), 1e-3);
	
}

TEST (TestNeuron3, Simulation)
{
	Neuron n;
	n.setInput(1.01);
	n.update(4000, 0);
	EXPECT_EQ(4, n.getNumbSpikes());
}

TEST (TestNeuron4, SpikeTimes)
{
	Neuron n1;
	n1.setInput(1.01);
	
	//Time of the first spike => the number of spikes is increased by 1
	n1.update(924, 0);
	EXPECT_EQ(0, n1.getNumbSpikes());
	
	//when the neuron spikes => membrane potential is reset to 0
	n1.update(1, 0);
	EXPECT_EQ(1, n1.getNumbSpikes());
	EXPECT_EQ(0.0, n1.getMembPot());
}

TEST (twoNeurons, NoJSpikes)
{	
	Neuron n1, n2;
	int Delay =15;
	n1.setInput(1.01);
	
	//there is no spike => the first neuron doesn't send a synaptic input J
	for(int i(0); i<925+Delay; ++i) 
	{
		if(n1.update(1, 0))
		{
			n2.update(1, 0);
			EXPECT_EQ(0.0, n1.getMembPot());
		}
	}
}	

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

