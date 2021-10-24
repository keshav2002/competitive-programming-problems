// https://cses.fi/problemset/task/2190

/*
 Code by,
 ___     _               __ _       
| _ \___| |_  __ _ _ _  / _(_)______
|   / _ \ ' \/ _` | ' \|  _| |_ /_ /
|_|_\___/_||_\__,_|_||_|_| |_/__/__|                                                       
*/
#include<bits/stdc++.h>
typedef int int32_t;
#define int         long long int
#define LOOP(i,n)   for (int i = 1; i <= n; i++)
#define loop(i,n)   for(int i = 0;i<n;i++)
#define REP(i,a,b)  for(int i = a;i<=b;i++)
#define INF         1000000000
#define mod         1000000007
#define pb          push_back
#define ff          first
#define ss          second
#define ii          pair<int,int>
#define vi          vector<int>
#define vvi         vector<vi>
#define vii         vector<ii>
 
#define szv(V)      ((int)(V).size())
#define allv(V)     (V).begin(), (V).end()
#define sortv(V)    sort(allv(V));
#define debug       cout<<"debugged here"<<endl;
 
#define endl        '\n'
#define X           real()
#define Y           imag()
#define tup         tuple<int,int,int>
#define graphType   vector<vector<tup>>
#define zt(x)       get<0>(x)
#define ot(x)       get<1>(x)
#define tt(x)       get<2>(x)
//oprations
#define isPowerOf2(x) (x && ceil(log2(x))==floor(log2(x)))
#define dotp(a,b)   ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define crossp(a,b) ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define firstSetBit(n) ( (log2(n & -n) + 1)   )
//
const double EPS = (1e-7);
const double PI = 3.141592653589793238460;
typedef std::complex<double> point;
typedef std::valarray<point> CArray;
    
using namespace std;
int __lcm(int a,int b) {return a*b/__gcd(a,b);}
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}
 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
 
void addEdge(graphType& graph, int src, int nbr, int wt){
    graph[src].pb(make_tuple(src,nbr,wt));
}
 
void addEdge2(graphType& graph, int src, int nbr, int wt){
    graph[src].pb(make_tuple(src,nbr,wt));
    graph[nbr].pb(make_tuple(nbr,src,wt));
}
 
graphType graphDefine(int sz){
    graphType graph;
    for(int i = 0;i<sz;i++){
        vector<tup> t; 
        graph.pb(t);
    }
    return graph;
}
 
int ori(int x1,int y1,int x2,int y2,int x3,int y3){
    int val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
    if(val>0) return 1; // clockwise
    else if(val<0) return 2; // counter-clockwise
    return 0; //collinear
}
 
bool onSeg(int x1,int y1,int x2,int y2,int x3,int y3){
    return (x3<=max(x1,x2) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3>=min(y1,y2));
}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T; cin>>T;
    while(T--){
        int x1,y1,x2,y2,x3,y3,x4,y4; cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        int o1 = ori(x1,y1,x2,y2,x3,y3);
        int o2 = ori(x1,y1,x2,y2,x4,y4);
        int o3 = ori(x3,y3,x4,y4,x1,y1);
        int o4 = ori(x3,y3,x4,y4,x2,y2);
        if( o1!=o2  && o3!=o4 ){
            cout<<"YES"<<endl;
        }else if(o1 == 0 && onSeg(x1,y1,x2,y2,x3,y3)){      
            cout<<"YES"<<endl;
        }else if(o2 == 0 && onSeg(x1,y1,x2,y2,x4,y4)){
            cout<<"YES"<<endl;
        }else if(o3 == 0 && onSeg(x3,y3,x4,y4,x1,y1)){
            cout<<"YES"<<endl;
        }else if(o4 == 0 && onSeg(x3,y3,x4,y4,x2,y2)){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
}
/* 
Checks
-> provided test cases
-> integer overflow,array bounds
-> special cases (n==1?)
-> copy all used functions
*/
