#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream filename("time.txt");
    filename <<"MY text document";
    filename.close();
    
 // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("time.txt");
  while (getline (MyReadFile, myText)) 
  {
    cout << myText;
  }
  MyReadFile.close();
  return 0;
}
