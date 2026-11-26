/**
 * crtp_supervisor_sitl.c - crtp_supervisor without its CRTP port handler.
 *
 * shortcut: CRTP_PORT_SUPERVISOR (0x09) collides with CRTP_PORT_SETPOINT_SIM in SITL, so the
 * supervisor port is not served; emergency stop still works through the deprecated
 * platform/localization paths. Upgrade once the simulator port moves off 0x09.
 */
#include <stdbool.h>
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "crtp_supervisor.h"

static bool isEmergencyStopRequested = false;
static uint32_t emergencyStopWatchdogNotificationTick = 0;

void crtpSupervisorInit(void) {}

void crtpSupervisorSetEmergencyStop(void) {
  isEmergencyStopRequested = true;
}

void crtpSupervisorNotifyEmergencyStopWatchdog(void) {
  emergencyStopWatchdogNotificationTick = xTaskGetTickCount();
}

bool crtpSupervisorIsEmergencyStopRequested(void) {
  return isEmergencyStopRequested;
}

uint32_t crtpSupervisorGetEmergencyStopWatchdogNotificationTick(void) {
  return emergencyStopWatchdogNotificationTick;
}
