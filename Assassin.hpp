#include <iostream>
#include "Player.hpp"

namespace coup{
    class Assassin: public Player{
        public:
            Assassin(Game game, std::string name);
            void coup(Player player);
    };
}