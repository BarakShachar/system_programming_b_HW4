#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    Game::Game(){
        this->player_turn = 0;
        this->active = true;
        this->is_started = false;
    }

    std::string Game::turn(){
        return this->players_list[this->player_turn]->get_name();
    }

    std::vector<std::string> Game::players(){
        std::vector<std::string> players_names;
        for(Player* player : this->players_list){
            if (player->get_active()){
                players_names.push_back(player->get_name());
            }
	    }
        return players_names;
    }

    std::string Game::winner(){
        if (!this->is_started || this->active){
            throw std::invalid_argument("game hasnt finished yet");
        }
        std::string player_won;
        for(Player* player : this->players_list){
            if (player->get_active()){
                player_won = player->get_name();
            }
	    }
        return player_won;
    }

    void Game::add_player(Player* player){
        this->players_list.push_back(player);
    }

    std::string Game::get_player_turn(){
        return this->players_list[this->player_turn]->get_name();
    }

    void Game::end_turn(std::string const &act){
        if (act == "coup"){
            int active_players = 0;
            for (Player* player : this->players_list){
                if (player->get_active()){
                    active_players++;
                }
            }
            if (active_players == 1){
                this->active = false;
                return;
            }
        }
        this->player_turn++;
        this->player_turn = this->player_turn % this->players_list.size();
        while(!this->players_list[this->player_turn]->get_active()){
            this->player_turn++;
            this->player_turn = this->player_turn % this->players_list.size();
        }
    }

    bool Game::get_is_started() const{
        return this->is_started;
    }

    void Game::start_game(){
        this->is_started = true;
    }

    Player* Game::get_player(std::string const &name){
        for (Player* player : this->players_list){
            if (player->get_name() == name){
                return player;
            }
        }
        return NULL;
    }

    int Game::players_in_game(){
        return this->players_list.size();
    }
}