#include "book.h"

#include <fstream>
#include <iostream>

void Book::add_contact(Contact &contact) {
    contacts.push_back(contact);
}

void Book::list_contacts() {
    for (const Contact& contact : contacts) {
        std::cout << contact.name << ": " << contact.email << std::endl;
    }
}

void Book::save_to_csv(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return;
    for (const auto& contact : contacts) {
        file << contact.name << "," << contact.email << "\n";
    }
    file.close();
}

Contact Book::get_contact(std::string name) {
    for (const Contact& contact : contacts) {
        if (contact.name == name) {
            return contact;
        }
    }
}
