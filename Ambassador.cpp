#include <iostream>
#include "Ambassador.hpp"
#include "Player.hpp"

namespace coup{
    Ambassador::Ambassador(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Ambassador";
    }
    void Ambassador::transfer(Player from_player, Player to_player){}
    void Ambassador::block(Player player){}
}