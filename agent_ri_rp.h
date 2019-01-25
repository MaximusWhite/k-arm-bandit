#pragma once
class agent_ri_rp {
	public:
		agent_ri_rp();
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

		float c;
		float* Qt;    // quality of each arm 1..k

		// FUNCTIONS
		void initialize_arrays();
		float adjusting_function(float current_quality, int current_count);
};

