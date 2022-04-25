#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"

namespace coup{
    Assassin::Assassin(Game game, std::string name){
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = "Assassin";
    }
    void Assassin::coup(Player player){}
}