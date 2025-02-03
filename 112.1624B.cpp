/* https://codeforces.com/problemset/problem/1624/B
B. Make AP
time limit per test2 seconds
memory limit per test256 megabytes
Polycarp has 3
 positive integers 𝑎
, 𝑏
 and 𝑐
. He can perform the following operation exactly once.

Choose a positive integer 𝑚
 and multiply exactly one of the integers 𝑎
, 𝑏
 or 𝑐
 by 𝑚
.
Can Polycarp make it so that after performing the operation, the sequence of
three numbers 𝑎 , 𝑏 , 𝑐 (in this order) forms an arithmetic progression? Note
that you cannot change the order of 𝑎 , 𝑏 and 𝑐
.

Formally, a sequence 𝑥1,𝑥2,…,𝑥𝑛
 is called an arithmetic progression (AP) if there exists a number 𝑑
 (called "common difference") such that 𝑥𝑖+1=𝑥𝑖+𝑑
 for all 𝑖
 from 1
 to 𝑛−1
. In this problem, 𝑛=3
.

For example, the following sequences are AP: [5,10,15]
, [3,2,1]
, [1,1,1]
, and [13,10,7]
. The following sequences are not AP: [1,2,4]
, [0,1,0]
 and [1,3,2]
.

You need to answer 𝑡
 independent test cases.

Input
The first line contains the number 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each of the following 𝑡
 lines contains 3
 integers 𝑎
, 𝑏
, 𝑐
 (1≤𝑎,𝑏,𝑐≤108
).

Output
For each test case print "YES" (without quotes) if Polycarp can choose a
positive integer 𝑚 and multiply exactly one of the integers 𝑎 , 𝑏 or 𝑐 by 𝑚 to
make [𝑎,𝑏,𝑐] be an arithmetic progression. Print "NO" (without quotes)
otherwise.

You can print YES and NO in any (upper or lower) case (for example, the strings
yEs, yes, Yes and YES will be recognized as a positive answer).

Example
InputCopy
11
10 5 30
30 5 10
1 2 3
1 6 3
2 6 3
1 1 1
1 1 2
1 1 3
1 100000000 1
2 1 1
1 2 2
OutputCopy
YES
YES
YES
YES
NO
YES
NO
YES
YES
NO
YES
Note
In the first and second test cases, you can choose the number 𝑚=4
 and multiply the second number (𝑏=5
) by 4
.

In the first test case the resulting sequence will be [10,20,30]
. This is an AP with a difference 𝑑=10
.

In the second test case the resulting sequence will be [30,20,10]
. This is an AP with a difference 𝑑=−10
.

In the third test case, you can choose 𝑚=1
 and multiply any number by 1
. The resulting sequence will be [1,2,3]
. This is an AP with a difference 𝑑=1
.

In the fourth test case, you can choose 𝑚=9
 and multiply the first number (𝑎=1
) by 9
. The resulting sequence will be [9,6,3]
. This is an AP with a difference 𝑑=−3
.

In the fifth test case, it is impossible to make an AP.



*/

#include <iostream>

using namespace std;

bool isPossible(int a, int b, int c) {
  // Case 1: Multiply a by m -> (m*a, b, c)
  int required_a = 2 * b - c; // To make (a', b, c) an AP: 2*b = a' + c
  if (required_a % a == 0 && required_a / a > 0)
    return true;

  // Case 2: Multiply b by m -> (a, m*b, c)
  int required_b = (a + c) / 2; // To make (a, b', c) an AP: 2*b' = a + c
  if ((a + c) % 2 == 0 && required_b % b == 0 && required_b / b > 0)
    return true;

  // Case 3: Multiply c by m -> (a, b, m*c)
  int required_c = 2 * b - a; // To make (a, b, c') an AP: 2*b = a + c'
  if (required_c % c == 0 && required_c / c > 0)
    return true;

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    // d=xi+1-xi
    // x1,x2,....xn are in AP
    // print yes if m can be chosen such that upon with multiplication of a,b
    // or c with m generates AP
    if (isPossible(a, b, c)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1624/304295910
