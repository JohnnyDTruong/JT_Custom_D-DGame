#ifndef MAGE_H
#define MAGE_H
#include "Common.h"

//this allows the wizard class to access the public
//variables of the ComStats class
class Wizard: public ComStats
{
	public:
		Wizard(int HP, int Shield, int Battle, string battDie, string AttackLabel)
			: ComStats(HP, Shield, Battle, battDie, 0, AttackLabel, "")
		{
			
		}
		//this rand generates the damage
		virtual int GetAttackDamage()
		{
			int damage;
			damage = rand() % 4 + 1;

			return damage;
		}
		//this prints out the current stats of the Mage Wizard
		virtual void DisplayStats()
		{
			cout << "Health: " << health << "\n" << "Base Attack Die: " << baseattDie << "\n" << "Armor: " << armor << "\n" <<
					"Attack Modifier" << (attModLabel) << ": " << attmod << endl;
		}

};

#endif
