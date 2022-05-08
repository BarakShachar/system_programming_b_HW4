#include "doctest.h"
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include <vector>

using namespace coup;
using namespace std;

TEST_CASE("Game constructor"){
    CHECK_NOTHROW(Game game_1{});
}


TEST_CASE("Roles constructor"){
    Game game_1{};
    CHECK_NOTHROW(Duke duke(game_1, "Moshe"));
	CHECK_NOTHROW(Assassin assassin(game_1, "Yossi"));
	CHECK_NOTHROW(Ambassador ambassador(game_1, "Meirav"));
	CHECK_NOTHROW(Captain captain(game_1, "Reut"));
	CHECK_NOTHROW(Contessa contessa(game_1, "Gilad"));
}

TEST_CASE("game functions"){
    vector<string> Players {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    vector<string> game_players = game_1.players();
    CHECK(game_players.size() == 5);
    for (size_t i = 0; i<game_players.size(); i++){
        CHECK(Players[i] == game_players[i]);
    }
    CHECK(game_1.turn() == "Moshe");
    duke.income();
    CHECK(game_1.turn() == "Yossi");
    assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();
    CHECK(game_1.turn() == "Moshe");
    CHECK_THROWS(game_1.winner());
}

TEST_CASE("player functions"){
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK(duke.coins() == 0);
    duke.income();
    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 0);
    assassin.foreign_aid();
    CHECK(assassin.coins() == 2);
    CHECK(assassin.role() == "Assassin");
    CHECK_NOTHROW(ambassador.block(assassin));
    CHECK(assassin.coins() == 0);
    CHECK_THROWS(captain.block(duke));
}

TEST_CASE("Game winner + coup"){
    Game game_1{};
    Assassin assassin{game_1, "Yossi"};
    CHECK_THROWS(assassin.income());
	Ambassador ambassador{game_1, "Meirav"};
    assassin.foreign_aid();
    CHECK_THROWS(ambassador.coup(assassin));
    ambassador.income();
    CHECK_THROWS(ambassador.income());
    assassin.income();
    ambassador.income();
    CHECK_NOTHROW(assassin.coup(ambassador));
    CHECK(game_1.winner() == "Yossi");
    CHECK_THROWS(ambassador.income());
}

TEST_CASE("too much players"){
    Game game_1{};
	Duke duke{game_1, "player 1"};
	Assassin assassin{game_1, "player 2"};
	Ambassador ambassador{game_1, "player 3"};
	Captain captain{game_1, "player 4"};
	Contessa contessa{game_1, "player 5"};
    Contessa contessa1{game_1, "player 6"};
    CHECK_THROWS(Contessa contessa2(game_1, "player 7"));
}

TEST_CASE("too few players"){
    Game game_1{};
	Duke duke{game_1, "player 1"};
    CHECK_THROWS(duke.income());
}
