#include "book.h"

using namespace std;

int main() {
    Book book;

    book.load_from_csv("D:/eblan/eb.csv");
    book.list_contacts();

    return 0;
}