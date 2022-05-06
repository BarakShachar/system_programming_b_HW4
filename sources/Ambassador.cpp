#include <iostream>
#include "Ambassador.hpp"
#include "Player.hpp"

namespace coup{
    void Ambassador::transfer(Player& from_player, Player& to_player){
        if (this->game->get_player_turn() != this->name){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (from_player.coins() == 0){
            throw std::invalid_argument("cant transfer from this player");
        }
        from_player.update_coins(-1);
        to_player.update_coins(1);
        this->last_act.clear();
        this->last_act.push_back("transfer");
        this->last_act.push_back(from_player.get_name());
        this->last_act.push_back(to_player.get_name());
        this->game->end_turn("transfer");
    }

    void Ambassador::block(Player& player){
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.role() != "Captain" || player.get_last_action()[0] != "steal"){
            throw std::invalid_argument("cant block this");
        }
        player.update_coins(-2);
        Player* stolen_player = this->game->get_player(player.get_last_action()[1]);
        stolen_player->update_coins(2); 
        this->last_act.clear();
    }
}