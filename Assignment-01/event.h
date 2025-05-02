/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 02/02/2025


**************************************/

#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H


#include <utility>
#include <chrono>

namespace seneca 
{
    class Event 
    {
        const char* m_eventName;

        std::chrono::nanoseconds m_duration;
    public:
        Event();

        Event(const char* name, const std::chrono::nanoseconds& duration);

        friend std::ostream& operator<<(std::ostream& out, Event& event);
    };
}
#endif 
/* SENECA_EVENT_H */
/*END OF PROGRAM*/