// Prime Factorization: Represent N as p1^k1 p2^k2…… pm^km

void solve() {
    int n;
    cin>>n;

    vector<int> v1;

    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            v1.push_back(i);
            n/=i;
        }
    }
    if(n > 1) v1.push_back(n);

    for(auto x: v1) cout<<x<<" ";
}
