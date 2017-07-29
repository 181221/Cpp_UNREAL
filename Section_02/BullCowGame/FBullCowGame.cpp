#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map


//Making the code Unreal friendlyS
using int32 = int;
using FString = std :: string;


//Reset function called in the contructor. 
void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = 8;

	const FString HIDDEN_WORD = "earth";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTries = 1;
	bGameIsWon = false;
	return;
}

//Receives a valid guess and increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTries++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assuming the same length as guess

	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {

		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {

			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { //if they match then
					BullCowCount.Bulls++; //increment bulls if they're in the same place
				}
				else {
					BullCowCount.Cows++; //increment cows if they're not
				}
			}
			
		}

	}

	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{

	// treat 0 and 1 letter words as isograms

	if (Word.length() <= 1) { return true;
	}

	TMap<char, bool> LetterSeen; //setup our map

	for (auto Letter : Word) //for all letters of the word
	{
	
		Letter = tolower(Letter); //can handle mix cases
		if (LetterSeen[Letter]) {
			return false; //we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;
		
		// if the letter is in the map
			//we do not have an isogram
		//otherwise
			//add the letter to the map as seen
			}
		}

	return true; //for examples where \0 is entered (null character)
}

bool FBullCowGame::IsLowerCase(FString Word) const
{

	for(auto Letter : Word) 
	{
		//if not a lowercase letter
		if (!islower(Letter)) {
			return false;
		}
			
	}


	return true;
}

int32 FBullCowGame::RemainingTries()
{
	return MyMaxTries-MyCurrentTries+1;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTries;}

int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon () const {return bGameIsWon;}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) //if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowerCase(Guess)) //if the guess isn't all lowercase  
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength()) //if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else 
	{
		return EGuessStatus::OK;
	}

}
