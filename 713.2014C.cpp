/*C. Robin Hood in Town
time limit per test2 seconds
memory limit per test256 megabytes
In Sherwood, we judge a man not by his wealth, but by his merit.
Look around, the rich are getting richer, and the poor are getting poorer. We
need to take from the rich and give to the poor. We need Robin Hood!

There are 𝑛
 people living in the town. Just now, the wealth of the 𝑖
-th person was 𝑎𝑖
 gold. But guess what? The richest person has found an extra pot of gold!

More formally, find an 𝑎𝑗=𝑚𝑎𝑥(𝑎1,𝑎2,…,𝑎𝑛)
, change 𝑎𝑗
 to 𝑎𝑗+𝑥
, where 𝑥
 is a non-negative integer number of gold found in the pot. If there are
multiple maxima, it can be any one of them.

A person is unhappy if their wealth is strictly less than half of the average
wealth∗
.

If strictly more than half of the total population 𝑛
 are unhappy, Robin Hood will appear by popular demand.

Determine the minimum value of 𝑥
 for Robin Hood to appear, or output −1
 if it is impossible.

∗
The average wealth is defined as the total wealth divided by the total
population 𝑛 , that is, ∑𝑎𝑖𝑛 , the result is a real number.

Input
The first line of input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the total population.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
) — the wealth of each person.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of gold that the
richest person must find for Robin Hood to appear. If it is impossible, output
−1 instead.

Example
InputCopy
6
1
2
2
2 19
3
1 3 20
4
1 2 3 4
5
1 2 3 4 5
6
1 2 1 1 1 25
OutputCopy
-1
-1
0
15
16
0
Note
In the first test case, it is impossible for a single person to be unhappy.

In the second test case, there is always 1
 happy person (the richest).

In the third test case, no additional gold are required, so the answer is 0
.

In the fourth test case, after adding 15
 gold, the average wealth becomes 254
, and half of this average is 258
, resulting in 3
 people being unhappy.

In the fifth test case, after adding 16
 gold, the average wealth becomes 315
, resulting in 3
 people being unhappy.



*/

/*t
 (t--){
 n
 vector<int> a(n);
 cin>>a;

 wealth of ith person is a[i]
 find a[j]=max(a[0],a[1]...a[n])
 change a[j] to a[j]+x
 a[j]+=x

 unhappy condition-> a[i]<=avg_wealth/2
 avg_wealth=sum(a[0]...a[n])/n

 if count_unhappy>=n/2 robin hood appear

 find minx for which he appears else -1
 }
*/

/*find sum=a[0]..a[n]
 sort a

 binary search on x
 find T = (sum + x) / (2n)

find how many a[i]<=T
If count >= n/2, possible → move left. Else → move right.

If never possible, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

bool can(long long x, const vector<int> &a, long long sum, int n) {
  long double T = (long double)(sum + x) / (2.0 * n);
  int cnt = upper_bound(a.begin(), a.end(), T) - a.begin();
  return cnt >= n / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (n <= 2) {
      cout << -1 << endl;
      continue;
    }
    sort(a.begin(), a.end());
    lon long res = 2 * n * a[n / 2] - s + 1;
    res = (res > 0 ? res : 0);
    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2014/340106603
