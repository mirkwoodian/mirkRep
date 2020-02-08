#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>
#include <math.h>
#include <array>
#include <time.h>
#include <chrono>
using namespace std;
int binarySearch(int* arr, int l, int r, int x)
{
if (r >= l)
{
int mid = l + (r - l) / 2;

if (arr[mid] == x)
return mid;
if (arr[mid] > x)
return binarySearch(arr, l, mid - 1, x);
return binarySearch(arr, mid + 1, r, x);
}
return -1;
}
int main()
{
int m = 128;
int arr[m];
int n = sizeof(arr) / sizeof(arr[0]);
clock_t start2 = clock();
for (int i = 0; i < 10000000; i++) {
int result = binarySearch(arr, 0, n, 2);
}
clock_t stop2 = clock();
double time2 = (double)(stop2 - start2) / CLOCKS_PER_SEC;
cout << "Time elapsed during c++ search (seconds): " << time2 << endl;
return 0;
}