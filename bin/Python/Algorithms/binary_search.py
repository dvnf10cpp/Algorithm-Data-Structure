"""
Time Complexity : O(log n), traverse only half elements from the array and reduice it to more sub half
Best case scenario : O(1), the target element is in the mid index
Worst case scenario : O(log n), it only traverse half elements from the array even if the target is at the most end or start
Only works if the input is sorted
Space Complexity : O(1), doesnt create copy of array, just create some variables
"""

def binary_search(arr : list, target : int) -> int :
    low = 0;
    high = len(arr)-1;
    while ( low <= high ) :
        mid = (low + high) // 2; # double (/) cause python, means floor
        if(arr[mid]==target) :
            return mid + 1;
        if (arr[mid]<target):
            low = mid + 1;
        else :
            high = mid - 1;
    return -1;

print('index: ', binary_search([1,2,3,4,5,6,7,8,9,10], 7));
print('index: ', binary_search([1,2,3,4,5,6,7,8,9,10], 1));
print('index: ', binary_search([10,15,20,25,30,35,40,45,50], 20));
print('index: ', binary_search([10,15,20,25,30,35,40,45,50], 11));