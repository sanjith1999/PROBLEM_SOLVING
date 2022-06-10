# include<bits/stdc++.h>

using namespace std;

// Linked List
list<int> list1 = {1, 2, 3, 4};
/*
Normal functionalities : push_back(),push_front(),back(),front(),pop_back(),pop_front(),sort(),merge(list_to_merge)
1. empty() : Returns whether the list is empty
2. insert() : Insert new element in the list before the specified position
3. erase() : Remove single or range of elements from the list
4. assign() : Assigns new elements into the list by replacing the  current elements from  the  list
5. remove() : Removes all the elements from list which are equal to the given element
6. remove_if() : Remove all the values from the  list that corresponding to true predictate of the conditional statement
7. reverse() : Reversing list
8. size() : Returns number of elements in the list
9. list_resize() : used to resize a list container
10. sort() : Sorts the list in increasing order
11. list_max_size() : Returns maximum number of elements list container can hold
12. list_unique() : Removes all the duplicate consecutive elements from the list
13. list::emplace_front(), list::emplace_back() : inserting new element
14. list::clear() : removing all the elements from the list
15. list::swap() : swapping content of one list with another
16. list_splice() : Used to transfer elements from one list to another
17. list_merge() : Merges two list
18. list_emplace() : Extends list by inserting new element in the given position.
 Acessing list.begin() --> list.end()
*/

// Deque
// Best performance compared to vector in growing size but get worse when we try to insert element in the middle(Constant memory access time)
deque<int> d(5, 0);
/*
 memory acessing : d.begin() --> d.end()
 Common Functionalities : push_back(),push_front(), swap(deque_to_swap)
 1. shrink_to_fit() : Reducing the memory allocation to fit size
 2. std::swap_ranges(d1.begin(),d1.begin()+n, d2.begin())
 */

// Queue : FIFO
// Continers -> deque(default), list  (queue<int, list<int>> q;)
queue<int> q1;
/*
empty() : Test whether container is empty
size() : Returns the size of queue
front() : Access the next element
back() : Access the last element
push() : Inserting element in last
emplace() : Construct and inserting element
pop() : Remove first element
swap(queue) : exchange contents of queue
Pointers not available to access memory...!
 */


// Stack : LIFO
// Containers -> deque(default), list, vector
stack<int> st;
/*
 1. push() : Pushing element in the last position
 2. pop() : Removing the last element
 3. emplace() : create and push at last
 4. size() : size of the stack
 5. top() : Last element of the stack
 6. empty() : whether stack is empty
 */

// Priority Queue
priority_queue<int> max_heap;
priority_queue<int, list<int>, greater<int>> min_heap;   // Implementation also possible by negating each elements of max_heap and negating back before use
/*
 push() : Inserting element
 size()
 empty() : whether empty
 top() : top of the priority queue
 pop() : removing top element
 */

// Defining a function to be used in custom-dtype priority queue
struct compare_function {
    bool operator()(pair<int, int> const &p1, pair<int, int> const &p2) {
        return p1.first > p2.first;
    }
};

priority_queue<int, list<pair<int, int>>, compare_function> custom_min_q;

