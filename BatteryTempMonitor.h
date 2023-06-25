#ifndef BATTERY_TEMP_H_
#define BATTERY_TEMP_H_ *
#include "Common.h"
#include "AlertMessage.h"
#include <map>
#include <iostream>
#include <memory>

using namespace std;

class BatteryTempMonitor
{
public:
    BatteryTempMonitor();
    virtual ~BatteryTempMonitor() = default;
    void checkAndAlert(
        AlertTarget alertTarget, BatteryModel batteryInfo, double temperatureInC);
    BateryTemp inferBreach(double value, double lowerLimit, double upperLimit);
    void sendMessage(AlertTarget alertTarget, BateryTemp temperature);

private:
    std::map<CoolingType, std::pair<int, int>> m_batteryTemp;
    std::shared_ptr<AlertMessage> m_alertMessage;
};

#endif // BATTERY_TEMP_H_-+