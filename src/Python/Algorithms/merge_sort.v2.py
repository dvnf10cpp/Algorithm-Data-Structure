"""
This implementation is sorted in place without returning new array
"""

def merge(arr : list, left_sub : list, right_sub : list) -> None :
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

    while (r < len(right_sub)) :
        arr[k] = right_sub[r];
        k += 1; r += 1;

def merge_sort(arr : list) -> None :
    if (len(arr) <= 1) :
        return;

    mid : int = len(arr) // 2;
    left_sub = arr[:mid];
    right_sub = arr[mid:];
    merge_sort(left_sub);
    merge_sort(right_sub);
    merge(arr, left_sub, right_sub);

array = [76,51,35,87,91,33,12,56,12,11,40,44,56];
print('Before: ', array);
merge_sort(array);
print('After: ', array);

"""
Visualitation :
array = [76,51,35,87,91,33,12,56,12,11,40,44,56];
left = 76,51,35,87,91,33         |  right = 12,56,12,11,40,44,56
76,51,35   |  87,91,33           |  12,56,12   | 40,44,56
76 | 51,35 | 87 | 91,33          |  12 | 56,12 | 40 | 44,56
76 | 35,51 | 87 | 33,91          |  12 | 12,56 | 40 | 44,56
35,51,76   |  33,91,87           |  12,12,56   | 40,44,56
33,35,51,76,87,91                |  12,12,40,44,56
lalu terkahir di sort disini setelah masing-masing subarray sudah di sort
"""    