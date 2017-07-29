#pragma once
#include <string>

using int32 = int;
using FString = std :: string;

//All values set to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK, 
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:

	FBullCowGame(); //constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const; 
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	int32 RemainingTries();
	EGuessStatus CheckGuessValidity(FString) const;
	void Reset(); 
	FBullCowCount SubmitValidGuess(FString Guess); //example of a rich return

private:
	//initialization in contructor
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
	
};