#pragma once
#include <map>

class agent_ri_rp {
	public:
		agent_ri_rp(int k, float alpha, float beta, bool is_reward_inaction);
		~agent_ri_rp();

		int choose_action();
		void check_reward(int reward);

		void DBG_show_probabilities();
	private:
		// VARS
		int k;
		int total_interactions;
		int last_action;

		// float c;
		float alpha;
		float beta;
		float* action_probabilities;    // probability of picking each action

		// FUNCTIONS
		void initialize_arrays();
};

