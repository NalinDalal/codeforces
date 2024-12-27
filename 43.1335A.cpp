/*
https://codeforces.com/problemset/problem/1335/A

A. Candies and Two Sisters
time limit per test1 second
memory limit per test256 megabytes
There are two sisters Alice and Betty. You have 𝑛 candies. You want to
distribute these 𝑛 candies between two sisters in such a way that: Alice will
get 𝑎 (𝑎>0) candies; Betty will get 𝑏 (𝑏>0) candies; each sister will get some
integer number of candies; Alice will get a greater amount of candies than Betty
(i.e. 𝑎>𝑏); all the candies will be given to one of two sisters (i.e. 𝑎+𝑏=𝑛).

Your task is to calculate the number of ways to distribute exactly 𝑛 candies
between sisters in a way described above. Candies are indistinguishable.

Formally, find the number of ways to represent 𝑛 as the sum of 𝑛=𝑎+𝑏, where 𝑎
and 𝑏 are positive integers and 𝑎>𝑏.

You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡 (1≤𝑡≤104) — the number of
test cases. Then 𝑡 test cases follow.

The only line of a test case contains one integer 𝑛 (1≤𝑛≤2⋅109) — the number of
candies you have.

Output
For each test case, print the answer — the number of ways to distribute exactly
𝑛 candies between two sisters in a way described in the problem statement. If
there is no way to satisfy all the conditions, print 0.

Example
InputCopy
6
7
1
2
3
2000000000
763243547
OutputCopy
3
0
0
1
999999999
381621773
Note
For the test case of the example, the 3 possible ways to distribute candies are:
𝑎=6, 𝑏=1; 𝑎=5, 𝑏=2; 𝑎=4, 𝑏=3.
*/

// a+b=n;a>b;a,b>0

// if n<=1 output=0
// else floor[n-1/2]
/*
 a>n/2
Valid Ways=n−(⌊
2
n
​
⌋+1)+1=⌊
2
n−1
​
⌋
valid ways=floor((n-1)/2)
*/

#include <iostream>
using namespace std;

int main() {
  int t; // Number of test cases
  cin >> t;
  while (t--) {
    long long n; // Number of candies
    cin >> n;
    if (n <= 1) {
      cout << 0 << endl; // No valid distributions
    } else {
      cout << (n - 1) / 2 << endl; // Calculate valid distributions
    }
  }
  return 0;
}
