#include <bits/stdc++.h>
using namespace std;

const vector<string> key = {"sizeof", "static", "struct", "switch", "typedef",
                            "union", "const", "continue", "default", "if", "int", "long", "register", "return",
                            "short", "signed", "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "unsigned", "void", "volatile", "while", "auto", "break", "case", "char"};

bool isKey(const string &str)
{
    return find(key.begin(), key.end(), str) != key.end();
}

bool isOperator(const string &str)
{
    const vector<string> operators = {">=", "<=", "&&", "||", "!", "+=", "-=", "*=",
                                      "/=", "%=", "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<"};
    return find(operators.begin(), operators.end(), str) != operators.end();
}

bool isNumber(const string &str)
{
    bool decimal = false;
    for (char c : str)
    {
        if (c == '.' && !decimal)
        {
            decimal = true;
        }
        else if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

void analyzeTokens(const string &input)
{
    vector<string> tokens;
    string token;
    for (char c : input)
    {
        if (isspace(c) || c == ';')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += c;
        }
    }
    if (!token.empty())
    {
        tokens.push_back(token);
    }

    for (const string &token : tokens)
    {
        if (isKey(token))
        {
            cout << "Token: " << token << " -> Key" << endl;
        }
        else if (isOperator(token))
        {
            cout << "Token: " << token << " -> Operator" << endl;
        }
        else if (isNumber(token))
        {
            cout << "Token: " << token << " -> Number" << endl;
        }
        else
        {
            cout << "Token: " << token << " -> Identifier" << endl;
        }
    }
}

int main()
{
    string input1, input2;
    cout << "Enter first input: ";
    getline(cin, input1);
    cout << "Enter second input: ";
    getline(cin, input2);

    cout << "\nResult 1:\n";
    analyzeTokens(input1);

    cout << "\n\nResult 2:\n";
    analyzeTokens(input2);

    return 0;
}