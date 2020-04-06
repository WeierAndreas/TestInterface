#include <iostream>
#include "can_interface.h"
#include "can.h"
#include <thread> //https://en.cppreference.com/w/cpp/thread/thread/thread
#include <chrono> 
#include <memory>

/**
Exercice 1
----------
Create a can device which receive
**/ 
// on each message received increment a counter of received message and his data type
// create a thread which is responsible to simulate incomming messages every 0.5 seconds 

void onMsgRcv(const ICan::CanData&)
{
  printf("Hello World \n");
}

void simulationThread(ICan* can)
{
  while(true)
  {
    can->simulateIncommingCanMessage();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

int main() {

 std::unique_ptr<ICan> can0(std::make_unique<Can>("/dev/can0"));
 auto aThread = std::thread(simulationThread, can0.get());
 can0->registerCallback(onMsgRcv);
 can0->send({});

 aThread.join();
}
