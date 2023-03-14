void solve() {
    int n;
    cin>>n;

    vector<int> v1;

    for(int i=1;i*i<=n;i++){
      if(!(n%i)){
        v1.push_back(i);
        if (i != n/i) 
            v1.push_back(n/i);
      }
    }
    for(auto x: v1) cout<<x<<" ";
}
