/*****************************************************************************************
*  Program Name: Project1.cpp
*  Created Date: 10/18/18
*  Created By: Shawn Ruby
*  Purpose: Robot Fighting Game
*  Acknowledgements: None
*****************************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

/* Creates Structures for the Robots */
struct Robot
{
	int health;
	int damage;
	string name;
	int win;
	int loss;
};

/*****************************************************************************************
*  Function Name:  main()
*  Parameters:     None
*  Return Value:   int
*  Purpose: Runs the code, looping through to determine how many fights the robots fight
*****************************************************************************************/

int main()
{
	/* Picks a random number between 1 - 100 to assign damage */
	srand((unsigned int)time(0));

	/* Assigns variables for both robots from the structures. Health, damage, name, wins, losses*/
	Robot Computer = { 100, rand() % 100 + 1, Computer.name, 0, 0 };
	Robot user = { 100, rand() % 100 + 1, user.name, 0, 0 };

	/* Asks the user for the name of their robot */
	cout << "What would you like your robot's name to be? ";
	cin >> user.name;

	/* Asks the user for the name of the opponent's robot*/
	cout << "\nWhat would you like the opponent's robot's name to be? ";
	cin >> Computer.name;

	/* Clears the screen to start the battle sequence */
	system("CLS");
	
	/* variable for turn */
	int attack = 1;

	/* variable for continuing with rounds or not */
	string decision;

	/* while loop that will loop through the code until user chooses otherwise */
	while (true)
	{
		/* do loop for the while loop */
		do
		{
			/* Variable for both robot's damage between 0 and the damage they were assigned in the structure */
			int DamageComputer = rand() % Computer.damage;
			int DamageUser = rand() % user.damage;
			
			/* variable for the turn of who attacks between 1 or 2 */
			int turn = rand() % 2 + 1;

			/* if statement for if both robot's healths are above 0 */
			if (Computer.health > 0 && user.health > 0)
			{
				/* Displays turn */
				cout << "Turn: " << attack << "\n";

				/* Displays all of the user's robot's info */
				cout << "\nRobot Name: " << user.name << "\n\nHealth: " << user.health << "\n\nDamage: " << user.damage <<
					"\n\nWins: " << user.win << "\n\nLosses: " << user.loss;

				/* Displays all of the user's robot's info */
				cout << "\n\nRobot Name: " << Computer.name << "\n\nHealth: " << Computer.health << "\n\nDamage: " << Computer.damage <<
					"\n\nWins: " << Computer.win << "\n\nLosses: " << Computer.loss << "\n\n";

				if (turn == 1)
				{
					/* if turn is 1 then the user's robot attacks */
					cout << "It is " << user.name << "'s turn.\n" << user.name << " does " << DamageUser << " damage.\n\n";
					
					/* damage is deducted from the computer's health */
					Computer.health -= DamageUser;
				}

				else if (turn == 2)
				{
					/* if turn is 2 then the computer's robot attacks */
					cout << "It is " << Computer.name << "'s turn.\n" << Computer.name << " does " << DamageComputer << " damage.\n\n";
					
					/* damage is deducted from the user's health */
					user.health -= DamageComputer;
				}
				/* turn increases by 1 */
				attack += 1;
				system("pause");
				system("CLS");
			}

		} while (user.health > 0 && Computer.health > 0);
		
		if (Computer.health <= 0)
		{
			/* if the computer was defeated, it will set it's health to 0 */
			Computer.health = 0;

			/* displays the computer lost and the user won and displays the health left */
			cout << Computer.name << " was defeated. The Robot had " << Computer.health << " health left.\n" << user.name <<
				" was victorious! Your Robot had " << user.health << " health left.\n\n";
			
			/* user wins adds 1 */
			user.win += 1;

			/* computer losses adds 1 */
			Computer.loss += 1;

			/* asks the user if they would like to do another round */
			cout << "Would you like to do another round? (y/n) ";
			cin >> decision;
			
			if (decision == "y" || decision == "Y")
			{
				/* clears the screen for next round and will go back to the while loop */
				system("CLS");

				/* sets computer health back to 0 */
				Computer.health = 100;

				/* sets user health back to 0 */
				user.health = 100;

				/* sets turn back to 0 */
				attack = 1;
			}
			else if (decision == "n" || decision == "N")
			{
				/* clears the screen and ends loop */
				system("CLS");

				/* if statement for when both robots only win 1 round it will display "time" instead of times */
				if (user.win == 1 && Computer.win == 1)
				{
					/* displays how many times the robots won */
					cout << "Your Robot, " << user.name << ", won " << user.win << " time.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " time.\n\n";
					
					/* pauses */
					system("pause");
					
					/* ends loop, ends program */
					return false;
				}

				/* if statement for if computer robot only wins 1, it will display time instead of times */
				else if (Computer.win == 1)
				{
					/* displays how many times the robots won */
					cout << "Your Robot, " << user.name << ", won " << user.win << " times.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " time.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}

				/* if statement for if user robot only wins 1, it will display time instead of times */
				else if (user.win == 1)
				{ 
					/* displays how many times the robots won */
					cout << "Your Robot, " << user.name << ", won " << user.win << " time.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " times.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}
				else
				{
					/* if both robots both win more than once, then it displays times for both */
					cout << "Your Robot, " << user.name << ", won " << user.win << " times.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " times.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}
			}
		}

		else if (user.health <= 0)
		{
			/* if the user was defeated, it will set it's health to 0 */
			user.health = 0;
			 
			/* displays the user lost and the computer won and displays the health left */
			cout << user.name << " was defeated. Your Robot had " << user.health << " health left.\n" << Computer.name <<
				" was victorious! The Robot had " << Computer.health << " health left.\n\n";
			
			/* computer wins adds 1 */
			Computer.win += 1;

			/* user losses adds 1 */
			user.loss += 1;

			/* asks the user if they would like to do another round*/
			cout << "Would you like to do another round? (y/n) ";
			cin >> decision;

			if (decision == "y" || decision == "Y")
			{
				/* clears the screen for next round and will go back to the while loop */
				system("CLS");

				/* sets user health back to 0 */
				user.health = 100;

				/* sets computer health back to 0 */
				Computer.health = 100;

				/* sets turn back to 0 */
				attack = 1;
			}
			else if (decision == "n" || decision == "N")
			{
				/* clears the screen and ends loop */
				system("CLS");

				/* if statement for when both robots only win 1 round it will display "time" instead of times */
				if (user.win == 1 && Computer.win == 1)
				{
					cout << "Your Robot, " << user.name << ", won " << user.win << " time.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " time.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}

				/* if statement for if computer robot only wins 1, it will display time instead of times */
				else if (Computer.win == 1)
				{
					cout << "Your Robot, " << user.name << ", won " << user.win << " times.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " time.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}

				/* if statement for if user robot only wins 1, it will display time instead of times */
				else if (user.win == 1)
				{
					cout << "Your Robot, " << user.name << ", won " << user.win << " time.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " times.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}
				else
				{
					/* if both robots both win more than once, then it displays times for both */
					cout << "Your Robot, " << user.name << ", won " << user.win << " times.\nThe opponent's Robot, " <<
						Computer.name << ", won " << Computer.win << " times.\n\n";

					/* pauses */
					system("pause");

					/* ends loop, ends program */
					return false;
				}
			}
		}
	} 
}
