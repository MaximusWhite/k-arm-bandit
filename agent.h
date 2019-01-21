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
		float c;
		float* Qt;    // quality of each arm 1..k
		float* Nt;    // number of times arm 1..k was chosen 
		
		// FUNCTIONS
		void initialize_choice_counts();
		void initialize_choice_qualities();
		int argmax();
		void record_reward();

};