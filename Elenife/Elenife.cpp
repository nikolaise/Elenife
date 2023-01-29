#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string originText;
    fstream originFile;
    originFile.open("noEditText.txt", ios::in);

    if (originFile.is_open()) {
        while (getline(originFile, originText)) {
            cout << originText << "\n";
        }
        originFile.close();
    }
    else
    {
        cout << "Error! File don't open!" << "\n";
    }
    system("Pause");
    return 0;
}