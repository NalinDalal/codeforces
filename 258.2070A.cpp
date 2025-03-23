/*
A. FizzBuzz Remixed
time limit per test1 second
memory limit per test512 megabytes
FizzBuzz is one of the most well-known problems from coding interviews. In this
problem, we will consider a remixed version of FizzBuzz:

Given an integer 𝑛
, process all integers from 0
 to 𝑛
. For every integer such that its remainders modulo 3
 and modulo 5
 are the same (so, for every integer 𝑖
 such that 𝑖mod3=𝑖mod5
), print FizzBuzz.

However, you don't have to solve it. Instead, given the integer 𝑛
, you have to report how many times the correct solution to that problem will
print FizzBuzz.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case contains one line consisting of one integer 𝑛
 (0≤𝑛≤109
).

Output
For each test case, print one integer — the number of times the correct solution
will print FizzBuzz with the given value of 𝑛
.

Example
InputCopy
7
0
5
15
42
1337
17101997
998244353
OutputCopy
1
3
4
9
270
3420402
199648872
Note
In the first test case, the solution will print FizzBuzz for the integer 0
.

In the second test case, the solution will print FizzBuzz for the integers 0,1,2
.

In the third test case, the solution will print FizzBuzz for the integers
0,1,2,15
.



*/
#include <iostream>
int countValid(int n) {
  int baseCount = (n / 15) * 3; // Every block of 15 contributes 3 numbers
  int extraCount = 0;
  int start = (n / 15) * 15;

  // Check numbers in the last partial block
  for (int i = start; i <= n; i++) {
    if (i % 3 == i % 5) {
      extraCount++;
    }
  }

  return baseCount + extraCount;
}
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;

    /*
// process all integer from 0 to n
// i mod 3==i mod 5 increase count
for (int i = 0; i < n; i++) {
  if (i % 3 == i % 5)
    ans++;
}*/
    // problem-> tle

    // alt->
    // i=r mod 3, i=r mod 5 => i=15k+r where r mod 3=r mod 5
    std::cout << countValid(n) << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2070/312068110
