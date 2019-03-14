//https://www.geeksforgeeks.org/binary-search/

//Learning linear search and binary search
//*** is a misunderstanding
//*** How do you calculate Big O?
    //write a program to determine approx Big O?
//linear search = O(n)
//binary search = O(Log n)
    //Must be sorted

//10 len
//sort
//x = arr[10/2]
//while divided value is not 1 or 2
    //if want val > x
        //take lower mid
    //else
        //take mid

#include <iostream>
#include <string>

using namespace std;

int binarySearch(int *, int, int, int);

int binarySearch(int arr[], int left, int right, int find)
{
    while(left <= right)
    {
        int middle = left + (right - left) / 2;

        //Is find in the middle?
        if (arr[middle] == find)
            return middle;
        
        //find is greater
        if(arr[middle] < find)
            left = middle + 1;

        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3 , 5, 40};
    int find = 5;
    //***
    int right = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, right - 1, find);
    (result == -1) ? cout << "not found" : cout << "found at " << result;

    return 0;
}