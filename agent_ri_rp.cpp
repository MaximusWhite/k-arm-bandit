#include "pch.h"
#include "agent_ri_rp.h"
#include <cmath>


agent_ri_rp::agent_ri_rp() {
	this->k = k;
	this->c = c;
	total_interactions = 0;
	Nt = new int[k];
	Rt = new int[k];
	Qt = new float[k];
	initialize_arrays();
}


agent_ri_rp::~agent_ri_rp() {
	delete[] Nt;
	delete[] Qt;
}

int agent_ri_rp::choose_action() {
	float max = adjusting_function(Qt[0], Nt[0] == 0 ? 1 : Nt[0]);
	int max_ind = 0;
	for (int i = 0; i < k; i++) {
		int n = Nt[i] == 0 ? 1 : Nt[i];
		float new_q = adjusting_function(Qt[i], n);

		if (new_q > max) {
			max = new_q;
			max_ind = i;
		}

	}

	Nt[max_ind] += 1;
	total_interactions++;
	last_action = max_ind;
	return max_ind;
}

void agent_ri_rp::check_reward(int reward) {
	Qt[last_action] += (reward - Qt[last_action]) / (float)Nt[last_action];
	Rt[last_action] = reward;
}

// PRIVATE

void agent_ri_rp::initialize_arrays() {
	for (int i = 0; i < k; i++) {
		Nt[i] = 0;
		Qt[i] = 0.0f;
		Rt[i] = 0;
	}
}

float agent_ri_rp::adjusting_function(float current_quality, int current_count) {
	return (current_quality + c * sqrt(log(total_interactions == 0 ? 1 : total_interactions) / (float)current_count));
}