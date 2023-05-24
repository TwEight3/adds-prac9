#include "DocumentManager.h"

void DocumentManager::addDocument(std::string name, int id, int license_limit){
    
     Document doc(name, id, license_limit);
        documents[id] = doc;

}

void DocumentManager::addPatron(int patronID){
     patrons.insert(patronID);
}

int DocumentManager::search(std::string name){
     for (const std::pair<const int, Document>& pair : documents) {
            if (pair.second.name == name) {
                return pair.second.id;
            }
        }
        return 0;
} // returns docid if name is in the document collection or 0 if the name is not in the collection

bool DocumentManager::borrowDocument(int docid, int patronID){
       if (documents.find(docid) == documents.end() || patrons.find(patronID) == patrons.end()) {
            return false;  // Invalid document or patron ID
        }

        Document& doc = documents[docid];
        if (doc.borrowed_count >= doc.license_limit) {
            return false;  // License limit reached
        }

        doc.borrowed_count++;
        doc.patrons.insert(patronID);
        return true;
}  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void DocumentManager::returnDocument(int docid, int patronID){
        if (documents.find(docid) == documents.end() || patrons.find(patronID) == patrons.end()) {
            return;  // Invalid document or patron ID
        }

        Document& doc = documents[docid];
        doc.borrowed_count--;
        doc.patrons.erase(patronID);
    }
