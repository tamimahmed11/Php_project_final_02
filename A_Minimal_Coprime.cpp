#include<bits/stdc++.h>
using namespace std;
int main() 
{
    string input;
    int choice;
    cout << "Select a pattern to match:\n";
    cout << "1. Starts with 'a' and ends with 'b'\n";
    cout << "2. Contains only vowels\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); 
    regex pattern;
    if (choice == 1) 
    {
        pattern = regex("^a.*b$");
    } else if (choice == 2) 
    {
        pattern = regex("^[aeiouAEIOU]+$");
    } 
    else 
    {
        cout << "Invalid choice. Exiting program.\n";
        return 1;
    }
    cout << "Enter a string: ";
    getline(cin, input);
    if (regex_match(input, pattern)) 
    {
        cout << "Accepted"<<endl;
    } 
    else 
    {
        cout << "Rejected"<<endl;
    }
    return 0;
}
