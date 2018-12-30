/*
ID: maxnova1
TASK: friday
LANG: C++
*/

#include <fstream>//file stream
#include <iostream>//input output stream
#include <string>

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
    int output[7] = {0};//monday is 0 sunday is 6
    int weekCounter = 0;//should always been changing with all scopes
    int yearCount = 1900, day;
    int leapFlag;
    years = yearCount + years;

    while(yearCount != years)
    {
        if(yearCount % 100 == 0 && yearCount % 400 == 0)
            leapFlag = 1;
        else if(yearCount % 4 == 0 && yearCount % 100 != 0)
            leapFlag = 1;
        else
            leapFlag = 0;

        for(int month = 1; month <= 12; month++)
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
                {
                    printf("%d-", output[weekCounter]);
                    output[weekCounter] += 1;
                    /*
                    3month should be tues but is fri
                    */
                }

                weekCounter++;
            }
        }

        yearCount++;
    }

    infile.close();
    outfile.open ("friday.out");

    /*
    THE OUPUT WAS ORDERED DIFFERENTLY THAN WHAT USACO WANTS, SO I REWIRED THE WEEKDAYS
    */
    int reformedOutput[7];
    reformedOutput[0] = output[5];
    reformedOutput[1] = output[6];
    reformedOutput[2] = output[0];
    reformedOutput[3] = output[1];
    reformedOutput[4] = output[2];
    reformedOutput[5] = output[3];
    reformedOutput[6] = output[4];

    for(int x = 0; x < 7; x++)
    {
        if(x < 6)
            outfile << reformedOutput[x] << " ";
        else
            outfile << reformedOutput[x] << "\n";
    }


    return 0;
}
/*
WHAT I LEARNED:
    -ALOT OF COMPUTATIONS ARE DIFFCULT TO DEBUG
    -MAKE SURE YOUR VARIABLE NAMES MAKE SENSE
    -LOOK AT OUTPUTS WITH DIFFERENT PERSPECTIVIES
    */
