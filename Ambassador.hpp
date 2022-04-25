#include <iostream>
#include "Player.hpp"

namespace coup{
    class Ambassador: public Player{
        public:
            Ambassador(Game game, std::string name);
            void transfer(Player from_player, Player to_player);
            void block(Player player);
    };
}