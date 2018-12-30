/*
ID: maxnova1
TASK: 
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream

using namespace std;

#define POUR 100
#define NUM_BUCKET 3

/*
TODO:
    FIND OUT HOW TO READ UNTIL EOF
Notes:
-Take bucket from each cow --> diff size --> maybe not full
1 --> 1 into 2, 2 into 3, 3 into 1, 1 into 2, etc
TOTAL OF 100 POURS
PRINT TOTAL OF EACH BUCKET AFTER THE 100 POURS
POURING ENDS WHEN  
    --> BUCKET B IS FULL OR A IS EMPTY
*/

void print_buck(int cows[]);
void calc_buck(int cows[], int capacity[]);
void read_input(int cows[], int capacity[]);

int main()
{
    //WORK ON UNDERSTANDING POINTERS
    int cows[NUM_BUCKET];
    int capacity[NUM_BUCKET];
    
    read_input(cows, capacity);
    calc_buck(cows, capacity);
    print_buck(cows);    

    return 0;
}

//WORKS
void read_input(int cows[], int capacity[])
{
    ifstream infile;
    infile.open("mixmilk.in");

    for(int y = 0; y < NUM_BUCKET; y++)
    {
        infile >> capacity[y];
        infile >> cows[y];
    }

    infile.close();
}

//MISSING SOME CASES --> I DUNNO 
void calc_buck(int cows[], int capacity[])
{
    for(int i = 0; i < POUR; i++)
    {
        //overflow test a overflows b
        if(capacity[(i+1)%3] -(cows[i%3] + cows[(i+1)%3]) >= 0)
        {
            cows[(i+1)%3] += cows[i%3];
            cows[i%3] = 0;
        }
        else
        {
            int temp = (capacity[(i+1)%3] - cows[(i+1)%3]) % cows[i%3];
            cows[i%3] -= temp;
            cows[(i+1)%3] += temp;
        }
    }
}

//WORKS
//put into out file data
void print_buck(int cows[])
{
    ofstream outfile;
    outfile.open ("mixmilk.out");

    for(int x = 0; x < 3; x++)
    {
        printf("\n%d\n", cows[x]);
        outfile << cows[x];
        //HOW DAFAQ DO THEY SCORE RANDOM SPACES IN YOUR OUTPUT
        if(x != 3-1)
        {
            outfile << "\n";
        }
    }
}

//g++ compiler flags --> g++ x.cpp -O2 -lm -o <x.out>