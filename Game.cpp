#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    Game::Game(){
        this->player_turn = 0;
        this->active = true;
        this->is_started = false;
        this->player_list = std::vector<player>;
    }
    std::string Game::turn(){
        return this->player_list[this->player_turn];
    }
    std::vector<std::string> Game::players(){
        return this->players_list;
    }
    std::string Game::winner(){
        if (!this->is_started){
            throw std::invalid_argument("game hasnt finished yet");
        }
        std::string player_won = "";
        for(Player player : this->player_list){
	    }
    }
}