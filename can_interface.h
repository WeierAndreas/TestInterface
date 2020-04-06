#pragma once
#include <stdint.h>
#include <functional>
#include <vector>

class ICan
{
  public:
    enum class MsgType
    {
      NEW_MSG,
      ERROR
    };

    enum class MsgError
    {
      NO_ERROR,
      BIT_FAILURE,
      CHECKSUM_ERROR
    };

    struct CanData
    {
      static constexpr size_t DATA_SIZE = 20;
      std::array<uint8_t, DATA_SIZE> data;
      MsgError error;
    };
    /** regitster a callback funciton which will be called on any new msg*/
    virtual void registerCallback(std::function<void(const CanData&)> onMsgRcv)=0;
    /** blocking read of a can message*/
    virtual CanData read()=0;
    /** send a mesg on the hw interface. This function is blocking*/
    virtual void send(CanData)=0;
        /** simulate an incomming message on every Ican object */
    virtual void simulateIncommingCanMessage()=0;

    virtual ~ICan(){};
};