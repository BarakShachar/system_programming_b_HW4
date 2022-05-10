#include <iostream>
#include "Contessa.hpp"
#include "Player.hpp"

namespace coup{
    void Contessa::block(Player& player){
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (player.role() != "Assassin" || player.get_last_action().empty() || player.get_last_action()[0] != "coup"){
            throw std::invalid_argument("Contessa can only block assassin coup");
        }
        if (player.get_last_action().size() != 3){
            throw std::invalid_argument("it was a normal coup, cant block this");
        }
        Player* eliminated_player = this->game->get_player(player.get_last_action()[1]);
        eliminated_player->set_active(true);
    }
}