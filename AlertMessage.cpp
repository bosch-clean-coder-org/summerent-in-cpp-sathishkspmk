#include "AlertMessage.h"

AlertMessage::AlertMessage()
{
    m_batteryTemp[TOO_LOW] = "Hi, the temperature is too Low";
    m_batteryTemp[TOO_HIGH] = "Hi, the temperature is too High";
    m_batteryTemp[NORMAL] = "Hi, the temperature is Normal";
}

void AlertMessage::sendToController(BateryTemp temperature)
{
    const unsigned short header = 0xfeed;
    std::cout << header << ":" << temperature << std::endl;
}

void AlertMessage::sendToEmail(BateryTemp temperature)
{
    const char *recepient = "a.b@c.com";
    std::cout << "To: " << recepient << std::endl;
    std::cout << m_batteryTemp[temperature] << std::endl;
}