#include <iostream>
#include <utility>

using namespace std;

void explainPair()
{
    pair<int, int> p = {2, 4};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, char>> p2 = {1, {5, 'X'}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {4, 5}};
    for (pair<int, int> p : arr)
    {
        cout << p.first << "," << p.second << " | ";
    }
}

int main()
{
    explainPair();

    return 0;
}