#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    std::vector<std::string> cpu_parse = LinuxParser::CpuUtilization();
    float user = stof(cpu_parse[0]);
    float nice = stof(cpu_parse[1]);
    float system = stof(cpu_parse[2]);
    float idle = stof(cpu_parse[3]);
    float iowait = stof(cpu_parse[4]);
    float irq = stof(cpu_parse[5]);
    float softirq = stof(cpu_parse[6]);
    float steal = stof(cpu_parse[7]);
    float guest = stof(cpu_parse[8]);
    float guest_nice = stof(cpu_parse[9]);

    //Use the following implementation form https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    float PrevIdle = prevIdle_ + prevIowait_;
    float Idle = idle + iowait;

    float PrevNonIdle = prevUser_ + prevNice_ + prevSystem_ + prevIrq_ + prevSoftirq_ + prevSteal_;
    float NonIdle = user + nice + system + irq + softirq + steal;

    float PrevTotal = PrevIdle + PrevNonIdle;
    float Total = Idle + NonIdle;

    float totald = Total - PrevTotal;
    float idled = Idle - PrevIdle;
    float cpuPercentage = (totald - idled)/totald; //calculate the total cpu percentage
    
    //update previous states
     prevUser_ = user;
     prevNice_ = nice;
     prevSystem_ = system;
     prevIdle_ = idle;
     prevIowait_ = iowait;
     prevIrq_ = irq;
     prevSoftirq_ = softirq;
     prevSteal_ = steal;
     prevGuest_ = guest;
     prevGuest_nice_ = guest_nice;

    return cpuPercentage;

 }