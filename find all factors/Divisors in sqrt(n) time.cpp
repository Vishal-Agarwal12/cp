// It does using the simple fact that factors occurs in pairs!

void solve() {
    int n;
    cin>>n;

    vector<int> v1;

    for(int i=1;i*i<=n;i++){
      if(n%i==0){
        v1.push_back(i);
        if (n/i != i) 
            v1.push_back(n/i);
      }
    }
    for(auto x: v1) cout<<x<<" ";
}
