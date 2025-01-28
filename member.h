#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <map>
using namespace std;

class Member {
private:
    string memberid;
    int borrow_limit;
    int borrowcount;
    map<string, int> borrowedbooks;

public:
    string name;

    Member(string mid, string nme, int bl);
    Member(string mid, string nme);

    string getmemberid();
    bool borrowbook(string isbn);
    bool returnBook(string isbn);
    void printDetails();
};

#endif