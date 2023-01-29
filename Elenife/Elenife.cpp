#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string WriteFileInString() {
    string originText = "";
    fstream originFile;
    originFile.open("noEditText.txt", ios::in);

    if (originFile.is_open()) {
        while(originFile.good()){
            string newWord;
            originFile >> newWord;
            originText += newWord += " ";

        }
    }
    else
    {
        cout << "Error! File don't open!" << "\n";
    }

    originFile.close();
    return originText;
}

int main()
{
    string originText;
    originText = WriteFileInString();
    cout << originText << "\n";
    system("Pause");
    return 0;
}