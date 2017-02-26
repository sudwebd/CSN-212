#include <iostream>
#include <string>
using namespace std;
 
int max(int a, int b) {  return (a > b) ? a : b; }
 
int lzzs(int arr[], int n)
{
    int Z[n][2];
    for (int i = 0; i < n; i++)
        Z[i][0] = Z[i][1] = 1;
 
    int res = 1; // Initialize result
 
 
    for (int i = 1; i < n; i++)
    {
 
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && Z[i][0] < Z[j][1] + 1)
                Z[i][0] = Z[j][1] + 1;
            if( arr[j] > arr[i] && Z[i][1] < Z[j][0] + 1)
                Z[i][1] = Z[j][0] + 1;
        }
        if (res < max(Z[i][0], Z[i][1]))
            res = max(Z[i][0], Z[i][1]);
    }
 
    return res;
}
int main()
{
    
    int arr[] = 	
    	
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
    int n =50;
    cout << lzzs(arr, n)<<endl;
    
    return 0;
}