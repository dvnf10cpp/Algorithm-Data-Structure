"""
sorts a list in ascending order
it returns new sorted array.
3 steps : 
1. Divide : Find the midpoint and divide into subarray
2. Conquer : Recursively sort the sublist from the prev step
3. Combine : Merge the sorted sublist created form the prev step
"""

def divide(array : list) -> list :
    # Divide array at midpoint, return subarray left and right
    mid : int = len(array) // 2;
    left = array[:mid];  # starts from zero until midpoint
    right = array[mid:]; # starts from midpoint until end of array
    return left, right;

def merge(left : list, right : list) -> list : 
    # Merge two arrays, sorting them in process
    new : list = [];
    l : int = 0;
    r : int = 0; 
    while (l < len(left) and r < len(right)) :
        if (left[l] < right[r]) :
            new.append(left[l]);
            l += 1;
        else :
            new.append(right[r]);
            r += 1;
    
    while (l < len(left)) : 
        new.append(left[l]);
        l += 1;
    while (r < len(right)) : 
        new.append(right[r]);
        r += 1;
    return new;

def merge_sort(array : list) -> list :
    if (len(array) <= 1) :
        return array;

    left_half, right_half = divide(array);
    left = merge_sort(left_half);
    right = merge_sort(right_half);

    return merge(left, right);

array = [76,51,35,87,91,33,12,56,12,11,40,44,56];
print(merge_sort(array))