#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"

namespace coup{
    void Duke::tax(){
        if (this->game->get_player_turn() != this->name){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started() && this->game->players().size()==1){
            throw std::invalid_argument("you cant play by yourself");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (this->coins_count >= 10){
            throw std::invalid_argument("you must do a coup");
        }
        this->coins_count += 3;
        this->last_act.clear();
        this->last_act.push_back("tax");
        this->game->end_turn("tax");        
    }

    void Duke::block(Player& player){
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.get_last_action()[0] != "foreign_aid"){
            throw std::invalid_argument("cant block this");
        }
        player.update_coins(-2); 
    }
}