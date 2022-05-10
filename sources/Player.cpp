#include <iostream>
#include "Player.hpp"

int const MAX_PLAYERS = 6;
int const MAX_COINS_IN_HAND = 10;
int const COINS_FOR_COUP = 7;

namespace coup{
    Player::Player(Game* game, std::string name, std::string player_role){
        if (game->get_is_started()){
            throw std::invalid_argument("cant join, already started");
        }
        if (game->players_in_game() == MAX_PLAYERS){
            throw std::invalid_argument("too much players");
        }
        this->name = std::move(name);
        this->game = game;
        this->coins_count = 0;
        this->player_role = std::move(player_role);
        this->active = true;
        this->game->add_player(this);
    }
    void Player::income(){
        if (this->game->get_player_turn() != this){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started() && this->game->players().size()==1){
            throw std::invalid_argument("you cant play by yourself");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (this->coins_count >= MAX_COINS_IN_HAND){
            throw std::invalid_argument("you must do a coup");
        }
        this->coins_count++;
        this->last_act.clear();
        this->last_act.push_back("income");
        this->game->end_turn("income");
    }

    void Player::foreign_aid(){

        if (this->game->get_player_turn() != this){
            throw std::invalid_argument("its not your turn");
        }
        if (!this->game->get_is_started() && this->game->players().size()==1){
            throw std::invalid_argument("you cant play by yourself");
        }
        if (!this->game->get_is_started()){
            this->game->start_game();
        }
        if (this->coins_count >= MAX_COINS_IN_HAND){
            throw std::invalid_argument("you must do a coup");
        }
        this->coins_count += 2;
        this->last_act.clear();
        this->last_act.push_back("foreign_aid");
        this->game->end_turn("foreign_aid");
    }

    void Player::coup(Player& player){
        if (this->game->get_player_turn() != this){
            throw std::invalid_argument("its not your turn");
        }
        if (this->coins_count < COINS_FOR_COUP){
            throw std::invalid_argument("no enough coins");
        }
        if (!player.get_active()){
            throw std::invalid_argument("this player already eliminated");
        }
        this->coins_count -= COINS_FOR_COUP;
        player.set_active(false);
        this->last_act.clear();
        this->last_act.push_back("coup");
        this->last_act.push_back(player.get_name());
        this->game->end_turn("coup");
    }

    std::string Player::role(){
        return this->player_role;
    }

    int Player::coins() const{
        return this->coins_count;
    }

    std::string Player::get_name(){
        return this->name;
    }

    bool Player::get_active() const{
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