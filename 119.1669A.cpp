/* https://codeforces.com/problemset/problem/1669/A
A. Division?

Codeforces separates its users into 4 divisions by their rating:
For Division 1: 1900≤rating
For Division 2: 1600≤rating≤1899
For Division 3: 1400≤rating≤1599
For Division 4: rating≤1399

Given a rating, print in which division the rating belongs.

Input
The first line of the input contains an integer 𝑡 (1≤𝑡≤104) — the number of
testcases.

The description of each test consists of one line containing one integer rating
(−5000≤rating≤5000).

Output
For each test case, output a single line containing the correct division in the
format "Division X", where 𝑋 is an integer between 1 and 4 representing the
division for the corresponding rating.

Example
InputCopy
7
-789
1299
1300
1399
1400
1679
2300
OutputCopy
Division 4
Division 4
Division 4
Division 4
Division 3
Division 2
Division 1
Note
For test cases 1−4, the corresponding ratings are −789, 1299, 1300, 1399, so all
of them are in division 4.

For the fifth test case, the corresponding rating is 1400, so it is in
division 3.

For the sixth test case, the corresponding rating is 1679, so it is in
division 2.

For the seventh test case, the corresponding rating is 2300, so it is in
division 1.




*/
#include <cstdio>

int main() {

  long t;
  scanf("%ld", &t);
  while (t--) {
    long r;
    scanf("%ld", &r);
    int res(1);
    if (r <= 1399) {
      res = 4;
    } else if (r <= 1599) {
      res = 3;
    } else if (r <= 1899) {
      res = 2;
    } else if (1900 <= r) {
      res = 1;
    }
    printf("Division %d\n", res);
  }
}
// sub: https://codeforces.com/contest/1669/submission/304936783
