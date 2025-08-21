/*B. Maximum Cost Deletion
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
 of length 𝑛
 consisting only of the characters 0 and 1.

You perform the following operation until the string becomes empty: choose some
consecutive substring of equal characters, erase it from the string and glue the
remaining two parts together (any of them can be empty) in the same order. For
example, if you erase the substring 111 from the string 111110, you will get the
string 110. When you delete a substring of length 𝑙 , you get 𝑎⋅𝑙+𝑏 points.

Your task is to calculate the maximum number of points that you can score in
total, if you have to make the given string empty.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤2000
) — the number of testcases.

The first line of each testcase contains three integers 𝑛
, 𝑎
 and 𝑏
 (1≤𝑛≤100;−100≤𝑎,𝑏≤100
) — the length of the string 𝑠
 and the parameters 𝑎
 and 𝑏
.

The second line contains the string 𝑠
. The string 𝑠
 consists only of the characters 0 and 1.

Output
For each testcase, print a single integer — the maximum number of points that
you can score.

Example
InputCopy
3
3 2 0
000
5 -2 5
11001
6 1 -4
100111
OutputCopy
6
15
-2
Note
In the first example, it is enough to delete the entire string, then we will get
2⋅3+0=6 points.

In the second example, if we delete characters one by one, then for each deleted
character we will get (−2)⋅1+5=3 points, i. e. 15 points in total.

In the third example, we can delete the substring 00 from the string 100111, we
get 1⋅2+(−4)=−2 points, and the string will be equal to 1111, removing it
entirely we get 1⋅4+(−4)=0 points. In total, we got −2 points for 2 operations.
*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    long d(0);
    for (long p = 1; p < s.size(); p++) {
      d += (s[p] != s[p - 1]);
    }
    long factor = (b >= 0) ? n : (1 + (d + 1) / 2);
    std::cout << n * a + factor * b << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1550/334732567
