/*
https://codeforces.com/problemset/problem/1328/A

A. Divisibility Problem
time limit per test1 second
memory limit per test256 megabytes
You are given two positive integers 𝑎
 and 𝑏
. In one move you can increase 𝑎
 by 1
 (replace 𝑎
 with 𝑎+1
). Your task is to find the minimum number of moves you need to do in order to
make 𝑎 divisible by 𝑏 . It is possible, that you have to make 0 moves, as 𝑎 is
already divisible by 𝑏 . You have to answer 𝑡 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then 𝑡
 test cases follow.

The only line of the test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤109
).

Output
For each test case print the answer — the minimum number of moves you need to do
in order to make 𝑎 divisible by 𝑏
.

Example
InputCopy
5
10 4
13 9
100 13
123 456
92 46
OutputCopy
2
5
4
333
0

*/

/*#include <iostream>
using namespace std;

int main() {
  int t; // testcases, counter
  cin >> t;
  while (t--) {
    int a, b;  // input
    int c = 0; // counter
    cin >> a >> b;
    while (a % b != 0) {
      a++;
      c++;
    }
    cout << c << endl;
  }

  return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t; // Number of test cases
  cin >> t;

  // Vector to store results of all test cases
  vector<int> results;

  // Process each test case
  while (t--) {
    int a, b; // Input numbers
    cin >> a >> b;

    // Calculate how many increments are needed
    int c = (b - (a % b)) % b; // If a is divisible by b, c will be 0;
                               // otherwise, calculate the required increments

    // Store the result for the current test case
    results.push_back(c);
  }

  // Output all results after processing all test cases
  for (int result : results) {
    cout << result << endl;
  }

  return 0;
}
