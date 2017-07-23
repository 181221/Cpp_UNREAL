#include "FBullCowGame.h"


//Reset function called in the contructor. 
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = 8;
	MyCurrentTries = 1;
	return;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const	{return MyCurrentTries;}

bool FBullCowGame::IsGameWon () const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity()
{
	return false;
}
