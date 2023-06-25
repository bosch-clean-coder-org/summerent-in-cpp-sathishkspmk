#ifndef COMMON_H_
#define COMMON_H_

/*PASSIVE TEMPERAURE*/
constexpr auto PASSIVE_TEMP_LOW = 0;
constexpr auto PASSIVE_TEMP_HIGH = 30;
/*MEDIUM Level TEMPERAURE*/
constexpr auto MEDIUM_TEMP_LOW = 0;
constexpr auto MEDIUM_TEMP_HIGH = 40;
/*High Level TEMPERAURE*/
constexpr auto HI_TEMP_LOW = 0;
constexpr auto HI_TEMP_HIGH = 45;

typedef enum
{
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING

} CoolingType;

typedef enum
{
    NORMAL,
    TOO_LOW,
    TOO_HIGH
} BateryTemp;

typedef enum
{
    TO_CONTROLLER,
    TO_EMAIL
} AlertTarget;

typedef struct
{
    CoolingType coolingType;
    char brand[48];
} BatteryModel;

#endif // COMMON_H_
