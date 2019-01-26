#include "pch.h"
#include "agent_ri_rp.h"
#include <cmath>


agent_ri_rp::agent_ri_rp(int k) {
	this->k = k;
	total_interactions = 0;
	Nt = new int[k];
	Rt = new int[k];
	action_probabilities = new float[k];
	initialize_arrays();
}


agent_ri_rp::~agent_ri_rp() {
	delete[] Nt;
	delete[] action_probabilities;
}

int agent_ri_rp::choose_action() {
	return -1;
}

void agent_ri_rp::check_reward(int reward) {
	
}

// PRIVATE

void agent_ri_rp::initialize_arrays() {
	float* tmp = new float[k];
	for (int i = 0; i < k; i++) {
		Nt[i] = 0;
		tmp[i] = rand();
		Rt[i] = 0;
	}
}

float agent_ri_rp::adjusting_function(float current_quality, int current_count) {
	return -1.0f;
}