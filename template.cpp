#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

// Fast Input/Output
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Shortcuts for common containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;

// Fast GCD Calculation
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Factorial Precompute for nCr & nPr
const int N = 1e5;
ll fact[N + 1];

void precompute_factorial() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// Modular Exponentiation (x^y % p)
ll power(ll x, ll y, ll p) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

// Compute nCr % MOD
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * power(fact[r], MOD - 2, MOD) % MOD * power(fact[n - r], MOD - 2, MOD) % MOD;
}

// Compute nPr % MOD
ll nPr(ll n, ll r) {
    if (r > n) return 0;
    return fact[n] * power(fact[n - r], MOD - 2, MOD) % MOD;
}

// Generate all permutations of a string and store in vector
vector<string> permutations;
void permute(string s, int l, int r) {
    if (l == r) {
        permutations.push_back(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

// Generate all subsequences of a string and store in vector
vector<string> subsequences;
void subseq(string s, string out, int i) {
    if (i == sz(s)) {
        subsequences.push_back(out);
        return;
    }
    subseq(s, out + s[i], i + 1);
    subseq(s, out, i + 1);
}

// Loop Macros
#define FOR_LT(i, a, b) for (int i = (a); i < (b); i++)
#define FOR_LE(i, a, b) for (int i = (a); i <= (b); i++)
#define FOR_GT(i, a, b) for (int i = (a); i > (b); i--)
#define FOR_GE(i, a, b) for (int i = (a); i >= (b); i--)
#define WHILE_LT(x, a) while ((x) < (a))
#define WHILE_LE(x, a) while ((x) <= (a))
#define WHILE_GT(x, a) while ((x) > (a))
#define WHILE_GE(x, a) while ((x) >= (a))

// Shorter Names for Loops
#define FORLT FOR_LT
#define FORLE FOR_LE
#define FORGT FOR_GT
#define FORGE FOR_GE
#define WLT WHILE_LT
#define WLE WHILE_LE
#define WGT WHILE_GT
#define WGE WHILE_GE

// Prasun Singh Template 🚀
