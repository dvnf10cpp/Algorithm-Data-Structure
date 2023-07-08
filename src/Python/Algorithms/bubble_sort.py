#
"""
Time Complexity : O(n^2)
Space Complexity : O(1)
It iterates every element in the array in a loop that run in O(n)
"""

def bubble_sort(array : list) -> None :
    n : int = len(array);
    for i in range(0,n-1) :
        for j in range(i + 1, n-1) :
            if(array[i] > array[j]) :
                array[i], array[j] = array[j], array[i];

array : list = [4,6,2,1,4,9,3,8,3,6,5,10];
bubble_sort(array)
print(array);