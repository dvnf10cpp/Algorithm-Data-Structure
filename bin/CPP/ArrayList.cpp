#include <bits/stdc++.h>

using namespace std;

// mock up implementing list ADT, particulary ArrayList from java AFAIK
// required knowledge: OOP, Dynamic Memory(heap), pointers
class ArrayList {
private:
    int* pointer;
    int size;
public:
    ArrayList(){
        this->size=0;
        this->pointer = new int[size];
    }

    ArrayList(int size) {
        this->size = size;
        this->pointer = new int[size];
    }

    ~ArrayList() { 
        // implementing our delete operation when calling delete to this object class
        // so it also deallocates the memory we already allocate for the array
        delete[] pointer; 
    }

    void insert(int data) {
        /**
         * inserting at the end of index
         * takes O(1) time complexity for this specific implementation  
        */ 
        *(pointer + size++) = data;
    }

    void remove(int index) {
        if(index < 0 || index >= size) {
            return;
        }
        /**
         * remove element at index from list
         * takes O(N) time complexity
         * memcpy implementation
        */ 
        int* newPointer = new int[size - 1];
        memcpy(newPointer, pointer, index * sizeof(int));
        mempcpy(newPointer + index, pointer + index + 1, (size - index) * sizeof(int));
        delete[] pointer; //delete the memory we allocated from prev array
        this->pointer = newPointer;
        size--;
    }

    void insert(int data, int index) {
        if(index < 0 || index >= size) {
            return;
        }
        /**
         * remove element at index from list
         * takes O(N) time complexity
         * memcpy implementation
        */ 
        int* newPointer = new int[size + 1];
        mempcpy(newPointer, pointer, index * sizeof(int)); // copy memory from an address to address
        *(newPointer + index) = data;
        mempcpy(newPointer + index + 1, pointer + index, (size - index) * sizeof(int));
        delete[] pointer; //delete the memory we allocated from prev array
        this->pointer = newPointer;
        size++;
    }

    int indexOf(int data) {
        /**
         * searching index of data the first time we encounter it
         * takes O(N) time complexity
        */ 
        for(int i = 0; i < size; i++) {
            if(*(pointer + i) == data) 
                return i;
        }
        return -1;
    }

    int get(int index) {
        if(index < 0 || index >= size) {
            return INT_MIN;
        }
        /**
         * read element at index 
         * takes O(1) time complexity
        */ 
        return *(pointer + index);
    }

    void set(int data, int index) {
        /**
         * write element at index 
         * takes O(1) time complexity
        */ 
        *(pointer + index) = data;
    }

    bool contains(int data) {
        // use indexOf method, takes O(N)
        return indexOf(data) >= 0;
    }

    void clear() {
        // takes O(1) time complexity
        delete[] pointer;
        this->pointer = new int[size];
    }

    int sizeOf() {
        return size;
    }

    bool empty() {
        return size==0;
    }

    // below method only for learning purpose only
    void print() {
        for(int i = 0; i < size; i++) {
            printf("| %d ", *(pointer + i));
        }
        // printing address;
        // printf("|\n");
        // for(int i = 0; i < size; i++) {
        //     printf("| %d ", pointer + i);
        // }
        printf("|\n");
    }
};

int main(){ 
    ArrayList* arr = new ArrayList;
    for(int i = 0; i < 10; i++) {
        arr->insert(i + 1);
    }

    arr->print();
    arr->remove(2);
    arr->print();
    arr->insert(10,2);
    arr->remove(0);
    arr->print();
    cout << arr->get(1) << '\n';
    delete arr; //deallocate object from heap if we already dont use them anymore
    return 0;
}