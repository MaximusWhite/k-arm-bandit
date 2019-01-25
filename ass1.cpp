// ass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <time.h>  
#include "agent_ucb.h"
#include "environment.h"

const int K = 10;
const int RUNS = 5000;
const float C = 1.0;


int main()
{	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		std::cout << "Run " << i + 1 << " -----------------------------------------" << std::endl;

		agent* agnt = new agent(K, C);
		environment* env = new environment(K);
		env->DBG_show_probabilities();

		for (int j = 0; j < RUNS; j++) {
			int decision = agnt->choose_action(); // agent decides what action to choose based on its experience
			int reward = env->give_reward(decision); // environment evaluates decision and gives reward
			agnt->check_reward(reward); // agent gets reward as feedback

			if (j % 100 == 0 && j != 0) {
				std::cout << "Step " << j << ": Avg. Reward = " << env->get_avg_reward() << "; Optimal actions: " << env->get_optimal_choices_count() 
					<< "(" << (env->get_optimal_choices_count() / (float) RUNS) * 100 << "%)" << std::endl;
			}
		}
		delete agnt;
		delete env;
	}
}