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
#define mx 100005
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
vector<int>par(mx);
bool vis[mx];
int ans;

void dfs(int x)
{
    // debug(x);
    if(ans) return;
    vis[x] = true;
    for(int v: adj[x])
    {
        if(ans) return;
        if(v!=par[x])
        {
            // debug(v);
            par[v] = x;
            if(vis[v])
            {
                ans = v;
                // debug(ans);
                return;
            }
            dfs(v);
        }
    }
}

void eff()
{
    int n,m;
    sff(n,m);
    int u,v;
    for(int i = 0;i<m;i++)
    {
        sff(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // for(int i = 1;i<=n;i++)
    // {
    //     cout<<i<<" -> ";
    //     for(int j = 0;j<adj[i].size();j++)
    //     {
    //         cout<<adj[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    for(int i = 1; i<=n;i++)
    {
        if(vis[i]==0 && ans==0)
        {
            par[i] = -1;
            dfs(i);
            if(ans==1) break;
        }
        // memset(par,0,sizeof(par));
        // memset(vis,0,sizeof(vis));
    }
    // debug(ans);
    // debug(par);
    if(ans)
    {
        vector<int>result;
        result.pb(ans);
        int x = ans;
        while (par[x]!=ans)
        {
            x = par[x];
            result.pb(x);
        }
        result.pb(ans);
        cout<<result.size()<<endl;
        for(int temp: result)
        {
            cout<<temp<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
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