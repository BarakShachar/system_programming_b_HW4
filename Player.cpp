#include <iostream>
#include "Player.hpp"

namespace coup{
    Player::Player(Game* game, std::string name, std::string player_role){
        if (game->get_is_started()){
            throw std::invalid_argument("cant join, already started");
        }
        this->name = name;
        this->game = game;
        this->coins_count = 0;
        this->player_role = player_role;
        this->active = true;
        this->game->add_player(this);
    }
    void Player::income(){
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
        this->coins_count++;
        this->last_act.clear();
        this->last_act.push_back("income");
        this->game->end_turn("income");
    }

    void Player::foreign_aid(){

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
        this->coins_count += 2;
        this->last_act.clear();
        this->last_act.push_back("foreign_aid");
        this->game->end_turn("foreign_aid");
    }

    void Player::coup(Player& player){
        if (this->game->get_player_turn() != this->name){
            throw std::invalid_argument("its not your turn");
        }
        if (this->coins_count < 7){
            throw std::invalid_argument("no enough coins");
        }
        if (!player.get_active()){
            throw std::invalid_argument("this player already eliminated");
        }
        this->coins_count -= 7;
        player.set_active(false);
        this->last_act.clear();
        this->last_act.push_back("coup");
        this->last_act.push_back(player.get_name());
        this->game->end_turn("coup");
    }

    std::string Player::role(){
        return this->player_role;
    }

    int Player::coins(){
        return this->coins_count;
    }

    std::string Player::get_name(){
        return this->name;
    }

    bool Player::get_active(){
        return this->active;
    }

    void Player::set_active(bool activity){
        this->active = activity;
    }

    void Player::update_coins(int sum){
        this->coins_count += sum;
    }

    std::vector<std::string> Player::get_last_action(){
        return this->last_act;
    }
}