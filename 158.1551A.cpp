/* A. Polycarp and Coins
time limit per test1 second
memory limit per test256 megabytes
Polycarp must pay exactly 𝑛 burles at the checkout. He has coins of two nominal
values: 1 burle and 2 burles. Polycarp likes both kinds of coins equally. So he
doesn't want to pay with more coins of one type than with the other.

Thus, Polycarp wants to minimize the difference between the count of coins of 1
burle and 2 burles being used. Help him by determining two non-negative integer
values 𝑐1 and 𝑐2 which are the number of coins of 1 burle and 2 burles,
respectively, so that the total value of that number of coins is exactly 𝑛
(i. e. 𝑐1+2⋅𝑐2=𝑛), and the absolute value of the difference between 𝑐1 and 𝑐2 is
as little as possible (i. e. you must minimize |𝑐1−𝑐2|).

Input
The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases. Then
𝑡 test cases follow.

Each test case consists of one line. This line contains one integer 𝑛 (1≤𝑛≤109)
— the number of burles to be paid by Polycarp.

Output
For each test case, output a separate line containing two integers 𝑐1 and 𝑐2
(𝑐1,𝑐2≥0) separated by a space where 𝑐1 is the number of coins of 1 burle and 𝑐2
is the number of coins of 2 burles. If there are multiple optimal solutions,
print any one.

Example
InputCopy
6
1000
30
1
32
1000000000
5
OutputCopy
334 333
10 10
1 0
10 11
333333334 333333333
1 2
Note
The answer for the first test case is "334 333". The sum of the nominal values
of all coins is 334⋅1+333⋅2=1000, whereas |334−333|=1. One can't get the better
value because if |𝑐1−𝑐2|=0, then 𝑐1=𝑐2 and 𝑐1⋅1+𝑐1⋅2=1000, but then the value of
𝑐1 isn't an integer.

The answer for the second test case is "10 10". The sum of the nominal values is
10⋅1+10⋅2=30 and |10−10|=0, whereas there's no number having an absolute value
less than 0*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // c1- for 1 burle
    // c2- for 2 burle
    // c1+2.c2=n
    // minimise abs(c1-c2)
    // return c1,c2

    int d = n / 3;
    // Adjust counts based on remainder
    int c1 = d + (n % 3 == 1);
    int c2 = d + (n % 3 == 2);

    cout << c1 << " " << c2 << endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1551/307036516
