# Time Complexity : O(log n), traverse only half elements from the array and reduice it to more sub half
# Best case scenario : O(1), the target element is in the mid index
# Worst case scenario : O(log n), 
# This algorithm is also called simple search or sequential search
def binary_search(arr, target) -> int :
    low = 0;
    high = len(arr)-1;
    while(low<high) :
        mid = (low+high) / 2;
        if(arr[mid]==target) :
            return mid;
        if (arr[mid]<target):
            low = mid;
        else :
            high = mid;
    return -1;