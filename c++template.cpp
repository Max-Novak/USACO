/*
ID: maxnova1
TASK: 
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream
#include<string>

using namespace std;

/*
TODO:

Notes:

*/
int main()
{
    ofstream outfile;
    ifstream infile;
    
    infile.open(".in");
    infile.close();
    outfile.open (".out");

    return 0;
}

//g++ compiler flags --> g++ x.cpp -O2 -lm -o <x.bin>
