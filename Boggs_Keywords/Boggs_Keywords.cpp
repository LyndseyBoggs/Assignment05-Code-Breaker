// ch03_WordJumble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Instructions
	cout << "\t\tWelcome to Code Breaker\n\n";
	cout << "\nThis is a training simulation to decode the words of foreign entities.\n";
	cout << "\nYou must complete 3 jumbled terms for this simulation.\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "Use the letter 'e' after the vowel instead of an umlaut. . .\n";
	cout << "...The umlaut is too powerful for our system to handle.\n\n";
	cout << "Viel Glueck!\n\n";
	cout << "****************************************************************************\n\n"; 
	
	// Create the array of words and hints
	enum fields { WORD, HINT, NUM_FIELDS }; //cound the number of fields you have
	const int NUM_WORDS = 10; // create a constant integer for the fixed size of array
	const string WORDS[NUM_WORDS][NUM_FIELDS] = // create a two dimesnional array containing strings for words and hints, call it "WORDS". 
	{
		{ "laufen", "German: to run" },
		{ "sehen", "German: to see" },
		{ "tanzen", "German: to dance" },
		{ "spielen", "German: to play" },
		{ "singen", "German: to sing" },
		{ "schlafen", "German: sleep" },
		{ "hoeren", "German: to hear or listen to" },
		{ "lesen", "German: to read" },
		{ "schreiben", "German: to write" },
		{ "malen", "German: to paint" }
	};

		
	//Prepare for replay
	char again; //create character variable "again" and leave it empty
	do
	{
		//Create variables for game stats
		int guessCount = 0;
		int wrongGuess = 0;
		int hintCount = 0;

		// Loop 3 times (for three words)
		for (int i = 0; i < 3; ++i)
		{

			// Get a random word and its hint
			srand(static_cast<unsigned int>(time(0))); //seed the randomizer
			int choice = (rand() % NUM_WORDS); // get a random integer between 1 and the total number of words
			string theWord = WORDS[choice][WORD]; // word to guess (gathered from random number = location in array)
			string theHint = WORDS[choice][HINT]; // hint for word you picked

												  //Jumble the word
			string jumble = theWord; // make a string copy of the word to jumble and call it 'jumble'
			int length = jumble.size(); // get the length of the word
			for (int i = 0; i < length; ++i) //iterate through each character in the word
			{
				int index1 = (rand() % length); //select a random character location in the word and pick its integer position in the string
				int index2 = (rand() % length); // pick another random character and get its integer location in the string
				char temp = jumble[index1]; // make a temporary copy of the character you have selected
				jumble[index1] = jumble[index2]; // overwrite the first random location with the second random letter
				jumble[index2] = temp; // overwrite the second random location with the first random letter (that we made a copy of)
			}


			//Make the JUMBLE
			cout << "\n****************************************************************************\n\n";
			cout << "The jumble is: " << jumble; // Show the jumble to the player

			string guess; // create an empty string called "guess"
			cout << "\n\nYour guess: "; // Text field label for player input
			cin >> guess; // get the player's string input and assign it to "guess"

			//Game Loop
			while ((guess != theWord) && (guess != "quit"))// while the guess is incorrect and the player has not quit: 
			{
				//if the player asks for the hint, show them the hint
				if (guess == "hint")
				{
					cout << theHint; // display Hint
					++hintCount; // add 1 to hint count
				}

				//otherwise, the guess is incorrect
				else
				{
					cout << "Sorry, that's not it."; // tell the player that guess is incorrect
					++wrongGuess; // add 1 to wrong guess count
					++guessCount; // add 1 to total guess count
				}

				cout << "\n\nYour guess: "; // let them guess again
				cin >> guess; //assign their new input to "guess". Check again at top of while loop
			}

			//Quiting
			if (guess == "quit")
			{
				break;
			}

			//Victory
			if (guess == theWord) // if guess is correct
			{
				++guessCount; // add 1 to total guess count
				cout << "\nWunderbar! Sehr gut gemacht!\n\n";
				cout << "****************************************************************************\n\n";
			}
		}

		//Display Statistics
		cout << "You used " << guessCount << " guesses to solve 3 words.\n";
		cout << "You used a total of " << hintCount << " hints.\n";
		cout << "You made " << wrongGuess << " incorrect guesses.\n\n";

		//Play Again?
		cout << "****************************************************************************\n\n";
		cout << "Would you like to repeat the training? Type y or n \n\n"; //Ask if the player would like to play again
		cout << "Your answer: "; //text field lable for player response
		cin >> again; // assign player input to character variable "again"

	} while (again == 'y');

	//Exit
	cout << "\n Herzlichen Dank! Auf Wiedersehen! \n";

	system("pause"); // pause console to remain on screen
	return 0; // return to OS
}

