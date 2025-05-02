//Tejasvi Nititnkumar Parmar



#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include "mediaItem.h"
#include "settings.h"
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace seneca {

    
    class TvShow;

    struct TvEpisode 
    {
        const TvShow* m_show{};            
        unsigned short m_numberOverall{}; 
        unsigned short m_season{};        
        unsigned short m_numberInSeason{}; 
        std::string m_airDate{};           
        unsigned int m_length{};           
        std::string m_title{};             
        std::string m_summary{};          

       
        TvEpisode(const TvShow* show, unsigned short numberOverall, unsigned short season,
            unsigned short numberInSeason, const std::string& airDate,
            unsigned int length, const std::string& title,
            const std::string& summary)
            : m_show(show), m_numberOverall(numberOverall), m_season(season),
            m_numberInSeason(numberInSeason), m_airDate(airDate), m_length(length),
            m_title(title), m_summary(summary) {}
    };

    class TvShow : public MediaItem 
    {
        std::string m_id;                     
        std::vector<TvEpisode> m_episodes;    // List of episodes....

        
        TvShow(const std::string& id, const std::string& title, const std::string& summary, unsigned short year)
            : MediaItem(title, summary, year), m_id(id) {}

    public:
      
        void display(std::ostream& out) const override;

      
        static TvShow* createItem(const std::string& strShow);

        
        template <typename Collection_t>
        static void addEpisode(Collection_t& col, const std::string& strEpisode)
        {
            if (strEpisode.empty() || strEpisode[0] == '#') {
                throw "Not a valid episode."; 
            }

            std::istringstream stream(strEpisode);
            std::string id, airDate, lengthStr, title, summary, seasonStr;
            unsigned short numberOverall, season = 1, numberInSeason;

        
            auto parseTime = [](const std::string& timeStr) -> unsigned int 
                {
                unsigned int hours = 0, minutes = 0, seconds = 0;
                char delimiter; // For ':'
                std::istringstream timeStream(timeStr);
                timeStream >> hours >> delimiter >> minutes >> delimiter >> seconds;
                return hours * 3600 + minutes * 60 + seconds; 
                };

            // Parsefields.......
            std::getline(stream, id, ',');             
            stream >> numberOverall;                     
            stream.ignore();                             
            std::getline(stream, seasonStr, ',');        
            stream >> numberInSeason;                    
            stream.ignore();                             
            std::getline(stream, airDate, ',');          
            std::getline(stream, lengthStr, ',');        
            std::getline(stream, title, ',');            
            std::getline(stream, summary);               

            // Trim ..........
            trim(id);
            trim(seasonStr);
            trim(airDate);
            trim(lengthStr);
            trim(title);
            trim(summary);

          
            if (seasonStr.empty()) 
            {
                season = 1; 
            }
            else {
                try {
                    season = std::stoi(seasonStr); 
                }
                catch (...) {
                    season = 1;
                }
            }

           
            unsigned int lengthInSeconds = parseTime(lengthStr);

            
            TvShow* matchingShow = nullptr;
            for (size_t i = 0; i < col.size(); ++i) {
                MediaItem* item = col[i];
                TvShow* show = dynamic_cast<TvShow*>(item);
                if (show && show->m_id == id) {
                    matchingShow = show;
                    break;
                }
            }
            if (!matchingShow) {
                throw "Show not found for episode."; 
            }

            
            TvEpisode episode = { matchingShow, numberOverall, season, numberInSeason, airDate, lengthInSeconds, title, summary };
            matchingShow->m_episodes.push_back(episode);
        }

       
        double getEpisodeAverageLength() const;


       
        std::list<std::string> getLongEpisodes() const;
    };
}

#endif 
