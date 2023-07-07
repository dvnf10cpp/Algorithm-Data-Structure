# Time Complexity : O(n), traverse every element from the array
# Best case scenario : O(1), the target element is in the first index
# Worst case scenario : O(n), the target element is in the last index (index n-1)
# This algorithm is also called simple search or sequential search
def linear_search(arr, target) -> int :
    for i in range(len(arr)) :
        if(arr[i]==target) :
            return i;
    return -1;