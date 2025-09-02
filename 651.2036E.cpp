/*E. Reverse the Rivers
time limit per test2 seconds
memory limit per test256 megabytes
A conspiracy of ancient sages, who decided to redirect rivers for their own
convenience, has put the world on the brink. But before implementing their grand
plan, they decided to carefully think through their strategy — that's what sages
do.

There are 𝑛
 countries, each with exactly 𝑘
 regions. For the 𝑗
-th region of the 𝑖
-th country, they calculated the value 𝑎𝑖,𝑗
, which reflects the amount of water in it.

The sages intend to create channels between the 𝑗
-th region of the 𝑖
-th country and the 𝑗
-th region of the (𝑖+1)
-th country for all 1≤𝑖≤(𝑛−1)
 and for all 1≤𝑗≤𝑘
.

Since all 𝑛
 countries are on a large slope, water flows towards the country with the
highest number. According to the sages' predictions, after the channel system is
created, the new value of the 𝑗 -th region of the 𝑖 -th country will be
𝑏𝑖,𝑗=𝑎1,𝑗|𝑎2,𝑗|...|𝑎𝑖,𝑗 , where | denotes the bitwise "OR" operation.

After the redistribution of water, the sages aim to choose the most suitable
country for living, so they will send you 𝑞 queries for consideration.

Each query will contain 𝑚
 requirements.

Each requirement contains three parameters: the region number 𝑟
, the sign 𝑜
 (either "<
" or ">
"), and the value 𝑐
. If 𝑜
 = "<
", then in the 𝑟
-th region of the country you choose, the new value must be strictly less than
the limit 𝑐 , and if 𝑜 = ">
", it must be strictly greater.

In other words, the chosen country 𝑖
 must satisfy all 𝑚
 requirements. If in the current requirement 𝑜
 = "<
", then it must hold that 𝑏𝑖,𝑟<𝑐
, and if 𝑜
 = ">
", then 𝑏𝑖,𝑟>𝑐
.

In response to each query, you should output a single integer — the number of
the suitable country. If there are multiple such countries, output the smallest
one. If no such country exists, output −1
.

Input
The first line contains three integers 𝑛
, 𝑘
, and 𝑞
 (1≤𝑛,𝑘,𝑞≤105
) — the number of countries, regions, and queries, respectively.

Next, there are 𝑛
 lines, where the 𝑖
-th line contains 𝑘
 integers 𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑘
 (1≤𝑎𝑖,𝑗≤109
), where 𝑎𝑖,𝑗
 is the value of the 𝑗
-th region of the 𝑖
-th country.

Then, 𝑞
 queries are described.

The first line of each query contains a single integer 𝑚
 (1≤𝑚≤105
) — the number of requirements.

Then follow 𝑚
 lines, each containing an integer 𝑟
, a character 𝑜
, and an integer 𝑐
 (1≤𝑟≤𝑘
, 0≤𝑐≤2⋅109
), where 𝑟
 and 𝑐
 are the region number and the value, and 𝑜
 is either "<
" or ">
" — the sign.

It is guaranteed that 𝑛⋅𝑘
 does not exceed 105
 and that the sum of 𝑚
 across all queries also does not exceed 105
.

Output
For each query, output a single integer on a new line — the smallest number of
the suitable country, or −1 if no such country exists.

Example
InputCopy
3 4 4
1 3 5 9
4 6 5 3
2 1 2 7
3
1 > 4
2 < 8
1 < 6
2
1 < 8
2 > 8
1
3 > 5
2
4 > 8
1 < 8
OutputCopy
2
-1
3
1
Note
In the example, the initial values of the regions are as follows:

1
3
5
9
4
6
5
3
2
1
2
7
After creating the channels, the new values will look like this:

1
3
5
9
1|4
3|6
5|5
9|3
1|4|2
3|6|1
5|5|2
9|3|7
↓
1
3
5
9
5
7
5
11
7
7
7
15
In the first query, it is necessary to output the minimum country number (i.e.,
row) where, after the redistribution of water in the first region (i.e.,
column), the new value will be greater than four and less than six, and in the
second region it will be less than eight. Only the country with number 2 meets
these requirements.

In the second query, there are no countries that meet the specified
requirements.

In the third query, only the country with number 3
 is suitable.

In the fourth query, all three countries meet the conditions, so the answer is
the smallest number 1
.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;

  vector<vector<int>> b(n, vector<int>(k));
  // read first row
  for (int j = 0; j < k; j++)
    cin >> b[0][j];

  // prefix OR along rows
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      b[i][j] = b[i - 1][j] | x;
    }
  }

  // transpose for binary search access: col -> vector of values
  vector<vector<int>> col(k);
  for (int j = 0; j < k; j++) {
    col[j].resize(n);
    for (int i = 0; i < n; i++)
      col[j][i] = b[i][j];
  }

  while (q--) {
    int m;
    cin >> m;
    int L = 1, R = n; // valid i must be in [L, R]

    for (int t = 0; t < m; t++) {
      int r, c;
      char op;
      cin >> r >> op >> c;
      --r; // 0-indexed region

      auto &arr = col[r];

      if (op == '<') {
        // find largest index i where arr[i] < c
        int pos = int(lower_bound(arr.begin(), arr.end(), c) - arr.begin()) - 1;
        if (pos < 0)
          R = 0; // no valid index
        else
          R = min(R, pos + 1); // +1 because countries are 1-indexed
      } else {
        // find smallest index i where arr[i] > c
        int pos = int(upper_bound(arr.begin(), arr.end(), c) - arr.begin());
        if (pos >= n)
          L = n + 1; // no valid index
        else
          L = max(L, pos + 1); // +1 for 1-indexed
      }
    }

    if (L <= R)
      cout << L << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2036/336639455
