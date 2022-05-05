#include <iostream>
#include "Player.hpp"

namespace coup{
    class Duke: public Player{
        public:
            Duke(Game& game, std::string name) : Player(&game, name, "Duke"){};
            void tax();
            void block(Player& player);
    };
}