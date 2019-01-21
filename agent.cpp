#include "pch.h"
#include "agent.h"

// PUBLIC

agent::agent(int k, float c) {
	this->k = k;
	this->c = c;
	Nt = new float[k];
	Qt = new float[k];
	initialize_choice_counts();
	initialize_choice_qualities();
}


agent::~agent() {
	delete[] Nt;
	delete[] Qt;
}

int agent::choose_action() {
	return 1;
}

void agent::check_reward(bool reward) {

}

// PRIVATE

void agent::initialize_choice_counts() {
	for (int i = 0; i < k; i++) {
		Nt[i] = 0.0f;
	}
}

void agent::initialize_choice_qualities() {
	for (int i = 0; i < k; i++) {
		Qt[i] = 0.0f;
	}
}



