#include <iostream>

using namespace std;

struct User
{
    const int uId;
    const char *name; // const is on pointer, not the value in it. Pointer can't point anything other than name
    const char *email;
    int cars_count;
};

int main()
{
    // defining users
    User donald = {001, "donald", "donal@dc", 2};
    User micky = {002, "micky", "micky@mk", 4};

    User *d = &donald; // d is a pointer of User data type

    cout << donald.email << endl; // donal@dc
    cout << d->email << endl;     // donal@dc

    donald.email = "ddonald@rd";
    cout << donald.email << endl; // ddonald@rd

    d->email = "donaldo";
    cout << d->email << endl; // donaldo

    return 0;
}