"""
How quick sort works
1. Pick first item from an array, call it pivot
2. Break the array into 2 subarray, 
    first one contain items that value is less or same than the pivot
    second one contain items that value is greater than pivot
    if they were already sorted, join the all of them together
3. Do it recursively 
Time Complexity : O(n log n), subdividing array
Worst case : O(n^2), if the array is already almost sorted
"""

def quick_sort(arr : list) -> list :
    if (len(arr) <= 1) :
        return arr;

    pivot: any = arr[0];
    less_than: list = []
    greater_than: list = []
    for i in range(1,len(arr)) :
        if (arr[i] <= pivot) :
            less_than.append(arr[i]);
        else :
            greater_than.append(arr[i]);

    print("%15s %1s %-15s" % (less_than, pivot, greater_than)); # visualization
    return quick_sort(less_than) + [pivot] + quick_sort(greater_than);



file_in = open('data/unsorted.txt', 'r');

arr_in : list = [line.strip() for line in file_in.readlines()];

print(quick_sort([2,5,1,3,9,8,5,10,3,4,6]));
#arr_in_sorted = quick_sort(arr_in);

#print(arr_in_sorted);