/*G1. Ruler (easy version)
time limit per test1 second
memory limit per test256 megabytes
This is the easy version of the problem. The only difference between the two
versions is that in this version, you can make at most 10 queries.

This is an interactive problem. If you are unsure how interactive problems work,
then it is recommended to read the guide for participants.

We have a secret ruler that is missing one number 𝑥
 (2≤𝑥≤999
). When you measure an object of length 𝑦
, the ruler reports the following values:

If 𝑦<𝑥
, the ruler (correctly) measures the object as having length 𝑦
.
If 𝑦≥𝑥
, the ruler incorrectly measures the object as having length 𝑦+1
.

The ruler above is missing the number 4
, so it correctly measures the first segment as length 3
 but incorrectly measures the second segment as length 6
 even though it is actually 5
.

You need to find the value of 𝑥
. To do that, you can make queries of the following form:

? 𝑎 𝑏
 — in response, we will measure the side lengths of an 𝑎×𝑏
 rectangle with our ruler and multiply the results, reporting the measured area
of the rectangle back to you. For example, if 𝑥=4 and you query a 3×5 rectangle,
we will measure its side lengths as 3×6 and report 18 back to you. Find the
value of 𝑥 . You can ask at most 10 queries.

Input
Each test contains multiple test cases. The first line of input contains a
single integer 𝑡 (1≤𝑡≤1000 ) — the number of test cases.

Interaction
There is no initial input for each test case. You should begin the interaction
by asking a query.

To make a query, output a single line of the form ? 𝑎 𝑏
 (1≤𝑎,𝑏≤1000
). In response, you will be told the measured area of the rectangle, according
to our secret ruler.

When you are ready to print the answer, output a single line of the form ! 𝑥
 (2≤𝑥≤999
). After that, proceed to process the next test case or terminate the program if
it was the last test case. Printing the answer does not count as a query.

The interactor is not adaptive, meaning that the answer is known before the
participant asks the queries and doesn't depend on the queries asked by the
participant.

If your program makes more than 10
 queries for one set of input data, makes an invalid query, or prints the wrong
value of 𝑥 , then the response to the query will be −1 . After receiving such a
response, your program should immediately terminate to receive the verdict Wrong
Answer. Otherwise, you can get an arbitrary verdict because your solution will
continue to read from a closed stream.

After printing a query do not forget to output the end of line and flush the
output. Otherwise, you may get Idleness limit exceeded verdict. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see the documentation for other languages.
Hacks

To make a hack, use the following format.

The first line should contain a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The only line of each test case should contain a single integer 𝑥
 (2≤𝑥≤999
) — the missing number on the ruler.

Example
InputCopy
2

18

25


9999
OutputCopy
? 3 5

? 4 4

! 4
? 99 100

! 100
Note
In the first test, the interaction proceeds as follows.

Solution	Jury	Explanation
𝟸
There are 2 test cases.
? 𝟹 𝟻
𝟷𝟾
Secretly, the jury picked 𝑥=4
. The solution requests the 3×5
 rectangle, and the jury responds with 3×6=18
, as described in the statement.
? 𝟺 𝟺
𝟸𝟻
The solution requests the 4×4
 rectangle, which the jury measures as 5×5
 and responds with 25
.
! 𝟺
The solution has somehow determined that 𝑥=4
, and outputs it. Since the output is correct, the jury continues to the next
test case. ? 𝟿𝟿 𝟷𝟶𝟶 𝟷 Secretly, the jury picked 𝑥=100 . The solution requests
the 99×100 rectangle, which the jury measures as 99×101 and responds with 9999
.
! 𝟷𝟶𝟶
The solution has somehow determined that 𝑥=100
, and outputs it. Since the output is correct and there are no more test cases,
the jury and the solution exit. Note that the line breaks in the example input
and output are for the sake of clarity, and do not occur in the real
interaction.
*/

/*There’s a secret number x (2 ≤ x ≤ 999) missing from the ruler.

Query:
? a b → returns (measured a) × (measured b).
Where:

If y < x, measured(y) = y.

If y ≥ x, measured(y) = y + 1.

Goal: find x using ≤ 10 queries.

if you query ? k (k+1):
Case 1: if both < x, measured = k × (k+1) (normal).
Case 2: if k < x ≤ k+1: measured = k × (k+2) (because (k+1) gets bumped).
Case 3: if both ≥ x: measured = (k+1) × (k+2).


Just ask ? y y:

If y < x: response = y².

If y ≥ x: response = (y+1)².
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t; // number of test cases
  while (t--) {
    int l = 2, r = 999;
    while (l < r) {
      int mid = (l + r) / 2;
      cout << "? " << mid << " " << mid << endl;
      cout.flush();

      long long val;
      cin >> val;
      if (val == 1)
        return 0; // safety: interactor error

      if (val == 1LL * mid * mid) {
        // still before x
        l = mid + 1;
      } else {
        // at or after x
        r = mid;
      }
    }

    cout << "! " << l << endl;
    cout.flush();
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1999/339195526
