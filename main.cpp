#include <iostream>
#include "DocumentManager.h"
using namespace std;


int main(){
    DocumentManager a;
    a.addDocument("aaa", 111, 3);
    a.addDocument("bbb", 112, 8);
    a.addDocument("ccc", 113, 1);
    a.addDocument("ddd", 114, 0);

    a.addPatron(1);
    cout<<a.search("ccc")<<endl;
    cout<<a.search("ddd")<<endl;

    cout<<a.borrowDocument(113, 1)<<endl;
    cout<<a.search("ccc")<<endl;
    cout<<a.borrowDocument(113, 1)<<endl;
    a.returnDocument(113, 1);
    cout<<a.borrowDocument(113, 1)<<endl;
}