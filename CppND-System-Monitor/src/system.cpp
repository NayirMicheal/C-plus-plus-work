#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() {
  cpu_=Processor();  
  return cpu_; 
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() 
{  
  vector<int> PIDS= LinuxParser::Pids();
  for(auto PID : PIDS)
  {
    processes_.push_back(Process(PID,LinuxParser::User(PID),LinuxParser::Ram(PID)));
  }
  sort(processes_.begin(), processes_.end(),[](const Process & first, const Process & second) { return first < second; }); 
  return processes_;
}  
// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }