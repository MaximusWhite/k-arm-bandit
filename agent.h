#pragma once
class agent {
	public:
		agent(int k, float c);
		~agent();
		int choose_action();
		void check_reward(bool reward);
	private:
		// VARS
		int k;
		int total_interactions;
		int last_action;
		int* Nt;    // number of times arm 1..k was chosen 

		float c;
		float* Qt;    // quality of each arm 1..k
		
		// FUNCTIONS
		void initialize_choice_counts();
		void initialize_choice_qualities();
		float adjusting_function(float current_quality, int current_count);
		void record_reward();

};