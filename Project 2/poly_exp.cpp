
///////////////////////////////////////////////////////////////////////////////
// poly_exp.cpp
//
// Definitions for the functions declared in poly_exp.hpp.
//
///////////////////////////////////////////////////////////////////////////////

#include "poly_exp.hpp"
#include<bits/stdc++.h>
namespace subarray {

summed_span max_subarray_exh(const std::vector<int>& input) {

  assert(!input.empty());

  int max_sum = -2147483648;
  int sum = 0;
  int start = 0;
  int end = 0;
  int s=0;

  for (int i=0; i< input.size(); i++ )
  {
      sum += input[i];

      if (max_sum < sum)
      {
          max_sum = sum;
          start = s;
          end = i + 1;
      }

      if (sum < 0)
      {
          sum = 0;
          s = i + 1;
      }
  }

  auto startIndex = input.begin() + start;
  auto endIndex = input.begin() + end;

  return summed_span(startIndex, endIndex);
}

summed_span maximum_subarray_crossing(const std::vector<int>& in, int low, int middle, int high) {
  int leftSum = -2147483647;
  int rightSum = -2147483647;
  int sum = 0;
  int b = 0;
  int e = 0;
  for (int i = middle; i>=low; i--)
  {
    sum+= in[i];
    if (sum>leftSum)
    {
      leftSum = sum;
      b = i;
    }
  }

  sum = 0;
  for (int j=middle+1; j<=high; j++)
  {
    sum += in[j];
    if (sum>rightSum)
    {
      rightSum = sum;
      e = j;
    }
  }

  auto startIndex = in.begin() + b;
  auto endIndex = in.begin() + (e+1);

  return summed_span(startIndex, endIndex);
};

summed_span max_subarray_recuse(const std::vector<int>& in, int low, int high) {
  if (low == high)
  {
    auto startIndex = in.begin() + low;
    auto endIndex = in.begin() + (low + 1);

    return summed_span(startIndex, endIndex);
  }

  int middle = (low+high)/2;
  summed_span entireLeft = max_subarray_recuse(in, low, middle);
  summed_span entireRight = max_subarray_recuse(in, middle + 1, high);
  summed_span crossing = maximum_subarray_crossing(in, low, middle, high);

  if ((entireLeft.sum() > entireRight.sum()) && (entireLeft.sum() > crossing.sum()))
  {
    return entireLeft;
  }
  else if ((entireRight.sum() > entireLeft.sum())&& (entireRight.sum() > crossing.sum()))
  {
    return entireRight;
  }
  else
  {
    return crossing;
  }
};

summed_span max_subarray_dbh(const std::vector<int>& input) {

  assert(!input.empty());

  return max_subarray_recuse(input, 0, input.size() - 1);
}

int addingValues(std::vector<int> input){
  int sum = 0;
  for(int i = 0; i < input.size();i++){
    sum += input[i];
  }
  return sum;
}
std::optional<std::vector<int>>
subset_sum_exh(const std::vector<int>& input, int target) {

  assert(!input.empty());
  assert(input.size() < 64);

    if (input.size() == 1){
      if (input[0] == target){
        return input;
      }
    }
    for (long long int i = 0; i < pow(2,input.size()); i++)
    {
      std::vector<int> candidate = {};

      for (int j=0;j < input.size() ; j++)
      {
        if (((i>>j) & 1 ) == 1)
        {
          candidate.push_back(input[j]);
        }
      }
      if(candidate.size()>0 && addingValues(candidate) == target)
      {
        return candidate;
      }
    }

    return std::nullopt;
 }
}
