#include <iostream>
#include <vector>

struct Contact {
    std::string name;
    std::string email;
};

void add_contact(std::vector<Contact>& contacts, const Contact& contact) {
    contacts.push_back(contact);
}

void list_contacts(const std::vector<Contact>& contacts) {
    for (const Contact& contact : contacts) {
        std::cout << contact.name << ": " << contact.email << std::endl;
    }
}

Contact find_contact(const std::vector<Contact>& contacts, const std::string& name) {
    for (const Contact& contact : contacts) {
        if (contact.name == name) {
            return contact;
        }
    }
}

int main() {
    std::vector<Contact> contacts;

    add_contact(contacts, Contact{"John", "john@email.com"});
    Contact contact = find_contact(contacts, "John");
    std::cout << contact.name << ": " << contact.email << std::endl;
    list_contacts(contacts);

    return 0;
}