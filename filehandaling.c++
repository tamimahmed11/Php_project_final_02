#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <cctype>

using namespace std;

// Function to check if a token is a keyword
bool isKeyword(const string &token) {
    unordered_set<string> keywords = {
        "int", "float", "double", "char", "bool", "if", "else", "while", "for",
        "do", "switch", "case", "break", "continue", "return", "void", "static",
        "const", "signed", "unsigned", "long", "short", "struct", "class", "private",
        "public", "protected", "virtual", "new", "delete", "try", "catch", "namespace",
        "using", "inline", "true", "false", "sizeof", "enum", "this", "nullptr"
    };
    return keywords.find(token) != keywords.end();
}

// Function to check if a token is an operator
bool isOperator(const char &ch) {
    string operators = "+-*/%=<>&|^!~";
    return operators.find(ch) != string::npos;
}

// Function to check if a token is a number
bool isNumber(const string &token) {
    for (char ch : token) {
        if (!isdigit(ch) && ch != '.') return false;
    }
    return !token.empty();
}

// Function to tokenize a line into words
vector<string> tokenize(const string &line) {
    vector<string> tokens;
    string token;
    for (char ch : line) {
        if (isalnum(ch) || ch == '.') {
            token += ch;
        } else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            if (isOperator(ch) || ispunct(ch)) {
                tokens.push_back(string(1, ch));
            }
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}

int main() {
    ifstream inputFile("source.cpp"); // Input file containing the C++ program
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string line;
    cout << "Lexical Analysis Output:\n";
    while (getline(inputFile, line)) {
        vector<string> tokens = tokenize(line);

        for (const string &token : tokens) {
            if (isKeyword(token)) {
                cout << "Token: " << token << " -> Keyword\n";
            } else if (isalpha(token[0]) || token[0] == '_') {
                cout << "Token: " << token << " -> Identifier\n";
            } else if (isNumber(token)) {
                cout << "Token: " << token << " -> Number\n";
            } else if (isOperator(token[0])) {
                cout << "Token: " << token << " -> Operator\n";
            } else {
                cout << "Token: " << token << " -> Symbol\n";
            }
        }
    }

    inputFile.close();
    return 0;
}
