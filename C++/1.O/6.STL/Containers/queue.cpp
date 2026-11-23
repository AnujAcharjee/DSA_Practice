#include <iostream>
#include <queue>

using namespace std;

void implementQueue()
{
    queue<int> q; // FIFO

    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4); // {1,2,3,4}

    q.back() += 5;
    cout << q.back() << endl; // 9

    q.front(); // 1

    q.pop(); // {2,3,9}

    // size swap same as stack
}

void implementPriorityQueue()
{
    priority_queue<int> pq; // a tree data structure is maintained which add nodes on the basis of priority.

    pq.push(3);  // {3}
    pq.push(40); // {40,3}
    pq.push(20); // {40, 20, 3}
    pq.push(30); // {40, 30, 20,3}

    cout << pq.top() << endl; // 40

    pq.pop(); // {30, 20, 3 }

    // size swap empty

    //* Mean Heap
    priority_queue<int, vector<int>, greater<int>> mh;

    mh.push(3);  // {3}
    mh.push(40); // {40,3}
    mh.push(20); // {40, 20, 3}
    mh.push(30); // {40, 30, 20,3}

    cout << mh.top();
}

int main()
{
    implementQueue();
    implementPriorityQueue();
}
