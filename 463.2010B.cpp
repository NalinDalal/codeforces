/*B. Three Brothers
time limit per test1 second
memory limit per test256 megabytes
Three brothers agreed to meet. Let's number the brothers as follows: the oldest
brother is number 1, the middle brother is number 2, and the youngest brother is
number 3.

When it was time for the meeting, one of the brothers was late. Given the
numbers of the two brothers who arrived on time, you need to determine the
number of the brother who was late.

Input
The first line of input contains two different integers a and b (1 ≤ a, b ≤ 3,
a ≠ b) — the numbers of the brothers who arrived on time. The numbers are given
in arbitrary order.

Output
Output a single integer — the number of the brother who was late to the meeting.

Example
InputCopy
3 1
OutputCopy
2


*/

// really nigga, if a,b are there, obviously c is not there so it's like
// 1,2,3; given 2 no, find which is not there
// sum=1+2+3=6
// find sum of input, minus it from 6, that no is not there

#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << 6 - (a + b) << endl;
  return 0;
}
//sub: https://codeforces.com/problemset/submission/2010/326910703
