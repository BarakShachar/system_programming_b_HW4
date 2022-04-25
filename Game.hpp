#include <iostream>
#include <vector>
#pragma once

namespace coup{
    class Game{
        private:
            std::vector<std::string> players_list;
            int player_turn;
            bool active;
            std::vector<std::string> last_act;
        public:
            std::string turn();
            std::vector<std::string> players();
            std::string winner();
    };
}