/* C. Preparing for the Exam
time limit per test1.5 seconds
memory limit per test256 megabytes
Monocarp is preparing for his first exam at the university. There are 𝑛
 different questions which can be asked during the exam, numbered from 1
 to 𝑛
. There are 𝑚
 different lists of questions; each list consists of exactly 𝑛−1
 different questions. Each list 𝑖
 is characterized by one integer 𝑎𝑖
, which is the index of the only question which is not present in the 𝑖
-th list. For example, if 𝑛=4
 and 𝑎𝑖=3
, the 𝑖
-th list contains questions [1,2,4]
.

During the exam, Monocarp will receive one of these 𝑚
 lists of questions. Then, the professor will make Monocarp answer all questions
from the list. So, Monocarp will pass only if he knows all questions from the
list.

Monocarp knows the answers for 𝑘
 questions 𝑞1,𝑞2,…,𝑞𝑘
. For each list, determine if Monocarp will pass the exam if he receives that
list.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Each test case consists of three lines:

the first line contains three integers 𝑛
, 𝑚
 and 𝑘
 (2≤𝑛≤3⋅105
; 1≤𝑚,𝑘≤𝑛
);
the second line contains 𝑚
 distinct integers 𝑎1,𝑎2,…,𝑎𝑚
 (1≤𝑎𝑖≤𝑛
; 𝑎𝑖<𝑎𝑖+1
);
the third line contains 𝑘
 distinct integers 𝑞1,𝑞2,…,𝑞𝑘
 (1≤𝑞𝑖≤𝑛
; 𝑞𝑖<𝑞𝑖+1
).
Additional constraints on the input:

the sum of 𝑛
 over all test cases does not exceed 3⋅105
.
Output
For each test case, print a string of 𝑚
 characters. The 𝑖
-th character should be 1 if Monocarp passes the exam if he receives the 𝑖
-th question list, 0 if Monocarp won't pass.

Example
InputCopy
4
4 4 3
1 2 3 4
1 3 4
5 4 3
1 2 3 4
1 3 4
4 4 4
1 2 3 4
1 2 3 4
2 2 1
1 2
2
OutputCopy
0100
0000
1111
10
Note
In the first test case, Monocarp knows the questions [1,3,4]
. Let's consider all the question lists:

the first list consists of questions [2,3,4]
. Monocarp doesn't know the 2
-nd question, so he won't pass;
the second list consists of questions [1,3,4]
. Monocarp knows all these questions, so he will pass;
the third list consists of questions [1,2,4]
. Monocarp doesn't know the 2
-nd question, so he won't pass;
the fourth list consists of questions [1,2,3]
. Monocarp doesn't know the 2
-nd question, so he won't pass.

*/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    for (int i = 0; i < m; i++)
      cin >> a[i];

    unordered_set<int> known;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      known.insert(x);
    }
    // print string of m char
    // ith char is 1 if Monocarp passes the exam if he recieves the ith
    // question
    // 0 if won't pass

    string res = "";
    for (int i = 0; i < m; i++) {
      int missing = a[i];
      if (known.find(missing) == known.end()) {
        // missing question is not known → Monocarp must know exactly n - 1
        // other questions
        res += (known.size() == n - 1 ? '1' : '0');
      } else {
        // missing question is known → Monocarp must know all other n - 1
        // questions
        res += (known.size() == n ? '1' : '0');
      }
    }

    cout << res << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2051/321658522
