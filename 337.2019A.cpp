/* A. Max Plus Size
time limit per test1 second
memory limit per test256 megabytes
EnV - Dynasty
⠀
You are given an array 𝑎1,𝑎2,…,𝑎𝑛
 of positive integers.

You can color some elements of the array red, but there cannot be two adjacent
red elements (i.e., for 1≤𝑖≤𝑛−1 , at least one of 𝑎𝑖 and 𝑎𝑖+1 must not be red).

Your score is the maximum value of a red element plus the number of red
elements. Find the maximum score you can get.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤100
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤1000
) — the given array.

Output
For each test case, output a single integer: the maximum possible score you can
get after coloring some elements red according to the statement.

Example
InputCopy
4
3
5 4 5
3
4 5 4
10
3 3 3 3 4 1 2 3 4 5
9
17 89 92 42 29 92 14 70 45
OutputCopy
7
6
10
97
Note
In the first test case, you can color the array as follows: [5,4,5]
. Your score is max([5,5])+size([5,5])=5+2=7
. This is the maximum score you can get.

In the second test case, you can color the array as follows: [4,5,4]
. Your score is max([4,4])+size([4,4])=4+2=6
. This is the maximum score you can get.

In the third test case, you can color the array as follows:
[3,3,3,3,4,1,2,3,4,5] . Your score is max([3,3,4,3,5])+size([3,3,4,3,5])=5+5=10
. This is the maximum score you can get.


*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (i % 2)
        a = max(a, x);
      else
        b = max(b, x);
    }
    a += n / 2;
    b += (n + 1) / 2;
    cout << max(a, b) << endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/2019/318941326
