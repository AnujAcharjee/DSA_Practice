#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st; // LIFO
    
    st.push(1); 
    st.push(2);
    st.push(3);
    st.push(4); // {1,2,3,4}
    st.emplace(5); // {1,2,3,4,5}

    st.top(); // 5

    st.pop(); // {4,3,2,1}

    st.size(); // 4

    st.empty(); // false

    stack<int> st1, st2;
    st1.swap(st2);


}
