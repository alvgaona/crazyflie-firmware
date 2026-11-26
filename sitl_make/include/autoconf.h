// SITL has no Kconfig run: every CONFIG_* stays undefined, i.e. Kconfig defaults that are "n".
#pragma once

// Non-bool Kconfig options used by core modules (Kconfig defaults).
#define CONFIG_SUPERVISOR_CRASH_DETECTION_G 0
