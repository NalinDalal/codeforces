/* https://codeforces.com/problemset/problem/1901/A

A. Line Trip
time limit per test2 seconds
memory limit per test256 megabytes
There is a road, which can be represented as a number line. You are located in
the point 0 of the number line, and you want to travel from the point 0 to the
point 𝑥 , and back to the point 0
.

You travel by car, which spends 1
 liter of gasoline per 1
 unit of distance travelled. When you start at the point 0
, your car is fully fueled (its gas tank contains the maximum possible amount of
fuel).

There are 𝑛
 gas stations, located in points 𝑎1,𝑎2,…,𝑎𝑛
. When you arrive at a gas station, you fully refuel your car. Note that you can
refuel only at gas stations, and there are no gas stations in points 0 and 𝑥
.

You have to calculate the minimum possible volume of the gas tank in your car
(in liters) that will allow you to travel from the point 0 to the point 𝑥 and
back to the point 0
.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case consists of two lines:

the first line contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤50
; 2≤𝑥≤100
);
the second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0<𝑎1<𝑎2<⋯<𝑎𝑛<𝑥
).
Output
For each test case, print one integer — the minimum possible volume of the gas
tank in your car that will allow you to travel from the point 0 to the point 𝑥
 and back.

Example
InputCopy
3
3 7
1 2 5
3 6
1 2 5
1 10
7
OutputCopy
4
3
7
Note
In the first test case of the example, if the car has a gas tank of 4 liters,
you can travel to 𝑥 and back as follows:

travel to the point 1, then your car's gas tank contains 3 liters of fuel;
refuel at the point 1, then your car's gas tank contains 4 liters of fuel;
travel to the point 2, then your car's gas tank contains 3 liters of fuel;
refuel at the point 2, then your car's gas tank contains 4 liters of fuel;
travel to the point 5, then your car's gas tank contains 1 liter of fuel;
refuel at the point 5, then your car's gas tank contains 4 liters of fuel;
travel to the point 7, then your car's gas tank contains 2 liters of fuel;
travel to the point 5, then your car's gas tank contains 0 liters of fuel;
refuel at the point 5, then your car's gas tank contains 4 liters of fuel;
travel to the point 2, then your car's gas tank contains 1 liter of fuel;
refuel at the point 2, then your car's gas tank contains 4 liters of fuel;
travel to the point 1, then your car's gas tank contains 3 liters of fuel;
refuel at the point 1, then your car's gas tank contains 4 liters of fuel;
travel to the point 0, then your car's gas tank contains 3 liters of fuel.

*/

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
    ll n, x;
    cin >> n >> x;
    vl v(n);
    rep(i, 0, n) cin >> v[i];
    vl diff(n);
    ll ans = 0;
    ans = max(ans, v[0]);
    rep(i, 0, n - 1) { diff[i] = v[i + 1] - v[i]; }
    diff[n - 1] = 2 * (x - v[n - 1]);
    ans = max(ans, *max_element(all(diff)));
    cout << ans << nl;
  }
  return 0;
}

// submission: https://codeforces.com/problemset/submission/1901/299393111
