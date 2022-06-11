#include <bits/stdc++.h>

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
priority_queue<int, list<int>, greater<int>> min_heap; // Implementation also possible by negating each elements of max_heap and negating back before use
/*
 push() : Inserting element
 size()
 empty() : whether empty
 top() : top of the priority queue
 pop() : removing top element
 */

// Defining a function to be used in custom-dtype priority queue
struct compare_function
{
    bool operator()(pair<int, int> const &p1, pair<int, int> const &p2)
    {
        return p1.first > p2.first;
    }
};

priority_queue<int, list<pair<int, int>>, compare_function> custom_min_q;

// Set : RED-BLACK TREES
set<int, less<int>> s;
multiset<int> ms; // This allows insertion of multiple element with same key
/*
Acessing Memory --> begin(), end()
1. empty() : returns whether empty
2. size() : returns size
3. max_size() : returns maximum possible number of elements
4. clear() : clears the content
5. insert() : insert elements
6. emplace() : create and place an element
7. erase() : erase elements
8. swap() : swap contents
9. extract() : extract nodes from container
10. merge()
11. count() : returns number of elements matching specific key
12. find() : find element with specific key
13. contains() : check whether specific key present
14. lower_bound() : returns an iterator to first element not less than given key
15. upper_bound() : returns an iterator to first element greater than given key
Non-Member Functions
--------------------
erase_if(set) : erase all elements satisfying specific criteria
MULTI_SET
--------
1. equal_range() : returns range of elements matching specific key
 */

// MAP : RED-BLACK TREES(sorted container)
map<string, int, less<string>> m;
multimap<string,int> mm;// This allows insertion of multiple element with same key
/* 
m["element"] is same as m.at("element")
Acesssing memory : begin(), end()
1. empty() : whether empty
2. size() : returns number of elements
3. max_size() : returns maximum possible number of elements
4. clear(): clear contents
5. insert() : insert elements
6. insert_or_assign() : insert an element or assign current value if key exist
7. emplace() : construct element in place
8. try_emplace() : insert in place if key not-exist(otherwise leave)
9. erase() : erase elements
10. swap() : swapping contents
11. merge ()
12. count() : 
13. find() : iterator to specific key
14. contains() : 
15. equal_range
16. lower_bound
17. upper_bound
Non-Member Functions
--------------------
erase_if(set) : erase all elements satisfying specific criteria
erase_if(m, [](const auto& pair){ return pair.second > 25; })
 */


//UNOREDRED SET : HASH MAPPING
unordered_set<int> us; //constant time insertion and deletion operation
unordered_multiset<int> ums;
unordered_map<string,int> um;
unordered_multimap<string,int> umm;
/* 
Acesssing memory : begin(), end()
1. empty() : whether empty
2. size() : returns number of elements
3. max_size() : returns maximum possible number of elements
4. clear(): clear contents
5. insert() : insert elements
7. emplace() : construct element in place
9. erase() : erase elements
10. swap() : swapping contents
11. merge ()
12. count() : 
13. find() : iterator to specific key
14. contains() : 
15. equal_range
16. buckey_count() : returns number of buckets
17. bucket_size() : returns number of elements in specified bucket
18. bucket() : returns the bucket of specified key
19. load_factor() : average number of elements per bucket
20. rehash() : regenerates hash table
21. hash_function() : function used to hash the keys
22. key_eq() : func used to compare keys
 */