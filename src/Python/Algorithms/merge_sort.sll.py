"""
Merge sort for linked list,
perlu belajar lagi bagaimana caranya
"""
from data_structures import SLL, Node

def split(linked_list : SLL) -> SLL :
    # Divide unsorted list at midpoint into sublist
    if (linked_list is None or linked_list.head is None) :
        left_half = linked_list;
        right_half = None;
        return left_half, right_half;

    size: int = linked_list.sizeOf();
    mid: int = size // 2;
    mid_node: Node  = linked_list.get(mid - 1);
    left: SLL = linked_list;
    right: SLL = SLL();
    right.head = mid_node.next;
    mid_node.next = None;

    return left, right;

def merge_sort(linked_list : SLL) -> SLL :
    # Sorts a linked list in ascending order
    # Recursively divide linked_list into sublist
    # Repeatedly merge sorted sublist
    # return sorted linked list
    if(linked_list.sizeOf() == 1 or linked_list.head is None) :
        return linked_list;

    left_half, right_half = split(linked_list);
    left = merge_sort(left_half);
    right = merge_sort(right_half);
    return merge(left, right);

def merge(left : SLL, right : SLL) -> SLL : 
    # Sort 2 unsorted linked list and merge them
    new = SLL();
    new.append(0);

    current = new.head;

    left_head = left.head;
    right_head = right.head;

    while (left_head or right_head) :
        if (left_head is None) :
            current.next = right_head;
            right_head = right_head.next;
            continue;
        elif (right_head is None) :
            current.next = left_head;
            left_head = left_head.next;
            continue;
        
        if (left_head.data < right_head.data) :
            current.next = left_head;
            left_head = left_head.next;
        else :
            current.next = right_head;
            right_head = right_head.next;
        current = current.next;

    head : Node = new.head.next;
    new.head = head;
    return new;

def test() -> None :
    sll : SLL = SLL();
    sll.append(10);
    sll.append(2);
    sll.append(44);
    sll.append(15);
    sll.append(200);

    print(sll);
    print(merge_sort(sll));

test();