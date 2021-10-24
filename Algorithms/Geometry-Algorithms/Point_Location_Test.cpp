//https://cses.fi/problemset/task/2189
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        long x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        long val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
        if(val>0){ // clockwise
            cout<<"RIGHT"<<endl;
        }else if(val<0){
            cout<<"LEFT"<<endl;
        }else cout<<"TOUCH"<<endl;
 
    }
}
