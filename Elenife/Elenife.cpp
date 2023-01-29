#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
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

string LowerCase(string editedOriginText) {

    for (int i = 0;i < editedOriginText.length();i++) {
        editedOriginText[i] = towlower(editedOriginText[i]);
    }
    return editedOriginText;
}

string RemoveNotEnglishAlphabetCharacters(string editedOriginText) {
    for (int i = 0;i < editedOriginText.length();i++) {
        if ((editedOriginText[i] < 'a' || editedOriginText[i]>'z') &&
            (editedOriginText[i] < 'A' || editedOriginText[i]>'Z') &&
            editedOriginText[i]!=' ') {
            editedOriginText[i] = '\0';
        }
    }
    return editedOriginText;
}

string EditOriginText(string originText) {
    string editedOriginText = originText;
    editedOriginText = LowerCase(editedOriginText);
    editedOriginText = RemoveNotEnglishAlphabetCharacters(editedOriginText);

    return editedOriginText;
}

int main()
{
    string originText;
    originText = WriteFileInString();

    string editedOriginText;
    editedOriginText = EditOriginText(originText);

    cout << editedOriginText << "\n";
    system("Pause");
    return 0;
}