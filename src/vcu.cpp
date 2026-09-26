#include "vcu.h"

DriveCommand determineDriveCommand(
    BMSState state
){
    switch(state){
        case NORMAL:
           return DRIVE_ENABLED;
        case WARNING:
           return DRIVE_LIMITED;
        case RECOVERY:
           return DRIVE_LIMITED;
        case FAULT:
           return DRIVE_DISABLED;
        case INIT:
           return DRIVE_DISABLED;
        default:
           return DRIVE_DISABLED;
    }
}

const char* driveCommandToString(
    DriveCommand command
){
    switch(command){
        case DRIVE_ENABLED:
           return "DRIVE ENABLED";
        case DRIVE_LIMITED:
           return "DRIVE LIMITED";
        case DRIVE_DISABLED:
           return "DRIVE DISABLED";
        default:
           return "UNKNOWN";
    }
}

int determineTorqueRequest(
    DriveCommand command
){
    switch(command){
        case DRIVE_ENABLED:
           return 100;
        case DRIVE_LIMITED:
           return 50;
        case DRIVE_DISABLED:
           return 0;
        default:
           return 0;
    }
}