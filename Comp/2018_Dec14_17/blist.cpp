/*
ID: maxnova1
TASK: 
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream
#include <stdio.h>
#include <algorithm> 

using namespace std;

#define POUR 100

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

building good code early on helps later
*/

void print_buck(int buckets_needed);
int calc_buck(int cows[100][4], int cow_num);
int read_input(int cows[100][4]);
void sort(int cows[100][4], int cow_num);
void print_data(int cows[100][4], int cow_num);

int main()
{
    //WORK ON UNDERSTANDING POINTERS
    int cow_num, buckets_needed;
    int cows[100][4];

    cow_num = read_input(cows);
    sort(cows, cow_num);
    print_data(cows, cow_num);

    //buckets_needed = calc_buck(cows);
    //print_buck(buckets_needed);      

    return 0;
}

//WORKS
//s t b
//start time --> end time --> requires b buckets
//only 1 cow at a time
int read_input(int cows[100][4])
{
    ifstream infile;
    infile.open("blist.in");
    int cow_num;
    infile >> cow_num;

    for(int y = 0; y < cow_num; y++)
    {
        cows[y][0] = y;
        infile >> cows[y][1];
        infile >> cows[y][2];
        infile >> cows[y][3];
    }

    infile.close();

    return cow_num;
}

/*
int calc_buck(int cows[100][4], int cow_num)
{
    for(int i = 0; i < POUR; i++)
    {
        //overflow test a overflows b
        if(cows[i%3] > capacity[(i+1)%3])
        {
            cows[i%3] -= capacity[(i+1)%3];
            cows[(i+1)%3] = capacity[(i+1)%3];
        }
        else
        {
            cows[(i+1)%3] += cows[i%3];
            cows[i%3] = 0;
        }
    }

    /*
    PS Structure
    for()
        for()
    
}*/

//WORKS!!!
//put into out file data
void print_buck(int buckets_needed)
{
    ofstream outfile;
    outfile.open ("blist.out");

    outfile << buckets_needed;
}

    void print_data(int cows[100][4], int cow_num)
    {
        for(int i = 0; i < cow_num; i++)
        {
            for(int k = 0; k < 4; k++)
                printf(" %d --"), cows[i][k];
            puts("");
        }
    }

//source found here --> https://ideone.com/KrW6Hs
void sort_by_marks(int cows[100][4], int cow_num)
{
  auto ptr = (pair<int, int>*) cows;
  sort(ptr, ptr+cow_num);
}

//g++ compiler flags --> g++ x.cpp -O2 -lm -o <x.out>