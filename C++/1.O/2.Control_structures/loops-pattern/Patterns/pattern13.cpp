#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cin>>n;

    for(i=1;i<=n;i++){
        for(j=1;j<=2*n-i;j++){
            if(i+j==10 ){
                cout<<"*";

            }else{
                cout<<"  ";
            }
            cout<<endl;

        }

    }
    return 0;

}

