#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
using namespace std;

class ComStats
{
	//other classes can access the protected and the public as well
	protected:
		int health;
		int armor;
		int attmod;
		int initmod;
		int initScore;
		string attModLabel;
		string initModLabel;
		string baseattDie;
		
	public:
		ComStats(int HP, int Shield, int Battle, string battDie, int initiativeMod, string AttackLabel, string InitiativeLabel)
		{
			srand(time(0));
			health = HP;
			armor = Shield;
			attmod = Battle;
			baseattDie = battDie;
			initmod = initiativeMod;
			attModLabel = AttackLabel;
			initModLabel = InitiativeLabel;
		}
		//this is for the attack modifier
		int getAttMod()
		{
			return attmod;
		}
		//this is for the initiative modifier
		virtual int getModifier()
		{
			return initmod;
		}
		//this is the health
		int getHP()
		{
			return health;
		}
		//attack function
		virtual int GetAttackDamage() = 0;
		//this receives the damage from the attack
		//and subtracts it to the health
		virtual void takeDamage(int attack)
		{
			health = health - attack;
		}
		//this randomizes the initiative score
		//from 1-20
		int getinitScore()
		{
			int score;
			score = rand() % 20 + 1;

			return score;
		}
		//this displays the stats
		virtual void DisplayStats() = 0;
};
#endif
