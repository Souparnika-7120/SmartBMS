#ifndef VCU_H
#define VCU_H

#include "battery.h"
enum DriveCommand{
    DRIVE_DISABLED,
    DRIVE_LIMITED,
    DRIVE_ENABLED
};
DriveCommand determineDriveCommand(
    BMSState state
);

const char* driveCommandToString(
    DriveCommand command
);

int determineTorqueRequest(
    DriveCommand command
);

#endif