#include <iostream>
#include <cassert>
#include <vector>

int getSubsequence(const std::vector<int> & elems, const std::vector<int> counters, int curPos) {

  int pos = curPos;
  for(int i = curPos-1; i >= 0; i--) // O(curPos)
    if(elems[i] <= elems[curPos])
      if(counters[i] > counters[pos]) pos = i;
  return pos;
}

// O(n^2)
int longestIncrSubseq(const std::vector<int> & elems) {

  if(elems.size() <= 1)
    return elems.size();

  std::vector<int> counters(elems.size(), 0);
  counters[0] = 1;

  for(int i = 1; i < elems.size(); i++) { // O(n)
    int prevSubSeq = getSubsequence(elems, counters, i);
    counters[i] = std::max(counters[prevSubSeq] + 1, counters[i-1]);
  }

  int maxSeqCount = -1;
  for(int i = 0; i < counters.size(); i++) // O(n)
    if(counters[i] > maxSeqCount) maxSeqCount = counters[i];

  return maxSeqCount;
}

int main() {

  std::vector<int> arr1 = {1, 2, 3, 0, 4};
  std::vector<int> arr2 = {10, 9, 2, 5, 3, 7, 101, 18};
  std::vector<int> arr3 = {};
  std::vector<int> arr4 = {122};
  std::vector<int> arr5 = {1 ,1};

  assert(longestIncrSubseq(arr1) == 4);
  assert(longestIncrSubseq(arr2) == 4);
  assert(longestIncrSubseq(arr3) == 0);
  assert(longestIncrSubseq(arr4) == 1);
  assert(longestIncrSubseq(arr5) == 2);

  return 0;
}
