/* https://codeforces.com/problemset/problem/723/A

A. The New Year: Meeting Friends
time limit per test1 second
memory limit per test256 megabytes
There are three friend living on the straight line Ox in Lineland. The first
friend lives at the point x1, the second friend lives at the point x2, and the
third friend lives at the point x3. They plan to celebrate the New Year
together, so they need to meet at one point. What is the minimum total distance
they have to travel in order to meet at some point and celebrate the New Year?

It's guaranteed that the optimal answer is always integer.

Input
The first line of the input contains three distinct integers x1, x2 and x3
(1 ≤ x1, x2, x3 ≤ 100) — the coordinates of the houses of the first, the second
and the third friends respectively.

Output
Print one integer — the minimum total distance the friends need to travel in
order to meet together.

Examples
InputCopy
7 1 4
OutputCopy
6
InputCopy
30 20 10
OutputCopy
20
Note
In the first sample, friends should meet at the point 4. Thus, the first friend
has to travel the distance of 3 (from the point 7 to the point 4), the second
friend also has to travel the distance of 3 (from the point 1 to the point 4),
while the third friend should not go anywhere because he lives at the point 4.

*/

// Sort the three coordinates.
// The optimal meeting point is the middle one after sorting, which minimizes
// the total travel distance.

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  // Put the coordinates into an array
  int arr[3] = {x1, x2, x3};

  // Sort the array to find the median
  sort(arr, arr + 3);

  // The optimal meeting point is the median (arr[1])
  int minDist = (arr[2] - arr[1]) + (arr[1] - arr[0]);

  cout << minDist << endl;
  return 0;
}
// submission: t.ly/-dCvK
