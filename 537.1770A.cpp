/*A. Koxia and Whiteboards
time limit per test1 second
memory limit per test256 megabytes
Kiyora has 𝑛
 whiteboards numbered from 1
 to 𝑛
. Initially, the 𝑖
-th whiteboard has the integer 𝑎𝑖
 written on it.

Koxia performs 𝑚
 operations. The 𝑗
-th operation is to choose one of the whiteboards and change the integer written
on it to 𝑏𝑗
.

Find the maximum possible sum of integers written on the whiteboards after
performing all 𝑚 operations.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of test cases
follows.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤100
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
).

The third line of each test case contains 𝑚
 integers 𝑏1,𝑏2,…,𝑏𝑚
 (1≤𝑏𝑖≤109
).

Output
For each test case, output a single integer — the maximum possible sum of
integers written on whiteboards after performing all 𝑚 operations.

Example
InputCopy
4
3 2
1 2 3
4 5
2 3
1 2
3 4 5
1 1
100
1
5 3
1 1 1 1 1
1000000000 1000000000 1000000000
OutputCopy
12
9
1
3000000002
Note
In the first test case, Koxia can perform the operations as follows:

Choose the 1
-st whiteboard and rewrite the integer written on it to 𝑏1=4
.
Choose the 2
-nd whiteboard and rewrite to 𝑏2=5
.
After performing all operations, the numbers on the three whiteboards are 4
, 5
 and 3
 respectively, and their sum is 12
. It can be proven that this is the maximum possible sum achievable.

In the second test case, Koxia can perform the operations as follows:

Choose the 2
-nd whiteboard and rewrite to 𝑏1=3
.
Choose the 1
-st whiteboard and rewrite to 𝑏2=4
.
Choose the 2
-nd whiteboard and rewrite to 𝑏3=5
.
The sum is 4+5=9
. It can be proven that this is the maximum possible sum achievable.



*/
#include <iostream>
#include <set>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n, m;
    cin >> n >> m;
    multiset<long> s;
    long long total = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      s.insert(x);
      total += x;
    }

    while (m--) {
      long b;
      cin >> b;
      auto it = s.begin();
      total += (b - (*it));
      s.erase(it);
      s.insert(b);
    }

    cout << total << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1770/330932754
