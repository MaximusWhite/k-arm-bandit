#include "pch.h"
#include "agent.h"
#include <cmath>

// PUBLIC

agent::agent(int k, float c) {
	this->k = k;
	this->c = c;
	total_interactions = 0;
	Nt = new int[k];
	Qt = new float[k];
	initialize_choice_counts();
	initialize_choice_qualities();
}


agent::~agent() {
	delete[] Nt;
	delete[] Qt;
}

int agent::choose_action() {
	float max = adjusting_function(Qt[0], Nt[0] == 0 ? 1 : Nt[0]);
	int max_ind = 0;
	for (int i = 0; i < k; i++) {
		int n = Nt[i] == 0 ? 1 : Nt[i];
		float new_q = adjusting_function(Qt[i], n);

		if (new_q > max) {
			max = new_q;
			max_ind = i;
		}

		Qt[i] = new_q;
	}

	Nt[max_ind] += 1;
	last_action = max_ind;
	return max_ind;
}

void agent::check_reward(bool reward) {

}

// PRIVATE

void agent::initialize_choice_counts() {
	for (int i = 0; i < k; i++) {
		Nt[i] = 0;
	}
}

void agent::initialize_choice_qualities() {
	for (int i = 0; i < k; i++) {
		Qt[i] = 0.0f;
	}
}

float agent::adjusting_function(float current_quality, int current_count) {
	return (current_quality + c * sqrt(log(total_interactions == 0 ? 1 : total_interactions) / (float)current_count));
}

