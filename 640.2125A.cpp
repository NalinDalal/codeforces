/*A. Difficult Contest
time limit per test2 seconds
memory limit per test256 megabytes
It is known that a contest can be represented by a string 𝑠
, consisting of uppercase Latin letters that denote problems. It is also known
that a contest is difficult if it contains "FFT" or "NTT" as a contiguous
substring.

Your task is to rearrange the problem in contest 𝑠
 in such a way that this contest is not difficult. If the initial contest is not
difficult, you may leave it as it is.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test
cases follows.

The only line of each test case contains 𝑠
 (1≤|𝑠|≤2⋅105
).

Additional constraints on the input data:

the total length of strings across all test cases does not exceed 2⋅105
.
Output
For each test case, output a string — a non-difficult contest that was obtained
from 𝑠 by rearranging the letters.

If there are multiple correct answers, you may output any. It can be shown that
at least one correct answer always exists.

Example
InputCopy
5
FFT
ABFBANTTA
FFTNTT
FFTFFTFFTNNTNNT
AFFTBFFNTTFTTZ
OutputCopy
FTF
ABFBANATT
NTFTFT
TFFFFFFNTNTNTNT
AFTFBTTFFNFTTZ
*/

/*string can't have fft or ntt as a substring
 hmm traverse the string and check for 3 places {i,i+1,i+2}
 if you find fft/ntt reverse it
 move to i++, check again
 do until u reach the string end
 return string

sort in reverse order
*/
#include <algorithm>
#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    sort(s.rbegin(), s.rend());
    std::cout << s << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2125/336205133
