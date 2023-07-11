# Randomize order of the array until it's sorted
# Worst Sorting Algorithm

import random

file_in = open('data/unsorted.txt', 'r');

arr_in = file_in.readlines();

def is_sorted (arr : list) -> bool : 
    for i in range(0,len(arr) - 1) : 
        if (arr[i] > arr[i + 1]) :
            return False;

    return True;

def bogo_sort(arr : list) -> list : 

    attempts : int = 0;
    while not is_sorted(arr) :
        random.shuffle(arr);
        attempts += 1;

    print("Attempts: ", attempts);
    return arr;

print(bogo_sort([5,4,8,1,3])); # only works if the array size is small
# print(bogo_sort(arr_in)) # try to uncomment to see how ineffecient the algorithm