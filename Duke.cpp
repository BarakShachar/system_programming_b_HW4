#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup{
    Duke::Duke(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Duke";
    }
    void Duke::tax(){}
    void Duke::block(Player player){}
}