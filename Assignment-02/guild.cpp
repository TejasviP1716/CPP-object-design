/**************************************


Name: Tejasvi NitinKumar Parmar

submission date: 16/02/2025


**************************************/



#include "guild.h"
#include <iostream>
#include <string>

using namespace std;

namespace seneca {

    void Guild::addMember(Character* c) 
    {
        int index = find(c->getName());
        if (index != -1)
        {
            return;
        }
        // Resize (if capacity being full)........
        if (size_ == capacity_)
        {
            capacity_ *= 2;
            Character** temp = new Character * [capacity_];
            for (size_t i = 0; i < size_; ++i) 
            {
                temp[i] = member_[i];
            }
            delete[] member_;
            member_ = temp;
        }

        c->setHealthMax(c->getHealthMax() + 300);
        c->setHealth(c->getHealthMax());

        member_[size_++] = c;
    }

    // remove the member of the game..........
    void Guild::removeMember(const std::string& c) 
    {
        int valid = find(c);
        if (valid == -1)
        {
            return;
        }

        member_[valid]->setHealthMax(member_[valid]->getHealthMax() - 300);
        member_[valid]->setHealth(member_[valid]->getHealthMax());

        for (size_t i = valid; i < size_ - 1; ++i)
        {
            member_[i] = member_[i + 1];
        }
        size_--;
    }

    Character* Guild::operator[](size_t idx) const 
    {
        if (idx >= size_) 
        {
            return nullptr;
        }

        return member_[idx];
    }


    // show the member of the game...........
    void Guild::showMembers() const 
    {
        if (capacity_ == 0)
        {
            cout << "No guild." << m_name << "\n";
            return;
        }

        cout << "[Guild] " << m_name << "\n";
        for (size_t i = 0; i < size_; ++i)
        {
            cout << "    " << i + 1 << ": " << *member_[i] << "\n";
        }
    }

} // end of the program.....
