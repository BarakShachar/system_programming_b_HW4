#include <iostream>
#include <vector>
#include "Player.hpp"
#pragma once

namespace coup{
    class Game{
        private:
            std::vector<player> players_list;
            size_t player_turn;
            bool active;
            bool is_started:
        public:
            Game();
            std::string turn();
            std::vector<std::string> players();
            std::string winner();
    };
}