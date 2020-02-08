#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() //there are 3m arrays, each array has 800k elements set to 1
{
int m = 800;																																						0; //change this as needed to triple the amount of arrays made

//creation of the first set of dynamic arrays
int size1 = 800000;
int* arr[3*m - 1];
for (int i = 0; i < 3*m; i++) {
    arr[i] = (int*)malloc(size1*sizeof(int));
}
//allocation#1
int value1 = 1;
clock_t start = clock();
for (int k = 0; k < 3*m; k++) {
for (int i = 0; i < size1; i++) {
arr[k][i] = value1;
}
}
clock_t stop = clock();
double time1 = 0.0;
time1 += (double)(stop - start) / CLOCKS_PER_SEC;
printf ("Time elapsed during first allocation: %f seconds\n", time1);
//deallocation of even numbered arrays
for (int z = 0; z < 3*m; z++) {
if (z % 2 == 0) {
    free(arr[z]);
}
}
clock_t start2 = clock();
// creation of second set of arrays
int size2 = 1000000;
int* arr2[m];
for (int i = 0; i < m; i++) {
    arr2[i] = (int*)malloc(size2*sizeof(int));
}
//allocation of second set of arrays. this should take longer?
int value2 = 2;
for (int l = 0; l < m; l++) {
for (int j = 0; j < size2; j++) {
arr2[l][j] = value2;
}
}
clock_t stop2 = clock();
double time2 = (double)(stop2 - start2) / CLOCKS_PER_SEC;
printf("Time elapsed during second allocation: %f seconds\n", time2);
double time3 = time2/time1;
printf("Time2 compared to Time1 : %f\n", time3);
for (int i = 0; i < 3*m; i++) {
if (i%2 != 0) {
    free(arr[i]);
}
}
for (int i = 0; i < m; i++) {
    free(arr2[i]);
}
return 0;
}
