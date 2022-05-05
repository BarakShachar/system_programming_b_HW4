#include <iostream>
#include "Assassin.hpp"
#include "Player.hpp"

namespace coup{
    void Assassin::coup(Player& player){
        if (this->game->get_player_turn() != this->name){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (!player.get_active()){
            throw std::invalid_argument("this player already eliminated");
        }
        if (this->coins_count < 3){
            throw std::invalid_argument("no enough coins");
        }
        if (this->coins_count >= 7){
            Player::coup(player);
        }
        else{
            this->coins_count -= 3;
            player.set_active(false);
            this->last_act.clear();
            this->last_act.push_back("coup");
            this->last_act.push_back(player.get_name());
            this->last_act.push_back("special");
            this->game->end_turn("coup");
        }
    }
}