#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sortbyfirst(const pair<long, long> &a,
                 const pair<long, long> &b)
{
    return (a.first < b.first);
}

// Heap Implementation
class min_heap
{
private:
    vector<pair<long, long>> heap;
    long l(long parent);
    long r(long parent);
    long par(long child);
    void heapify_up(long index);
    void heapify_down(long index);

public:
    void delete_min();
    min_heap() {}
    void insert(pair<long, long> element);
    pair<long, long> extract_min();
    long size();
};

long min_heap::size()
{
    return heap.size();
}

void min_heap::insert(pair<long, long> ele)
{
    heap.push_back(ele);
    heapify_up(heap.size() - 1);
}

void min_heap::delete_min()
{
    if (heap.size() == 0)
    {
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapify_down(0);
}

pair<long, long> min_heap::extract_min()
{
    pair<long, long> result = heap.front();
    delete_min();
    return result;
}

long min_heap::l(long parent)
{
    long l = 2 * parent + 1;
    if (l < (int)heap.size())
        return l;
    else
        return -1;
}

long min_heap::r(long parent)
{
    int r = 2 * parent + 2;
    if (r < (long)heap.size())
        return r;
    else
        return -1;
}

long min_heap::par(long child)
{
    long p = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return p;
}

void min_heap::heapify_up(long in)
{
    if (in >= 0 && par(in) >= 0 && heap[par(in)].first > heap[in].first)
    {
        heap[in].swap(heap[par(in)]);
        heapify_up(par(in));
    }
}

void min_heap::heapify_down(long in)
{
    long child = l(in);
    long child1 = r(in);
    if (child >= 0 && child1 >= 0 && heap[child].first > heap[child1].first)
    {
        child = child1;
    }
    if (child > 0 && heap[in].first > heap[child].first)
    {
        heap[in].swap(heap[child]);
        heapify_down(child);
    }
}