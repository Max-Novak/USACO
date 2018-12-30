/*
ID: maxnova1
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

struct Person
{
    int money = 0;
    string name;
};


/*
TODO:
UNDERSTAND LOGIC BETTER AND HOW TO READ NUMBERS VS WORDS
Notes:
*/
int main()
{   
    ofstream outfile;
    ifstream infile;
    int numPeople;

    infile.open("gift1.in");

    infile >> numPeople;
    struct Person people[numPeople];

    while(!(infile.eof())) 
    {
        string prevLine = to_string(numPeople);
        infile >> prevLine;
        if(cin >> numPeople)
        {
            //line is a number
            //take the number in and the next number
            int giftMoney, giftPeople;
            cin >> giftPeople;

        }

    }
    

    cout << numPeople << "\n";//debug output
    //struct body bodies[numPeople];
    //INPUT FORMAT
        //Giver
        //cash num people
        //People given to
    //create people in group
    //first is name
    //take money and go back
        //sub given and add remainder
    //
    outfile.open ("gift1.out");
    infile.close();

    return 0;
}