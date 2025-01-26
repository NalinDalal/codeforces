/* https://codeforces.com/problemset/problem/1807/D
D. Odd Queries
time limit per test2 seconds
memory limit per test256 megabytes
You have an array 𝑎1,𝑎2,…,𝑎𝑛
. Answer 𝑞
 queries of the following form:

If we change all elements in the range 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟
 of the array to 𝑘
, will the sum of the entire array be odd?
Note that queries are independent and do not affect future queries.
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case consists of 2
 integers 𝑛
 and 𝑞
 (1≤𝑛≤2⋅105
; 1≤𝑞≤2⋅105
) — the length of the array and the number of queries.

The second line of each test case consists of 𝑛
 integers 𝑎𝑖
 (1≤𝑎𝑖≤109
) — the array 𝑎
.

The next 𝑞
 lines of each test case consists of 3
 integers 𝑙,𝑟,𝑘
 (1≤𝑙≤𝑟≤𝑛
; 1≤𝑘≤109
) — the queries.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
, and the sum of 𝑞
 doesn't exceed 2⋅105
.

Output
For each query, output "YES" if the sum of the entire array becomes odd, and
"NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
2
5 5
2 2 1 3 2
2 3 3
2 3 4
1 5 5
1 4 9
2 4 3
10 5
1 1 1 1 1 1 1 1 1 1
3 8 13
2 5 10
3 8 10
1 10 2
1 9 100
OutputCopy
YES
YES
YES
NO
YES
NO
NO
NO
NO
YES
Note
For the first test case:

If the elements in the range (2,3)
 would get set to 3
 the array would become {2,3,3,3,2}
, the sum would be 2+3+3+3+2=13
 which is odd, so the answer is "YES".
If the elements in the range (2,3)
 would get set to 4
 the array would become {2,4,4,3,2}
, the sum would be 2+4+4+3+2=15
 which is odd, so the answer is "YES".
If the elements in the range (1,5)
 would get set to 5
 the array would become {5,5,5,5,5}
, the sum would be 5+5+5+5+5=25
 which is odd, so the answer is "YES".
If the elements in the range (1,4)
 would get set to 9
 the array would become {9,9,9,9,2}
, the sum would be 9+9+9+9+2=38
 which is even, so the answer is "NO".
If the elements in the range (2,4)
 would get set to 3
 the array would become {2,3,3,3,2}
, the sum would be 2+3+3+3+2=13
 which is odd, so the answer is "YES".



*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    long cs(0);
    for (long p = 1; p <= n; p++) {
      long x;
      cin >> x;
      cs += x;
      cs %= 2;
      a[p] = cs;
    }
    while (q--) {
      long l, r, k;
      cin >> l >> r >> k;
      long rep = ((r - l + 1) % 2) * (k % 2);
      // cout<< ((2 + cs + rep + a[r] - a[l - 1]) % 2) ? "YES" : "NO")<<endl;
      if ((2 + cs + rep + a[r] - a[l - 1]) % 2 == 1) {
        cout << "YES" << endl; // Odd case
      } else {
        cout << "NO" << endl; // Even case
      }
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1807/303137664
