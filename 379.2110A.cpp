/* A. Fashionable Array
time limit per test1 second
memory limit per test256 megabytes
In 2077, everything became fashionable among robots, even arrays...

We will call an array of integers 𝑎
 fashionable if min(𝑎)+max(𝑎)
 is divisible by 2
 without a remainder, where min(𝑎)
 — the value of the minimum element of the array 𝑎
, and max(𝑎)
 — the value of the maximum element of the array 𝑎
.

You are given an array of integers 𝑎1,𝑎2,…,𝑎𝑛
. In one operation, you can remove any element from this array. Your task is to
determine the minimum number of operations required to make the array 𝑎
 fashionable.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤103
). The description of the test cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤50
) — the size of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤50
) — the elements of the array 𝑎
.

Output
For each test case, output one integer — the minimum number of operations
required to make the array 𝑎 fashionable.

Example
InputCopy
6
2
5 2
7
3 1 4 1 5 9 2
7
2 7 4 6 9 11 5
3
1 2 1
2
2 1
8
8 6 3 6 4 1 1 6
OutputCopy
1
0
2
1
1
3
Note
In the first test case, at least one element needs to be removed since
min(𝑎)+max(𝑎)=2+5=7 , and 7 is not divisible by 2 . If any of the elements are
removed, only one element will remain. Then max(𝑎)+min(𝑎) will be divisible by 2
.

In the second test case, nothing needs to be removed since min(𝑎)+max(𝑎)=1+9=10
, and 10
 is divisible by 2
.

In the third test case, you can remove the elements with values 2
 and 4
, then min(𝑎)+max(𝑎)=5+11=16
, and 16
 is divisible by 2
.



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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((v[i] + v.back()) % 2)
        cnt++;
      else
        break;
    }
    int ans = cnt;
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if ((v[0] + v[i]) % 2) {
        ++cnt;
      } else {
        break;
      }
    }
    ans = (ans < cnt ? ans : cnt);
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2110/322004974
