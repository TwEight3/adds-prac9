#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

struct Document { //struct made instead of class as didn't want to make another file.
    std::string name;
    int id;
    int license_limit;
    int borrowed_count;
    std::unordered_set<int> patrons; //set used over map as patronID is unqiue number and only thing stored

    Document() : id(0), license_limit(0), borrowed_count(0) {}//sets everything to 0 to stop random values and mem leak

    Document(std::string name, int id, int license_limit)
        : name(name), id(id), license_limit(license_limit), borrowed_count(0) {}
};

class DocumentManager{

private:
    std::unordered_map<int, Document> documents; //map used to make searching for docid easier to code.
    std::unordered_set<int> patrons;


    public:
void addDocument(std::string name, int id, int license_limit);

void addPatron(int patronID);

int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void returnDocument(int docid, int patronID);



};



#endif