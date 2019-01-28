// ass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <time.h>  
#include "agent_ucb.cpp"
#include "environment.cpp"
#include "agent_ri_rp.cpp"

const int K = 10;
const int RUNS = 5000;
const float C = 1.0;


int main()
{	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 1; i++) {
		std::cout << "Run " << i + 1 << " -----------------------------------------" << std::endl;

		// agent* agnt = new agent(K, C);
		agent_ri_rp* agnt = new agent_ri_rp(K, 0.5, 0.5, false);
		environment* env = new environment(K);
		env->DBG_show_probabilities();

		for (int j = 0; j < RUNS; j++) {
			int decision = agnt->choose_action(); // agent decides what action to choose based on its experience
			bool reward = env->give_reward(decision); // environment evaluates decision and gives reward
			agnt->check_reward(reward); // agent gets reward as feedback

			if (j % 100 == 0 && j != 0) {
				// agnt->DBG_show_probabilities();
				std::cout << "Step " << j << ": Avg. Reward = " << env->get_avg_reward() << "; Optimal actions: " << env->get_optimal_choices_count() 
					<< "(" << (env->get_optimal_choices_count() / (float) (j+1)) * 100 << "%)" << " - " << decision << std::endl;
			}
		}
		delete agnt;
		delete env;
	}
}