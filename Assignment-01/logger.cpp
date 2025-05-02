/**************************************


Name: Tejasvi NitinKumar Parmar
student id: 151236239
email.id: tnparmar2@myseneca.ca
submission date: 02/02/2025


**************************************/

#include <iostream>
#include <utility>
#include "logger.h"

namespace seneca {
    Logger::Logger() {
        m_event = nullptr;
        m_array = 0;
    }
    Logger::Logger(Logger&& src) {
        *this = std::move(src);
    }

    Logger& Logger::operator=(Logger&& src) 
    {
        // Self-Assign Guard
        if (this != &src)
        {
            // Clean the memory
            delete[] m_event;
            // Shallow Copy
            m_array = src.m_array;
            m_event = src.m_event;
            // Delete the old ptr
            src.m_event = nullptr;
        }
        return *this;
    }

    Logger::~Logger() {
        delete[] m_event;
    }


    void Logger::arrayResize()
    {
        // create tmp array 
        Event* tmp = new Event[m_array];
        for (int i = 0; i < m_array; i++)
            tmp[i] = m_event[i];

        // clean the old array
        delete[] m_event;


        // resize array & copy the old array
        m_event = new Event[m_array + 1];
        for (int i = 0; i < m_array; i++)
            m_event[i] = tmp[i];

        // increment the size of the array 
        m_array++;
        delete[] tmp;
    }

    void Logger::addEvent(const Event& event) {
        this->arrayResize();
        m_event[m_array - 1] = event;
    }

    std::ostream& operator<<(std::ostream& out, Logger& log) {
        for (auto i = 0; i < log.m_array; ++i) {
            out << log.m_event[i] << std::endl;
        }
        return out;
    }
}

/*END OF PROGRAM*/