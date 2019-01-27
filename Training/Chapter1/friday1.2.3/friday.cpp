/*
ID: maxnova1
TASK: friday
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream

using namespace std;

/*
TODO:
FIX IN DEBUGGER -- number of fridays is really wrong? line 65
Notes:
#January 1, 1900 to December 31, 1900+N-1
#January 1, 1900 was on a Monday
#Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
#Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
#The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
#OUTPUT: 7 spaces integers in one line
#Find how many times of each day friday 13th exists
*/
int main()
{
    ofstream outfile;
    ifstream infile;
    int years;
    infile.open("friday.in");
    infile >> years;
    int output[7] = {0};
    int weekCounter = 0;//should always been changing with all scopes
    int yearCount = 1900, month, day;
    int leapFlag;
    years = yearCount + years;

    while(yearCount != years-1)
    {
        if(yearCount % 100 == 0 && yearCount % 400 == 0)
            leapFlag = 1;
        else if(yearCount % 4 == 0 && yearCount % 100 != 0)
            leapFlag = 1;
        else
            leapFlag = 0;
        
        month = 1;
        
        for(int months = 1; months <= 12; months++)
        {
            //contraint tree to determine day in a month
            if(month == 4 || month == 9 || month == 11 || month == 6)
                day = 30;
            else if(month == 2 && leapFlag == 1)
                day = 29;
            else if(month == 2)
                day = 28;
            else
                day = 31;

            for(int days = 1; days <= day; days++)
            {
                if(weekCounter >= 7)
                        weekCounter = 0;
                if(days == 13)
                    output[weekCounter] += 1;
                    //printf("%d-", output[weekCounter]);
                    
                
                weekCounter++;
            }
        }

        yearCount++;
    }

    infile.close();
    outfile.open ("friday.out");

    for(int x = 0; x < 7; x++)
    {
        printf("\n%d\n", output[x]);
        outfile << output[x] << " ";
    }

    return 0;
}