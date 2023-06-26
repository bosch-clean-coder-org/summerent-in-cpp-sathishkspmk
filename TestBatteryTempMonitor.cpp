#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BatteryTempMonitor.h"

TEST_CASE("Battery temperature Low")
{
  BatteryTempMonitor tempMonitor;
  REQUIRE(tempMonitor.inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("Battery temperature Medium")
{
  BatteryTempMonitor tempMonitor;
  REQUIRE(tempMonitor.inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("Battery temperature High")
{
  BatteryTempMonitor tempMonitor;
  REQUIRE(tempMonitor.inferBreach(45, 20, 30) == TOO_HIGH);
}

TEST_CASE("Send Message to Controller")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = PASSIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 10);
}

TEST_CASE("Passive type Low Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = PASSIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 10);
}

TEST_CASE("Passive type High Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = PASSIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 50);
}

TEST_CASE("MED type Low Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = MED_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 5);
}

TEST_CASE("MED type High Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = MED_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 50);
}

TEST_CASE("HI type Low Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = HI_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 5);
}

TEST_CASE("HI type High Temperature")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = HI_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_CONTROLLER, model, 50);
}

TEST_CASE("HI type Low Temperature send to Mail")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = HI_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_EMAIL, model, 5);
}

TEST_CASE("HI type High Temperature send to Mail")
{
  BatteryTempMonitor tempMonitor;
  BatteryModel model;
  model.coolingType = HI_ACTIVE_COOLING;
  tempMonitor.checkAndAlert(TO_EMAIL, model, 50);
}
