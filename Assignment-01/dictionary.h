/**************************************


Name: Tejasvi NitinKumar Parmar

submission date: 02/02/2025


**************************************/


#pragma once
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include "settings.h"

namespace seneca {
    extern Settings g_settings;

    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection,
    };

    struct Word {
        std::string m_word;
        std::string m_definition;
        PartOfSpeech m_pos = PartOfSpeech::Unknown;

        std::string getPos();
    };

    class Dictionary {
        Word* m_words;
        int m_lenghtArray;
    public:
        Dictionary();
        Dictionary(const char* filename);
        Dictionary(const Dictionary& src);
        Dictionary(Dictionary&& src) noexcept;
        Dictionary& operator=(const Dictionary& src);
        Dictionary& operator=(Dictionary&& src) noexcept;
        ~Dictionary();

        void searchWord(const char* word) const;
    };
}

#endif 
/* SENECA_DICTIONARY_H */
/*END OF PROGRAM*/
