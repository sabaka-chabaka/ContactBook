#include "book.h"

#include <iostream>

void Book::add_contact(Contact &contact) {
    contacts.push_back(contact);
}

void Book::list_contacts() {
    for (const Contact& contact : contacts) {
        std::cout << contact.name << ": " << contact.email << std::endl;
    }
}

Contact Book::get_contact(std::string name) {
    for (const Contact& contact : contacts) {
        if (contact.name == name) {
            return contact;
        }
    }
}