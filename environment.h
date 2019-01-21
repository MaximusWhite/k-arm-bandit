#pragma once
#include "agent.h"
class environment {
	public:
		// FUNCTIONS
		environment();
		environment(int k);
		~environment();
		bool give_reward(int decision);

		// DBG - debugging functions 
		void DBG_show_probabilities();
	private:
		// VARS
		int k;
		int interaction_count;
		int optimal_choice;
		float* probabilities;

		// FUNCTIONS
		void generate_k_probabilities();
		void find_optimal_choice();

};

