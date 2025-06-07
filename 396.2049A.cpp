/* A. MEX Destruction
time limit per test1 second
memory limit per test256 megabytes

Evirir the dragon snuck into a wizard's castle and found a mysterious
contraption, and their playful instincts caused them to play with (destroy)
it...

Evirir the dragon found an array 𝑎1,𝑎2,…,𝑎𝑛
 of 𝑛
 non-negative integers.

In one operation, they can choose a non-empty subarray∗
 𝑏
 of 𝑎
 and replace it with the integer mex(𝑏)
†
. They want to use this operation any number of times to make 𝑎
 only contain zeros. It can be proven that this is always possible under the
problem constraints.

What is the minimum number of operations needed?

∗
An array 𝑐
 is a subarray of an array 𝑑
 if 𝑐
 can be obtained from 𝑑
 by the deletion of several (possibly, zero or all) elements from the beginning
and several (possibly, zero or all) elements from the end.

†
The minimum excluded (MEX) of a collection of integers 𝑓1,𝑓2,…,𝑓𝑘
 is defined as the smallest non-negative integer 𝑥
 which does not occur in the collection 𝑓
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤200
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
), the length of 𝑎
.

The second line of each test case contains 𝑛
 space-separated integers, 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤100
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 500
.

Output
For each test case, output a single integer on a line, the minimum number of
operations needed to make 𝑎 contain only zeros.

Example
InputCopy
10
4
0 1 2 3
6
0 0 0 0 0 0
5
1 0 1 0 1
5
3 1 4 1 5
4
3 2 1 0
7
9 100 0 89 12 2 3
4
0 3 9 0
7
0 7 0 2 0 7 0
1
0
2
0 1
OutputCopy
1
0
2
1
1
2
1
2
0
1
Note
In the first test case, Evirir can choose the subarray 𝑏=[1,2,3]
 and replace it with mex(1,2,3)=0
, changing 𝑎
 from [0,1,2,3⎯⎯⎯⎯⎯⎯⎯⎯⎯]
 to [0,0]
 (where the chosen subarray is underlined). Therefore, the answer is 1
.

In the second test case, 𝑎
 already contains only 0
s, so no operation is needed.

In the third test case, Evirir can change 𝑎
 as follows: [1,0,1,0,1⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯]→[1,2⎯⎯⎯⎯⎯⎯]→[0]
. Here, mex(0,1,0,1)=2
 and mex(1,2)=0
.

In the fourth test case, Evirir can choose 𝑏
 to be the entire array 𝑎
, changing 𝑎
 from [3,1,4,1,5⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯]
 to [0]
.


*/

#include <iostream>
using std::cin, std::cout, std::endl;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 0;
    bool prev = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x) {
        // If current is 1 and previous was 0, increment s
        s += !prev;
        prev = 1;
      } else {
        // If current is 0 and previous was 1, increment s
        s += prev;
        prev = 0;
      }
    }
    if (s == 0)
      cout << "0" << endl;
    else if (s <= 2)
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2049/323276369
