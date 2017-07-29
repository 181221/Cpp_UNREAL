/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class. 
*/


#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std :: string;


void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
void PrintGameSummary();

FBullCowGame BCGame; //Instantiate a new game. Global variable



//Entry point for our application
int main() {
	
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0; //exit the application
}


//Introduce the game
void PrintIntro() {

	std :: cout << "\nWelcome to Bulls and Cows, a fun word game." << std :: endl;
	std :: cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std :: cout << " letter isogram I'm thinking of?\n";
	std::cout << "If you get a bull; you have placed the right letter in the correct location.\n";
	std::cout << "If you get a cow; you have the right letter in the wrong location.\n";
	std :: cout << std :: endl;
	return;
}

//Play the game
void PlayGame() {
	
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//Loop through guess tries
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <=MaxTries) {
		FText Guess = GetValidGuess(); 
		

		//submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n";
		std::cout << "You have " << BCGame.RemainingTries() <<" attempts left\n\n" ;
	}

	PrintGameSummary();
	return;
}

//Continuous loop until valid guess is entered. 
FText GetValidGuess() { 


		FText Guess = "";
		EGuessStatus Status = EGuessStatus::Invalid_Status;
	
	do {
		//Get a guess from the player
		int32 GuessNumber = BCGame.GetCurrentTry();
		std::cout << "Try " << GuessNumber << "." << " Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please type your guess in lowercase.\n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "The word you typed is not an isogram.\n\n";
			break;

		default:
			//assume the guess is valid
			break;

		}

		

	} while (Status != EGuessStatus::OK); //Keep looping until we get no errors
	return Guess;
}

//Ask the player if they want to play again
bool AskToPlayAgain() {

	std :: cout << "Do you want to play again with the same hidden word (y/n)?";
	FText Response = "";
	std :: getline(std :: cin, Response);
	std :: cout << std :: endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() {

	if (BCGame.IsGameWon()) 
	{
		std::cout << "YOU WIN!\n\n";
	}
	else 
	{
		std::cout << "OUFF...BETTER LUCK NEXT TIME!\n\n";
	}

}