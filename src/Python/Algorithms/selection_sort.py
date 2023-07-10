"""
Find the minimum value of the array, then append it to new array
Keep doing it until the old array is empty
Time Complexity : O(n^2)
"""

def selection_sort(arr : list) :
    sorted_arr = [];
    for i in range(0,len(arr)) :
        index_to_move = index_of_min(arr);
        sorted_arr.append(arr.pop(index_to_move));
        # print("%-25s   %-25s" % (arr, sorted_arr)); # visualization
    return sorted_arr;

def index_of_min(arr : list) :
    min_index = 0;
    for i in range(1,len(arr)) :
        if (arr[i] < arr[min_index]) :
            min_index = i;

    return min_index;
        
    
file_in = open('data/unsorted.txt', 'r');

arr_in : list = [line.strip() for line in file_in.readlines()];

print(selection_sort([3,6,1,7,2,3,9,0,8]))

arr_sorted = selection_sort(arr_in)
for item in arr_sorted :
    print(item);
             