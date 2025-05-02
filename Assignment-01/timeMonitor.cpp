/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 02/02/2025


**************************************/

#include <chrono>
#include <string>
#include "timeMonitor.h"
#include "event.h"

namespace seneca {
    void TimeMonitor::startEvent(const char* name) {
        if (name != nullptr) {
            m_name = name;
        }
        else {
            m_name = "Error: No Name";
        }
        m_timeStart = std::chrono::steady_clock::now();
    }

    Event TimeMonitor::stopEvent() 
    {
        // ending of the clock time 
        m_timeEnd = std::chrono::steady_clock::now();


        // Casting clock time difference 
        std::chrono::duration<double> spanTime  = std::chrono::duration_cast<std::chrono::duration<double>>(m_timeEnd - m_timeStart);


        // Casting duration to nanoseconds 
        std::chrono::nanoseconds nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(spanTime);
        return Event(m_name, nanoseconds);
    }
}

/*END OF PROGRAM*/