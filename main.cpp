#include <iostream>
#include "library.h"

using namespace std;

int main() {
    Library lib;
    string command;
    int i = 0;
    while (cin >> command) {
        i++;
        if (command == "Done") break;

        if (command == "Book") {
            string first;
            cin >> first;

            if (first == "None") {
                Book b;
                lib.addbook(b);
            } else {
                string second, third;
                cin >> second >> third;
                if (!lib.exists(second)) {
                    int n1, n2;
                    cin >> n1 >> n2;
                    Book b(first, second, third, n1, n2);
                    lib.addbook(b);
                } else {
                    Book existingBook = lib.findbook(second);
                    Book newBook(existingBook, third);
                    lib.addbook(newBook);
                }
            }
        } else if (command == "UpdateCopiesCount") {
            string isbn;
            int count;
            cin >> isbn >> count;
            lib.updatecopy(isbn, count);
        } else if (command == "Member") {
            string first;
            cin >> first;
            if (first == "NoBorrowLimit") {
                string second, third;
                cin >> second >> third;
                Member m(second, third);
                lib.registermember(m);
            } else {
                string second;
                int third;
                cin >> second >> third;
                Member m(first, second, third);
                lib.registermember(m);
            }
        } else if (command == "Borrow") {
            string memberId, isbn;
            cin >> memberId >> isbn;
            lib.borrowbook(memberId, isbn);
        } else if (command == "Return") {
            string memberId, isbn;
            cin >> memberId >> isbn;
            lib.returnbook(memberId, isbn);
        } else if (command == "PrintBook") {
            string isbn;
            cin >> isbn;
            Book b = lib.findbook(isbn);
            if (b.getisbn() == "ISBN") {
                cout << "Invalid request! Book with given isbn does not exist\n";
                continue;
            }
            b.printdetails();
        } else if (command == "PrintMember") {
            string memberId;
            cin >> memberId;
            Member m = lib.findmember(memberId);
            if (m.getmemberid() == "") {
                cout << "Invalid request! Member with given id does not exist\n";
                continue;
            }
            m.printDetails();
        } else if (command == "PrintLibrary") {
            lib.printlibrarydetails();
        }
    }
    return 0;
}