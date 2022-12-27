#include "gtest/gtest.h"
#include <csignal>

namespace
{
  volatile std::sig_atomic_t gSignalStatus;
}
 
void signal_handler(int signal)
{
  std::cout<<"Above test case generated SegFault. Revisit the Sources"<<std::endl;
  gSignalStatus = signal;
  sleep(5);
}

int main(int argc, char **argv) {
  std::signal(SIGSEGV, signal_handler);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}