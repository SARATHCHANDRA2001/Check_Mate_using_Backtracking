#include<bits/stdc++.h>
using namespace std;
vector<int>rows={1,-1,0,0,1,1,-1,-1};
vector<int>cols={0,0,1,-1,1,-1,-1,1};
bool isValid(int i,int j){
    if(i<0 || j<0 || i>7 || j>7)
        return false;
    return true;
}
bool check(int a,int b,vector<pair<int,int>>&pos){
    for(int i=1;i<=7;i++){
            int x=pos[0].first;
            int y=pos[0].second;
            for(int j=0;j<8;j++){
                if(isValid(x+rows[j]*i,y+cols[j]*i) && x+rows[j]*i==a,y+cols[j]*i==b){
                    return true;
                }
            }
        }
        int x=pos[1].first;
        int y=pos[1].second;
        for(int i=0;i<8;i++){
            if(isValid(x+rows[i],y+cols[i]) && x+rows[i]==a && y+cols[i]==b){
                return true;
            }
        }
        return false;

}
bool checkmate(vector<pair<int,int>>&pos){
        int x=pos[2].first;
        int y=pos[2].second;
        for(int i=0;i<8;i++){
            if(isValid(x+rows[i],y+cols[i]) && !check(x+rows[i],y+cols[i],pos)){
                    return false;
            }
        }
        return true;
}

void dist(int chance,vector<pair<int,int>>pos,int &ans,int d){
    if(chance==1){
        // logic for opp king movement
        int x=pos[2].first;
        int y=pos[2].second;
        if(checkmate(pos)){
            ans=min(ans,d);
            return ;
        }
        for(int i=0;i<8;i++){
            if(isValid(x+rows[i],y+cols[i]) && !check(x+rows[i],y+cols[i],pos)){
                    pos[2].first=x+rows[i];
                    pos[2].second=y+cols[i];
                    dist(1-chance,pos,ans,d+1);
                    pos[2].first=x;
                    pos[2].second=y;
            }
        }
    }
    else{
        // logic for our queen movement
        for(int i=1;i<=7;i++){
            int x=pos[0].first;
            int y=pos[0].second;
            for(int j=0;j<8;j++){
                if(isValid(x+rows[j]*i,y+cols[j]*i)){
                    pos[0].first=x+rows[j]*i;
                    pos[0].second=y+cols[j]*i;
                    dist(1-chance,pos,ans,d+1);
                    pos[0].first=x;
                    pos[0].second=y;
                }
            }
        }

        // logic for our king movement
        int x=pos[1].first;
        int y=pos[1].second;
        for(int i=0;i<8;i++){
            if(isValid(x+rows[i],y+cols[i])){
                    pos[1].first=x+rows[i];
                    pos[1].second=y+cols[i];
                    dist(1-chance,pos,ans,d+1);
                    pos[1].first=x;
                    pos[1].second=y;
            }
        }
    }
}
int main(){
    vector<vector<int>>board(8,vector<int>(8,0));
    vector<pair<int,int>>pos;
    for(int i=0;i<3;i++){
        int x,y;cin>>x>>y;
        pos.push_back(make_pair(x,y));
    }
    int ans=INT_MAX;
    dist(0,pos,ans,0);
    cout<<ans;
}