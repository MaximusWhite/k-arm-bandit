#pragma once
#include "agent.h"
class environment {
	public:
		// FUNCTIONS
		environment();
		environment(int k);
		~environment();
		bool give_reward(int decision);
		int get_optimal_choices_count();
		float get_avg_reward();

		// DBG - debugging functions 
		void DBG_show_probabilities();
	private:
		// VARS
		int k;
		int interaction_count;
		int optimal_choice;
		int optimal_count;
		int reward_given;

		float* probabilities;

		// FUNCTIONS
		void generate_k_probabilities();
		void find_optimal_choice();

};

