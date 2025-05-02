/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 16/02/2025


**************************************/


#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <string>

namespace seneca {

    class Guild
    {
        size_t size_, capacity_; //size_ means that variable of the class 
       
        Character** member_;

        std::string m_name;

      
        int find(const std::string& c) const
        {
            for (size_t i = 0; i < size_; ++i)
            {
                if (member_[i]->getName() == c)
                {
                    return i;
                }
            }
            return -1;
        }

    public:
        // Default constructor is thid.......
        Guild()
            : size_(0), capacity_(2), member_(new Character* [capacity_]),
            m_name("") {}

       

        Guild(const char* name)
            : size_(0), capacity_(2), member_(new Character* [capacity_]),
            m_name(name) {}

        // 1.Copy constructor:rule of five .......
        Guild(const Guild& other) 
        {
            size_ = other.size_;
            capacity_ = other.capacity_;
            member_ = new Character * [capacity_];
            for (size_t i = 0; i < size_; ++i) {
                member_[i] = other.member_[i];
            }
            m_name = other.m_name;
        }


        //2.copy the assignment : rule of five .......
        Guild& operator=(const Guild& other)
        {
            if (this != &other) {
                delete[] member_;

                size_ = other.size_;
                capacity_ = other.capacity_;
                member_ = new Character * [capacity_];
                for (size_t i = 0; i < size_; ++i) 
                {
                    member_[i] = other.member_[i];
                }
                m_name = other.m_name;
            }

            return *this;
        }


        //3.move constructor : rule of five .....
        Guild(Guild&& other) noexcept
        {
            size_ = other.size_;
            capacity_ = other.capacity_;
            member_ = other.member_;
            m_name = other.m_name;

            other.size_ = 0;
            other.capacity_ = 0;
            other.member_ = nullptr;
            other.m_name = "";
        }


        //4.move the assignment the constrour : rule of five........
        Guild& operator=(Guild&& other) noexcept
        {
            if (this != &other) 
            {
                delete[] member_;

                size_ = other.size_;
                capacity_ = other.capacity_;
                member_ = other.member_;
                m_name = other.m_name;

                other.size_ = 0;
                other.capacity_ = 0;
                other.member_ = nullptr;
                other.m_name = "";
            }
            return *this;
        }

        //5. destructor:rule of five ...........
        ~Guild() { delete[] member_; }

        void addMember(Character* c);

        void removeMember(const std::string& c);

        Character* operator[](size_t idx) const;

        void showMembers() const;
    };
} 

#endif

// end of the program