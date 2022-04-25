#include <iostream>
#include "Game.hpp"
#pragma once

namespace coup{
    class Player{
        protected:
            Game game;
            std::string name;
            int coins_count;
            std::string player_role;
        public:
            void income();
            void foreign_aid();
            void coup(Player);
            std::string role();
            int coins();
    };
}