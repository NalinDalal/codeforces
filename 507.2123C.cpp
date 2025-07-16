/*C. Prefix Min and Suffix Max
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎
 of distinct integers.

In one operation, you may either:

choose a nonempty prefix∗
 of 𝑎
 and replace it with its minimum value, or
choose a nonempty suffix†
 of 𝑎
 and replace it with its maximum value.
Note that you may choose the entire array 𝑎
.

For each element 𝑎𝑖
, determine if there exists some sequence of operations to transform 𝑎
 into [𝑎𝑖]
; that is, make the array 𝑎
 consist of only one element, which is 𝑎𝑖
. Output your answer as a binary string of length 𝑛
, where the 𝑖
-th character is 1
 if there exists a sequence to transform 𝑎
 into [𝑎𝑖]
, and 0
 otherwise.

∗
A prefix of an array is a subarray consisting of the first 𝑘
 elements of the array, for some integer 𝑘
.

†
A suffix of an array is a subarray consisting of the last 𝑘
 elements of the array, for some integer 𝑘
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤2⋅105
) — the size of the array 𝑎
.

The second line of each test case contains 𝑛
 integers, 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
). It is guaranteed that all 𝑎𝑖
 are distinct.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a binary string of length 𝑛
  — the 𝑖
-th character should be 1
 if there exists a sequence of operations as described above, and 0
 otherwise.

Example
InputCopy
3
6
1 3 5 4 7 2
4
13 10 12 20
7
1 2 3 4 5 6 7
OutputCopy
100011
1101
1000001
Note
In the first sample, you can first choose the prefix of size 3
. Then the array is transformed into

1	4	7	2
Next, you can choose the suffix of size 2
. Then the array is transformed into
1	4	7
Finally, you can choose the prefix of size 3
. Then the array is transformed into
1
So we see that it is possible to transform 𝑎
 into [1]
.
It can be shown that it is impossible to transform 𝑎
 into [3]
.
*/

// if we can convert whole array to a[i], thn print 1 for that i else 0
// make a prefix min array, suffix max array
// if(curr==prefixMin || curr==suffixMax) return true;
// else return false;
// if(true)cout<<"1"<<endl;
// else cout<<"0"<<endl;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
      cin >> x;
    map<int, int> mp;

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (v[i] < mn) {
        mn = v[i];
        mp[v[i]] = 1;
      }
    }

    int mx = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] > mx) {
        mx = v[i];
        mp[v[i]] = 1;
      }
    }

    for (auto &x : v)
      cout << mp[x];
    cout << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2123/329195222
