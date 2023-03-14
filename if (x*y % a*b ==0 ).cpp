void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int x = a + 1; x <= c;x++){
        int g = __gcd(a * b, x);
        int y = a * b / g;
        for (int j = 1;j*y<=d;j++){
            if(j*y>b){
                cout << x << ' ' << j * y << '\n';
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << '\n';
}
