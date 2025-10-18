/*B. Maria Breaks the Self-isolation
time limit per test2 seconds
memory limit per test256 megabytes
Maria is the most active old lady in her house. She was tired of sitting at
home. She decided to organize a ceremony against the coronavirus.

She has 𝑛
 friends who are also grannies (Maria is not included in this number). The 𝑖
-th granny is ready to attend the ceremony, provided that at the time of her
appearance in the courtyard there will be at least 𝑎𝑖 other grannies there. Note
that grannies can come into the courtyard at the same time. Formally, the granny
𝑖 agrees to come if the number of other grannies who came earlier or at the same
time with her is greater than or equal to 𝑎𝑖
.

Grannies gather in the courtyard like that.

Initially, only Maria is in the courtyard (that is, the initial number of
grannies in the courtyard is 1
). All the remaining 𝑛
 grannies are still sitting at home.
On each step Maria selects a subset of grannies, none of whom have yet to enter
the courtyard. She promises each of them that at the time of her appearance
there will be at least 𝑎𝑖 other grannies (including Maria) in the courtyard.
Maria can call several grannies at once. In this case, the selected grannies
will go out into the courtyard at the same moment of time. She cannot deceive
grannies, that is, the situation when the 𝑖 -th granny in the moment of
appearing in the courtyard, finds that now there are strictly less than 𝑎𝑖 other
grannies (except herself, but including Maria), is prohibited. Please note that
if several grannies appeared in the yard at the same time, then each of them
sees others at the time of appearance. Your task is to find what maximum number
of grannies (including herself) Maria can collect in the courtyard for the
ceremony. After all, the more people in one place during quarantine, the more
effective the ceremony!

Consider an example: if 𝑛=6
 and 𝑎=[1,5,4,5,1,9]
, then:

at the first step Maria can call grannies with numbers 1
 and 5
, each of them will see two grannies at the moment of going out into the yard
(note that 𝑎1=1≤2 and 𝑎5=1≤2
);
at the second step, Maria can call grannies with numbers 2
, 3
 and 4
, each of them will see five grannies at the moment of going out into the yard
(note that 𝑎2=5≤5 , 𝑎3=4≤5 and 𝑎4=5≤5
);
the 6
-th granny cannot be called into the yard  — therefore, the answer is 6
 (Maria herself and another 5
 grannies).
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases in the input. Then test cases follow.

The first line of a test case contains a single integer 𝑛
 (1≤𝑛≤105
) — the number of grannies (Maria is not included in this number).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2⋅105
).

It is guaranteed that the sum of the values 𝑛
 over all test cases of the input does not exceed 105
.

Output
For each test case, print a single integer 𝑘
 (1≤𝑘≤𝑛+1
) — the maximum possible number of grannies in the courtyard.

Example
InputCopy
4
5
1 1 2 2 1
6
2 3 4 5 6 7
6
1 5 4 5 1 9
5
1 2 3 5 6
OutputCopy
6
1
6
4
Note
In the first test case in the example, on the first step Maria can call all the
grannies. Then each of them will see five grannies when they come out.
Therefore, Maria and five other grannies will be in the yard.

In the second test case in the example, no one can be in the yard, so Maria will
remain there alone.

The third test case in the example is described in the details above.

In the fourth test case in the example, on the first step Maria can call
grannies with numbers 1 , 2 and 3 . If on the second step Maria calls 4 or 5
 (one of them), then when a granny appears in the yard, she will see only four
grannies (but it is forbidden). It means that Maria can't call the 4 -th granny
or the 5 -th granny separately (one of them). If she calls both: 4 and 5 , then
when they appear, they will see 4+1=5 grannies. Despite the fact that it is
enough for the 4 -th granny, the 5 -th granny is not satisfied. So, Maria cannot
call both the 4 -th granny and the 5 -th granny at the same time. That is, Maria
and three grannies from the first step will be in the yard in total.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for (long i = 0; i < n; ++i) {
      std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    long cnt = 1;
    for (long i = n - 1; i >= 0; --i) {
      if (a[i] <= i + 1) {
        cnt = i + 2;
        break;
      }
    }

    std::cout << cnt << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1358/344459848
