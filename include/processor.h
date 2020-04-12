#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  float prevUser_{0},prevNice_{0},prevSystem_{0},prevIdle_{0},prevIowait_{0},prevIrq_{0},prevSoftirq_{0},prevSteal_{0},prevGuest_{0},prevGuest_nice_{0};
};

#endif