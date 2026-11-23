#include <iostream>
using namespace std;

void fibonacci(int n){
    int n1 = 0;
    int n2 = 1;
    int nextTerm;

    for(int i=0; i<n; i++){
        cout<< n1 <<endl;
        nextTerm = n1 + n2;
        n1 = n2;
        n2 = nextTerm;
    }
    return;
}

int main(){
    int n;
    cout << "Enter the number of terms:";
    cin>>n;
    fibonacci(n);

    return 0;
}