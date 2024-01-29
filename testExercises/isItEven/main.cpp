#include <iostream>

using namespace std;

int main () {
    int n, usrInp;
    cout << "enter how many numbers you will be testing: " << endl;
    cin >> n;
    for (int i=0; i <= n; i++) {
        cout << "enter whole number: " << endl;
        cin >> usrInp;
        if (usrInp % 2 == 0){
            cout << "Even" << endl;
        } 
        else {
            cout << "Odd" << endl;
        }
    }
    return 0;
}