#include "Book.h"
#include <vector>

//Book catalog system for inputting book data by name, author, genre, and year of publishing
//can display whole catalog, search by book name, search book by author name
//TODO
//VERIFY INPUT FOR SETTERS AND GETTERS

Book* EnterBookData(){
    string bkName, authFrstName, authLastName, authNationality, genre; //for input better sep into function
    int year;
    
    
    cout << "Enter book name(-1 to exit): ";
    getline(cin,bkName);
    cout << "Enter author first name: ";
    getline(cin,authFrstName);
    cout << "Enter author last name: ";
    getline(cin,authLastName);
    cout << "Enter authors nationality: ";
    getline(cin,authNationality);
    cout << "Enter book genre: " ;
    getline(cin,genre);
    cout << "Enter year of publishing: " ;
    cin >> year;
    Author author( authFrstName, authLastName, authNationality);
    Book* book= new Book( bkName, author, genre, year);
    cin.ignore();
    return book;
}

void showHomeMenu(){
    cout << "Hello, welcome to the book inventory system,"<< endl << "1. enter book data, " << endl <<"2. View Book Catalog" << endl; 
    cout << "3. lookup books by name" << endl <<"4. search books by author"<< endl <<" ~ to exit: ";
}

string toLower(string str){          //COPY FOR USE ANYWHERE TOLOWER STRINGS
    string lStr;
    for (int i = 0; i < str.length(); i++){
        lStr+=char(tolower(str[i]));
    }
    return lStr;
}

int main(){
    vector<Author *> authors;
    vector<Book *> books;
    // string bkName, authFrstName, authLastName, authNationality, genre; //for input better sep into function
    // int year;
    Author brandoSando("Brandon", "Sanderson", "American");
    Book* b1Ptr = new Book("The Way of Kings", brandoSando, "Fantasy", 2020 );
    b1Ptr->print();
    books.push_back(b1Ptr);
    string usrInp;
    
    showHomeMenu();
    // cin.ignore();
    getline(cin, usrInp);
    while (usrInp != "~"){
        int choice = stoi(usrInp);
        string srchTerm, lSrchTrm, bookName, authorName, lBookName, lAuthorName; // added extra lStrings jsut to see the change to lower, we can always string = toLower(string); and use less vars
        bool bkFound = false;
        if (choice == 1){ //awaits inp for book data from user
            Book* bkPtr = EnterBookData();
            books.push_back(bkPtr);
            books.back()->print();
        }
        if (choice ==2){ // displays whole catalog
            for (int i = 0; i < books.size(); i++){
                books.at(i)->print();
            }
        }
        if (choice == 3){ //awaits search term to search for book in catalog
            cout << "Enter book name or part of name: ";
            getline(cin, srchTerm);
            lSrchTrm = toLower(srchTerm);
            for (int i = 0; i < books.size(); i++){
                bookName = books.at(i)->getName();
                lBookName = toLower(bookName);
                if ( lBookName.find(lSrchTrm) < 1000){
                    cout << "Book found: ";
                    books.at(i)->print();
                    bkFound = true;
                } 
            }
            if (!bkFound){
                cout << "Book not found in this catalog." << endl;
            }
        }
        if (choice == 4){ //awaits inp for author name to display books found under that name
            cout << "Enter author name: ";
            getline(cin, srchTerm);
            lSrchTrm = toLower(srchTerm);
            for (int i = 0; i < books.size(); i++){
                bookName = books.at(i)->getName();
                authorName = books.at(i)->getAuthor().getName() + " " + books.at(i)->getAuthor().getSurname();
                lAuthorName = toLower(authorName);
                if (lAuthorName.find(lSrchTrm) < 1000){
                    cout << "Book(s) found by author: ";
                    // cout << bookName << endl;   //or
                    books.at(i)->print();  //full info of book if not just title
                    bkFound = true;
                }
            }
            if (!bkFound){
                cout << "Book by that author not found in this catalog." << endl;
            }

        }
/*         // switch (choice){    //switch makes it all heccd up and doesnt want ot run, something anout cross initializing Book*
        //     case 1:
        //         Book* bkPtr = EnterBookData();
        //         books.push_back(bkPtr);
        //         books.back()->print();
                
        //         break;
        //     case 2:
        //         for (int i = 0; i < books.size(); i++){
        //             books.at(i)->print();
        //         }

        //         break;
        //     default:
        //         showHomeMenu();
 
        // } */     //uncomment switch case and ask why no go
 
        showHomeMenu();
        getline(cin, usrInp);

    }
    //pre alpha under this line/* 
    // books.push_back(b1Ptr);
    // brandoSando.print();
    // string s;
    // string sTrm;
    // cout << "Enter search term: ";
    // getline(cin, sTrm);
    // s = "The Way of Kings";
    // // cout << s.find("ings") << endl; // returns index at which it finds the given arg(string)
    // // cout << char(tolower(s[0])) << endl; //returns lowercase char at s[0]
    // string lSrch;
    // lSrch = toLower(s);
    // sTrm = toLower(sTrm);
    // cout << lSrch.find(sTrm) << endl; 
    // s.tolower();      */
    return 0;
}