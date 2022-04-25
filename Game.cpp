#include <iostream>
#include <vector>
#include "Game.hpp"

namespace coup{
    std::string Game::turn(){
        return "a";
    }
    std::vector<std::string> Game::players(){
        return this->players_list;
    }
    std::string Game::winner(){
        return "a";
    }

}