#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include "processor.h"
#include "linux_parser.h"
using std::stof;
using std::string;
using std::vector;
// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
 static float user,nice,system,idle,iowait,irq,softirq,steal;
 static float prev_user,prev_nice,prev_system,prev_idle,prev_iowait,prev_irq;
 static float prev_softirq,prev_steal;
 vector<string> mem_nums = LinuxParser::CpuUtilization();
 prev_user=user;
 prev_nice=nice;
 prev_system=system;
 prev_idle=idle;
 prev_iowait=iowait;
 prev_irq=irq;
 prev_softirq=softirq;
 prev_steal=steal;
 user = stof(mem_nums[0]);
 nice = stof(mem_nums[1]);
 system = stof(mem_nums[2]);
 idle = stof(mem_nums[3]);
 iowait = stof(mem_nums[4]);
 irq = stof(mem_nums[5]);
 softirq = stof(mem_nums[6]);
 steal = stof(mem_nums[7]);
 float Tot_prev_idle,Tot_prev_nonIdle,Tot_idle,Tot_nonIdle,prev_Tot,Tot;
  Tot_prev_idle=prev_idle+prev_iowait;
  Tot_idle = idle+iowait;
  Tot_prev_nonIdle=prev_user+prev_nice+prev_system+prev_irq+prev_softirq+prev_steal;
  Tot_nonIdle = user+nice+system+irq+softirq+steal;
  
  prev_Tot=Tot_prev_idle+Tot_prev_nonIdle;
  Tot=Tot_idle+Tot_nonIdle;
  this->cpu_util=(float)(((Tot-prev_Tot)-(Tot_idle-Tot_prev_idle))/(Tot-prev_Tot));
  return (float)(((Tot-prev_Tot)-(Tot_idle-Tot_prev_idle))/(Tot-prev_Tot));
/*
PrevIdle = previdle + previowait
Idle = idle + iowait
PrevNonIdle = prevuser + prevnice + prevsystem + previrq + prevsoftirq + prevsteal
NonIdle = user + nice + system + irq + softirq + steal

PrevTotal = PrevIdle + PrevNonIdle
Total = Idle + NonIdle

# differentiate: actual value minus the previous one
totald = Total - PrevTotal
idled = Idle - PrevIdle

CPU_Percentage = (totald - idled)/totald
reference  https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
*/
 }