#pragma once

class agent {
    public:
        virtual int choose_action() = 0;
        virtual void check_reward(int reward) = 0;
};