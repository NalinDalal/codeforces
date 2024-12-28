/*
https://codeforces.com/problemset/problem/1352/A

A. Sum of Round Numbers
time limit per test1 second
memory limit per test256 megabytes
A positive (strictly greater than zero) integer is called round if it is of the
form d00...0. In other words, a positive integer is round if all its digits
except the leftmost (most significant) are equal to zero. In particular, all
numbers from 1 to 9 (inclusive) are round.

For example, the following numbers are round: 4000, 1, 9, 800, 90. The following
numbers are not round: 110, 707, 222, 1001.

You are given a positive integer 𝑛 (1≤𝑛≤104). Represent the number 𝑛 as a sum of
round numbers using the minimum number of summands (addends). In other words,
you need to represent the given number 𝑛 as a sum of the least number of terms,
each of which is a round number.

Input
The first line contains an integer 𝑡 (1≤𝑡≤104) — the number of test cases in the
input. Then 𝑡 test cases follow.

Each test case is a line containing an integer 𝑛 (1≤𝑛≤104).

Output
Print 𝑡 answers to the test cases. Each answer must begin with an integer 𝑘 —
the minimum number of summands. Next, 𝑘 terms must follow, each of which is a
round number, and their sum is 𝑛. The terms can be printed in any order. If
there are several answers, print any of them.

Example
InputCopy
5
5009
7
9876
10000
10
OutputCopy
2
5000 9
1
7
4
800 70 6 9000
1
10000
1
10
*/

/*#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      if (digit == 0) {
        sum += digit;
        n /= 10;
      }
    }
    cout << sum << endl;
  }
  return 0;
}*/

/*Extract each digit using n % 10.
Add the digit to sum.
Remove the last digit from n using n /= 10.
Repeat until n becomes 0.*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t; // Number of test cases

  while (t--) {
    int n;
    cin >> n;                 // Input number for the test case
    vector<int> roundNumbers; // To store round numbers

    int placeValue = 1; // Start with the units place
    while (n > 0) {
      int digit = n % 10; // Extract the last digit
      if (digit != 0) {
        roundNumbers.push_back(digit * placeValue);
      }
      n /= 10;          // Remove the last digit
      placeValue *= 10; // Move to the next place value
    }

    // Output the result for the current test case
    cout << roundNumbers.size() << endl;
    for (int num : roundNumbers) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}

/* Extract Round Numbers:
- For each test case, extract the digits of 𝑛 starting from the least
significant digit.
- Multiply each digit by its positional value (e.g., 5 in the thousands place
becomes 5000).
- Only keep non-zero values as they are the round numbers.

Output Results:
- The number of round numbers 𝑘 is the size of the resulting list.
- Print 𝑘 followed by the list of round numbers.*/
