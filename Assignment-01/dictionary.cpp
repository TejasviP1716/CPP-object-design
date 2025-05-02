/**************************************


Name: Tejasvi NitinKumar Parmar

submission date: 02/02/2025


**************************************/


#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "dictionary.h"

namespace seneca {
    std::string Word::getPos() {
        switch (m_pos) {
        case PartOfSpeech::Noun: return " - (noun)";
        case PartOfSpeech::Pronoun: return " - (pronoun)";
        case PartOfSpeech::Adjective: return " - (adjective)";
        case PartOfSpeech::Adverb: return " - (adverb)";
        case PartOfSpeech::Verb: return " - (verb)";
        case PartOfSpeech::Preposition: return " - (preposition)";
        case PartOfSpeech::Conjunction: return " - (conjunction)";
        case PartOfSpeech::Interjection: return " - (interjection)";
        default: return " - ";
        }
    }

    Dictionary::Dictionary() : m_words(nullptr), m_lenghtArray(0) {}

    Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_lenghtArray(0) {
        if (!filename || std::string(filename).empty()) {
            std::cerr << "Error: No filename provided to the Dictionary constructor." << std::endl;
            return;
        }

        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: Cannot open file: " << filename << std::endl;
            return;
        }
        std::string line;
        std::vector<Word> words;

        while (std::getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            if (pos1 != std::string::npos && pos2 != std::string::npos) {
                Word word;
                word.m_word = line.substr(0, pos1);
                std::string pos = line.substr(pos1 + 1, pos2 - pos1 - 1);
                word.m_definition = line.substr(pos2 + 1);

                if (pos == "n." || pos == "noun") word.m_pos = PartOfSpeech::Noun;
                else if (pos == "v. i." || pos == "v. t.") word.m_pos = PartOfSpeech::Verb;
                else if (pos == "a." || pos == "adjective" || pos == "adject.") word.m_pos = PartOfSpeech::Adjective;


                words.push_back(word);
            }
        }

        m_lenghtArray = words.size();
        m_words = new Word[m_lenghtArray];
        for (int i = 0; i < m_lenghtArray; ++i) {
            m_words[i] = words[i];
        }
    }

    Dictionary::Dictionary(const Dictionary& src) : m_words(nullptr), m_lenghtArray(0) {
        *this = src;
    }

    Dictionary::Dictionary(Dictionary&& src) noexcept : m_words(nullptr), m_lenghtArray(0) {
        *this = std::move(src);
    }

    Dictionary& Dictionary::operator=(const Dictionary& src) {
        if (this != &src) {
            delete[] m_words;
            m_lenghtArray = src.m_lenghtArray;
            m_words = new Word[m_lenghtArray];
            for (int i = 0; i < m_lenghtArray; ++i) {
                m_words[i] = src.m_words[i];
            }
        }
        return *this;
    }

    Dictionary& Dictionary::operator=(Dictionary&& src) noexcept {
        if (this != &src) {
            delete[] m_words;
            m_words = src.m_words;
            m_lenghtArray = src.m_lenghtArray;
            src.m_words = nullptr;
            src.m_lenghtArray = 0;
        }
        return *this;
    }

    Dictionary::~Dictionary() {
        delete[] m_words;
    }

    void Dictionary::searchWord(const char* word) const {
        if (!m_words || m_lenghtArray == 0) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
            return;
        }

        bool found = false;
        // we get the lenght of the word
        size_t wordLength = 0; 

        // Only T1 will have POS - others woundl not 
        bool showPos = g_settings.m_verbose; 

        for (int i = 0; i < m_lenghtArray; ++i) {
            if (m_words[i].m_word == word) {
                if (!found) {
                    // 1st definition: it will print the word in T1
                    std::cout << m_words[i].m_word;
                    std::string pos = m_words[i].getPos();

                    if (showPos && pos != " - ")
                    {
                        // no extra space
                        std::cout << pos; 
                        std::cout << " " << m_words[i].m_definition << std::endl;

                        wordLength = m_words[i].m_word.length();

                        found = true;
                    }

                    else
                    {
                        std::cout << " - " << m_words[i].m_definition << std::endl;

                        wordLength = m_words[i].m_word.length();
                        found = true;
                    }
                }
                else 
                {
                    //  Align the `-` properly
                    std::cout << std::string(wordLength, ' '); 
                    std::string pos = m_words[i].getPos();

                    if (showPos && pos != " - ") {
                        std::cout << pos; 
                    }
                    else 
                    {
                        // For  the words without POS
                        std::cout << " -"; 
                    }
                    std::cout << " " << m_words[i].m_definition << std::endl;
                }
                if (!g_settings.m_show_all) break;
            }
        }

        if (!found) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }

}
/*END OF PROGRAM*/
