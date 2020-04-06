#include "can.h"
#include <unistd.h>
#include <functional>

  static std::vector<std::function<void(const Can::CanData&)>> cbks;
  constexpr int DELAY_s = 1;

  Can::Can(std::string deviceName)
  {
    mDevName = deviceName;
  }

    /** regitster a callback funciton which will be called on any new msg*/
  void Can::registerCallback(std::function<void(const Can::CanData&)> onMsgRcv)
  {
    cbks.push_back(onMsgRcv);
    printf("registered %s\n", mDevName.c_str());
  }

  Can::CanData Can::read()
  {
    sleep(DELAY_s);
    printf("read out %s\n", mDevName.c_str());
    return CanData{};
  }

  void Can::send(Can::CanData)
  {
    sleep(DELAY_s);
    printf("sent out %s\n", mDevName.c_str());
  }


  void Can::simulateIncommingCanMessage()
  {
    constexpr auto msg = ICan::MsgError::NO_ERROR;
    constexpr ICan::CanData dumyData{{1,2,3,4},msg};
    
    for (auto& cbk : cbks)
    {
      cbk(dumyData);
    }
  }

Can::~Can(){};