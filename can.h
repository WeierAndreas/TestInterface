#pragma once
#include "can_interface.h"

class Can : public ICan
{
  public:
  /***/
    Can(std::string deviceName);
    ~Can();
    void registerCallback(std::function<void(const CanData&)> onMsgRcv)override;
    CanData read()override;
    void send(CanData)override;
    void simulateIncommingCanMessage()override;

  private:
    std::string mDevName;
};

