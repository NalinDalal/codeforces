/* https://codeforces.com/problemset/problem/1896/A
A. Jagged Swaps
time limit per test1 second
memory limit per test256 megabytes
You are given a permutation† 𝑎 of size 𝑛. You can do the following operation

Select an index 𝑖 from 2 to 𝑛−1 such that 𝑎𝑖−1<𝑎𝑖 and 𝑎𝑖>𝑎𝑖+1. Swap 𝑎𝑖 and 𝑎𝑖+1.
Determine whether it is possible to sort the permutation after a finite number
of operations.

A permutation is an array consisting of 𝑛 distinct integers from 1 to 𝑛 in
arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a
permutation (2 appears twice in the array) and [1,3,4] is also not a permutation
(𝑛=3 but there is 4 in the array).

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤5000). Description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (3≤𝑛≤10) — the size
of the permutation.

The second line of each test case contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛) — the
elements of permutation 𝑎.

Output
For each test case, print "YES" if it is possible to sort the permutation, and
"NO" otherwise.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs"
will all be recognized as positive answer).

Example
InputCopy
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4
OutputCopy
YES
YES
NO
NO
NO
NO
Note
In the first test case, the permutation is already sorted.
In the second test case, we can choose index 𝑖=2 as 1<3 and 3>2 to form
[1,2,3,5,4]. Then, we can choose index 𝑖=4 as 3<5 and 5>4 to form [1,2,3,4,5].
In the third test case, it can be proven that it is impossible to sort the
permutation.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // sort logic-> i from 2 to n-1;a[i-1]<a[i] && a[i]>a[i+1],
    // swap(a[i],a[i+1]) if all swap possible then flag=true else flag=false
    // if(flag)print Yes
    // else print No
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
      }
    }

    // Check if the array is sorted
    bool isSorted = true;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] > a[i]) {
        isSorted = false;
        break;
      }
    }

    // Output result
    cout << (isSorted ? "YES" : "NO") << endl;
  }
  return 0;
}

/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define print_map(m)                                                           \
  for (const auto &[key, value] : m) {                                         \
    cout << '[' << key << ']' << ' ' << '=' << ' ' << value << '\n';           \
  }
#define print_vector(v)                                                        \
  int vadnfiv = 0;                                                             \
  for (const auto &value : v) {                                                \
    cout << vadnfiv << ' ' << value << '\n';                                   \
    vadnfiv++;                                                                 \
  }
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / gcd(a, b)))
unsigned long long int rangesum(long long int L, long long int R) {
  return ((L + R) * (abs(R - L) + 1)) / 2;
}
#define start_time                                                             \
  using std::chrono::duration;                                                 \
  using std::chrono::duration_cast;                                            \
  using std::chrono::high_resolution_clock;                                    \
  using std::chrono::milliseconds;                                             \
  auto t1111 = high_resolution_clock::now();
#define end_time                                                               \
  auto t2222 = high_resolution_clock::now();                                   \
  duration<double, std::milli> ms_double = t2222 - t1111;                      \
  std::cout << ms_double.count() << 'm' << 's' << nl;
#define goodluck                                                               \
  for (int arik = 0; arik < 9185319; arik++) {                                 \
    string a = "arik";                                                         \
    a.pop_back();                                                              \
    a.pop_back();                                                              \
    a.pop_back();                                                              \
    a.pop_back();                                                              \
  }
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
#define multicase                                                              \
  int NoOfTestCase = 1;                                                        \
  cin >> NoOfTestCase;                                                         \
  for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)
bool isPrime(int n) {
  if (n == 2 || n == 3) {
    return true;
  }
  if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
bool isPalindrome(string S) {
  string P = S;
  reverse(P.begin(), P.end());
  if (S == P) {
    return true;
  } else {
    return false;
  }
}
bool isPowerof(long long num, long long base) {
  if (num <= 0) {
    return false;
  }
  if (num % base == 0) {
    return isPowerof(num / base, base);
  }
  if (num == 1) {
    return true;
  }
  return false;
}

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

int main() {
  fastio multicase {
    ll n;
    cin >> n;
    vl v(n);
    rep(i, 0, n) { cin >> v[i]; }
    if (v[0] == 1) {
      cout << "YES" << nl;
    } else {
      cout << "NO" << nl;
    }
  }
  return 0;
}
