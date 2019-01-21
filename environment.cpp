#include "pch.h"
#include "environment.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>   
#include <time.h>  

// PUBLIC

environment::environment() {
	environment(10);
}

environment::environment(int k) {
	srand((unsigned int)time(NULL));
	interaction_count = 0;
	this->k = k;
	generate_k_probabilities();
	find_optimal_choice();
}


environment::~environment() {
	delete[] probabilities;
}

void environment::DBG_show_probabilities() {
	std::cout << k << " probabilities: \n" << std::endl;
	for (int i = 0; i < k; i++) {
		if (i == optimal_choice) {
			std::cout << "[[ " << probabilities[i] << " ]]" << "; ";
		} else {
			std::cout << probabilities[i] << "; ";
		}
	}
	std::cout << std::endl;
}

bool environment::give_reward(int decision) {
	return true;
}

// PRIVATE

void environment::generate_k_probabilities() {
	probabilities = new float[k];
	for (int i = 0; i < k; i++) {
		probabilities[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); // probability between 0.0 and 1.0
	}
}

void environment::find_optimal_choice() {
	float max_ind = 0;
	float max = probabilities[0];
	for (int i = 0; i < k; i++) {
		max = probabilities[i] > max ? i : max;
	}
	optimal_choice = max;
}
