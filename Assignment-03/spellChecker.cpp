//Tejasvi Nititnkumar Parmar


#include "spellChecker.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>  
namespace seneca {

  
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename); 
        if (!file) {
            throw "bad file name"; 
        }

        std::string line;  
        size_t loop = 0;  

       
        while (std::getline(file, line) && loop < 6) {
            std::istringstream stream(line); // Parse ...........
            stream >> m_badWords[loop] >> m_goodWords[loop]; 
            ++loop;
        }

        // 6 word pairs..........
        if (loop < 6) {
            throw "file does not contain enough word pairs.";
        }
    }

    
    void SpellChecker::operator()(std::string& text) {
        for (size_t i = 0; i < 6; ++i) { 
            size_t position = text.find(m_badWords[i]); 
            while (position != std::string::npos) { 
                text.replace(position, m_badWords[i].length(), m_goodWords[i]); 
                ++m_replacementCounts[i]; 
                position = text.find(m_badWords[i], position + m_goodWords[i].length()); 
            }
        }
    }

  
    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics\n";
        for (size_t i = 0; i < 6; ++i) { 
            out << std::left << std::setw(15) << m_badWords[i] << ": "  
                << m_replacementCounts[i] << " replacements" << std::endl; 
        }
    }

} 
