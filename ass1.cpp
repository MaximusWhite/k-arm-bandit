// ass1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "agent.h"
#include "environment.h"

const int K = 10;

int main()
{	

	for (int i = 0; i < 100; i++) {

		agent* agnt = new agent(K, 2.0);
		environment* env = new environment(K);
		env->DBG_show_probabilities();

		for (int j = 0; j < 5000; j++) {
			int decision = agnt->choose_action();
			int reward = env->give_reward(decision);
			agnt->check_reward(reward);
		}
	}
}