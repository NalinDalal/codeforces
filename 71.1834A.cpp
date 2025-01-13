/* https://codeforces.com/problemset/problem/1834/A
A. Unit Array
time limit per test1 second
memory limit per test256 megabytes
Given an array 𝑎
 of length 𝑛
, which elements are equal to −1
 and 1
. Let's call the array 𝑎
 good if the following conditions are held at the same time:

𝑎1+𝑎2+…+𝑎𝑛≥0
;

𝑎1⋅𝑎2⋅…⋅𝑎𝑛=1
.
In one operation, you can select an arbitrary element of the array 𝑎𝑖
 and change its value to the opposite. In other words, if 𝑎𝑖=−1
, you can assign the value to 𝑎𝑖:=1
, and if 𝑎𝑖=1
, then assign the value to 𝑎𝑖:=−1
.

Determine the minimum number of operations you need to perform to make the array
𝑎 good. It can be shown that this is always possible.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤500 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (𝑎𝑖=±1
) — the elements of the array 𝑎
.

Output
For each test case, output a single integer — the minimum number of operations
that need to be done to make the 𝑎 array good.

Example
InputCopy
7
4
-1 -1 1 -1
5
-1 -1 -1 1 1
4
-1 1 -1 1
3
-1 -1 -1
5
1 1 1 1 1
1
-1
2
-1 -1
OutputCopy
1
1
0
3
0
1
2
Note
In the first test case, we can assign the value 𝑎1:=1
. Then 𝑎1+𝑎2+𝑎3+𝑎4=1+(−1)+1+(−1)=0≥0
 and 𝑎1⋅𝑎2⋅𝑎3⋅𝑎4=1⋅(−1)⋅1⋅(−1)=1
. Thus, we performed 1
 operation.

In the second test case, we can assign 𝑎1:=1
. Then 𝑎1+𝑎2+𝑎3+𝑎4+𝑎5=1+(−1)+(−1)+1+1=1≥0
 and 𝑎1⋅𝑎2⋅𝑎3⋅𝑎4⋅𝑎5=1⋅(−1)⋅(−1)⋅1⋅1=1
. Thus, we performed 1
 operation.

In the third test case, 𝑎1+𝑎2+𝑎3+𝑎4=(−1)+1+(−1)+1=0≥0
 and 𝑎1⋅𝑎2⋅𝑎3⋅𝑎4=(−1)⋅1⋅(−1)⋅1=1
. Thus, all conditions are already satisfied and no operations are needed.

In the fourth test case, we can assign the values 𝑎1:=1,𝑎2:=1,𝑎3:=1
. Then 𝑎1+𝑎2+𝑎3=1+1+1=3≥0
 and 𝑎1⋅𝑎2⋅𝑎3=1⋅1⋅1=1
. Thus, we performed 3
 operations.


*/
// good array-> sum>=0;product=1
// either change 1 to -1 or -1 to 1
// say we change 1 to -1 to satisfy condition increase opr by 1
// so what if get sum of even and odd, then see their absolute diff,
// return diff+1
#include <iostream>
using namespace std;

int main() {
  long t;
  cin >> t; // Reading number of test cases
  while (t--) {
    long n;
    cin >> n; // Reading the size of the array
    long pos = 0, neg = 0;

    // Read the elements and count positive and negative numbers
    for (long p = 0; p < n; p++) {
      int x;
      cin >> x;
      if (x > 0)
        pos++; // Increment pos for positive numbers
      if (x < 0)
        neg++; // Increment neg for negative numbers
    }

    long move = 0;

    // If there are more negative numbers, we need to balance the positive and
    // negative numbers
    if (pos < neg) {
      move =
          (neg - pos + 1) / 2; // Calculate how many changes we need to balance
      pos += move;
      neg -= move;
    }

    // If the number of negative numbers is odd, we need one more move
    if (neg % 2) {
      ++move;
    }

    // Output the result
    cout << move << endl;
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1834/300854475
