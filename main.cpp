#include <iostream>

#include "book.h"

using namespace std;

void cycle() {
    Book book;
    const char* user_env = std::getenv("USERNAME");
    string user(user_env);
    book.load_from_csv("C:/Users/" + user + "/contactsBook.csv");

    while (true) {
        cout << "1 - Add | 2 - List | 3 - Get | 4 - Save" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            default:
                cout << "Invalid choice" << endl;
                break;

            case 1: {
                Contact c;
                cout << "Enter name: ";
                cin >> c.name;
                cout << endl;
                cout << "Enter email: ";
                cin >> c.email;
                cout << endl;
                book.add_contact(c);
                break;
            }

            case 2:
                book.list_contacts();
                break;

            case 3: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                cout << endl;
                Contact co = book.get_contact(name);
                cout << co.name << " with email: " << co.email << endl;
                break;
            }

            case 4: {
                book.save_to_csv("C:/Users/" + user + "/contactsBook.csv");
            }
        }
    }
}

int main() {
    cycle();
    return 0;
}