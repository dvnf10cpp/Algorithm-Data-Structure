"""
Time Complexity : O(n), traverse every element from the array
Best case scenario : O(1), the target element is in the first index
Worst case scenario : O(n), the target element is in the last index (index n-1)
This algorithm is also called simple search or sequential search
Space Complexity : O(1), doesnt create copy of array, just create some variables
"""
def linear_search(arr : list, target : int) -> int :
    for i in range(0, len(arr)) :
        if(arr[i]==target) :
            return i + 1;
    return -1; # return -1 if it doesnt exist

print('index: ', linear_search([1,2,3,4,5,6,7,8,9,10], 5));
print('index: ', linear_search([4,7,8,9,2,1,3,5,6,10], 3));
print('index: ', linear_search([1,2,3,4,5,6,7,8,9,10], -1));
print('index: ', linear_search([1,2,3,4,5,6,7,8,9,10], 12));