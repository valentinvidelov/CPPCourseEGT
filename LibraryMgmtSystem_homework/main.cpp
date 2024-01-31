#include "Book.h"
#include "Member.h"


int main(){

    Member* m[2];               //initializng members pointer array 
    Member* m1 = new Member("Julian Assange", 50, "M345242");
    Member* m2 = new Member("Roger Waters", 45, "M000212");
    m[0]= m1;
    m[1] = m2;            //assigning member pointers to array

    // use book array per client request
    Book ba[2] = {Book("Mistborn", "Brando Sando", "ISBN4389423fake"), Book("How to Escape Belmarsh for Dummies", "Author Unknown", "ISBNfaux4389423")};

    m[1]->borrowBook(&ba[0]);
    m[0]->borrowBook(&ba[1]);
    
    return 0;
}