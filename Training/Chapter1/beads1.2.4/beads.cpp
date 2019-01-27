/*
ID: maxnova1
TASK: beads
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream
#include<string>

using namespace std;

typedef int i;

/*
TODO:
    load beads into array
        scan settings all white beads to red
        scan setting all white beads to blue
        find where left + right is consecutivly greatest

Notes:

*/
int main()
{
    ofstream outfile;
    ifstream infile;
    i numBeads;
    string necklace;
    char parseNecklace[351];
    i score;
    infile.open("beads.in");

    //take in data
    infile >> numBeads;
    infile >> parseNecklace;       
           
    for(int i = 0; i < numBeads; i++)
    {
        //char x = string[i];
        /*
        for(TAKE INITAL LEFT AND KEEP LOOKING FOR COLOR OR WHITE THEN STOP)

        for(TAKE INITAL RIGHT AND KEEP LOOKING FOR COLOR OR WHITE THEN STOP (SET WHITE TO SEARING COLOR))

         COUNT UP INDEXS TRAVELED
         */
    }




    /////////debugging
    cout << numBeads;
    cout << parseNecklace;
    /////////

    infile.close();
    outfile.open ("beads.out");

    return 0;
}