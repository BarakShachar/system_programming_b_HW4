#include <iostream>
#include "Player.hpp"

namespace coup{
    class Contessa: public Player{
        public:
            Contessa(Game& game, std::string name) : Player(&game, name, "Contessa"){};
            void block(Player& player);
    };
}