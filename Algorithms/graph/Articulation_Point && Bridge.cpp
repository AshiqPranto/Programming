/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include<bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x,y) for(ll i=x;i<=y;i++)
#define f0(x) for(ll i = 0;i<=x;i++)
#define f1(x) for(ll i = 1;i<=x;i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define matrix(x) vector<vector<x>>
#define vss vector<string>
#define PI (2*acos(0.0))
#define sqr(x) ((x)*(x))
#define sf(a)   scanf("%d",&a)
#define sfl(a)  scanf("%lld",&a)
#define sff(a,b)    scanf("%d %d",&a,&b)
#define sffl(a,b)   scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define ms(a,b) memset(a, b, sizeof(a))
#define ff  first
#define ss  second
#define lcm(a, b)   ((a)*((b)/__gcd(a,b)))
#define all(a)  a.begin(),a.end()
#define readfile freopen("input.txt","r",stdin);
#define writefile freopen("output.txt","w",stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define gap " "
#define mx 10000
#define inf (ll)1e17
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 1000000007
#define MOD(a,b) (a%b + b)%b
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
vector<int>adj[mx];
int disc[mx],low[mx],parent[mx];
bool vis[mx];
vector<pii>ansofbridge;
vector<int>ansofpoint;
int timer;

void dfs(int u,int p = -1)
{
    vis[u] = true;
    disc[u] = low[u] = timer++;
    int child = 0;
    for(int v : adj[u])
    {
        if(v==p) continue;
        if(vis[v])
        {
            low[u] = min(low[u],disc[v]);
        }
        else{
            child++;
            parent[v] = u;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(parent[u]==-1 && child>1)
                    ansofpoint.push_back(u);
            if(parent[u]!=-1 && low[v]>=disc[u])
            {
                // else 
                ansofpoint.push_back(u);
                
            }
            if(low[v]>disc[u])
            {
                ansofbridge.push_back({min(u,v),max(u,v)});
            }
        }
    }
}

void eff()
{
    int n,m;
    sff(n,m);
    int u,v;
    while(m--)
    {
        sff(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // memset(vis,0,sizeof(vis));
    for(int i = 0;i<mx;i++)
    {
        vis[i] = false;
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }
    timer = 0;
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    sort(ansofpoint.begin(),ansofpoint.end());
    cout<<"Articulation Points\n";
    cout<<ansofpoint.size()<<endl;
    for(int i = 0;i<ansofpoint.size();i++)
    {
        cout<<ansofpoint[i]<<" ";
    }
    cout<<"\nArticulation Bridge\n";
    cout<<endl<<ansofbridge.size()<<endl;
    sort(ansofbridge.begin(),ansofbridge.end());
    for(int i = 0;i<ansofbridge.size();i++)
    {
        cout<<ansofbridge[i].first<<" "<<ansofbridge[i].second<<endl;
    }
    // debug(ansofpoint);
    // debug(ansofbridge);
}
 
int main()
{
    // fastio
    ll test = 1;
    // sfl(test);
    for(ll i=0;i<test;i++)
    {
        // printf("Case %lld: ",i+1);
        eff();
    }
//    cout<<check(81);
    return 0;
}

// Sample Input
// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
// https://cp-algorithms.com/graph/bridge-searching.html