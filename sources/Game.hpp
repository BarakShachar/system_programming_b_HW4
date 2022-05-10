#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"

namespace coup{
    class Player;
    class Game{
        private:
            std::vector<Player*> players_list;
            size_t player_turn;
            bool active;
            bool is_started;
        public:
            Game();
            std::string turn();
            std::vector<std::string> players();
            std::string winner();
            void add_player(Player* player);
            Player* get_player_turn();
            void end_turn(std::string const &act);
            bool get_is_started() const;
            void start_game();
            Player* get_player(std::string const &name);
            int players_in_game();
    };
}