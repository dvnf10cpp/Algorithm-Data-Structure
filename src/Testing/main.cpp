#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi x
#define se y

using namespace std;

queue<int>rq;
queue<int>cq;
vector<vector<bool>> visit;
vector<vector<char>> gm;
vector<int> dr = {-1,+1,0,0};
vector<int> dc = {0,0,+1,-1};
int n,m,sx,sy;
int mvc=0,nl=1,nn=0;

void explore(int r, int c) {
    for(int i=0;i<4;i++){
        int rr=r+dr[i];
        int cc=c+dc[i];
        if(rr<0||cc<0||rr>=n||cc>=m) continue;
        if(visit[rr][cc]) continue;
        if(gm[rr][cc]=='#')continue;
        rq.push(rr);
        cq.push(cc);
        visit[rr][cc]=1;
        nn++;
    }
}

void solve(){
    
    bool reached=false;

    rq.push(sx); cq.push(sy);
    visit[sx][sy]=1;
    while(!rq.empty()) {
        int r = rq.front(); rq.pop();
        int c = cq.front(); cq.pop();
        if(gm[r][c]=='B') {
            reached=true; break;
        }
        explore(r,c);
        nl--;
        if(!nl){
            nl = nn;
            nn = 0;
            mvc++;
        }
    }
    if(reached) {
        cout << "YES\n" << mvc;
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin >> n >> m;
    visit = vector<vector<bool>>(n,vector<bool>(m,0));
    gm = vector<vector<char>>(n,vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> gm[i][j];
            if(gm[i][j]=='A') {
                sx=i;sy=j;
            }
        }
    }
    
    solve();
    
    
    return 0;
}