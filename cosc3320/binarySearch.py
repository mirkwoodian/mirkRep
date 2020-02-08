import time

def binarySearch (arr, l, r, x): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l) // 2
  
        # If element is present at the middle itself 
        if arr[mid] == x: 
            return mid 
          
        # If element is smaller than mid, then it  
        # can only be present in left subarray 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # Else the element can only be present  
        # in right subarray 
        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 
        # Element is not present in the array 
        return -1
  
# Driver Code 
def main():
    m = 2097152
    arr = [0] * m
  
    # Function call 
    startTime = time.time()
    for i in range(10000000):
        result = binarySearch(arr, 0, len(arr)-1, 2)
        finalTime = time.time() - startTime
    print ("Time elapsed during python3 search, for m of ", m, ": ", finalTime)

main()