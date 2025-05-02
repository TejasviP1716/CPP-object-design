/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 16/02/2025


**************************************/



#include <iostream>
#include <string>
#include "team.h"


using namespace std;

namespace seneca {

    void Team::addMember(const Character* c)
    {
        if (find(c->getName()) != -1)
        {
            return;
        }

        

        if (size_ == capacity_)
        
        {
            capacity_ *= 2;
            Character** temp = new Character * [capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                temp[i] = m_team[i];
            }
            delete[] m_team;
            m_team = temp;
        }

        m_team[size_++] = c->clone();
    }

    // Removes a character from the board........
    void Team::removeMember(const string& c) {
        int valid = find(c);
        if (valid == -1)
        {
            return;
        }

        delete m_team[valid]; 

        
        for (size_t i = valid; i < size_ - 1; ++i)
        {
            m_team[i] = m_team[i + 1];
        }
        size_--;
    }

  
    Character* Team::operator[](size_t idx) const
    {
        if (idx >= size_) 
        {
            return nullptr;
        }
        return m_team[idx];
    }

    // name of all team members are here .........
    void Team::showMembers() const
    {
        if (capacity_ == 0)
        {
            cout << "No team.\n";
            return;
        }

        cout << "[Team] " << m_name << "\n";
        for (size_t i = 0; i < size_; ++i)
        {
            cout << "    " << i + 1 << ": " << *m_team[i] << "\n";
        }
    }

}
//end of the program.......