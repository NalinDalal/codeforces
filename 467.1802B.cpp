/*B. Settlement of Guinea Pigs
time limit per test1 second
memory limit per test256 megabytes
Dasha loves guinea pigs very much. In this regard, she decided to settle as many
guinea pigs at home as possible and developed a plan for the next 𝑛 days. Every
day, she will either buy a new guinea pig or call a doctor to examine all her
pets.

Unfortunately, the store where she was going to buy guinea pigs does not
understand them. Therefore, it cannot determine their gender. Dasha can't do it
either. The only one who can help is a doctor.

To keep guinea pigs, aviaries are needed. Dasha plans to buy them in the same
store. Unfortunately, only one species is sold there — a double aviary. No more
than two guinea pigs can live in it.

Since Dasha does not want to cause moral injury to her pets — she will not
settle two guinea pigs of different genders in one aviary.

Help Dasha calculate how many aviaries in the worst case you need to buy so that
you can be sure that at no moment of time do two guinea pigs of different
genders live in the same aviary.

As part of this task, we believe that guinea pigs have only two genders — male
and female.

Input
The first line of input data contains one number 𝑡
 (1⩽𝑡⩽105
) — the number of input data sets.

The first line of each input data set contains one number 𝑛
 (1⩽𝑛⩽105
) — the number of days Dasha has a plan for.

The next line contains 𝑛
 numbers 𝑏1,𝑏2,𝑏3,…,𝑏𝑛
 (1⩽𝑏𝑖⩽2
) — Dasha's plan. If 𝑏𝑖=1
, then on the 𝑖
th day, Dasha will buy a new guinea pig. If 𝑏𝑖=2
, then on the 𝑖
th day, a doctor will come to Dasha and help determine the sex of all guinea
pigs that Dasha already has.

It is guaranteed that the sum of 𝑛
 for all input data sets does not exceed 105
.

Output
For each set of input data, output one number — the minimum number of aviaries
Dasha needs to buy so that no matter what the genders of the pigs turn out to
be, we can settle them so that at no point in time do two guinea pigs of
different genders live together.

Example
InputCopy
6
3
1 1 1
3
2 2 2
5
1 1 1 2 1
10
1 2 1 2 1 2 1 2 1 2
20
1 2 1 1 1 1 1 2 1 2 1 2 2 1 1 1 1 1 1 1
20
2 1 1 2 1 1 2 1 2 2 1 1 1 2 2 1 1 1 1 2
OutputCopy
3
0
3
4
12
9
Note
In the first set of input data, Dasha needs to put each guinea pig in a separate
enclosure, since she does not know their gender.

In the second set of input data, Dasha will buy 0
 guinea pigs, which means she will need 0
 aviaries.

In the third set of input data, you even need 3
 aviaries to put each guinea pig in a separate aviary before the doctor arrives
at the 4 th day. When she finds out their gender, at least two guinea pigs will
be of the same gender and they can be placed in one aviary, and the third in
another aviary. Thus, she will have one free aviary in which she can settle a
new guinea pig. So answer is 3
.

In the fourth set of input data, we show that 4
 is the optimal answer.

To begin with, we note that the first four guinea pigs can be placed one at a
time in an aviary. Then a doctor will come and determine their gender. Among
these four guinea pigs there will be at least one pair of the same gender,
because: either male guinea pigs are at least 2 , or they are not more than 1 ,
which means that the female is at least 3 . Now we can put this couple in one
aviary, and the other two in separate ones. We will have one more empty aviary
where we can put a new pig.

Now let's show that the answer is at least 4
. Let's say that among the first 4
 guinea pigs, 3
 are female and 1
 is male. We need at least 3
 aviaries to settle them. Then, when we buy a new guinea pig, we will need
another aviary in which we will put it, since we do not know its gender.



*/

#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    long u(0), v(0), res(0);
    for (long p = 0; p < n; p++) {
      int x;
      std::cin >> x;
      if (x == 1) {
        ++u;
      } else if (x == 2) {
        v += u;
        u = 0;
      }

      long cur = u + (v > 0) * (v + 2) / 2;
      res = (res > cur) ? res : cur;
    }
    std::cout << res << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1802/327085299
