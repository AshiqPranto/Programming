/* � Ashiq Uddin Pranto
   Department of Computer Science and Engineering
   BATCH 27
   University Of Rajshahi,Bangladesh
*/
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define FOR(x, y) for (ll i = x; i <= y; i++)
#define f0(x) for (ll i = 0; i <= x; i++)
#define f1(x) for (ll i = 1; i <= x; i++)
#define pb(x) push_back(x)
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vii vector<int>
#define vll vector<ll>
#define matrix(x) vector<vector<x>>
#define vss vector<string>
#define PI (2 * acos(0.0))
#define sqr(x) ((x) * (x))
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sffl(a, b) scanf("%lld %lld", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sfffl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define ms(a, b) memset(a, b, sizeof(a))
#define ff first
#define ss second
#define lcm(a, b) ((a) * ((b) / __gcd(a, b)))
#define all(a) a.begin(), a.end()
#define readfile freopen("input.txt", "r", stdin);
#define writefile freopen("output.txt", "w", stdout);
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define gap " "
#define mx 104
#define inf (ll)1e17
#define WHITE 1
#define GRAY 2
#define BLACK 3
#define EMPTY_VALUE -1
#define mod 1000000007
#define MOD(a, b) (a % b + b) % b
 
using namespace std;
 
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
 
int failure[1000005];
void build_failure(string pattern)
{
    int sz = pattern.size();
    failure[0] = failure[1] = 0;
    for (int i = 2; i <= sz; i++)
    {
        int j = failure[i - 1];
        while (true)
        {
                
        // printf("i = %d, j = %d\n",i,j); 
        // cout<<pattern<<endl;
        // if(pattern[j]==pattern[j]) cout<<"check 1"<<endl;
            if (pattern[j] == pattern[(i - 1)])
            {
                // debug("check");
                failure[i] = failure[i - 1] + 1;
                break;
            }
            if (j == 0)
            {
                failure[i] = 0;
                break;
            }
            j = failure[j];
        }
    }
}
 
int kmp(string text, string pattern)
{
    build_failure(pattern);
    int cnt = 0;
    int i = 0;
    int j = 0;
    int n = text.size();
    int m = pattern.size();
    while (true)
    {
        if (j == m)
        {
            cnt++;
            j = failure[j];
        }
        if (i == n)
            break;
        if (text[i] == pattern[j])
            i++, j++;
        else
        {
            if (j == 0)
                i++;
            j = failure[j];
        }
    }
    return cnt;
}
 
void eff()
{
    string text, pattern;
    cin >> text >> pattern;
    // printf("text = %d\npatter = %d\n",text.size(),pattern.size());
    
    cout << kmp(text, pattern) << endl;
    // for(int i = 0;i <=pattern.size();i++) cout<<failure[i]<<endl;
}
 
int main()
{
    // fastio
    ll test = 1;
    // sfl(test);
    for (ll i = 0; i < test; i++)
    {
        // printf("Case %lld: ",i+1);
        eff();
    }
    //    cout<<check(81);
    return 0;
}