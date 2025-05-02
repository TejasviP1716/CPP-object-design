//Tejasvi Nititnkumar Parmar


#include "collection.h"
#include <stdexcept>
#include <iomanip>
namespace seneca 

{

    
    Collection::Collection(const std::string& name) : m_name(name) {}

    
    Collection::~Collection() {
        for (auto item : m_items) {
            delete item; 
        }
    }

    
    const std::string& Collection::name() const {
        return m_name;
    }

    
    size_t Collection::size() const
    {
        return m_items.size();
    }

    // Observer callback........
    void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
        m_observer = observer;
    }

    
    Collection& Collection::operator+=(MediaItem* item) 
    {
       
        auto it = std::find_if(m_items.begin(), m_items.end(),
            [item](const MediaItem* existingItem) {
                return existingItem->getTitle() == item->getTitle();
            });
        if (it != m_items.end()) {
            delete item;  
        }
        else {
            m_items.push_back(item);  
            if (m_observer) {
                m_observer(*this, *item);  
            }
        }
        return *this;
    }

    
    MediaItem* Collection::operator[](size_t idx) const
    {
        if (idx >= m_items.size()) 
        {
            throw std::out_of_range("Bad index [" + std::to_string(idx) +
                "]. Collection has [" + std::to_string(m_items.size()) + "] items."); 
        }
        return m_items[idx];
    }

   
    MediaItem* Collection::operator[](const std::string& title) const 
    {
        auto it = std::find_if(m_items.begin(), m_items.end(),
            [title](const MediaItem* item) {
                return item->getTitle() == title;
            });
        return (it != m_items.end()) ? *it : nullptr;
    }

    
    std::string trimQuotes(const std::string& str)
    {
        if (str.empty()) return str;

        if (str.front() == '"' && str.back() == '"')
        {
            return str.substr(1, str.size() - 2); 
        }
        else if (str.front() == '"') {
            return str.substr(1); 
        }
        else if (str.back() == '"') {
            return str.substr(0, str.size() - 1); 
        }
        return str;
    }

    void Collection::removeQuotes() 
    {
        for (auto& item : m_items) {
            if (item) { 
                item->setTitle(trimQuotes(item->getTitle()));   
                item->setSummary(trimQuotes(item->getSummary())); 
            }
        }
    }

   
    void Collection::sort(const std::string& field)
    {
        if (field == "title") {
            std::sort(m_items.begin(), m_items.end(),
                [](const MediaItem* a, const MediaItem* b)
                {
                    return a->getTitle() < b->getTitle(); 
                });
        }
        else if (field == "year") {
            std::sort(m_items.begin(), m_items.end(),
                [](const MediaItem* a, const MediaItem* b)
                {
                    return a->getYear() < b->getYear(); 
                });
        }
    }

    
    std::ostream& operator<<(std::ostream& out, const Collection& collection) {
        for (const auto& item : collection.m_items) {
            out << *item;
        }
        return out;
    }

} 
