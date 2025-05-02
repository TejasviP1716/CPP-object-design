//Tejasvi Nititnkumar Parmar


#include "book.h"
#include <sstream>
namespace seneca {

    
    void Book::display(std::ostream& out) const {
        if (g_settings.m_tableView) { 
            out << "B | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | "; 

            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_country << " | "; 

            out << std::setw(4) << this->getYear() << " | "; 

            out << std::left;

            //maximum width..........
            if (g_settings.m_maxSummaryWidth > -1) {
                if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                    out << this->getSummary();
                else
                    out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
            else {
                out << this->getSummary();
            }
            out << std::endl;

        }
        else { 
            size_t pos = 0;
            out << this->getTitle() << " [" << this->getYear() << "] [";
            out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';

            
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
        }
    }

   
    Book* Book::createItem(const std::string& strBook)
    {
        if (strBook.empty() || strBook[0] == '#')
        {
            throw "Not a valid book.";
        }

        std::istringstream stream(strBook); 
        std::string author, title, country, priceStr, yearStr, summary;

        //cvs fields
        std::getline(stream, author, ',');
        std::getline(stream, title, ',');
        std::getline(stream, country, ',');
        std::getline(stream, priceStr, ',');
        std::getline(stream, yearStr, ',');
        std::getline(stream, summary);

      //trim
        trim(author);
        trim(title);
        trim(country);
        trim(summary);

        // Convert appropriate types
        unsigned short year = std::stoi(yearStr);
        double price = std::stod(priceStr);

        return new Book(title, summary, year, author, country, price);
    }

}  
