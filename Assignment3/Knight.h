#ifndef KNIGHT_H
#define KNIGHT_H
#include "Common.h"

class Knight: public ComStats
{
	//only the knight can heal
	private:
		string healDie;

	public:
		Knight(string BetterHealth, int HP, int Shield, int Battle, string battDie, int initiativeMod, string AttackLabel, string InitiativeLabel) 
			: ComStats(HP, Shield, Battle, battDie, initiativeMod, AttackLabel, InitiativeLabel)
		{
			healDie = BetterHealth;
		}
		//this is the additional health
		//and it randomizes what amount of additional health the knight will get
		int getAddHealth()
		{
			return rand() % 8 + 2;
		}
		//this is the heal funstion
		//this adds the extra health to the Hp of the knight
		void heal(int addHealth)
		{
			cout << "You heal yourself for " << addHealth << " hit points!!" << endl;
			health = addHealth + health;
			cout << "Total HP now at: " << health << endl;
		}
		//this is the attack function for the knight
		//this randomizes the damage of the knight to attack
		//with whatever damage the program randomly chooses
		virtual int GetAttackDamage()
		{
			int damage;
			damage = rand() % 6 + 1;

			return damage;
		}
		//this receives the damage
		virtual void takeDamage(int attack)
		{
			health = health - attack;
		}
		//this prints out the current stats for the knigth
		virtual void DisplayStats()
		{
			cout << "Health: " << health << "\n" << "Healing Die: " << healDie << "\n" << "Base Attack Die: " << baseattDie << "\n" << "Armor: " << armor << "\n" <<
				"Attack Modifier" << (attModLabel) << ": " << attmod  << "\n" << "Initiative Modifier" << (initModLabel) << initmod << endl;
		}
};


#endif
