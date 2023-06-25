#include "BatteryTempMonitor.h"
#include <utility>

using namespace std;

BatteryTempMonitor::BatteryTempMonitor()
    : m_alertMessage(std::make_shared<AlertMessage>())
{
    m_batteryTemp[PASSIVE_COOLING] = std::make_pair(PASSIVE_TEMP_LOW, PASSIVE_TEMP_HIGH);
    m_batteryTemp[MED_ACTIVE_COOLING] = std::make_pair(MEDIUM_TEMP_LOW, MEDIUM_TEMP_HIGH);
    m_batteryTemp[HI_ACTIVE_COOLING] = std::make_pair(HI_TEMP_LOW, HI_TEMP_HIGH);
}

BateryTemp BatteryTempMonitor::inferBreach(double value, double lowerLimit, double upperLimit)
{
    BateryTemp temperature = NORMAL;

    if (value < lowerLimit)
    {
        temperature = TOO_LOW;
    }
    if (value > upperLimit)
    {
        temperature = TOO_HIGH;
    }

    return temperature;
}

void BatteryTempMonitor::checkAndAlert(
    AlertTarget alertTarget, BatteryModel batteryInfo, double temperatureInC)
{
    int tempLow = 0, tempHigh = 0;

    tempLow = m_batteryTemp[batteryInfo.coolingType].first;
    tempHigh = m_batteryTemp[batteryInfo.coolingType].second;

    BateryTemp temperature = inferBreach(temperatureInC, tempLow, tempHigh);
    sendMessage(alertTarget, temperature);
}

void BatteryTempMonitor::sendMessage(AlertTarget alertTarget, BateryTemp temperature)
{
    switch (alertTarget)
    {
    case TO_CONTROLLER:
        m_alertMessage->sendToController(temperature);
        break;
    case TO_EMAIL:
        m_alertMessage->sendToEmail(temperature);
        break;
    }
}