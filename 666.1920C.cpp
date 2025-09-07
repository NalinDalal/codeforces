/*C. Partitioning the Array
time limit per test3 seconds
memory limit per test256 megabytes
Allen has an array 𝑎1,𝑎2,…,𝑎𝑛
. For every positive integer 𝑘
 that is a divisor of 𝑛
, Allen does the following:

He partitions the array into 𝑛𝑘
 disjoint subarrays of length 𝑘
. In other words, he partitions the array into the following subarrays:
[𝑎1,𝑎2,…,𝑎𝑘],[𝑎𝑘+1,𝑎𝑘+2,…,𝑎2𝑘],…,[𝑎𝑛−𝑘+1,𝑎𝑛−𝑘+2,…,𝑎𝑛]
Allen earns one point if there exists some positive integer 𝑚
 (𝑚≥2
) such that if he replaces every element in the array with its remainder when
divided by 𝑚 , then all subarrays will be identical. Help Allen find the number
of points he will earn.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the number of points Allen will
earn.

Example
InputCopy
8
4
1 2 1 4
3
1 2 3
5
1 1 1 1 1
6
1 3 1 1 3 1
6
6 2 6 2 2 2
6
2 6 3 6 6 6
10
1 7 5 1 4 3 1 3 1 4
1
1
OutputCopy
2
1
2
4
4
1
2
1
Note
In the first test case, 𝑘=2
 earns a point since Allen can pick 𝑚=2
 and both subarrays will be equal to [1,0]
. 𝑘=4
 also earns a point, since no matter what 𝑚
 Allen chooses, there will be only one subarray and thus all subarrays are
equal.

In the second test case, Allen earns 1
 point for 𝑘=3
, where his choice for 𝑚
 does not matter.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    // Step 1: get divisors of n
    vector<int> divisors;
    for (int d = 1; d * d <= n; d++) {
      if (n % d == 0) {
        divisors.push_back(d);
        if (d != n / d)
          divisors.push_back(n / d);
      }
    }
    sort(divisors.begin(), divisors.end());

    int ans = 0;
    vector<int> done(n + 1, 0), isDivisor(n + 1, 0);
    for (int d : divisors)
      isDivisor[d] = 1;

    // Step 2: check each divisor
    for (int divisor : divisors) {
      if (done[divisor])
        continue;

      vector<int> diffGcds;
      for (int i = 0; i + divisor < n; i += divisor) {
        int val = 0;
        for (int j = i; j < i + divisor; j++) {
          val = gcd(val, abs(arr[j] - arr[j + divisor]));
        }
        diffGcds.push_back(val);
      }

      int finalGcd = 0;
      for (int x : diffGcds)
        finalGcd = gcd(finalGcd, x);

      if (finalGcd != 1) {
        for (int i = divisor; i <= n; i += divisor) {
          if (isDivisor[i] && !done[i]) {
            done[i] = 1;
            ans++;
          }
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1920/337211557
