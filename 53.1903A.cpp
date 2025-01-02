// https://codeforces.com/problemset/problem/1903/A

/* A. Halloumi Boxes
time limit per test1 second
memory limit per test256 megabytes
Theofanis is busy after his last contest, as now, he has to deliver many
halloumis all over the world. He stored them inside 𝑛 boxes and each of which
has some number 𝑎𝑖 written on it.

He wants to sort them in non-decreasing order based on their number, however,
his machine works in a strange way. It can only reverse any subarray† of boxes
with length at most 𝑘.

Find if it's possible to sort the boxes using any number of reverses.

† Reversing a subarray means choosing two indices 𝑖 and 𝑗 (where 1≤𝑖≤𝑗≤𝑛) and
changing the array 𝑎1,𝑎2,…,𝑎𝑛 to 𝑎1,𝑎2,…,𝑎𝑖−1,𝑎𝑗,𝑎𝑗−1,…,𝑎𝑖,𝑎𝑗+1,…,𝑎𝑛−1,𝑎𝑛. The
length of the subarray is then 𝑗−𝑖+1.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤100) — the number of test cases.

Each test case consists of two lines.

The first line of each test case contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤100) — the
number of boxes and the length of the maximum reverse that Theofanis can make.

The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the number written
on each box.

Output
For each test case, print YES (case-insensitive), if the array can be sorted in
non-decreasing order, or NO (case-insensitive) otherwise.

Example
InputCopy
5
3 2
1 2 3
3 1
9 9 9
4 4
6 4 2 1
4 3
10 3 830 14
2 1
3 1
OutputCopy
YES
YES
YES
YES
NO
Note
In the first two test cases, the boxes are already sorted in non-decreasing
order.

In the third test case, we can reverse the whole array.

In the fourth test case, we can reverse the first two boxes and the last two
boxes.

In the fifth test case, it can be shown that it's impossible to sort the boxes.

*/

/*#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    //
int l = 0, r = n - 1;
while (l < r) {
  int mid = (l + r) / 2;
  if (v[mid] >= v[l]) {
    r = mid;
  } else {
    l = mid + 1;
  }
}
cout << "YES" << endl;
}
}//*

    vector<int> sorted_v = v;               // Copy of the array
    sort(sorted_v.begin(), sorted_v.end()); // Desired sorted order

    // Check if sorting is possible using sliding windows
    bool possible = true;
    for (int i = 0; i < n; i++) {
      // Check if `v[i]` can move to its correct position in `sorted_v`
      auto it = find(v.begin() + max(0, i - k + 1), v.begin() + min(n, i + k),
                     sorted_v[i]);
      if (it == v.begin() + min(n, i + k)) {
        possible = false; // Not found within the allowed range
        break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}*/

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n, k;
    cin >> n >> k; // Number of boxes and max length of reverse
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    vector<int> sorted_v = v;               // Copy the original array
    sort(sorted_v.begin(), sorted_v.end()); // Sort the copy

    // Check in groups of size `k` for matching segments
    bool possible = true;
    for (int i = 0; i < n; i++) {
      // Collect indices of elements in the same modulo group
      vector<int> original_group, sorted_group;
      for (int j = i; j < n; j += k) {
        original_group.push_back(v[j]);
        sorted_group.push_back(sorted_v[j]);
      }

      // Sort the original group and compare with sorted group
      sort(original_group.begin(), original_group.end());
      if (original_group != sorted_group) {
        possible = false; // If any group mismatches, sorting is impossible
        break;
      }
    }

    if (possible) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}*/

// correct:
/*#include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
      cin >> v[i];
    }
    bool isorteddd = is_sorted(v.begin(), v.end());
    if (isorteddd) {
      cout << "YES" << nl;
      continue;
    }
    if (k == 1 && isorteddd == false) {
      cout << "NO" << nl;
      continue;
    } else {
      cout << "YES" << nl;
    }
  }
  return 0;
}*/

// also correct:
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    if (k == 1) {
      if (std::is_sorted(a.begin(), a.end())) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    } else {
      std::cout << "YES\n";
    }
  }
  return 0;
}
// submission: https://codeforces.com/problemset/submission/1903/299392530
