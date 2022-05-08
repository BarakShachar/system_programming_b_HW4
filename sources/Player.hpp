#pragma once
#include <iostream>
#include "Game.hpp"


namespace coup{
    class Game;
    class Player{
        protected:
            Game* game;
            std::string name;
            int coins_count;
            std::string player_role;
            bool active;
            std::vector<std::string> last_act;
        public:
            Player(Game* game, std::string name, std::string player_role);
            void income();
            void foreign_aid();
            void coup(Player& player);
            std::string role();
            int coins() const;
            std::string get_name();
            bool get_active() const;
            void set_active(bool activity);
            void update_coins(int sum);
            std::vector<std::string> get_last_action();
    };
}