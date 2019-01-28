#include "pch.h"
#include "agent_ri_rp.h"
#include <cmath>
#include <random>
#include <chrono>

agent_ri_rp::agent_ri_rp(int k, float alpha, float beta, bool is_reward_inaction) {
	this->k = k;
	this->alpha = alpha;
	this->beta = is_reward_inaction ? 0.0f : beta;
	total_interactions = 0;
	action_probabilities = new float[k];
	last_action = 0;
	initialize_arrays();
}


agent_ri_rp::~agent_ri_rp() {
	delete[] action_probabilities;
}

void agent_ri_rp::DBG_show_probabilities() {
	std::cout << "Probs: [ ";
	for (int i = 0; i < k; i++) {
		std::cout << action_probabilities[i] << ", ";
	}
	std::cout << " ]" <<  std::endl;
}

int agent_ri_rp::choose_action() {
	// std::cout << "Choosing action " << std::endl;
	// unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::random_device r;
	std::default_random_engine generator{ r() };
  	std::uniform_real_distribution<float> distribution(0.0f,1.0f);
	float dice_roll = distribution(generator);
	float cum_sum = 0;
	total_interactions++;
	for (int i = 0; i < k; i++) {
		cum_sum += action_probabilities[i];
		if (dice_roll <= cum_sum) {
			// std::cout << "DICE ROLL = " << dice_roll << ", ACTION = " << i << std::endl;
			last_action = i;
			return i;
		}
	}

	return 0;
}

void agent_ri_rp::check_reward(int reward) {  // reward either 0 or 1 for this case
	if (reward == 1) {
		for (int i = 0; i < k; i++) {
			if (last_action == i) {
				action_probabilities[i] = action_probabilities[i] + alpha * (1 - action_probabilities[i]); // increase probability for action picked
			} else {
				action_probabilities[i] = (1 - alpha) * action_probabilities[i]; // decrease the rest
			}
		}
	} else {
		for (int i = 0; i < k; i++) {
			if (last_action == i) {
				action_probabilities[i] = (1 - beta) * action_probabilities[i]; // decrease probability for action picked
			} else {
				action_probabilities[i] = (beta / (float)(k - 1)) + (1 - beta) * action_probabilities[i]; // increase probabilities of everything else
			}
		}
	}
}

// PRIVATE

void agent_ri_rp::initialize_arrays() {
	int* tmp = new int[k];
	int rnd_sum = 0;
	for (int i = 0; i < k; i++) {
		tmp[i] = rand() % 50000;
		rnd_sum += tmp[i];
	}

	for (int i = 0; i < k; i++) {
		action_probabilities[i] = tmp[i] / (float) rnd_sum;
	}

	delete[] tmp;
}