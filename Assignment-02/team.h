/**************************************


Name: Tejasvi NitinKumar Parmar

submission date: 16/02/2025


**************************************/

#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include "character.h"
#include <string>

namespace seneca {

    class Team {
        size_t size_ = 0, capacity_ = 0;
       
        Character** m_team;

        std::string m_name;

        int find(const std::string& c) const
        {
            for (size_t i = 0; i < size_; ++i) 
            {
                if (m_team[i]->getName() == c) 
                {
                    return i;
                }
            }
            return -1;
        }

    public:
        Team()
            : size_(0), capacity_(2), m_team(new Character* [capacity_]),
            m_name("") {}

        Team(const char* name)
            : size_(0), capacity_(2), m_team(new Character* [capacity_]),
            m_name(name) {}

    //1. copy the constructor: rule of five.....
        Team(const Team& other)
        {
            size_ = other.size_;
            capacity_ = other.capacity_;
            m_team = new Character * [capacity_];
            for (size_t i = 0; i < size_; ++i) 
            {
                m_team[i] = other.m_team[i]->clone();
            }
            m_name = other.m_name;
        }


        //2. copy the assignment:rule of five.......
        Team& operator=(const Team& other)
        {
            if (this != &other) {
                for (size_t i = 0; i < size_; ++i) 
                {
                    delete m_team[i];
                }
                delete[] m_team;

                size_ = other.size_;
                capacity_ = other.capacity_;
                m_team = new Character * [capacity_];
                for (size_t i = 0; i < size_; ++i) {
                    m_team[i] = other.m_team[i]->clone();
                }
                m_name = other.m_name;
            }
            return *this;
        }


        //3.move the constructor: rule of five ..........
        Team(Team&& other) noexcept {
            size_ = other.size_;
            capacity_ = other.capacity_;
            m_team = other.m_team;
            m_name = other.m_name;

            other.size_ = 0;
            other.capacity_ = 0;
            other.m_team = nullptr;
            other.m_name = "";
        }



        //4.move the assignment constructoe:rule of five ..........
        Team& operator=(Team&& other) noexcept {
            if (this != &other) {
                for (size_t i = 0; i < size_; ++i) {
                    delete m_team[i];
                }
                delete[] m_team;

                size_ = other.size_;
                capacity_ = other.capacity_;
                m_team = other.m_team;
                m_name = other.m_name;

                other.size_ = 0;
                other.capacity_ = 0;
                other.m_team = nullptr;
                other.m_name = "";
            }
            return *this;
        }


        //5. destructor:rule of five.........
        ~Team() {
            for (size_t i = 0; i < size_; ++i) {
                delete m_team[i];
            }
            delete[] m_team;
        }

        void addMember(const Character* c);

        void removeMember(const std::string& c);

        Character* operator[](size_t idx) const;

        void showMembers() const;
    };

} 
#endif
// end of the program
