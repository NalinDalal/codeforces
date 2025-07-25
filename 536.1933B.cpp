/*B. Turtle Math: Fast Three Task
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
.

In one move, you can perform either of the following two operations:

Choose an element from the array and remove it from the array. As a result, the
length of the array decreases by 1
;
Choose an element from the array and increase its value by 1
.
You can perform any number of moves. If the current array becomes empty, then no
more moves can be made.

Your task is to find the minimum number of moves required to make the sum of the
elements of the array 𝑎 divisible by 3 . It is possible that you may need 0
 moves.

Note that the sum of the elements of an empty array (an array of length 0
) is equal to 0
.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤105
).

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤104
).

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer: the minimum number of moves.

Example
InputCopy
8
4
2 2 5 4
3
1 3 2
4
3 7 6 8
1
1
4
2 2 4 2
2
5 5
7
2 4 8 1 9 3 4
2
4 10
OutputCopy
1
0
0
1
1
2
1
1
Note
In the first test case, initially the array 𝑎=[2,2,5,4]
. One of the optimal ways to make moves is:

remove the current 4
th element and get 𝑎=[2,2,5]
;
As a result, the sum of the elements of the array 𝑎
 will be divisible by 3
 (indeed, 𝑎1+𝑎2+𝑎3=2+2+5=9
).
In the second test case, initially, the sum of the array is 1+3+2=6
, which is divisible by 3
. Therefore, no moves are required. Hence, the answer is 0
.

In the fourth test case, initially, the sum of the array is 1
, which is not divisible by 3
. By removing its only element, you will get an empty array, so its sum is 0
. Hence, the answer is 1
.
*/

#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    bool one = false;
    int s = 0;
    for (long p = 0; p < n; p++) {
      int x;
      cin >> x;
      if (x % 3 == 1)
        one = true;
      s += x;
      s %= 3;
    }

    if (!one && s % 3 == 1)
      cout << "2\n";
    else if (s % 3)
      cout << "1\n";
    else
      cout << "0\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1933/330932187
