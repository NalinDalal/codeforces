/*A. Array with Odd Sum
time limit per test1 second
memory limit per test256 megabytes
You are given an array 𝑎
 consisting of 𝑛
 integers.

In one move, you can choose two indices 1≤𝑖,𝑗≤𝑛
 such that 𝑖≠𝑗
 and set 𝑎𝑖:=𝑎𝑗
. You can perform such moves any number of times (possibly, zero). You can
choose different indices in different operations. The operation := is the
operation of assignment (i.e. you choose 𝑖 and 𝑗 and replace 𝑎𝑖 with 𝑎𝑗
).

Your task is to say if it is possible to obtain an array with an odd (not
divisible by 2 ) sum of elements.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤2000
) — the number of test cases.

The next 2𝑡
 lines describe test cases. The first line of the test case contains one integer
𝑛 (1≤𝑛≤2000 ) — the number of elements in 𝑎 . The second line of the test case
contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤2000
), where 𝑎𝑖
 is the 𝑖
-th element of 𝑎
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2000
 (∑𝑛≤2000
).

Output
For each test case, print the answer on it — "YES" (without quotes) if it is
possible to obtain the array with an odd sum of elements, and "NO" otherwise.

Example
InputCopy
5
2
2 3
4
2 2 8 8
3
3 3 3
4
5 5 5 5
4
1 1 1 1
OutputCopy
YES
NO
YES
NO
NO

*/
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count = 0;

    for (int p = 0; p < n; p++) {
      int x;
      cin >> x;
      count += (x % 2);
    }
    if ((count & 1) || (1 <= count && count < n))
      cout << "YES";
    else
      cout << "NO";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1296/309462046
