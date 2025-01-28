#include "book.h"
#include <iostream>

Book::Book() {
    title = "UnknownTitle";
    author = "UnknownAuthor";
    isbn = "ISBN";
    num_of_copies_available = 0;
    total_copies = 5;
}

Book::Book(string t, string a, string i, int n, int n1) {
    title = t;
    author = a;
    isbn = i;
    total_copies = n;
    num_of_copies_available = n1;
}

Book::Book(Book& a, string new_isbn) {
    this->title = a.title;
    this->author = a.author;
    this->isbn = new_isbn;
    this->total_copies = a.gettotalcopies();
    this->num_of_copies_available = a.getcopiesavailable();
}

string Book::getisbn() {
    return isbn;
}

int Book::getcopiesavailable() {
    return num_of_copies_available;
}

int Book::gettotalcopies() {
    return total_copies;
}

void Book::updatecopies(int ct) {
    if (ct + num_of_copies_available < 0) {
        cout << "Invalid request! Count becomes negative\n";
        return;
    }
    num_of_copies_available += ct;
    total_copies += ct;
}

bool Book::borrowbook() {
    if (num_of_copies_available > 0) {
        num_of_copies_available -= 1;
        return true;
    } else {
        cout << "Invalid request! Copy of book not available\n";
        return false;
    }
}

bool Book::returnbook() {
    if (num_of_copies_available == total_copies) {
        cout << "Invalid request! Copy of book exceeds total copies\n";
        return false;
    } else {
        num_of_copies_available += 1;
        return true;
    }
}

void Book::printdetails() {
    cout << title << ' ' << author << endl;
}