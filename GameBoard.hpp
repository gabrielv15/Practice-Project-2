//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:   
   enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };
   
   enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };
   
   // Build the gameboard
   // TO DO: implement this function
   void buildBoard();
   
   GameBoard() {
	  // TODO: implement this function properly
	   buildBoard();
	   if (a.empty()) {
		   throw std::logic_error("Board is not created yet");
	   }
   }

   // If player lands on chutes or ladders, returns the new position.
   // Otherwise, returns the player's current position.
   // If the player's position is outside of the gameboard, throws index out of bounds exception
   // TO DO: implement this function properly
   int checkChutesLadders(int position) {
	  if ((position < 0) || (position >= BOARD_SIZE)) {
		 throw range_error("index out of bounds");
	  }
	  // TODO: implement this function properly
	  if (a.at(position) == 1) {
		  return 38;
	  }
	  if (a.at(position) == 4) {
		  return 14;
	  }
	  if (a.at(position) == 9) {
		  return 31;
	  }
	  if (a.at(position) == 21) {
		  return 42;
	  }
	  if (a.at(position) == 28) {
		  return 84;
	  }
	  if (a.at(position) == 36) {
		  return 44;
	  }
	  if (a.at(position) == 51) {
		  return 67;
	  }
	  if (a.at(position) == 71) {
		  return 91;
	  }
	  if (a.at(position) == 80) {
		  return 100;
	  }
	  if (a.at(position) == 16) {
		  return 6;
	  }
	  if (a.at(position) == 47) {
		  return 26;
	  }
	  if (a.at(position) == 49) {
		  return 11;
	  }
	  if (a.at(position) == 56) {
		  return 53;
	  }
	  if (a.at(position) == 62) {
		  return 19;
	  }
	  if (a.at(position) == 64) {
		  return 60;
	  }
	  if (a.at(position) == 87) {
		  return 24;
	  }
	  if (a.at(position) == 93) {
		  return 73;
	  }
	  if (a.at(position) == 95) {
		  return 75;
	  }
	  if (a.at(position) == 98) {
		  return 78;
	  }
	  if (a.empty()) {
		  throw std::logic_error("Board is not created yet");
	  }
	  else
		  return position;
   }
   
private:
   // TO DO: add storage for squares including square of chutes and ladders
   // Requirement: use ExtendableVector to store the square
	ExtendableVector<int> a;
	int position;
};