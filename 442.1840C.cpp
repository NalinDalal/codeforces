/*C. Ski Resort
time limit per test1 second
memory limit per test256 megabytes
Dima Vatrushin is a math teacher at school. He was sent on vacation for 𝑛
 days for his good work. Dima has long dreamed of going to a ski resort, so he
wants to allocate several consecutive days and go skiing. Since the vacation
requires careful preparation, he will only go for at least 𝑘 days.

You are given an array 𝑎
 containing the weather forecast at the resort. That is, on the 𝑖
-th day, the temperature will be 𝑎𝑖
 degrees.

Dima was born in Siberia, so he can go on vacation only if the temperature does
not rise above 𝑞 degrees throughout the vacation.

Unfortunately, Dima was so absorbed in abstract algebra that he forgot how to
count. He asks you to help him and count the number of ways to choose vacation
dates at the resort.

Input
The first line of the input contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains three integers 𝑛
, 𝑘
, 𝑞
 (1≤𝑛≤2⋅105
, 1≤𝑘≤𝑛
, −109≤𝑞≤109
) — the length of the array 𝑎
, the minimum number of days at the resort, and the maximum comfortable
temperature for Dima.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,𝑎3,…,𝑎𝑛
 (−109≤𝑎𝑖≤109
) — the temperature at the ski resort.

The sum of all 𝑛
 values over all test cases does not exceed 2⋅105
.

Output
Output 𝑡
 integers, each of which is the answer to the corresponding test case — the
number of ways for Dima to choose vacation dates at the resort.

Example
InputCopy
7
3 1 15
-5 0 -10
5 3 -33
8 12 9 0 5
4 3 12
12 12 10 15
4 1 -5
0 -1 2 5
5 5 0
3 -1 4 -5 -3
1 1 5
5
6 1 3
0 3 -2 5 -4 -4
OutputCopy
6
0
1
0
0
1
9
Note
In the first test case of the example, Dima can go on any day, so the suitable
dates for him are [1], [2], [3], [1, 2], [2, 3], [1, 2, 3].

In the second and fourth test cases of the example, Dima cannot go on any day
due to the high temperature, so there are no suitable dates.

In the third test case of the example, Dima can only go on the dates [1, 2, 3].



*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {

    long n, k, q;
    cin >> n >> k >> q;
    long long cnt = 0, res = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      if (x <= q) {
        ++cnt;
      } else {
        cnt = 0;
      }
      res += (cnt >= k) ? (cnt - k + 1) : 0;
    }

    cout << res << endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1840/325831615
