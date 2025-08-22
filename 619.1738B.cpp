/*B. Prefix Sum Addicts
time limit per test2 seconds
memory limit per test512 megabytes
Suppose 𝑎1,𝑎2,…,𝑎𝑛
 is a sorted integer sequence of length 𝑛
 such that 𝑎1≤𝑎2≤⋯≤𝑎𝑛
.

For every 1≤𝑖≤𝑛
, the prefix sum 𝑠𝑖
 of the first 𝑖
 terms 𝑎1,𝑎2,…,𝑎𝑖
 is defined by
𝑠𝑖=∑𝑘=1𝑖𝑎𝑘=𝑎1+𝑎2+⋯+𝑎𝑖.

Now you are given the last 𝑘
 terms of the prefix sums, which are 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛
. Your task is to determine whether this is possible.

Formally, given 𝑘
 integers 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛
, the task is to check whether there is a sequence 𝑎1,𝑎2,…,𝑎𝑛
 such that

𝑎1≤𝑎2≤⋯≤𝑎𝑛
, and
𝑠𝑖=𝑎1+𝑎2+⋯+𝑎𝑖
 for all 𝑛−𝑘+1≤𝑖≤𝑛
.
Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤105
) — the number [48;56;204;1792;2856tof test cases. The following lines
contain the description of each test case.

The first line of each test case contains two integers 𝑛
 (1≤𝑛≤105
) and 𝑘
 (1≤𝑘≤𝑛
), indicating the length of the sequence 𝑎
 and the number of terms of prefix sums, respectively.

The second line of each test case contains 𝑘
 integers 𝑠𝑛−𝑘+1,…,𝑠𝑛−1,𝑠𝑛
 (−109≤𝑠𝑖≤109
 for every 𝑛−𝑘+1≤𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each test case, output "YES" (without quotes) if it is possible and "NO"
(without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and
"Yes" will be recognized as a positive response).

Example
InputCopy
4
5 5
1 2 3 4 5
7 4
-6 -5 -3 0
3 3
2 3 4
3 2
3 4
OutputCopy
Yes
Yes
No
No
Note
In the first test case, we have the only sequence 𝑎=[1,1,1,1,1]
.

In the second test case, we can choose, for example, 𝑎=[−3,−2,−1,0,1,2,3]
.

In the third test case, the prefix sums define the only sequence 𝑎=[2,1,1]
, but it is not sorted.

In the fourth test case, it can be shown that there is no sequence with the
given prefix sums.
*/

/*given a vector a and s
 s[i]=a[1]+a[2]+...+a[i]

 we are given:
 s_{n-k+1}, s_{n-k+2}, …, s_n

construct last k elements of a

since a1<=a2<a3....<=an, so
a_{n-k+1} ≤ a_{n-k+2} ≤ … ≤ a_n

hence
(s_{n-k+2} − s_{n-k+1}) ≤ (s_{n-k+3} − s_{n-k+2}) ≤ … ≤ (s_n − s_{n-1})

if k=1-> yes
if k>1->
    a_{n-k+1} ≤ (s_{n-k+2} − s_{n-k+1})
    s_{n-k+1} ≤ (n-k+1) * (s_{n-k+2} − s_{n-k+1})

algo:
1. if k==1 -> yes
2. d[i] = s_{i} − s_{i-1}   for i = n-k+2 … n
    check if d is non-decreasing, if not-> no
3. check if s_{n-k+1} ≤ (n-k+1) * d[n-k+2]
            yes
        else
            no
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> s(k);
    for (int i = 0; i < k; i++)
      cin >> s[i];

    if (k == 1) {
      cout << "YES\n";
      continue;
    }

    vector<long long> diff;
    for (int i = 1; i < k; i++) {
      diff.push_back(s[i] - s[i - 1]);
    }

    if (!is_sorted(diff.begin(), diff.end())) {
      cout << "NO\n";
      continue;
    }

    // check prefix condition
    long long firstPrefix = s[0];
    long long minAllowed = (long long)(n - k + 1) * diff[0];

    if (firstPrefix <= minAllowed)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1738/334976992
