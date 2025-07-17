// Includes
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <iomanip>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

// Macros & Typedefs
using ll = long long;
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define py cout << "Yes" << endl
#define pn cout << "No" << endl
#define pm cout << "-1" << endl
#define INF 1e18
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define faster ios::sync_with_stdio(false); cin.tie(nullptr);
const int mod = 998244353;
const int M = 1e9 + 7;

// Debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Math
int binexp(int a, int b, int p = M) { int res = 1; a %= p; while (b > 0) { if (b & 1) res = res * a % p; a = a * a % p; b >>= 1; } return res; }
int modinv(int x, int p = M) { return binexp(x, p - 2, p); }
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
inline int lcm(int x, int y) { return x / gcd(x, y) * y; }

// Factorial & Combinations
const int N = 1e5 + 5;
vector<int> fact(N), invFact(N);
void precompute_factorials(int p = M) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % p;
        invFact[i] = modinv(fact[i], p);
    }
}
int nCr(int n, int r, int p = M) {
    if (r < 0 || r > n) return 0;
    return fact[n] * 1LL * invFact[r] % p * invFact[n - r] % p;
}

// Prime & Sieve
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    return is_prime;
}

// DSU
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n); size.resize(n, 1); iota(all(parent), 0);
    }
    int find(int x) { return (x == parent[x]) ? x : parent[x] = find(parent[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x; size[x] += size[y];
        return true;
    }
};

// Z-function
vector<int> z_function(string s) {
    int n = s.size(); vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    } return z;
}

// Binary Search
int binarySearch(int lo, int hi, function<bool(int)> check) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// Misc
bool ispali(string s) { int n = s.size(); fr(i, 0, n / 2) if (s[i] != s[n - 1 - i]) return false; return true; }
int sod(int n) { int sum = 0; while (n > 0) { sum += (n % 10); n /= 10; } return sum; }
void printarray(const vector<int>& ans) { for (auto& x : ans) cout << x << " "; cout << endl; }

// Solve & Main
void solve() {
    // Your solution here
    int n;
    cin>>n;
    vector<int>vt(n);
    
    for(int i=0;i<n;i++)cin>>vt[i];
    int ans = INT_MAX;

    for(int i=0;i<n;i++){
        ans = min(ans,abs(vt[i]));
    }
    cout<<ans<<endl;
}

int main() {
    faster
    // int t;
    // cin >> t;
    // while (t--) 
    solve();
    return 0;
}