#include <bits/stdc++.h>

using namespace std;

void verify(bool &f, int &j, int &b, int &k, int &mn) {
    if(f) {
        if((j+b>=k)&&(j<mn)) {
            mn=j;
            b=1;
            j=0;
        }
        f=0;
    }
}

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
                j++; f=1; continue;
            } 
            b++;
            verify(f,j,b,k,mn);
            
        }
        verify(f,j,n,k,mn);
        cout << mn << endl;
    }
    return 0;
}

