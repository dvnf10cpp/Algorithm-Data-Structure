"""
Array is a common data structure that all programming language have.
It's also a fundemental data structure and can be used to represent a collection of values.
Arrays can be also used to create custom data structure.
Array is also a contigous data structure, means that the array is stored in blocks of memory 
that are right beside each others with no gaps
"""

"""
Some programming language have the array as hetero, means it can store many data types in one array.
Python and JS are the examples.
Some also have the array as homo, means it can only store one data type in one array
"""
class Person : 
    def __init__(self,name : str ,age : int) -> None : 
        self.name = name;
        self.age = age;
    
    def __str__(self) -> str : 
        return 'Name : ' + self.name + "\nAge : " + str(self.age);

array_1 = [1,2,3,4,5,6,7,8,9,10]; # Homo example
array_2 = ['Try',1,True, Person('Me',19)]; # Hetero example

# Accessing value from array
# Has constant time 
print(array_1[5]);
print(array_2[3]);

# Insert value to array, this specific implementation only works in python or js AFAIK
# Java default array is static unlike python.
empty_array = [];

## Append takes constant time 
empty_array.append(2);
empty_array.append(3);
empty_array.append(5);
empty_array.append(7);
empty_array.append(11);
print(empty_array);

## Insert takes linear time
empty_array.insert(2,4);
print(empty_array);

## Extends Operation
## this method takes another array as argument to add to the array
## Has linear runtime of O(k), k is the size of the array that we passed to the function
empty_array.extend([13,17,19]) 
print(empty_array);

## Deletes Operation
## Has linear runtime of O(n)
empty_array.remove(13)
print(empty_array);
