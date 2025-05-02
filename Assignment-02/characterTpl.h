/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 16/02/2025


**************************************/


#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include <iostream>
#include "character.h"


namespace seneca
{

    template <typename T> class CharacterTpL : public Character
    {
        int m_healthMax;
        T m_health;

    public:
        // Constructor initializing character name and health
        CharacterTpL(const char* name, int healthMax)
            : Character(name), m_healthMax(healthMax) 
        {
            m_health = (int)m_healthMax;
        }

        // Copy the constructor.............
        CharacterTpL(const CharacterTpL& other)
            : Character(other.getName().c_str()), m_healthMax(other.m_healthMax) 
        {
            m_health = (int)other.m_healthMax;
        }

        void takeDamage(int dmg) override 
        {
            m_health -= dmg;

            if (m_health < 0) 
            {
                m_health = 0;
            }

            if (Character::isAlive() == false)
            {
                std::cout << "    " << Character::getName() << " has been defeated!\n";
            }
            else 
            {
                std::cout << "    " << Character::getName() << " took " << dmg
                    << " damage, " << getHealth() << " health remaining.\n";
            }
        }

        int getHealth() const override { return static_cast<int>(m_health); }

        int getHealthMax() const override { return m_healthMax; }

        void setHealth(int health) override { m_health = health; }

        void setHealthMax(int health) override { m_healthMax = health; }
    };

} 

#endif

// end of the program