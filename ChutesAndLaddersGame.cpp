//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

// TODO: implement the constructor with all your team members
// constructor with the default value of a minimum players
ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
   // TODO: implement this function properly
	player1.setName("Gabriel");
	player2.setName("Meng-Shen");
	player3.setName("Beren");
	b.enqueue(player1);
	b.enqueue(player2);
	b.enqueue(player3);
	if (b.empty()) {
		throw std::logic_error("No Players in the Que");
	}
}

// TODO: implement the destructor
// destructor - dequeue players from the queue
ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   // TODO: implement this function properly
	while (!b.empty()) {
		b.dequeue();
	}
	if (!b.empty()) {
		throw std::logic_error("The Que is not empty");
	}
}

// TO DO: implement this function properly
// reset the game - rebuild the list of players
//        (i.e., the list should be the same as in the constructor).
//        Place all players at the figurative square zero
void ChutesAndLaddersGame::resetGame() {
   // TODO: implement this function properly
	nowinner = true;
	while (!b.empty()) {
		b.dequeue();
	}
	player1.setPosition(0);
	b.enqueue(player1);
	player2.setPosition(0);
	b.enqueue(player2);
	b.enqueue(player3);
	player3.setPosition(0);
	if (b.empty()) {
		throw std::logic_error("No players are reQued");
	}
}

// TO DO: implement this function properly
// Play the chutes and ladders until a player reaches the winning square 100
//    - Each player takes turn to roll the die and moves to the new square by invoking rollDieAndMove.
//         If the new square is outside of the board, the player stays put
//    - Player's new position is checked against the game board's checkChutesLadders
//    - checkChutesLadders returns a different square if player lands on a chute or a ladder
//    - Player's position is then set to the new position as indicated by checkChutesLadders
//          If player lands on a chute or a ladder, player slides down or climbs up
//    - If player lands on the winning square 100, game is over
//    - playGame returns after congratulating and printing the winner's name
void ChutesAndLaddersGame::playGame() {
   // TODO: implement this function properly
	if (b.empty()) {
		throw std::logic_error("No Players in the Que");
	}
	do {

	    v = b.front();
		b.dequeue();
		v.setPosition(gameBoard.checkChutesLadders(v.rollDieAndMove()));
		//cout << v.getPosition() << " " << v.getName() << " " << v.getDie().getFaceValue() << endl;
		if (v.getPosition() == 100) {
			winner = v.getName();
			nowinner = false;
		}
		else {
			b.enqueue(v);
		}
		
		/*player1.getDie().roll();
		Player player1copy = player1;
		player1copy.rollDieAndMove();
		player1.setPosition(gameBoard.checkChutesLadders(player1copy.getPosition()));
		cout << player1.getPosition() << " " << player1.getName() << " " << player1copy.getDie().getFaceValue() << endl;
		if (player1.getPosition() == 100) {
			winner = player1.getName();
		}
		player2.getDie().roll();
		Player player2copy = player2;
		player2copy.rollDieAndMove();
		player2.setPosition(gameBoard.checkChutesLadders(player2copy.getPosition()));
		cout << player2.getPosition() << " " << player2.getName() << " " << player2copy.getDie().getFaceValue() << endl;
		if (player2.getPosition() == 100) {
			winner = player2.getName();
		}
		player3.getDie().roll();
		Player player3copy = player3;
		player3copy.rollDieAndMove();
		player3.setPosition(gameBoard.checkChutesLadders(player3copy.getPosition()));
		cout << player3.getPosition() << " " << player3.getName() << " " << player3copy.getDie().getFaceValue() << endl;
		if (player3.getPosition() == 100) {
			winner = player3.getName();
		}*/
	} while (nowinner);
	cout << "Congraulations " << getWinner() << endl;
}
