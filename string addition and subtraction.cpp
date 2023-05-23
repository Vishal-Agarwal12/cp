// include this define also 

#define si(x) int(x.size())        



        string add(string a,string b){
            if(si(a)<si(b)) swap(a,b);

            for(int i=0;i<si(b);i++){
                a[si(a)-1-i]+=int(b[si(b)-1-i]-'0');
                if(a[si(a)-1-i]>'9'&&si(a)-1-i){
                    a[si(a)-1-i]-=10;
                    a[si(a)-1-i-1]++;
                }
            }
            for(int i=si(a)-1;i>=1;i--){
                if(a[i]>'9'){
                    a[i]-=10;
                    a[i-1]++;
                }
            }
            string res;

            if(a[0]>'9'){
                a[0]-=10;
                res+='1';
            }
            res+=a;

            for(int i=si(res)-1;i>=0;i--){
                if(res[i]>'9'){
                    res[i]-=10;
                    res[i-1]++;
                }
            }

            return res;
        }

        string sub(string a,string b){
            if(si(a)<si(b)) return "";
            if(si(a)==si(b)&&a<=b) return "";

            for(int i=0;i<si(b);i++){
                if(a[si(a)-1-i]<b[si(b)-1-i]){
                    a[si(a)-1-i-1]--;
                    a[si(a)-1-i]+=10;
                }
                a[si(a)-1-i]-=int(b[si(b)-1-i]-'0');
            }

            for(int i=si(a)-1;i>=0;i--){
                if(a[i]<'0'){
                    a[i-1]--;
                    a[i]+=10;
                }
            }
            int i=0;
            while(a[i]=='0') i++;

            return a.substr(i);
        }
