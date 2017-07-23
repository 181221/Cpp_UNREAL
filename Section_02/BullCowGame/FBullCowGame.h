#pragma once
#include <string>

class FBullCowGame {
public:

	FBullCowGame(); //constructor
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value
	bool CheckGuessValidity();
	//provide a method for counting bulls & cows, and increase turn #



private:
	//initialization in contructor
	int MyCurrentTries;
	int MyMaxTries;

};