#include "book.h"

using namespace std;

int main() {
    Book book;

    Contact c;
    c.email = "c@em";
    c.name = "c";

    book.add_contact(c);
    book.list_contacts();
    book.save_to_csv("D:/eblan/eb.csv");

    return 0;
}