/*  

Class Design and Objects: Design a class named Book with private 
attributes for title (string), author (string), and pages (int). Include 
a constructor to initialize these attributes and a public method display() 
to print the book's details.

*/

#include <iostream>
using namespace std;

class Book{

public:
    Book(string t, string a, int p){
        title = t;
        author = a;
        pages = p;
    }
    void display(){
        cout << "Book title: " << title << "\nWritten by: " << author <<
        "\nPage Count: " << pages << endl;
    }

private:
    string title, author;
    int pages;

};

int main(){

    Book b1("The Thief", "Megan Whalen Turner", 219);
    b1.display();
    
    return 0;
}