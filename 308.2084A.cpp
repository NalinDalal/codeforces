/*A. Max and Mod
time limit per test1 second
memory limit per test256 megabytes

You are given an integer 𝑛
. Find any permutation 𝑝
 of length 𝑛
∗
 such that:

For all 2≤𝑖≤𝑛
, max(𝑝𝑖−1,𝑝𝑖)mod𝑖
 †
 =𝑖−1
 is satisfied.
If it is impossible to find such a permutation 𝑝
, output −1
.

∗
A permutation of length 𝑛
 is an array consisting of 𝑛
 distinct integers from 1
 to 𝑛
 in arbitrary order. For example, [2,3,1,5,4]
 is a permutation, but [1,2,2]
 is not a permutation (2
 appears twice in the array), and [1,3,4]
 is also not a permutation (𝑛=3
 but there is 4
 in the array).

†
𝑥mod𝑦
 denotes the remainder from dividing 𝑥
 by 𝑦
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤99
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (2≤𝑛≤100
).

Output
For each test case:

If such a permutation 𝑝
 doesn't exist, output a single integer −1
.
Otherwise, output 𝑛
 integers 𝑝1,𝑝2,…,𝑝𝑛
 — the permutation 𝑝
 you've found. If there are multiple answers, output any of them.
Example
InputCopy
4
2
3
4
5
OutputCopy
-1
3 2 1
-1
1 5 2 3 4
Note
In the first test case, it is impossible to find such a permutation 𝑝
, so you should output −1
.

In the fourth test case, 𝑝=[1,5,2,3,4]
 satisfies the condition:

For 𝑖=2
, max(𝑝1,𝑝2)=5
 and 5mod2=1
.
For 𝑖=3
, max(𝑝2,𝑝3)=5
 and 5mod3=2
.
For 𝑖=4
, max(𝑝3,𝑝4)=3
 and 3mod4=3
.
For 𝑖=5
, max(𝑝4,𝑝5)=4
 and 4mod5=4.*/
#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {

    int n;
    std::cin >> n;
    if (n % 2 == 0) {
      std::cout << "-1" << std::endl;
      continue;
    }
    std::cout << n << std::endl;
    for (int i = 1; i < n; i++)
      std::cout << i << " ";
  }
  return 0;
}
/*#include <cstdio>
#include <vector>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        if(n % 2 == 0){puts("-1"); continue;}
        printf("%ld ", n);
        for(long p = 1; p < n; p++){printf("%ld ", p);}
        puts("");
    }

}*/
// sub: https://codeforces.com/problemset/submission/2084/316638016
