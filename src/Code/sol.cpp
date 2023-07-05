#include <bits/stdc++.h>

using namespace std;

int main() {
    char c; bool f;
    int t,n,k,j,mn,b;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        f=0; j=0; b=0; mn=n+1;
        for(int i=0;i<n;i++) {
            cin >> c;
            if(c=='W') {
                j++; f=1; 
            }  else {
                if(b>=k) {mn=0;}
                b++;
            }
        }
        cout << mn << endl;
    }
    return 0;
}

