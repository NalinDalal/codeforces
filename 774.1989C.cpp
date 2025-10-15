/*C. Two Movies
time limit per test2 seconds
memory limit per test256 megabytes
A movie company has released 2
 movies. These 2
 movies were watched by 𝑛
 people. For each person, we know their attitude towards the first movie (liked
it, neutral, or disliked it) and towards the second movie.

If a person is asked to leave a review for the movie, then:

if that person liked the movie, they will leave a positive review, and the
movie's rating will increase by 1
;
if that person disliked the movie, they will leave a negative review, and the
movie's rating will decrease by 1
;
otherwise, they will leave a neutral review, and the movie's rating will not
change. Every person will review exactly one movie — and for every person, you
can choose which movie they will review.

The company's rating is the minimum of the ratings of the two movies. Your task
is to calculate the maximum possible rating of the company.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
).

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (−1≤𝑎𝑖≤1
), where 𝑎𝑖
 is equal to −1
 if the first movie was disliked by the 𝑖
-th viewer; equal to 1
 if the first movie was liked; and 0
 if the attitude is neutral.

The third line contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (−1≤𝑏𝑖≤1
), where 𝑏𝑖
 is equal to −1
 if the second movie was disliked by the 𝑖
-th viewer; equal to 1
 if the second movie was liked; and 0
 if the attitude is neutral.

Additional constraint on the input: the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the maximum possible rating of the
company, if for each person, choose which movie to leave a review on.

Example
InputCopy
4
2
-1 1
-1 -1
1
-1
-1
5
0 -1 1 0 1
-1 1 0 0 1
4
-1 -1 -1 1
-1 1 1 1
OutputCopy
0
-1
1
1
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;

  while (t--) {
    long n;
    std::cin >> n;

    std::vector<int> v(n);
    for (long p = 0; p < n; ++p) {
      std::cin >> v[p];
    }

    long a = 0, b = 0, minus = 0, plus = 0;
    for (long p = 0; p < n; ++p) {
      int x;
      std::cin >> x;
      if (v[p] < 0 && x < 0)
        ++minus;
      else if (v[p] > 0 && x > 0)
        ++plus;
      else if (v[p] > 0 && x <= 0)
        ++a;
      else if (v[p] <= 0 && x > 0)
        ++b;
    }

    if (a > b)
      std::swap(a, b);

    long diff = std::min(b - a, minus);
    b -= diff;
    minus -= diff;

    diff = std::min(b - a, plus);
    a += diff;
    plus -= diff;

    if (minus && plus) {
      long mn = std::min(minus, plus);
      minus -= mn;
      plus -= mn;
    }

    if (minus)
      a -= (minus + 1) / 2;
    else if (plus)
      a += plus / 2;

    std::cout << a << "\n";
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1989/343891762
