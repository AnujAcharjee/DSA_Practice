#include <iostream>
using namespace std;

enum myCollection
{
    ITEM1, // first element has 0 as default value
    ITEM2,
    ITEM3 = 5, // if we assign a value to an element, the next element will be incremented by 1
    ITEM4,
};

enum class TransactionType
{
    BUY,
    SELL
};

int main()
{
    cout << ITEM1 << endl; // 0
    cout << ITEM3 << endl; // 5
    cout << ITEM4 << endl; // 6

    TransactionType t = TransactionType::BUY; // ✅ Scoped access
    // int x = TransactionType::BUY;          //❌ Error: No implicit conversion

    // enum class values are strongly typed and do not implicitly convert to int, cout << t; will result in a compilation error.
    cout << static_cast<int>(t) << endl; // ✅ Explicit conversion to int

    return 0;
}
