/*
ID: maxnova1
TASK: ride
LANG: C++
*/

#include <fstream> 

using namespace std;

long ascii_product(string x)
{
    long product = 1;//ISSUE: compared value needs to be initalized
    for(int i=0; i < 6; i++)
    {
        if(x[i] == '\0')
            break;
        product *= (x[i] - 64);//ISSUE: I THOUGHT PROB SAID CONVERT TO ASCII INSTEAD OF INDEXS
    }
    return product;
}
int main()
{
    ofstream outfile;
    ifstream infile;
    string groupS;
    string cometS;
    long groupProduct;
    long cometProduct;
    
    infile.open("ride.in");
    
    getline(infile,groupS);
    getline(infile,cometS);

    //calc final number product
    groupProduct = ascii_product(groupS);
    cometProduct = ascii_product(cometS);
    if(groupProduct % 47 == cometProduct % 47)
    {
        outfile.open ("ride.out");
        outfile << "GO\n";
    }
    else 
    {
        outfile.open ("ride.out");
        outfile << "STAY\n";
    }
    return 0;
}