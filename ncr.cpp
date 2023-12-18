const int mod = 998244353;
 
ll POW(ll a,ll b){
    if(!b)return 1;
    ll res = POW(a,b/2);
    res = (res * res)%mod;
    if(b % 2)res = (res * a)%mod;
    return res;
}
vector<ll> fact,inv;
void init_COM(int n){
   fact = inv = vector<ll>(n+1);
   fact[0] = inv[0] = 1;
   for(int i=1;i<=n;i++){
      fact[i] = (fact[i-1] * i) % mod;
      inv[i] = POW(fact[i] , mod-2);
   }
}
inline ll nCk(ll n, ll k){
    return ((fact[n] * inv[k])%mod * inv[n-k])%mod;
}
inline ll nPk(ll n,ll k){
    return (fact[n]*inv[n-k])%mod;
}

void solve()
{
    ll n;
    cin>>n;

    ll dp1[61], dp2[61];
    dp1[2] = 1, dp2[2] = 0;

    for(int i=4;i<=60;i+=2) {
        dp1[i] = (nCk(i-1, i/2-1) + dp2[i-2])%mod;
        dp2[i] = (nCk(i, i/2) - 1- dp1[i])%mod;
    }

    cout<<dp1[n]<<" "<<dp2[n]<<" "<<1<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("moobuzz.in", "r", stdin);
    //freopen("moobuzz.out", "w", stdout);
    
    init_COM(60);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
