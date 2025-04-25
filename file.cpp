#include <iostream>
#include <fstream>

using namespace std; 

int main() 
{
    ofstream my_file("example.txt");
    ofstream file2("tamim.txt");

    
    file2.close();
    my_file.close();
    return 0;
}