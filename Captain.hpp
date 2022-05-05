#include <iostream>
#include "Player.hpp"

namespace coup{
    class Captain: public Player{
        public:
            Captain(Game& game, std::string name) : Player(&game, name, "Captain"){};
            void block(Player& player);
            void steal(Player& player);
    };
}