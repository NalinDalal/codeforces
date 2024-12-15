/* A. Vanya and Fence
time limit per test1 second
memory limit per test256 megabytes
Vanya and his friends are walking along the fence of height h and they do not
want the guard to notice them. In order to achieve this the height of each of
the friends should not exceed h. If the height of some person is greater than h
he can bend down and then he surely won't be noticed by the guard. The height of
the i-th person is equal to ai.

Consider the width of the person walking as usual to be equal to 1, while the
width of the bent person is equal to 2. Friends want to talk to each other while
walking, so they would like to walk in a single row. What is the minimum width
of the road, such that friends can walk in a row and remain unattended by the
guard?

Input
The first line of the input contains two integers n and h (1 ≤ n ≤ 1000,
1 ≤ h ≤ 1000) — the number of friends and the height of the fence, respectively.

The second line contains n integers ai (1 ≤ ai ≤ 2h), the i-th of them is equal
to the height of the i-th person.

Output
Print a single integer — the minimum possible valid width of the road.

Examples
InputCopy
3 7
4 5 14
OutputCopy
4
InputCopy
6 1
1 1 1 1 1 1
OutputCopy
6
InputCopy
6 5
7 6 8 9 10 5
OutputCopy
11
Note
In the first sample, only person number 3 must bend down, so the required width
is equal to 1 + 1 + 2 = 4.

In the second sample, all friends are short enough and no one has to bend, so
the width 1 + 1 + 1 + 1 + 1 + 1 = 6 is enough.

In the third sample, all the persons have to bend, except the last one. The
required minimum width of the road is equal to 2 + 2 + 2 + 2 + 2 + 1 = 11. */

// If a friend's height is less than or equal to the fence height h, they occupy
// a width of 1. If a friend's height exceeds h, they bend down and occupy a
// width of 2
#include <iostream>
using namespace std;

int main() {
  int n, h;
  cin >> n >> h;

  int total_width = 0;
  for (int i = 0; i < n; i++) {
    int height;
    cin >> height;
    if (height <= h) {
      total_width += 1; // Walks normally
    } else {
      total_width += 2; // Bends down
    }
  }

  cout << total_width << endl;
  return 0;
}
