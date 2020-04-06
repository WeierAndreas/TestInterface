#include <iostream>
#include "can_interface.h"
#include "can.h"
#include <thread> //https://en.cppreference.com/w/cpp/thread/thread/thread
#include <chrono> 
#include <memory>


/**
 * Exercice 1
 * ----------
 * a. sent a can message with a dumy message
 * b. simulate an incomming message every 200ms in the can device.
 * c. every time a new message is incoming a "hello word" should be plotted out. 
 *    Do not implent it in the simulation of the incomming message.
 **/ 


int main() {

 std::unique_ptr<ICan> can0(....);

}
