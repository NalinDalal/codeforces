/*C. Clock Conversion
time limit per test1 second
memory limit per test256 megabytes
Given the time in 24-hour format, output the equivalent time in 12-hour format.

24-hour format divides the day into 24 hours from 00
 to 23
, each of which has 60 minutes from 00
 to 59
.
12-hour format divides the day into two halves: the first half is AM
, and the second half is PM
. In each half, the hours are numbered in the order 12,01,02,03,…,11
. Each hour has 60 minutes numbered from 00
 to 59
.
Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1440
) — the number of test cases.

The only line of each test case contains a string 𝑠
 of length 5
 with format hh:mm representing a valid time in the 24-hour format. hh
represents the hour from 00 to 23 , and mm represents the minute from 00 to 59
.

The input will always be a valid time in 24-hour format.

Output
For each test case, output two strings separated by a space ("hh:mm AM" or
"hh:mm PM"), which are the 12-hour equivalent to the time provided in the test
case (without quotes).

You should output the time exactly as indicated; in particular, you should not
remove leading zeroes.

Example
InputCopy
11
09:41
18:06
12:14
00:59
00:00
14:34
01:01
19:07
11:59
12:00
21:37
OutputCopy
09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM


*/

// convert the time from 24 hr format to 12 hr format
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;                          // 24 hour format time as input
    int h = std::stoi(s.substr(0, 2)); // differentiate both hr and
                                       // min
    bool pm = false;
    pm = (h >= 12);
    if (h == 0) {
      h = 12;
    } else if (h > 12) {
      h -= 12;
    }

    string t = "";
    if (h < 10) {
      t = "0";
    }
    t += to_string(h);
    t += s.substr(2);
    t += pm ? " PM" : " AM";
    cout << t << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1950/309852255
