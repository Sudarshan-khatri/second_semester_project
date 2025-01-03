#include <windows.h>
#include <iostream>
using namespace std;


}

int main() {
    setColor(4); // Red
    cout << "This is red text" << endl;

    setColor(2); // Green
    cout << "This is green text" << endl;

    setColor(1); // Blue
    cout << "This is blue text" << endl;

    setColor(7); // Default
    cout << "This is default text" << endl;

    return 0;
}

