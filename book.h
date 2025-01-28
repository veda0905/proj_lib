#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string isbn;
    int num_of_copies_available;
    int total_copies;

public:
    string title;
    string author;

    Book();
    Book(string t, string a, string i, int n, int n1);
    Book(Book& a, string new_isbn);

    string getisbn();
    int getcopiesavailable();
    int gettotalcopies();
    void updatecopies(int ct);
    bool borrowbook();
    bool returnbook();
    void printdetails();
};

#endif