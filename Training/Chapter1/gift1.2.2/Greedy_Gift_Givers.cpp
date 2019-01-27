/*
ID: maxnova1
TASK: gift1
LANG: C++
*/

<<<<<<< HEAD
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
=======
#include <fstream>//file stream
#include <iostream>//input output stream
#include <string>
#include <vector>

using namespace std;

/*
TODO:
    -take all the data and place into variables
    -do math
    -output to file in format
    /*
    dave    laura
    init
Notes:
	-I learn how to use vectors here
    -i think doing all the input and output stuff in main and calling functions ofr the logic is the best
    =https://stackoverflow.com/questions/8067338/vector-of-structs-initialization#8067443
    -while(!infile.eof()) this didnt work
*/
struct Person
{
    string name;
    int bal;
};

void calcMoney(ifstream &infile, vector<Person> &users)
{
    string giver;
    int deposit, total = 0, give_each, keep;
    infile >> giver;
    infile >> deposit;
    infile >> total;
    if(total == 0)
    {
        give_each = 0;
		keep = 0;
    }
    else
    {
        give_each = deposit / total;
        keep = deposit % total;
    }


    for(int z = 0; z < users.size(); z++)
    {
        if(giver == users[z].name)
            users[z].bal += deposit*-1 + keep;
    }


    for(int i = 0; i < total; i++)
    {
        string taker;
        infile >> taker;
        for(int x = 0; x < users.size(); x++)
        {
            if(taker == users[x].name)
                users[x].bal += give_each;
        }
    }
}

int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("gift1.in");
    int numPeople;

    infile >> numPeople;

    //vector<Person> users(numPeople);
    vector<Person> users;
    for(int i = 0; i < numPeople; i++)
    {
        users.push_back(Person());
        infile >> users[i].name;
        users[i].bal = 0;
    }
	int x = users.size();
    printf("%d", x);
    //while(!infile.eof())
    for(int y = 0; y < numPeople; y++)
    {
        calcMoney(infile, users);
    }

    infile.close();
    outfile.open ("gift1.out");

    for(int i = 0; i < users.size(); i++)
        outfile << users[i].name << " " << users[i].bal << "\n";

    return 0;
}

//g++ compiler flags --> g++ x.cpp -O2 -lm -o <x.bin>
>>>>>>> ad3a01ad330cc9a3ca97ec7f23bc178a38eaf101
