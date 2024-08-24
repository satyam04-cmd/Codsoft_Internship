#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    
    int randomNumber = rand() % 10 + 1;
    int userGuess = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Select a random number between 1 and 100." << endl;
    cout << "Guess the number" << endl;
    
    while (userGuess != randomNumber) 
	{
        cout << "Enter your guess: ";
        cin >> userGuess;
        if (userGuess > randomNumber) 
		{
            cout << "Too high! Try again." << endl;
        }
		else if (userGuess < randomNumber) 
		{
            cout << "Too low! Try again." << endl;
        } 
		else 
		{
            cout << "Yayy! You guessed the correct number: " << randomNumber << endl;
        }
    }
    
    return 0;
}