#include <iostream>
#include "Player.hpp"

namespace coup{
    class Assassin: public Player{
        public:
            Assassin(Game& game, std::string name) : Player(&game, name, "Assassin"){};
            void coup(Player& player);
    };
}