/*
	Jonathan Truong
	(Inheritance) My Very Own Dungeons and Dragons Game
*/

#include <iostream>
#include <memory>
#include <string>
#include <time.h>

#include "Knight.h"
#include "Mage.h"
#include "Rogue.h"
using namespace std;

int main()
{
	//game is starting soon
	cout << "You are now Knight Timmy, a ferocious Warrior!!!" << endl;
	cout << "A Mage named Wizard Gandolfo appears and is ready to BATTLE!!!!" << endl;
	cout << "\n" << endl;

	//this is for Knight Timmy stats
	//ptr points at the Knight DisplatStats()
	cout << "Warrior Knight Timmy's current stats:" << endl;
	shared_ptr<Knight> KN = make_shared<Knight>(Knight("2 D5", 20, 5, 3, "1 D6", 4, " (Strength)", " (Speed): "));
	KN->DisplayStats();

	//this is for the Mage Wizard stats
	//ptr points at the Mage DisplatStats()
	cout << "\n" << endl;
	cout << "Mage Wizard Gandalfo's current stats" << endl;
	shared_ptr<Wizard> WM = make_shared<Wizard>(Wizard(15, 2, 7, "1 D4", " (Intellect)"));
	WM->DisplayStats();

	//this is for the game
	int tempAttack = 0;
	int KtempinitScore = 0;
	int WtempinitScore = 0;
	do
	{
		//this loop goes on until someone is slain but it moves onto
		//the assassin and when he is slain then you win the game!
		//in this case it is the knight vs. the wizard
		//if the knight has a high initiative score + the modifier is higher than the wizard
		//then the knight goes but if it is the other way around, then the wizard goes first
		KtempinitScore = KN->getinitScore();
		cout << "\nYou rolled one dice(1-20): Initiative score of " << KtempinitScore << " + a speed modifier of "
			<< KN->getModifier() << " for a total of " << KtempinitScore + KN->getModifier() << endl;
		WtempinitScore = WM->getinitScore();
		cout << "The Mage rolled one dice(1-20): Initiative score of " << WtempinitScore << " and has no bonus speed modifier "
			<<  endl;
		//this displays the attacks of the wizard and knight 
		//this shows the amount of HP the knight and wizard has after being attacked
		if (KtempinitScore + KN->getModifier() <= WtempinitScore)
		{
			tempAttack = WM->GetAttackDamage();
			cout << "Wizard Gandalfo's Move: " << endl;
			cout << "Wizard Gandolfo rolled one dice(1-4): Damage score of " << tempAttack << " + an intellect modifier of "
				<< WM->getAttMod() << " for a total of " << (tempAttack + WM->getAttMod()) << endl;
			
			tempAttack = tempAttack + WM->getAttMod();
			KN->takeDamage(tempAttack);
			cout << "\nKnight Timmy has taken " << tempAttack << " damage and is now at " << KN->getHP() << " HP" << endl;
			//this checks if the Knight is slain
			//and if so, then the game is over
			//and ends
			if (KN->getHP() <= 0)
			{
				cout << "\nThe Knight has been slain!!!" << endl;
				cout << "GAME OVER!!" << endl;

				return 0;
			}
			//this gives the user the option to heal or attack
			int option;
			cout << "Your Move: " << endl;
			cout << "What will you do? \n1: Attack \n2: Heal" << endl;
			cin >> option;
			//the attack option
			if (option == 1)
			{
				tempAttack = KN->GetAttackDamage();
				cout << "You rolled one dice(1-6): Damage score of " << tempAttack << " + a strength modifier of "
					<< KN->getAttMod()  << " for a total of " << (tempAttack + KN->getAttMod()) << endl;
				tempAttack = tempAttack + KN->getAttMod();
				WM->takeDamage(tempAttack);
				cout << "\nWizard Gandalfo has taken " << tempAttack << " damage and is now at " << WM->getHP() << " HP" << endl;
			}
			//the heal option
			else if (option == 2)
			{
				int tempHeal = KN->getAddHealth();
				KN->heal(tempHeal);
			}
		}
		//this allows the user to go if the wizard's initiative score is lower
		//than the knights, so the knight goes
		else if (WtempinitScore < KtempinitScore + KN->getModifier())
		{
			//this gives the user the option to attack or heal
			int option;
			cout << "Your Move: " << endl;
			cout << "What will you do? \n1: Attack \n2: Heal" << endl;
			cin >> option;
			//the attack option
			if (option == 1)
			{
				tempAttack = KN->GetAttackDamage();
				tempAttack = tempAttack + KN->getAttMod();
				WM->takeDamage(tempAttack);
				cout << "\nWizard Gandalfo has taken " << tempAttack << " damage and is now at " << WM->getHP() << " HP" << endl;
				if (WM->getHP() <= 0)

				{
					cout << "\nThe Mage has been slain!!!" << endl;
					break;
				}
			}
			//the heal option
			else if (option == 2)
			{
				int tempHeal = KN->getAddHealth();
				KN->heal(tempHeal);
			}
			//this is the wizard's move
			cout << "Wizard Gandalfo's Move: " << endl;
			tempAttack = WM->GetAttackDamage();
			cout << "Wizard Gandalfo rolled one dice(1-4): Damage score of " << tempAttack << " + an intellect modifier of "
				<< WM->getAttMod() << " for a total of " << (tempAttack + WM->getAttMod()) << endl;
			tempAttack = tempAttack + WM->getAttMod();
			KN->takeDamage(tempAttack);
			cout << "\nKnight Timmy has taken " << tempAttack << " damage and is now at " << KN->getHP() << " HP" << endl;

		}
	} while (KN->getHP() > 0 && WM->getHP() > 0);
	//the game is over if the knight's HP is 0 or less
	if (KN->getHP() <= 0)
	{
		cout << "\nThe Knight has been slain!!!" << endl;
		cout << "GAME OVER!!" << endl;

		return 0;
	}

	//new enemy has arrived
	cout << "\nA magical fairy visits you, health has been reset to 20!" << endl;
	cout << "A Rogue named Assassin Jim appears and is ready to battle!!!" << endl;


	//this is for Knight Timmy stats again
	//ptr points at the Knight DisplatStats()
	cout << "\nWarrior Knight Timmy's current stats:" << endl;
	KN = make_shared<Knight>(Knight("2 D5", 20, 5, 3, "1 D6", 4, " (Strength)", " (Speed): "));
	KN->DisplayStats();

	//this is for the new character Rogue stats
	//ptr points at the rogue DisplayStats()
	cout << "\n" << endl;
	cout << "Rogue Assassin Jim's current stats:" << endl;
	shared_ptr<Rogue> RO = make_shared<Rogue>(Rogue(10, 3, 4, "2 D4", 5, " (Agility)", " (Speed): "));
	RO->DisplayStats();

	int RtempinitScore = 0;

	do
	{
		//this goes on until someone gets slained
		KtempinitScore = KN->getinitScore();
		cout << "\nYou rolled one dice(1-20): Initiative score of " << KtempinitScore << " + a speed modifier of "
			<< KN->getModifier() << " for a total of " << (KtempinitScore + KN->getModifier()) << endl;
		RtempinitScore = RO->getinitScore();
		cout << "The Rogue rolled one dice(1-20): Initiative score of " << RtempinitScore <<" + a speed modifier of "
			<< RO->getModifier() << " for a total of " << (RtempinitScore + RO->getModifier()) << endl;
		if (KtempinitScore < RtempinitScore)
		{
			//if the knight's initiative score + modifier is less than 
			//the rogue;s initiative score + modifier then the Rogue goes
			//because the rogue has a highter total than the knight
			//this function is for Assassin Jim's moves and attacks
			tempAttack = RO->GetAttackDamage();
			cout << "Assassin Jim's Move: " << endl;
			cout << "Assassin Jim rolled two dice(1-4): Damage score of " << tempAttack << " + an agility modifier of " << RO->getAttMod()
				<< " for a total of " << (tempAttack + RO->getAttMod()) << endl;
			tempAttack = tempAttack + RO->getAttMod();
			KN->takeDamage(tempAttack);
			cout << "\nKnight Timmy has taken " << tempAttack << " damage and is now at " << KN->getHP() << " HP" << endl;
			//if the knight's health is 0 or less then the game ends
			if (KN->getHP() <= 0)
			{
				cout << "The Knight has been slain!!!" << endl;
				cout << "GAME OVER!!" << endl;

				return 0;
			}
			
			int option;
			cout << "Your Move: " << endl;
			cout << "What will you do? \n1: Attack \n2: Heal" << endl;
			cin >> option;
			//the attack option
			if (option == 1)
			{
				tempAttack = KN->GetAttackDamage();
				tempAttack = tempAttack + KN->getAttMod();
				RO->takeDamage(tempAttack);
			}
			//the heal option
			else if (option == 2)
			{
				int tempHeal = KN->getAddHealth();
				KN->heal(tempHeal);
			}
		}
		//if the rogue has a less or equal initiative score + modifier with the knight
		//then the knight will go
		else if (RtempinitScore <= KtempinitScore)
		{
			//this gives the user an option to attack or heal
			int option;
			cout << "Your Move: " << endl;
			cout << "What will you do? \n1: Attack \n2: Heal" << endl;
			cin >> option;
			//this option is to attack
			if (option == 1)
			{
				tempAttack = KN->GetAttackDamage();
				cout << "You rolled one dice(1-6): Damage score of " <<  tempAttack << " + a strength modifier of " << KN->getAttMod() <<
					" for a total of " << (tempAttack + KN->getAttMod()) << endl;
				tempAttack = tempAttack + KN->getAttMod();
				RO->takeDamage(tempAttack);
				if (RO->getHP() <= 0)
				{
					cout << "The Rogue has been slain!!!" << endl;
					cout << "You Won The Video Game!!" << endl;

					return 0;
				}
			}
			//this option is for heal
			else if (option == 2)
			{
				int tempHeal = KN->getAddHealth();
				KN->heal(tempHeal);
			}
			//this is for the assassin's move
			cout << "Assassin Jim's Move: " << endl;
			tempAttack = RO->GetAttackDamage();
			cout << "Assassin Jim rolled two dice(1-4): Damage score of " << tempAttack  << " + an agility modifier of " <<  RO->getAttMod()
				<< " for a total of " << (tempAttack + RO->getAttMod()) << endl;
			tempAttack = tempAttack + RO->getAttMod();
			KN->takeDamage(tempAttack);
			cout << "\nKnight Timmy has taken " << tempAttack + RO->getAttMod() << " damage and is now at " << KN->getHP() << " HP" << endl;
		}
	} while (KN->getHP() > 0 && RO->getHP() > 0);
	//the knight loses if the HP is 0 or less
	//the game ends and the user loses
	if (KN->getHP() <= 0)
	{
		cout << "The Knight has been slain!!!" << endl;
		cout << "GAME OVER!!" << endl;

		return 0;
	}
	//if the rogue is slain with 0 or less HP, the knight wins
	//and the user wins the game!!
	else if (RO->getHP() <= 0)
	{
		cout << "The Rogue has been slain!!!" << endl;
		cout << "YOU WON THE VIDEO GAME!!" << endl;

		return 0;
	}

	system("PAUSE");
	return 0;
}

/*
You are now Knight Timmy, a ferocious Warrior!!!
A Mage named Wizard Gandolfo appears and is ready to BATTLE!!!!


Warrior Knight Timmy's current stats:
Health: 20
Healing Die: 2 D5
Base Attack Die: 1 D6
Armor: 5
Attack Modifier (Strength): 3
Initiative Modifier (Speed): 4


Mage Wizard Gandalfo's current stats
Health: 15
Base Attack Die: 1 D4
Armor: 2
Attack Modifier (Intellect): 7

You rolled one dice(1-20): Initiative score of 11 + a speed modifier of 4 for a total of 15
The Mage rolled one dice(1-20): Initiative score of 12 and has no bonus speed modifier
Your Move:
What will you do?
1: Attack
2: Heal
1

Wizard Gandalfo has taken 6 damage and is now at 9 HP
Wizard Gandalfo's Move:
Wizard Gandalfo rolled one dice(1-4): Damage score of 1 + an intellect modifier of 7 for a total of 8

Knight Timmy has taken 8 damage and is now at 12 HP

You rolled one dice(1-20): Initiative score of 18 + a speed modifier of 4 for a total of 22
The Mage rolled one dice(1-20): Initiative score of 3 and has no bonus speed modifier
Your Move:
What will you do?
1: Attack
2: Heal
1

Wizard Gandalfo has taken 6 damage and is now at 3 HP
Wizard Gandalfo's Move:
Wizard Gandalfo rolled one dice(1-4): Damage score of 4 + an intellect modifier of 7 for a total of 11

Knight Timmy has taken 11 damage and is now at 1 HP

You rolled one dice(1-20): Initiative score of 9 + a speed modifier of 4 for a total of 13
The Mage rolled one dice(1-20): Initiative score of 8 and has no bonus speed modifier
Your Move:
What will you do?
1: Attack
2: Heal
1

Wizard Gandalfo has taken 9 damage and is now at -6 HP

The Mage has been slain!!!

A magical fairy visits you, health has been reset to 20!
A Rogue named Assassin Jim appears and is ready to battle!!!

Warrior Knight Timmy's current stats:
Health: 20
Healing Die: 2 D5
Base Attack Die: 1 D6
Armor: 5
Attack Modifier (Strength): 3
Initiative Modifier (Speed): 4


Rogue Assassin Jim's current stats:
Health: 10
Base Attack Die: 2 D4
Armor: 3
Attack Modifier (Agility): 4
Initiative Modifier (Speed): 5
Dodge: 50% chance to dodge an incoming attack


You rolled one dice(1-20): Initiative score of 7 + a speed modifier of 4 for a total of 11
The Rogue rolled one dice(1-20): Initiative score of 18 + a speed modifier of 5 for a total of 23
Assassin Jim's Move:
Assassin Jim rolled two dice(1-4): Damage score of 6 + an agility modifier of 4 for a total of 10

Knight Timmy has taken 10 damage and is now at 10 HP
Your Move:
What will you do?
1: Attack
2: Heal
1
The Rogue has taken 8 damage and is now at 2 HP

You rolled one dice(1-20): Initiative score of 13 + a speed modifier of 4 for a total of 17
The Rogue rolled one dice(1-20): Initiative score of 11 + a speed modifier of 5 for a total of 16
Your Move:
What will you do?
1: Attack
2: Heal
1
You rolled one dice(1-6): Damage score of 3 + a strength modifier of 3 for a total of 6
The Rogue has taken 6 damage and is now at -4 HP
The Rogue has been slain!!!
YOU WON THE VIDEO GAME!!

C:\Users\CSUFTitan\source\repos\Assignment3\Debug\Assignment3.exe (process 13896) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/