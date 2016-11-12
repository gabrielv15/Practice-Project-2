//
//  Player.cpp
//

#include "Player.hpp"

// TO DO: implement Player's assignment operator
Player& Player::operator=(const Player& p) {
   // TODO: implement this function properly
	setName(p.getName());
	setPosition(p.getPosition());
	die = p.die;
	if (p.getName() != getName()) {
		throw std::logic_error("Player names are not the same");
	}
}

// return player's new position after player rolls die
// If the new position is outside of the board, player stays put
// If not, player moves to the new square = player's postion + die's face value
// TO DO: implement this function to move player to the new postion
//        after player rolls die. Position must be inside the board
int Player::rollDieAndMove() {
	// TODO: implement this function properly
	die = Die();
	if (getPosition() + getDie().getFaceValue() > 100) {
		return getPosition();
	}
	if (getPosition() + getDie().getFaceValue() <= 100) {
		return (getPosition() + getDie().getFaceValue());
	}


}