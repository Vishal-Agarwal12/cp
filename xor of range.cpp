int f(int n){
    switch(n%4){
      case 0: return n;
      case 1: return 1;
      case 2: return n+1;
      default: return 0;
    }
}
// xor in range of L to R
int xr = (f(l-1)^ f(r));
