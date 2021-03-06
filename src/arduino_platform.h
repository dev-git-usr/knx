#include "knx/platform.h"

#include "Arduino.h"

extern Stream& _serialDBG;

class ArduinoPlatform : public Platform
{
  public:
    ArduinoPlatform(HardwareSerial* knxSerial);

    // basic stuff
    void fatalError();

    //uart
    virtual void knxUart( HardwareSerial* serial);
    virtual HardwareSerial* knxUart();
    virtual void setupUart();
    virtual void closeUart();
    virtual int uartAvailable();
    virtual size_t writeUart(const uint8_t data);
    virtual size_t writeUart(const uint8_t* buffer, size_t size);
    virtual int readUart();
    virtual size_t readBytesUart(uint8_t* buffer, size_t length);

    //spi
    void setupSpi() override;
    void closeSpi() override;
    int readWriteSpi (uint8_t *data, size_t len) override;

    static Stream* SerialDebug;

  protected:
    HardwareSerial* _knxSerial;
};
