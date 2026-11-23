#include <iostream>
using namespace std;

// in const objs - can't write anything which may change the state of obj

class Member
{
    int _privMember;
    const int _id; // const data member -> cant be changed again, once set. Cant change through setMember
    mutable int _mutableMem;

public:
    int pubMember;

    Member(int priv, int pub, int id) : _privMember(priv), pubMember(pub), _id(id) {};

    int getMember() const { return _privMember; }
    void setMember(int i) { _privMember = i; } // non constant member
    void print() const { cout << "privateM = " << _privMember << " publicM = " << pubMember << endl; }

    int getMut() const { return _mutableMem; }
    void setMut(int i) const { _mutableMem = i; } // Ok to change mutable.
};

int main()
{
    Member m(100, 200, 1); // non const obj - can invoke all member fun
    cout << m.getMember() << endl;
    m.setMember(333);
    m.pubMember = 666;
    m.print();
    // m.id = 3;   // not valid

    // const object - can invoke only const member func
    const Member mConst(700, 900, 2);
    cout << mConst.getMember() << endl;
    // mConst.setMember(222);   // -> not const
    // mConst.pubMember = 999;
    mConst.print();
    // mConst.id = 3 // not valid
    mConst.setMut(555);
    cout << mConst.getMut() <<endl;

    return 0;
}