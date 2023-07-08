"""
This implementation is sorted in place without returning new array
"""

def sort(arr : list, left_sub : list, right_sub : list) -> None :
    l = r = k = 0;
    while (l < len(left_sub) and r < len(right_sub)) :
        if (left_sub[l] < right_sub[r]) :
            arr[k] = left_sub[l];
            l += 1;
        else :
            arr[k] = right_sub[r];
            r += 1;
        k += 1;

    while (l < len(left_sub)) :
        arr[k] = left_sub[l];
        k += 1; l += 1;

    while (r < len(left_sub)) :
        arr[k] = right_sub[r];
        k += 1; r += 1;

def merge_sort(arr : list) -> None :
    if (len(arr) <= 1) :
        return;

    mid : int = len(arr) // 2;
    left_sub : int = arr[:mid];
    right_sub : int = arr[mid:];
    merge_sort(left_sub);
    merge_sort(right_sub);
    sort(arr, left_sub, right_sub);

array = [76,51,35,87,91,33,12,56,12,11,40,44,56];
merge_sort(array);
print(array);
    

    