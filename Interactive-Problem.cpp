// F. Flamingoes of Mystery 


#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int interact(int i , int j){
    cout<<"? "<<i<<" "<<j<<endl;
    int x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    int a=interact(1,3);
    int b=interact(1,2);
    int c=interact(2,3);
    vector<int>num(n);
    num[1]=a-c;
    num[2]=b-num[1];
    num[3]=c-num[2];
    for(int i=4;i<=n;i++){
        int x=interact(i-1,i);
        num[i]=x-num[i-1];
    }
    cout<<"! ";
    for(int i=1;i<=num.size();i++) cout<<num[i]<<" ";
    return;
}  
int main(){
    ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            
                solve();
    
    return 0;
}
