//Tejasvi Nititnkumar Parmar


#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
namespace seneca {

    struct Settings 
    {
        short m_maxSummaryWidth = 80; // Maximum width 80...........
        bool m_tableView = false;     
    };

    
    extern Settings g_settings;
}

#endif 
