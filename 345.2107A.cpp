/* A. LRC and VIP
time limit per test1 second
memory limit per test256 megabytes

You have an array 𝑎
 of size 𝑛
 — 𝑎1,𝑎2,…𝑎𝑛
.

You need to divide the 𝑛
 elements into 2
 sequences 𝐵
 and 𝐶
, satisfying the following conditions:

Each element belongs to exactly one sequence.
Both sequences 𝐵
 and 𝐶
 contain at least one element.
gcd
 (𝐵1,𝐵2,…,𝐵|𝐵|)≠gcd(𝐶1,𝐶2,…,𝐶|𝐶|)
 ∗
∗
gcd(𝑥,𝑦)
 denotes the greatest common divisor (GCD) of integers 𝑥
 and 𝑦
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤100
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤104
).

Output
For each test case, first output 𝚈𝚎𝚜
 if a solution exists or 𝙽𝚘
 if no solution exists. You may print each character in either case, for example
𝚈𝙴𝚂 and 𝚢𝙴𝚜 will also be accepted.

Only when there is a solution, output 𝑛
 integers on the second line. The 𝑖
-th number should be either 1
 or 2
. 1
 represents that the element belongs to sequence 𝐵
 and 2
 represents that the element belongs to sequence 𝐶
.

You should guarantee that 1
 and 2
 both appear at least once.

Example
InputCopy
3
4
1 20 51 9
4
5 5 5 5
3
1 2 2
OutputCopy
Yes
2 2 1 1
No
Yes
1 2 2
Note
In the first test case, 𝐵=[51,9]
 and 𝐶=[1,20]
. You can verify gcd(𝐵1,𝐵2)=3≠1=gcd(𝐶1,𝐶2)
.

In the second test case, it is impossible to find a solution. For example,
suppose you distributed the first 3 elements to array 𝐵 and then the last
element to array 𝐶 . You have 𝐵=[5,5,5] and 𝐶=[5] , but gcd(𝐵1,𝐵2,𝐵3)=5=gcd(𝐶1)
. Hence it is invalid.


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
    vector<int> a(n);
    int mna = 1e5, mxa = -1;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mna = (mna < a[i] ? mna : a[i]);
      mxa = (mxa > a[i] ? mxa : a[i]);
    }
    // divide a in 2 sequences
    // B,C contains atleast 1 element
    // each element belongs to exactly to one sequences
    // gcd(B)!=gcd(C)

    if (mna == mxa) {
      cout << "No" << endl;
      continue;
    }

    cout << "Yes" << endl;
    for (int p = 0; p < n; p++) {
      cout << (a[p] == mxa ? 1 : 2) << " ";
    }
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2107/319596658
