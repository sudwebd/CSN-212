
#include<iostream>
using namespace std;
#define LEN 100
int bad[LEN][4];
int badlen;
long long roadnum[LEN][LEN];
int reachable(int x1,int y1,int x2,int y2){
    for(int i=0;i<badlen;i++){
        if( (x1==bad[i][0]&& y1==bad[i][1]&& x2==bad[i][2] && y2== bad[i][3]) ||
           (x1==bad[i][2]&& y1==bad[i][3]&& x2==bad[i][0]&& y2==bad[i][1]) )
            return 0;
    }
    return 1;
}

long long dp(int m,int n){
    for(int i=0;i<=m;i++){
        roadnum[i][0]=0;
        if(reachable(i,0,i-1,0)&& (i>1&&roadnum[i-1][0]>0 || i==1) )roadnum[i][0]=1;
    }
    for(int i=0;i<=n;i++){
        roadnum[0][i]=0;
        if(reachable(0,i,0,i-1)&& (i>1&&roadnum[0][i-1]>0 || i==1) )roadnum[0][i]=1;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            roadnum[i][j]=0;
            if(reachable(i,j,i-1,j))
                roadnum[i][j]+=roadnum[i-1][j];
            if(reachable(i,j,i,j-1))
                roadnum[i][j]+=roadnum[i][j-1];
        }
    }
    return roadnum[m][n];
}
int main(){
    int m,n;
    while(cin>>m>>n){
        cin>>badlen;
        for(int i=0;i<badlen;i++){
            for(int j=0;j<4;j++){
                cin>>bad[i][j];
            }
        }
        cout<<dp(m,n)<<endl;
    }
}