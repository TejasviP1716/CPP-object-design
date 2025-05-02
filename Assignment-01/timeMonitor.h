/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 02/02/2025


**************************************/

#pragma once
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <string>
#include "event.h"

namespace seneca {
    class TimeMonitor {
        const char* m_name;

        std::chrono::steady_clock::time_point m_timeStart;

        std::chrono::steady_clock::time_point m_timeEnd;
    public:

        void startEvent(const char* name);

        Event stopEvent();

    };
}
#endif 
/* SENECA_TIMEMONITOR_H */
/*END OF PROGRAM*/