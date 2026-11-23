#include <iostream> 
#include <deque>

using namespace std;

int main() {
    deque<int> dq; // double ended queue

    dq.push_back(1); //{1}
    dq.emplace_back(2), //{1,2}

    dq.push_front(11); // {11,1,2}
    dq.emplace_front(22); // {22,11,1,2}

    dq.pop_back(); // {22,11,1}
    dq.pop_front(); // {11,1}

    dq.back();

    dq.front();

    // all func same as vector

    
}
