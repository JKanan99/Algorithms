///////////////////////////////////////////////////////////////////////////////
// algorithms.cpp
//
// Definitions for three algorithms:
//
// find_dip
// longest_balanced_span
// telegraph_style
//
///////////////////////////////////////////////////////////////////////////////

#include "algorithms.hpp"

std::vector<int>::const_iterator algorithms::find_dip(const std::vector<int>& values) {

     auto last_dip = values.end();
    
    if(values.size() == 3){
        if(values[0] == values[2] && values[1] < values[0]){
            last_dip = values.begin();
        }
    }
    else if(values.size() >= 4){
      for(int i = 0; i < values.size() - 3; ++i){
            if(values[i] == values[i+2] && values[i+1] < values[i]){
                last_dip = values.begin() + i;
            }
        }  
    }
    
    
    return last_dip;
}

std::optional<algorithms::span> algorithms::longest_balanced_span(const std::vector<int>& values) {
  int s = 0;
  int e = 0;
  int sum = 0;
  std::optional<algorithms::span> best = std::nullopt;

  for (int i=0;i < values.size(); i++)
  {
    sum = values[i];
    for(int j=i+1; j <= values.size(); j++)
    {
      if(sum == 0 && (j - i) >= (e - s)){
        e = j;
        s = i;
        auto start = values.begin() + i;
        auto end = values.begin() + j;
        algorithms::span temp(start, end);
        best = temp;
      }
      sum += values[j];
    }
  }

  return best;
}

std::string algorithms::telegraph_style(const std::string& s) {
  const std::string STOP = "STOP.";
  std::string newString = "";
  
  if(s.length() > 0 && s != STOP){
      for(int i = 0; i < s.length(); ++i){
          //Check for lowercase
          if(islower(s[i])){
              char letter = toupper(s[i]);
              newString += letter;
          }
          else if(isupper(s[i])){
              newString += s[i];
          }
          //Check for puncutation
          else if(s[i] == '!' || s[i] == '?' || s[i] == ';' || s[i] == '.'){
              newString += '.';
          }
          else if(s[i] == ' '){
            //If there are not multiple spaces, add one space
            if(s[i-1] != ' '){
              newString += s[i];
            }
          }
          else if(isalnum(s[i])){
            newString += s[i];
          }
      }
      //If the word stop. is not in the string, add it
      if(newString.find("STOP") == std::string::npos){
          newString += STOP;
      }
  }
  else{
    newString += STOP;
  }
  
  return newString;
}
