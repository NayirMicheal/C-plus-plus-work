#include <string>

#include "format.h"

using std::string;
using std::to_string;
// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hours = seconds /3600;
  int min,sec;
  seconds = seconds %3600;
  min = seconds/60;
  seconds = seconds %60;
  sec = seconds;
  return to_string(hours)+":"+to_string(min)+":"+to_string(sec);
}