//Summary of all the ways to use a vector
//A vector is just a container / List
//i.e. good array
//*** means I don't understand what it does

#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INIT VECTORS
    //example values to initliaze vector
    int arr[] = {10, 20, 5, 23, 42, 15};
    //***Using a preinit array
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect1(arr, arr+n);
    //Adding to an empty vector manually
    vector<int> vect2;
    vect2.push_back(10);
    vect2.push_back(20);
    //Init with a single value
    int size = 3;
    vector<int> vect3(size, 10);
    //Init like array
    vector<int> vect4{10, 20, 30};
    //Copy vector
    vector<int> vect5(vect4.begin(), vect4.end());
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}