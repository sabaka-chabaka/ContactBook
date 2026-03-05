#include "book.h"

using namespace std;

int main() {
    Book book;

    Contact c;
    c.email = "c@em";
    c.name = "c";

    book.add_contact(c);
    book.list_contacts();

    return 0;
}