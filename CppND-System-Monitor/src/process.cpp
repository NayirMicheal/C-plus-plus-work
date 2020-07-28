#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return PID_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
  string line;
  vector<string> line1;
  string temp;
  float totaltime;
  float uptime;
  float cpuusage;
  std::ifstream filestream(LinuxParser::kProcDirectory + to_string(PID_) + LinuxParser::kStatFilename);
  if (filestream.is_open()) {
      if(std::getline(filestream, line))
      {
      	std::istringstream linestream(line);
      	for(int i =0;i<22;i++)
        {
            linestream >>temp;
        	line1.push_back(temp);
   	  	}
      }
     uptime=LinuxParser::UpTime() - (stoi(line1[21])/sysconf(_SC_CLK_TCK));
     totaltime=stoi(line1[13])+stoi(line1[14])+stoi(line1[15])+stoi(line1[16]);
     totaltime=totaltime/sysconf(_SC_CLK_TCK);
     if(totaltime!=0)
    {
      cpuusage=((float)totaltime)/((float)uptime);
    }
    else
    {
      return 0;
    }
  }
   cpuUtilization_=cpuusage;
   return cpuUtilization_;
}

// TODO: Return the command that generated this process
string Process::Command() { 
  command_=LinuxParser::Command(Process::Pid());
  return command_; 
}

// TODO: Return this process's memory utilization
string Process::Ram() {
  ram_= LinuxParser::Ram(Process::Pid());
  return ram_; 
}

// TODO: Return the user (name) that generated this process
string Process::User() {
  user_=LinuxParser::User(Process::Pid());
  return user_; 
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
  uptime_=LinuxParser::UpTime(Process::Pid());
  return uptime_;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function

bool Process::operator<(Process const& a) const { 
  return cpuUtilization_ < a.cpuUtilization_; 
}