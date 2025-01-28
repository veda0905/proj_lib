#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "book.h"
#include "member.h"

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    bool addbook(Book& b);
    bool registermember(Member& m);
    bool borrowbook(string memid, string isbn);
    bool returnbook(string memid, string isbn);
    void printlibrarydetails();
    void updatecopy(string isbn, int count);
    bool exists(string isbn);
    Book findbook(string isbn);
    Member findmember(string memberid);
};

#endif