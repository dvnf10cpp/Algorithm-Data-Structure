"""
Merge sort for linked list  
"""
from data_structures import SLL, Node

def split(linked_list : SLL) -> SLL :
    # Divide unsorted list at midpoint into sublist
    if (linked_list is None or linked_list.head is None) :
        left_half = linked_list;
        right_half = None;
        return left_half, right_half;

    size: int = linked_list.sizeOf();
    mid = size // 2;
    mid_node: Node  = linked_list.get(mid);
    left: SLL = linked_list;
    right: SLL = SLL();
    right.head = mid_node.next;
    mid_node.next = None;

def merge_sort(linked_list : SLL) -> SLL :
    # Sorts a linked list in ascending order
    # Recursively divide linked_list into sublist
    # Repeatedly merge sorted sublist
    # return sorted linked list
    if(linked_list.size == 1 or linked_list.head is None) :
        return linked_list;

    left_half, right_half = split(linked_list);
    left = merge_sort(left_half);
    right = merge_sort(right_half);
    return merge(left, right);
