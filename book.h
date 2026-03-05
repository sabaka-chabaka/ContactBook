#ifndef CONTACTBOOK_BOOK_H
#define CONTACTBOOK_BOOK_H
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string email;
};

class Book {
private:
    std::vector<Contact> contacts;

public:

    void add_contact(Contact &contact);

    void list_contacts();

    void save_to_csv(const std::string &filename);

    std::vector<std::string> split(const std::string &line, char delimiter = ',');

    void load_from_csv(const std::string& filename);

    Contact get_contact(std::string name);
};


#endif