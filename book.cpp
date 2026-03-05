#include "book.h"

#include <fstream>
#include <iostream>
#include <sstream>

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

std::vector<std::string> Book::split(const std::string &line, char delimiter) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        parts.push_back(item);
    }
    return parts;
}

void Book::load_from_csv(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        auto parts = split(line, ',');
        if (parts.size() < 2) continue;

        Contact c;
        c.name  = parts[0];
        c.email = parts[1];

        contacts.push_back(c);
    }
}

Contact Book::get_contact(std::string name) {
    for (const Contact& contact : contacts) {
        if (contact.name == name) {
            return contact;
        }
    }
}
