/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main() {

	Game game_1{};


	Duke duke{game_1, "player 1"};
	Assassin assassin{game_1, "player 2"};
	Ambassador ambassador{game_1, "player 3"};
	Captain captain{game_1, "player 3"};
	Contessa contessa{game_1, "player 3"};

	vector<string> players = game_1.players();
	cout << "Game.players() function" << endl;
	for(string name : players){
		cout << name << endl;
	}
	cout << "***********************" << endl;

	cout << "Game.turn() function" << endl;
	cout << game_1.turn() << endl;
	cout << "***********************" << endl;

	cout << "Game.turn() function" << endl;
	// throws no exceptions
	duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();

	// throws exception, it is duke's turn now
	try{
		assassin.income();
	}catch (const std::exception &e){
		std::cerr << e.what() << '\n';
	}
	duke.income();
	assassin.foreign_aid();

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	try{
		captain.block(duke);
	}catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	cout << duke.coins() << endl; // prints 2
	cout << assassin.coins() << endl; // prints 3

	// throws exception, the last operation assassin performed
	// is foreign aid, which cannot be blocked by contessa
	try{
		contessa.block(assassin);
	}catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	duke.block(assassin);
	cout << assassin.coins() << endl; // prints 1

	ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
	captain.foreign_aid();
	contessa.foreign_aid();

	duke.tax();
	assassin.income();
	ambassador.foreign_aid();
	captain.steal(contessa);
	contessa.foreign_aid();

	duke.tax();
	// no exception, assassin can coup with only 3 coins
	assassin.coup(duke);

	players = game_1.players();
	/*
		prints:
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string name : players)
	{
		cout << name << endl;
	}

	contessa.block(assassin);

	players = game_1.players();
	/*
		prints:
		Moshe
		Yossi
		Meirav
		Reut
		Gilad
	*/
	for (string name : players)
	{
		cout << name << endl;
	}
}

