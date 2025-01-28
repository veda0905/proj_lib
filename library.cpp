#include "library.h"
#include <iostream>

bool Library::addbook(Book& b) {
    for (auto& bok : books) {
        if (bok.getisbn() == b.getisbn()) {
            cout << "Invalid request! Book with same isbn already exists\n";
            return false;
        }
    }
    books.push_back(b);
    return true;
}

bool Library::registermember(Member& m) {
    for (auto& mem : members) {
        if (mem.getmemberid() == m.getmemberid()) {
            cout << "Invalid request! Member with same id already exists\n";
            return false;
        }
    }
    members.push_back(m);
    return true;
}

bool Library::borrowbook(string memid, string isbn) {
    int bookin = -1, memin = -1;
    int b1=books.size();
    for (int i = 0; i < b1; i++) {
        if (books[i].getisbn() == isbn) {
            bookin = i;
            break;
        }
    }
    int m1=members.size();
    for (int i = 0; i < m1; i++) {
        if (members[i].getmemberid() == memid) {
            memin = i;
            break;
        }
    }
    if (bookin == -1 || memin == -1) {
        cout << "Invalid request! Book or member does not exist\n";
        return false;
    }
    if (!books[bookin].borrowbook()) {
        return false;
    }
    if (!members[memin].borrowbook(isbn)) {
        books[bookin].returnbook();
        return false;
    }

    return true;
}

bool Library::returnbook(string memid, string isbn) {
    int bookin = -1, memin = -1;
    int b1=books.size();
    for (int i = 0; i < b1; i++) {
        if (books[i].getisbn() == isbn) {
            bookin = i;
            break;
        }
    }
    int m1=members.size();
    for (int i = 0; i <m1; i++) {
        if (members[i].getmemberid() == memid) {
            memin = i;
            break;
        }
    }
    if (bookin == -1 || memin == -1) {
        cout << "Invalid request! Book or member does not exist\n";
        return false;
    }
    if (!books[bookin].returnbook()) {
        return false;
    }
    if (!members[memin].returnBook(isbn)) {
        books[bookin].borrowbook();
        return false;
    }
    return true;
}

void Library::printlibrarydetails() {
    for (auto& bok : books) {
        cout << bok.title << " " << bok.author << " " << bok.getcopiesavailable() << endl;
    }
    for (auto& mem : members) {
        cout << mem.getmemberid() << " " << mem.name << endl;
    }
}

void Library::updatecopy(string isbn, int count) {
    for (auto& bok : books) {
        if (bok.getisbn() == isbn) {
            bok.updatecopies(count);
            return;
        }
    }
    cout << "Invalid request! Book with given isbn does not exist\n";
}

bool Library::exists(string isbn) {
    for (auto& bok : books) {
        if (bok.getisbn() == isbn) {
            return true;
        }
    }
    return false;
}

Book Library::findbook(string isbn) {
    for (auto& bok : books) {
        if (bok.getisbn() == isbn) {
            return bok;
        }
    }
    return Book();
}

Member Library::findmember(string memberid) {
    for (auto& mem : members) {
        if (mem.getmemberid() == memberid) {
            return mem;
        }
    }
    return Member("", "", 0);
}