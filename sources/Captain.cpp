#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"

namespace coup{
    void Captain::block(Player& player){
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.role() != "Captain" || player.get_last_action().empty() || player.get_last_action()[0] != "steal"){
            throw std::invalid_argument("cant block this");
        }
        Player* stolen_player = this->game->get_player(player.get_last_action()[1]);
        if (player.get_last_action()[2] != "2"){
            player.update_coins(-2);
            stolen_player->update_coins(2); 
        }
        else if (player.get_last_action()[2] != "1"){
            player.update_coins(-1);
            stolen_player->update_coins(1); 
        }
    }
    
    void Captain::steal(Player& player){
        if (this->game->get_player_turn() != this){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (!player.get_active()){
            throw std::invalid_argument("cant steal from this player");
        }
        this->last_act.clear();
        this->last_act.push_back("steal");
        this->last_act.push_back(player.get_name());
        if (player.coins()>=2){
            this->coins_count += 2;
            player.update_coins(-2);
            this->last_act.push_back("2");
        }
        else if (player.coins()==1){
            this->coins_count += 1;
            player.update_coins(-1);
            this->last_act.push_back("1");
        }
        else{
            this->last_act.push_back("0");
        }
        this->game->end_turn("steal");
    }
}