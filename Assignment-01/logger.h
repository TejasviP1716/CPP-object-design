/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 02/02/2025


**************************************/


#pragma once
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include <iostream>
#include <chrono>
#include "event.h"

namespace seneca 
{
    class Logger
    {
        Event* m_event;

        int m_array;
    public:
        Logger();

        Logger(Logger&) = delete;

        Logger& operator=(Logger&) = delete;

        Logger(Logger&& src);


        Logger& operator=(Logger&& src);

        ~Logger();

        void arrayResize();

        void addEvent(const Event& event);

        friend std::ostream& operator<<(std::ostream& out, Logger& log);
    };
}
#endif
/* SENECA_LOGGER_H */
/*END OF PROGRAM*/