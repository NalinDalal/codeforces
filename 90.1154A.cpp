/* https://codeforces.com/problemset/problem/1154/A
A. Restoring Three Numbers
time limit per test1 second
memory limit per test256 megabytes
Polycarp has guessed three positive integers 𝑎, 𝑏 and 𝑐.
He keeps these numbers in secret, but he writes down four numbers on a board in
arbitrary order — their pairwise sums (three numbers) and sum of all three
numbers (one number). So, there are four numbers on a board in random order:
𝑎+𝑏, 𝑎+𝑐, 𝑏+𝑐 and 𝑎+𝑏+𝑐.

You have to guess three numbers 𝑎, 𝑏 and 𝑐 using given numbers. Print three
guessed integers in any order.

Pay attention that some given numbers 𝑎, 𝑏 and 𝑐 can be equal (it is also
possible that 𝑎=𝑏=𝑐).

Input
The only line of the input contains four positive integers 𝑥1,𝑥2,𝑥3,𝑥4
(2≤𝑥𝑖≤109) — numbers written on a board in random order. It is guaranteed that
the answer exists for the given number 𝑥1,𝑥2,𝑥3,𝑥4.

Output
Print such positive integers 𝑎, 𝑏 and 𝑐 that four numbers written on a board are
values 𝑎+𝑏, 𝑎+𝑐, 𝑏+𝑐 and 𝑎+𝑏+𝑐 written in some order. Print 𝑎, 𝑏 and 𝑐 in any
order. If there are several answers, you can print any. It is guaranteed that
the answer exists.

Examples
InputCopy
3 6 5 4
OutputCopy
2 1 3
InputCopy
40 40 40 60
OutputCopy
20 20 20
InputCopy
201 101 101 200
OutputCopy
1 100 100

*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x1, x2, x3, x4;
  cin >> x1 >> x2 >> x3 >> x4;
  // Sort the numbers to ensure that x4 is the largest number (a + b + c)
  int arr[4] = {x1, x2, x3, x4};
  sort(arr, arr + 4);
  // a,b,c such that can be in any order
  // x1=a+b
  // x2=a+c
  // x3=b+c
  // x4=a+b+c
  // a=x4-x3
  // b=x4-x2
  // c=x4-x1
  // Now, arr[3] is the sum of all three numbers (a + b + c)
  // Using the fact that:
  // a = (a + b + c) - (b + c)
  // b = (a + b + c) - (a + c)
  // c = (a + b + c) - (a + b)

  int a = arr[3] - arr[2];
  int b = arr[3] - arr[1];
  int c = arr[3] - arr[0];

  // Output the values of a, b, c in any order
  cout << a << " " << b << " " << c << endl;
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1154/302246357
