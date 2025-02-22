/* A. Bachgold Problem
time limit per test1 second
memory limit per test256 megabytes
Bachgold problem is very easy to formulate. Given a positive integer n represent
it as a sum of maximum possible number of prime numbers. One can prove that such
representation exists for any integer greater than 1.

Recall that integer k is called prime if it is greater than 1 and has exactly
two positive integer divisors — 1 and k.

Input
The only line of the input contains a single integer n (2 ≤ n ≤ 100 000).

Output
The first line of the output contains a single integer k — maximum possible
number of primes in representation.

The second line should contain k primes with their sum equal to n. You can print
them in any order. If there are several optimal solution, print any of them.

Examples
InputCopy
5
OutputCopy
2
2 3
InputCopy
6
OutputCopy
3
2 2 2

*/

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  bool three = false;
  if (n % 2) {
    three = true;
    n -= 3;
  }
  int twos = n / 2;
  int count = twos + three;
  std::cout << count << std::endl;
  while (twos--) {
    std::cout << "2 ";
  }
  if (three) {
    std::cout << "3";
  }
  std::cout << std::endl;
}

// sub: https://codeforces.com/problemset/submission/749/307324112
