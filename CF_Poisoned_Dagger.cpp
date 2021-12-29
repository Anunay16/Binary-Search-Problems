// link to the problem: https://codeforces.com/contest/1613/problem/C

//my solution: 
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define pii pair<int, int>
#define ff first
#define ss second
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mod 1000000007
#define sz(x) ((int)(x).size())
#define cc(ans) cout << ans << nline
#define all(x) (x).begin(), (x).end()
#define input(v) for (auto &x: v) cin >> x
#define print(v) for (auto &x: v) cout << x << " ";
#define rep(i, start, end) for(int i = start; i < end; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//=========================debugging================================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//==================================================================

bool isPossible(vector<ll>& a, ll h, ll k) {
    int n = sz(a);
    ll damage = 0;
    rep (i, 1, n) {
        ll gap = a[i] - a[i - 1];
        if (gap >= k) {
            damage += k;
        }
        else {
            damage += gap;
        }
    }
    damage += k;
    return h <= damage;
}

void solve() {
    /*
        the range of k is: 1 to 1e18
        so we may do binary search over this range
    */
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    input(a);
    ll start = 1;
    ll end = 1e18;
    ll ans = 1e18;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (isPossible(a, h, mid)) {
            ans = min(ans, mid);
            end = mid - 1LL;
        }
        else {
            start = mid + 1LL;
        }
    }
    cc(ans);
}

void FIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

signed main()
{
    fast;
    FIO();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
