#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_set>
using namespace std;

unordered_set<string> keywords = {"int", "float", "double", "char", "return", "if", "else", "for", "while"};
unordered_set<char> operators = {'+', '-', '*', '/', '=', '<', '>'};
unordered_set<char> symbols = {';', '(', ')', '{', '}', ','};

bool isNumber(const string &str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.') return false;
    }
    return !str.empty();
}

void tokenize(const string &filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    
    string token;
    char ch;
    
    while (file.get(ch)) {
        if (isspace(ch)) {
            if (!token.empty()) {
                if (keywords.count(token))
                    cout << "Token: " << token << " -> Keyword" << endl;
                else if (isNumber(token))
                    cout << "Token: " << token << " -> Number" << endl;
                else
                    cout << "Token: " << token << " -> Identifier" << endl;
                token.clear();
            }
        } else if (operators.count(ch)) {
            if (!token.empty()) {
                if (keywords.count(token))
                    cout << "Token: " << token << " -> Keyword" << endl;
                else if (isNumber(token))
                    cout << "Token: " << token << " -> Number" << endl;
                else
                    cout << "Token: " << token << " -> Identifier" << endl;
                token.clear();
            }
            cout << "Token: " << ch << " -> Operator" << endl;
        } else if (symbols.count(ch)) {
            if (!token.empty()) {
                if (keywords.count(token))
                    cout << "Token: " << token << " -> Keyword" << endl;
                else if (isNumber(token))
                    cout << "Token: " << token << " -> Number" << endl;
                else
                    cout << "Token: " << token << " -> Identifier" << endl;
                token.clear();
            }
            cout << "Token: " << ch << " -> Symbol" << endl;
        } else {
            token += ch;
        }
    }
    
    if (!token.empty()) {
        if (keywords.count(token))
            cout << "Token: " << token << " -> Keyword" << endl;
        else if (isNumber(token))
            cout << "Token: " << token << " -> Number" << endl;
        else
            cout << "Token: " << token << " -> Identifier" << endl;
    }
    
    file.close();
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    tokenize(filename);
    return 0;
}
