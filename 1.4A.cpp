/*
link: https://codeforces.com/problemset/problem/4/A

800 - Rating

A. Watermelon
time limit per test1 second
memory limit per test64 megabytes

One hot summer day Pete and his friend Billy decided to buy a watermelon. They
chose the biggest and the ripest one, in their opinion. After that the
watermelon was weighed, and the scales showed w kilos. They rushed home, dying
of thirst, and decided to divide the berry, however they faced a hard problem.

Pete and Billy are great fans of even numbers, that's why they want to divide
the watermelon in such a way that each of the two parts weighs even number of
kilos, at the same time it is not obligatory that the parts are equal. The boys
are extremely tired and want to start their meal as soon as possible, that's why
you should help them and find out, if they can divide the watermelon in the way
they want. For sure, each of them should get a part of positive weight.

Input
The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) —
the weight of the watermelon bought by the boys.

Output
Print YES, if the boys can divide the watermelon into two parts, each of them
weighing even number of kilos; and NO in the opposite case.

Examples
InputCopy: 8
OutputCopy: YES
Note: For example, the boys can divide the watermelon into two parts of 2 and 6
kilos respectively (another variant — two parts of 4 and 4 kilos).

*/

// Solution: well well what we can do, if the weight can be broken down into sum
// of even numbers, then we can divide it, hence if it is possible return true,
// else return false.

// take 2 integer, i,j where sum(i,j) ==w also i%2==0 and j%2==0
//     if it is possible return true else return false

// so just do shit in main function

#include <iostream>
using namespace std;

int main() {
  int w;
  cin >> w;
  if (w > 2) {
    if (w % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}
