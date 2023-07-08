"""
Time Complexity : O(log n), same as binary search iterative
Space Complexity : O(log n), it creates another sub array that is already halved and store it to stack memory, 
since its a recursive
"""
def rec_binary(arr : list, target : int) -> bool : 
    if (len(arr) == 0) : 
        return False;

    mid = len(arr) // 2; 
    if (arr[mid] == target) :
        return True;

    if (arr[mid] < target) : 
        return rec_binary(arr[mid+1:], target);
    else :
        return rec_binary(arr[:mid], target);

print('exist? : ', rec_binary([1,2,3,4,5,6,7,8,9,10], 7));
print('exist? : ', rec_binary([1,2,3,4,5,6,7,8,9,10], 1));
print('exist? : ', rec_binary([10,15,20,25,30,35,40,45,50], 20));
print('exist? : ', rec_binary([10,15,20,25,30,35,40,45,50], 11));