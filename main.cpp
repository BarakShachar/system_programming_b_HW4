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
	Captain captain{game_1, "player 4"};
	Contessa contessa{game_1, "player 5"};

	vector<string> players = game_1.players();
    cout << "***********************" << endl;
	cout << "Game.players() function" << endl;
	for(string name : players){
		cout << name << endl;
	}
	cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
	cout << "Game.turn() function" << endl;
	cout << game_1.turn() << endl;
	cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
	cout << "Game.winner() function" << endl;
    try{
        cout << game_1.winner() << endl;
    }
    catch (const std::exception &exc){
        // catch anything thrown within try block that derives from std::exception
        std::cerr << exc.what() << endl;
    }
    cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
    cout << "Player.role() function" << endl;
    cout << "duke.role() output: " << duke.role() << endl;
    cout << "***********************" << endl << endl;

    cout << "Player.coins() function" << endl;
    cout << "duke.coins() output: " << duke.coins() << endl;
    cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
    cout << "Player.income() function" << endl;
    duke.income();
    cout << "duke.coins() (after income) output: " << duke.coins() << endl;
    cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
    cout << "Player.foreign_aid() function" << endl;
    assassin.foreign_aid();
    cout << "assassin.coins() (after foreign_aid) output: " <<assassin.coins() << endl;
    cout << "***********************" << endl << endl;

    //add each player 4 coins
    for (int i=0; i<4; i++){
        ambassador.income();
        captain.income();
        contessa.income();
        duke.income();
        assassin.income();
    }
    //duke have 5
    //assassin 6
    //ambassador 4
    //captain 4
    //contessa 4

    cout << "***********************" << endl;
    cout << "Ambassador.transfer() function" << endl;
    cout << "duke.coins() output: " << duke.coins() << endl;
    cout << "assassin.coins() output: " << assassin.coins() << endl;
    ambassador.transfer(assassin, duke);
    cout << "duke.coins() after transfer output: " << duke.coins() << endl;
    cout << "assassin.coins() after trnsfer output: " << assassin.coins() << endl;
    cout << "***********************" << endl << endl;

    //duke have 6
    //assassin 5
    //ambassador 4
    //captain 4
    //contessa 4

    cout << "***********************" << endl;
    cout << "captain.steal() function" << endl;
    cout << "captain.coins() output: " << captain.coins() << endl;
    cout << "assassin.coins() output: " << assassin.coins() << endl;
    captain.steal(assassin);
    cout << "duke.coins() after steal output: " << captain.coins() << endl;
    cout << "assassin.coins() after steal output: " << assassin.coins() << endl;
    cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
    cout << "Ambassador.block() function to block captain" << endl;
    ambassador.block(captain);
    cout << "captain.coins() after captain block output: " << captain.coins() << endl;
    cout << "assassin.coins() after captain clock output: " << assassin.coins() << endl;
    cout << "***********************" << endl << endl;


    contessa.income();
    //duke have 6
    //assassin 5
    //ambassador 4
    //captain 4
    //contessa 5

    cout << "***********************" << endl;
    cout << "Duke.tax() function" << endl;
    cout << "duke.coins() output: " << duke.coins() << endl;
    duke.tax();
    cout << "duke.coins() after tax output: " << duke.coins() << endl;
    cout << "***********************" << endl << endl;
    //duke have 9
    //assassin 5
    //ambassador 4
    //captain 4
    //contessa 5
    cout << "***********************" << endl;
    cout << "Assassin.coup() function with less then 7 coins" << endl;
    cout << "assassin.coins() output: " << assassin.coins() << endl;
    assassin.coup(duke);
    cout << "assassin.coins() after coup output: " << assassin.coins() << endl;
    cout << "active players: (player 1 is couped)" << endl;
    vector<string> players1 = game_1.players();
	for(string name : players1){
		cout << name << endl;
	}
    cout << "***********************" << endl << endl;

    cout << "***********************" << endl;
    cout << "Contessa.block() function to block assassin" << endl;
    contessa.block(assassin);
    cout << "active players: (player 1 is back)" << endl;
    vector<string> players2 = game_1.players();
	for(string name : players2){
		cout << name << endl;
	}
    cout << "***********************" << endl << endl;
    //duke have 9
    //assassin 2
    //ambassador 4
    //captain 4
    //contessa 5
    ambassador.foreign_aid();

    cout << "***********************" << endl;
    cout << "Ambassador.block() function to block captain" << endl;
    cout << "captain.coins() output: " << captain.coins() << endl;
    captain.foreign_aid();
    cout << "captain.coins() after foreign_aid output: " << captain.coins() << endl;
    duke.block(captain);
    cout << "captain.coins() after duke block output: " << captain.coins() << endl;
    cout << "***********************" << endl << endl;
    contessa.foreign_aid();    
    //duke have 9
    //assassin 2
    //ambassador 6
    //captain 4
    //contessa 7
    duke.coup(captain);
    assassin.income();
    ambassador.income();
    contessa.coup(duke);
    assassin.coup(contessa);
    ambassador.coup(assassin);

    cout << "***********************" << endl;
    cout << "Game.winner() function" << endl;
    cout << "And the winner is: " << game_1.winner() << endl;
    cout << "***********************" << endl << endl;

}