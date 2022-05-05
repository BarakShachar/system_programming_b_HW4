#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"

namespace coup{
    void Captain::block(Player& player){
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.role() != "Captain" || player.get_last_action()[0] != "steal"){
            throw std::invalid_argument("cant block this");
        }
        player.update_coins(-2);
        Player* stolen_player = this->game->get_player(player.get_last_action()[2]);
        stolen_player->update_coins(2); 
    }
    
    void Captain::steal(Player& player){
        if (this->game->get_player_turn() != this->name){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.coins()<2 || !player.get_active()){
            throw std::invalid_argument("cant steal from this player");
        }
        this->coins_count += 2;
        player.update_coins(-2);
        this->last_act.clear();
        this->last_act.push_back("steal");
        this->game->end_turn("steal");
    }
}