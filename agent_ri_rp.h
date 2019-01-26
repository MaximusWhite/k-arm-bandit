#pragma once
class agent_ri_rp {
	public:
		agent_ri_rp(int k);
		~agent_ri_rp();

		int choose_action();
		void check_reward(int reward);
	private:
		// VARS
		int k;
		int total_interactions;
		int last_action;
		int* Nt;    // number of times arm 1..k was chosen 
		int* Rt;

		// float c;
		float alpha;
		float beta;
		float* action_probabilities;    // probability of picking each action

		// FUNCTIONS
		void initialize_arrays();
		float adjusting_function(float current_quality, int current_count);
};

