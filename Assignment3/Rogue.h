#ifndef ROGUE_H
#define ROGUE_H
#include "Common.h"

//this allows the Rogue class to acces the public
//variables of the comstats class
class Rogue: public ComStats
{
	public:
		Rogue(int HP, int Shield, int Battle, string battDie, int initiativeMod, string AttackLabel, string InitiativeLabel)
			: ComStats(HP, Shield, Battle, battDie, initiativeMod, AttackLabel, InitiativeLabel)
		{
		
		}
		//this receives the damage for the rogue
		virtual void takeDamage(int attack)
		{
			//gives a 50/50 dodge for the rogue
			int choice = rand() % 2;
			if (choice == 0)
			{
				cout << "Assassin Jim Dodged the attack!!" << endl;
			}
			if (choice == 1)
			{
				ComStats::takeDamage(attack);
				cout << "The Rogue has taken " << attack << " damage" << " and is now at " << health << " HP" << endl;
			}
		}
		//this prints out the damage for the rogue
		virtual int GetAttackDamage()
		{
			int damage, damage1, damage2;
			damage1 = rand() % 4 + 1;
			damage2 = rand() % 4 + 1;
			damage = damage1 + damage2;
			
			return damage;
		}
		//this displays the current stats of the rogue
		virtual void DisplayStats()
		{
			cout << "Health: " << health << "\n" << "Base Attack Die: " << baseattDie << "\n" << "Armor: " << armor << "\n" <<
				"Attack Modifier" << (attModLabel) << ": " << attmod << "\n" << "Initiative Modifier" << (initModLabel) << initmod << endl;
			cout << "Dodge: 50% chance to dodge an incoming attack\n" << endl;
		}
};

#endif
