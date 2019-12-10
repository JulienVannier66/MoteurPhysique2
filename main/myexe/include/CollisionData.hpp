#pragma once
#include <Contact.hpp>
#include <vector>

class CollisionData
{
private:
    std::vector<Contact> m_contacts;
    int m_contactRestant = 0;

public:
    CollisionData(){};

    void addContact(Contact p_contact)
    {
        m_contacts.push_back(p_contact);
        m_contactRestant++;
    }
};