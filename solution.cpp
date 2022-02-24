#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol418;
using namespace std;

/*takeaways

  - you can use greedy approach if that makes more sense to you
    but we are practicing DP here

  - the key concept is that we exhaust all the possibilities by making
    every word the very first word inside a row and count how many times
    we can fit in the sentence inside that row
    - starting from the second row, any word has a chance to be the first
      word depending on the dimensions of the screen and the sentence

  - fianlly start with placing the first word the first row and count
    the times you can fit in the sentence in the entire screen
*/

int Solution::countTimes(vector<string> &sentence, int rows, int cols)
{
  const auto N = sentence.size();
  /*
    - records how many times I can fit in the
      sentence inside a row if I start with
      the word sentence[i]
  */
  auto swTimes = vector<int>(N);
  /*
    - record what the start word should be
      for the next row after I finished
      fitting in the sentence, as many
      times as I can, inside the current
      row starting with word sentence[i]
  */
  auto swNextRow = vector<int>(N);

  /*C++ notes
    - have been bitten by this many times
    - size_t is not int and when you compare
      it to a negative in it doesn't work
      as you would expect
  */
  auto wordSize = [&](int index)
  {
    return (int)sentence[index].size();
  };

  /*
    - count how many times I can fitting in the
      sentence inside a row if I start with the
      word setence[i]
  */
  for (auto i = 0; i < N; i++)
  {
    auto times = 0, indx = i, left = cols;
    /*
      - start with word i, and see how many times
        we can fit in the sentence in this row
    */

    while (left >= wordSize(indx))
    {
      /* use up word size + additional space */
      left -= (wordSize(indx) + 1), indx++;
      if (indx == N)
        times++, indx = 0;
    }
    /* indx is pointing to the word that should be
       put into the beginning of the next row if
       we start this row with word i, sentence[i].
    */
    swTimes[i] = times;
    swNextRow[i] = indx;
  }

  /* start with word 0 */
  auto total = 0, next = 0;
  for (auto i = 0; i < rows; i++)
  {
    total += swTimes[next];
    next = swNextRow[next];
  }

  return total;
}