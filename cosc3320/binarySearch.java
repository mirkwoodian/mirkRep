import java.io.*;

// Java implementation of iterative Binary Search 
class BinarySearch { 
    // Returns index of x if it is present in arr[], 
    // else return -1 
    int binarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
  
            // Check if x is present at mid 
            if (arr[m] == x) 
                return m; 
  
            // If x greater, ignore left half 
            if (arr[m] < x) 
                l = m + 1; 
  
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
  
        // if we reach here, then element was 
        // not present 
        return -1; 
    } 
  
    // Driver method to test above 
    public static void main(String args[]) 
    { 
        BinarySearch ob = new BinarySearch(); 
        int m = 2097152;
        int []arr = new int[m]; 
        long startTime = System.currentTimeMillis();
        for (int i = 0; i < 10000000; i++) {
            int result = ob.binarySearch(arr, 2); 
        }
        long endTime = System.currentTimeMillis();
        long totalTime = (endTime - startTime);
        System.out.print("Time elapsed during java search, for m of "); 
        System.out.print(m);
        System.out.print(":");
        System.out.print(totalTime);
        System.out.println("ms");
    } 
} 