/*
 Copyright 2019 Claroworks

 written by Mike Wilson mail4mikew@gmail.com

 This file is part of an application designed to work with VESC firmware,
 and is intended for use with special use vehicles.

 This firmware is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This firmware is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
 Additional Copyright 2021 Benjamin Woodill bwoodill@gmail.com
 */

#ifndef APPLICATIONS_DIVEX_DEFAULTS_H_
#define APPLICATIONS_DIVEX_DEFAULTS_H_

#define USE_SAFETY_SPEED 0

// trigger timing values used for click timing
#define TRIG_ON_TOUT_MS 400			// click timeout when trigger is on
#define TRIG_OFF_TOUT_MS 500		// click timeout when trigger is off

// speed when user goes on trigger the first time
#define SPEED_DEFAULT 3

// ERPM PROGRAMMED SPEED - Optimized for Flipsky 7070/110kv (7-pole motor, max 40000 ERPM)
// Scaling: 65A max sustained, 40000 ERPM max
// Conservative speeds to ensure safe operation and thermal management
#define SPEEDS1 1200  // ~12% power, very slow startup
#define SPEEDS2 1800  // ~18% power, light cruising
#define SPEEDS3 2400  // ~24% power, moderate speed
#define SPEEDS4 3000  // ~30% power, medium speed
#define SPEEDS5 3600  // ~36% power, faster cruising
#define SPEEDS6 4500  // ~45% power, high speed
#define SPEEDS7 5400  // ~54% power, very high speed
#define SPEEDS8 6300  // ~63% power, near maximum
#define SPEEDS9 7000  // ~70% power, maximum safe speed

// CURRENT LIMIT PER PROGRAMMED SPEED - Flipsky 7070/110kv optimized
// Motor resistance: 0.055Ω, max 65A sustained
// Conservative current limits with progressive increase
#define LIMITS1 2.0   // 2.0A - minimal power draw
#define LIMITS2 3.5   // 3.5A - light load
#define LIMITS3 5.5   // 5.5A - light-medium load
#define LIMITS4 8.0   // 8.0A - medium load
#define LIMITS5 11.5  // 11.5A - medium-high load
#define LIMITS6 17.0  // 17.0A - high load
#define LIMITS7 28.0  // 28.0A - very high load
#define LIMITS8 45.0  // 45.0A - near maximum
#define LIMITS9 60.0  // 60.0A - maximum safe sustained

// BATTERY DISPLAY (PER DISPLAYED BAR) - Standard 48V configuration
#define DISP_BATT_VOLT1	34.0  // 1 bar threshold
#define DISP_BATT_VOLT2	36.0  // 2 bar threshold
#define DISP_BATT_VOLT3	38.0  // 3 bar threshold

// SPEED RAMPING - Time to ramp between speed settings
// 1500 ERPM/second = ~0.25 seconds per speed level
#define SPEED_RAMPING_RATE 1500

// Migration rate - Time for speed to drift back to default when trigger released
#define MIGRATE_SPEED_MILLISECONDS 5000

// SAFETY SPEED SETTINGS - For underwater obstacle detection
// Flipsky 7070/110kv typical current draw in water: 2-6A
#define SAFETY_SPEED_GUARD_HIGH 6.0   // Amps. Currents above indicate obstruction
#define SAFETY_SPEED_GUARD_LOW  0.5   // Amps. Currents below indicate out-of-water
#define SAFETY_SPEED_BI_LIMIT   0.30  // Amps. Battery current limit while in guard mode
#define SAFETY_SPEED_ERPM       900   // Running ERPM in guard mode (~9% of max)
#define SAFETY_SPEED_MAX_ERPM   1500  // Maximum ERPM in guard mode when unblocked (~3.75% of max)

// Safety detection counters (at 20Hz = 50ms per count)
#define RUNNING_SAFE_OK_CT 50   // 2.5 seconds to confirm safe running
#define RUNNING_SAFE_FAIL_CT  5  // 250ms to detect obstruction
#define SAFETY_FILTER_ALPHA 0.2  // Low-pass filter alpha for current smoothing

// DISPLAY SETTINGS
#define DISP_BRIGHTNESS 6           // 0 to 15 (Max)
#define DISP_ROTATION 0             // 0 to 3 - for fixing differences in display hardware
#define DISP_POWER_ON_OFFTIME 10000 // after power on - milliseconds until display stops
#define DISP_OFF_TRIGGER_BEG_MS 3000    // after OFF-TRIGGER, begin display - time for battery to settle
#define DISP_OFF_TRIG_DURATION_MS 6000  // after OFF-TRIGGER, leave the display on for this time period
#define DISP_ON_TRIGGER_SPEED_MS 3500   // after ON-TRIGGER, time that speed is shown

// BATTERY IMBALANCE - Dual battery system monitoring
#define BATTERY_MAX_IMBALANCE 2.0   // Volts that batteries are allowed to be different
#define BATTERY2_SENSE_RATIO 14     // Ratio of voltage divider resistors (141K to 10K)

// LOGGING - Debugging output control
#define LOGGING_OFF 0

// OPTIONAL FEATURES
#define CRUISE 0        // Cruise control mode
#define JUMP 0          // Jump speed feature (quick acceleration)
#define JUMP_SPEED 6    // Speed level for jump feature
#define LOW_MIGRATE 0   // Allow migration below default speed
#define REVERSE 0       // Reverse motor control

#endif /* APPLICATIONS_DIVEX_DEFAULTS_H_ */
