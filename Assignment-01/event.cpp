/**************************************


Name: Tejasvi NitinKumar Parmar

submission date: 02/02/2025


**************************************/


#include <iostream>
#include <iomanip>
#include <utility>
#include <chrono>
#include "event.h"
#include "settings.h"

namespace seneca {

    Event::Event() {
        m_eventName = "";
    }

    Event::Event(const char* name, const std::chrono::nanoseconds& duration) {
        Event();
        if (name != nullptr) {
            m_eventName = name;
        }
        if (duration.count() != 0) {
            m_duration = duration;
        }
    }

    std::ostream& operator<<(std::ostream& out, Event& event) {
        static int loop = 1;
        out << std::setw(2) << std::right << loop << ": "
            << std::setw(40) << event.m_eventName << " -> ";

        if (g_settings.m_time_units == "seconds") {
            std::chrono::seconds time = std::chrono::duration_cast<std::chrono::seconds>(event.m_duration);
            out << std::setw(2) << time.count() << " seconds";
        }
        else if (g_settings.m_time_units == "milliseconds") {
            std::chrono::milliseconds time = std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration);
            out << std::setw(5) << time.count() << " milliseconds";
        }
        else if (g_settings.m_time_units == "microseconds") {
            std::chrono::microseconds time = std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration);
            out << std::setw(8) << time.count() << " microseconds";
        }
        else if (g_settings.m_time_units == "nanoseconds") {
            std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(event.m_duration);
            out << std::setw(11) << time.count() << " nanoseconds";
        }

        loop++;
        return out;
    }
}

/*END OF PROGRAM*/
