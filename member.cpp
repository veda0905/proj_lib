#include "member.h"
#include <iostream>

Member::Member(string mid, string nme, int bl) {
    memberid = mid;
    name = nme;
    borrow_limit = bl;
    borrowcount = 0;
}

Member::Member(string mid, string nme) {
    borrow_limit = 3;
    memberid = mid;
    borrowcount = 0;
    name = nme;
}

string Member::getmemberid() {
    return memberid;
}

bool Member::borrowbook(string isbn) {
    if (borrowcount == borrow_limit) {
        cout << "Invalid request! Borrow limit exceeded\n";
        return false;
    } else {
        borrowedbooks[isbn]++;
        borrowcount++;
        return true;
    }
}

bool Member::returnBook(string isbn) {
    if (borrowedbooks[isbn] == 0) {
        cout << "Invalid request! Book not borrowed\n";
        return false;
    } else {
        borrowedbooks[isbn]--;
        borrowcount--;
        return true;
    }
}

void Member::printDetails() {
    for (auto& book : borrowedbooks) {
        if (book.second > 0) {
            cout << memberid << " " << name << " " << book.first << " " << book.second << endl;
        }
    }
}