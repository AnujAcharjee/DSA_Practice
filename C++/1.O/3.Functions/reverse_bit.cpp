#include<iostream>
using namespace std;

void reverse(int n){
    for(int i=0;i<32;i++){
        int bit=(n>>i);

        cout<<bit;
    }
}
int main(){
    int n;
    reverse(3);

    return 0;

}