#ifndef ALERT_MESSAGE_H_
#define ALERT_MESSAGE_H_

#include "Common.h"
#include <string>
#include <memory>
#include <map>
#include <iostream>

using namespace std;

class AlertMessage
{
public:
    AlertMessage();
    virtual ~AlertMessage() = default;
    void sendToController(BateryTemp temperature);
    void sendToEmail(BateryTemp temperature);

private:
    std::map<BateryTemp, string> m_batteryTemp;
};

#endif // ALERT_MESSAGE_H_