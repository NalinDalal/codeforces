/*B. Charming Meals
time limit per test2 seconds
memory limit per test256 megabytes
The Czech cuisine features 𝑛
 appetizers and 𝑛
 main dishes. The 𝑖
-th appetizer has spiciness 𝑎𝑖
, and the 𝑖
-th main dish has spiciness 𝑏𝑖
.

A typical Czech meal consists of exactly one appetizer and one main dish. You
want to pair up the 𝑛 appetizers and 𝑛 main dishes into 𝑛 meals with each
appetizer and each main dish being included in exactly one meal.

Your meals shall surprise the diners, so you want the spiciness levels of the
two parts of the same meal to be as different as possible. The charm of a meal
is the difference (in absolute value) between the spiciness of the appetizer and
the spiciness of the main dish. So, a meal consisting of an appetizer with
spiciness 𝑥 and a main dish with spiciness 𝑦 has charm equal to |𝑥−𝑦|
.

You want to maximize the minimum charm of the resulting 𝑛
 meals. What is the largest possible value of the minimum charm that you can
achieve?

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. The descriptions of the 𝑡
 test cases follow.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤5000
) —the number of appetizers and main dishes.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
) — the spicinesses of the 𝑛
 appetizers.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (0≤𝑏𝑖≤109
) — the spicinesses of the 𝑛
 main dishes.

It is guaranteed that the sum of 𝑛2
 over all test cases does not exceed 25⋅106
.

Output
For each test case, print the largest possible value of the minimum charm you
can achieve.

Example
InputCopy
4
3
0 0 0
1000000000 1000000000 1000000000
5
1 2 3 4 5
1 2 3 4 5
6
0 0 0 100 100 100
100 100 100 0 0 0
7
14 25 62 74 86 95 12
51 62 71 72 92 20 84
OutputCopy
1000000000
2
100
30
Note
In the first test case, no matter how you pair up the appetizers with the main
dishes, each meal will have an appetizer with spiciness 0 and a main dish with
spiciness 1000000000 , so the charm of each meal will be 1000000000
.

In the second test case, one optimal way to pair up appetizers and main dishes
is: (1,5) , (2,4) , (3,1) , (4,2) , (5,3) . The corresponding meals have charms:
4 , 2 , 2 , 2 , 2 . The resulting minimum charm is 2
.

In the third test case, one way to maximize the minimum charm is to pair up the
three appetizers with spiciness 0 with the three main dishes with spiciness 100
, and the three appetizers with spiciness 100
 with the three main dishes with spiciness 0
. Doing so, the charm of each meal will be exactly 100
.
*/
/*maximie min absolute diff
 If we sort both arrays, then the optimal pairing must be either:

Same order: pair a[i] with b[i].

Opposite order: pair a[i] with b[n-1-i].

Pair in same order: a[i] with b[i].

Pair in reverse order: a[i] with b[n-1-i].

then take:
ans = max(
    *min_element(diff_same.begin(), diff_same.end()),
    *min_element(diff_reverse.begin(), diff_reverse.end())
);
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int RANGE = pow(10, 9) + 1;

int min_diff_with_shift(vector<int> &a, vector<int> &b, int shift) {
  int n = a.size(), min_diff = RANGE;
  for (int i = 0; i < n; i++) {
    min_diff = min(min_diff, abs(a[i] - b[(i + shift) % n]));
  }
  return min_diff;
}

int main() {
  int n_tests = 0;
  cin >> n_tests;

  while (n_tests > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    int ans = 0;

    for (int &ai : a)
      cin >> ai;
    for (int &bi : b)
      cin >> bi;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int shift = 0; shift < n; shift++)
      ans = max(ans, min_diff_with_shift(a, b, shift));

    cout << ans << endl;
    n_tests--;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1949/338155622
