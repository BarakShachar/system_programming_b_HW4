#include <iostream>
#include "Contessa.hpp"
#include "Player.hpp"

namespace coup{
    Contessa::Contessa(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Contessa";
    }
    void Contessa::block(Player player){}
}