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

// Generate all permutations of a string and store in a vector passed as a parameter
void permute(string s, int l, int r, vector<string>& permutations) {
    if (l == r) {
        permutations.push_back(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r, permutations);
        swap(s[l], s[i]);
    }
}

// Generate all subsequences of a string and store in a vector passed as a parameter
void subseq(string s, string out, int i, vector<string>& subsequences) {
    if (i == sz(s)) {
        subsequences.push_back(out);
        return;
    }
    subseq(s, out + s[i], i + 1, subsequences);
    subseq(s, out, i + 1, subsequences);
}

// Priority Queue Macros
#define mheapi priority_queue<int> // Max-Heap for int
#define mnheapi priority_queue<int, vector<int>, greater<int>> // Min-Heap for int
#define mheapll priority_queue<ll> // Max-Heap for long long
#define mnheapll priority_queue<ll, vector<ll>, greater<ll>> // Min-Heap for long long

// Ordered & Unordered Map Macros
#define omapi map<int, int> // Ordered map for int
#define omapll map<ll, ll> // Ordered map for long long
#define umapi unordered_map<int, int> // Unordered map for int
#define umapll unordered_map<ll, ll> // Unordered map for long long

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

// Auto Loop Macro
#define FORA(x, container) for (auto& x : container)

// Prasun Singh Template 🚀
