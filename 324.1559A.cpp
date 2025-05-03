/* A. Mocha and Math
time limit per test1 second
memory limit per test256 megabytes
Mocha is a young girl from high school. She has learned so much interesting
knowledge from her teachers, especially her math teacher. Recently, Mocha is
learning about binary system and very interested in bitwise operation.

This day, Mocha got a sequence 𝑎
 of length 𝑛
. In each operation, she can select an arbitrary interval [𝑙,𝑟]
 and for all values 𝑖
 (0≤𝑖≤𝑟−𝑙
), replace 𝑎𝑙+𝑖
 with 𝑎𝑙+𝑖&𝑎𝑟−𝑖
 at the same time, where &
 denotes the bitwise AND operation. This operation can be performed any number
of times.

For example, if 𝑛=5
, the array is [𝑎1,𝑎2,𝑎3,𝑎4,𝑎5]
, and Mocha selects the interval [2,5]
, then the new array is [𝑎1,𝑎2&𝑎5,𝑎3&𝑎4,𝑎4&𝑎3,𝑎5&𝑎2]
.

Now Mocha wants to minimize the maximum value in the sequence. As her best
friend, can you help her to get the answer?

Input
Each test contains multiple test cases.

The first line contains a single integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. Each test case consists of two lines.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the sequence.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤109
).

Output
For each test case, print one integer — the minimal value of the maximum value
in the sequence.

Example
InputCopy
4
2
1 2
3
1 1 3
4
3 11 3 7
5
11 7 15 3 7
OutputCopy
0
1
3
3
Note
In the first test case, Mocha can choose the interval [1,2]
, then the sequence becomes [0,0]
, where the first element is 1&2
, and the second element is 2&1
.

In the second test case, Mocha can choose the interval [1,3]
, then the sequence becomes [1,1,1]
, where the first element is 1&3
, the second element is 1&1
, and the third element is 3&1
.
*/
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
    int res;
    cin >> res;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      res &= x;
    }
    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1559/318175112
