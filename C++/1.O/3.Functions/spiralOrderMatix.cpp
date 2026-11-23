#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>a[i][j];
        }
    }

    // initialise variables 
    int rs=0,re=n-1,cs=0,ce=m-1; 

    while(rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            cout<<a[rs][i]<<" ";
        }
        rs++;
        for(int j=rs;j<=re;j++){
            cout<<a[j][ce]<<" ";
        }
        ce--;
        
            for(int j=re;j>=rs;j--){
            cout<<a[j][rs]<<" ";
            }
            re--;
        
        
            for(int j=re;j>=rs;j--){
            cout<<a[j][rs]<<" ";
            }
            cs++;
        
        
    }
    return 0;
}
