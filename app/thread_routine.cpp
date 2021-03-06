/*
 * thread_routine.cpp
 */

#include <iostream>
#include <cstdio>
#include "core.h"
#include "firmware.hpp"


#include <thread>
#include <chrono>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigusr1(int sig) {
  printf("Received SIGUSR1...\n");
}

void child_function(void) {
  signal(SIGUSR1, handle_sigusr1);
  bemesh::main_routine(NULL);
  while(true) {
    printf("Im still alive!\n");
    wait(nullptr);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main(int argc, char** argv) {
  int pid = fork();
  if(pid) {
    child_function();
  } else {
    for(int i=0;i<5;++i) {
      std::this_thread::sleep_for(std::chrono::seconds(2));
      kill(pid, SIGUSR1);
    }
    wait(nullptr);
    return 0;
  }
}

