/* performance-dc-bricklet
 * Copyright (C) 2020-2021 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/bootloader/bootloader.h"

// Default functions
BootloaderHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants

#define PERFORMANCE_DC_DRIVE_MODE_DRIVE_BRAKE 0
#define PERFORMANCE_DC_DRIVE_MODE_DRIVE_COAST 1

#define PERFORMANCE_DC_GPIO_ACTION_NONE 0
#define PERFORMANCE_DC_GPIO_ACTION_NORMAL_STOP_RISING_EDGE 1
#define PERFORMANCE_DC_GPIO_ACTION_NORMAL_STOP_FALLING_EDGE 2
#define PERFORMANCE_DC_GPIO_ACTION_FULL_BRAKE_RISING_EDGE 4
#define PERFORMANCE_DC_GPIO_ACTION_FULL_BRAKE_FALLING_EDGE 8
#define PERFORMANCE_DC_GPIO_ACTION_CALLBACK_RISING_EDGE 16
#define PERFORMANCE_DC_GPIO_ACTION_CALLBACK_FALLING_EDGE 32

#define PERFORMANCE_DC_ERROR_LED_CONFIG_OFF 0
#define PERFORMANCE_DC_ERROR_LED_CONFIG_ON 1
#define PERFORMANCE_DC_ERROR_LED_CONFIG_SHOW_HEARTBEAT 2
#define PERFORMANCE_DC_ERROR_LED_CONFIG_SHOW_ERROR 3

#define PERFORMANCE_DC_CW_LED_CONFIG_OFF 0
#define PERFORMANCE_DC_CW_LED_CONFIG_ON 1
#define PERFORMANCE_DC_CW_LED_CONFIG_SHOW_HEARTBEAT 2
#define PERFORMANCE_DC_CW_LED_CONFIG_SHOW_CW_AS_FORWARD 3
#define PERFORMANCE_DC_CW_LED_CONFIG_SHOW_CW_AS_BACKWARD 4

#define PERFORMANCE_DC_CCW_LED_CONFIG_OFF 0
#define PERFORMANCE_DC_CCW_LED_CONFIG_ON 1
#define PERFORMANCE_DC_CCW_LED_CONFIG_SHOW_HEARTBEAT 2
#define PERFORMANCE_DC_CCW_LED_CONFIG_SHOW_CCW_AS_FORWARD 3
#define PERFORMANCE_DC_CCW_LED_CONFIG_SHOW_CCW_AS_BACKWARD 4

#define PERFORMANCE_DC_GPIO_LED_CONFIG_OFF 0
#define PERFORMANCE_DC_GPIO_LED_CONFIG_ON 1
#define PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_HEARTBEAT 2
#define PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_GPIO_ACTIVE_HIGH 3
#define PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_GPIO_ACTIVE_LOW 4

#define PERFORMANCE_DC_BOOTLOADER_MODE_BOOTLOADER 0
#define PERFORMANCE_DC_BOOTLOADER_MODE_FIRMWARE 1
#define PERFORMANCE_DC_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2
#define PERFORMANCE_DC_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3
#define PERFORMANCE_DC_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

#define PERFORMANCE_DC_BOOTLOADER_STATUS_OK 0
#define PERFORMANCE_DC_BOOTLOADER_STATUS_INVALID_MODE 1
#define PERFORMANCE_DC_BOOTLOADER_STATUS_NO_CHANGE 2
#define PERFORMANCE_DC_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3
#define PERFORMANCE_DC_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4
#define PERFORMANCE_DC_BOOTLOADER_STATUS_CRC_MISMATCH 5

#define PERFORMANCE_DC_STATUS_LED_CONFIG_OFF 0
#define PERFORMANCE_DC_STATUS_LED_CONFIG_ON 1
#define PERFORMANCE_DC_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2
#define PERFORMANCE_DC_STATUS_LED_CONFIG_SHOW_STATUS 3

// Function and callback IDs and structs
#define FID_SET_ENABLED 1
#define FID_GET_ENABLED 2
#define FID_SET_VELOCITY 3
#define FID_GET_VELOCITY 4
#define FID_GET_CURRENT_VELOCITY 5
#define FID_SET_MOTION 6
#define FID_GET_MOTION 7
#define FID_FULL_BRAKE 8
#define FID_SET_DRIVE_MODE 9
#define FID_GET_DRIVE_MODE 10
#define FID_SET_PWM_FREQUENCY 11
#define FID_GET_PWM_FREQUENCY 12
#define FID_GET_POWER_STATISTICS 13
#define FID_SET_THERMAL_SHUTDOWN 14
#define FID_GET_THERMAL_SHUTDOWN 15
#define FID_SET_GPIO_CONFIGURATION 16
#define FID_GET_GPIO_CONFIGURATION 17
#define FID_SET_GPIO_ACTION 18
#define FID_GET_GPIO_ACTION 19
#define FID_GET_GPIO_STATE 20
#define FID_SET_ERROR_LED_CONFIG 21
#define FID_GET_ERROR_LED_CONFIG 22
#define FID_SET_CW_LED_CONFIG 23
#define FID_GET_CW_LED_CONFIG 24
#define FID_SET_CCW_LED_CONFIG 25
#define FID_GET_CCW_LED_CONFIG 26
#define FID_SET_GPIO_LED_CONFIG 27
#define FID_GET_GPIO_LED_CONFIG 28
#define FID_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION 29
#define FID_GET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION 30
#define FID_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION 31
#define FID_GET_VELOCITY_REACHED_CALLBACK_CONFIGURATION 32
#define FID_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION 33
#define FID_GET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION 34

#define FID_CALLBACK_EMERGENCY_SHUTDOWN 35
#define FID_CALLBACK_VELOCITY_REACHED 36
#define FID_CALLBACK_CURRENT_VELOCITY 37
#define FID_CALLBACK_GPIO_STATE 38

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) SetEnabled;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetEnabled;

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) GetEnabled_Response;

typedef struct {
	TFPMessageHeader header;
	int16_t velocity;
} __attribute__((__packed__)) SetVelocity;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetVelocity;

typedef struct {
	TFPMessageHeader header;
	int16_t velocity;
} __attribute__((__packed__)) GetVelocity_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetCurrentVelocity;

typedef struct {
	TFPMessageHeader header;
	int16_t velocity;
} __attribute__((__packed__)) GetCurrentVelocity_Response;

typedef struct {
	TFPMessageHeader header;
	uint16_t acceleration;
	uint16_t deceleration;
} __attribute__((__packed__)) SetMotion;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetMotion;

typedef struct {
	TFPMessageHeader header;
	uint16_t acceleration;
	uint16_t deceleration;
} __attribute__((__packed__)) GetMotion_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) FullBrake;

typedef struct {
	TFPMessageHeader header;
	uint8_t mode;
} __attribute__((__packed__)) SetDriveMode;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetDriveMode;

typedef struct {
	TFPMessageHeader header;
	uint8_t mode;
} __attribute__((__packed__)) GetDriveMode_Response;

typedef struct {
	TFPMessageHeader header;
	uint16_t frequency;
} __attribute__((__packed__)) SetPWMFrequency;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetPWMFrequency;

typedef struct {
	TFPMessageHeader header;
	uint16_t frequency;
} __attribute__((__packed__)) GetPWMFrequency_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetPowerStatistics;

typedef struct {
	TFPMessageHeader header;
	uint16_t voltage;
	uint16_t current;
	int16_t temperature;
} __attribute__((__packed__)) GetPowerStatistics_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t temperature;
} __attribute__((__packed__)) SetThermalShutdown;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetThermalShutdown;

typedef struct {
	TFPMessageHeader header;
	uint8_t temperature;
} __attribute__((__packed__)) GetThermalShutdown_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	uint16_t debounce;
	uint16_t stop_deceleration;
} __attribute__((__packed__)) SetGPIOConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetGPIOConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint16_t debounce;
	uint16_t stop_deceleration;
} __attribute__((__packed__)) GetGPIOConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	uint32_t action;
} __attribute__((__packed__)) SetGPIOAction;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetGPIOAction;

typedef struct {
	TFPMessageHeader header;
	uint32_t action;
} __attribute__((__packed__)) GetGPIOAction_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetGPIOState;

typedef struct {
	TFPMessageHeader header;
	uint8_t gpio_state[1];
} __attribute__((__packed__)) GetGPIOState_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) SetErrorLEDConfig;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetErrorLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) GetErrorLEDConfig_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) SetCWLEDConfig;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetCWLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) GetCWLEDConfig_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) SetCCWLEDConfig;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetCCWLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) GetCCWLEDConfig_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	uint8_t config;
} __attribute__((__packed__)) SetGPIOLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetGPIOLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) GetGPIOLEDConfig_Response;

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) SetEmergencyShutdownCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetEmergencyShutdownCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) GetEmergencyShutdownCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) SetVelocityReachedCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetVelocityReachedCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	bool enabled;
} __attribute__((__packed__)) GetVelocityReachedCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) SetCurrentVelocityCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetCurrentVelocityCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) GetCurrentVelocityCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) EmergencyShutdown_Callback;

typedef struct {
	TFPMessageHeader header;
	int16_t velocity;
} __attribute__((__packed__)) VelocityReached_Callback;

typedef struct {
	TFPMessageHeader header;
	int16_t velocity;
} __attribute__((__packed__)) CurrentVelocity_Callback;

typedef struct {
	TFPMessageHeader header;
	uint8_t gpio_state[1];
} __attribute__((__packed__)) GPIOState_Callback;


// Function prototypes
BootloaderHandleMessageResponse set_enabled(const SetEnabled *data);
BootloaderHandleMessageResponse get_enabled(const GetEnabled *data, GetEnabled_Response *response);
BootloaderHandleMessageResponse set_velocity(const SetVelocity *data);
BootloaderHandleMessageResponse get_velocity(const GetVelocity *data, GetVelocity_Response *response);
BootloaderHandleMessageResponse get_current_velocity(const GetCurrentVelocity *data, GetCurrentVelocity_Response *response);
BootloaderHandleMessageResponse set_motion(const SetMotion *data);
BootloaderHandleMessageResponse get_motion(const GetMotion *data, GetMotion_Response *response);
BootloaderHandleMessageResponse full_brake(const FullBrake *data);
BootloaderHandleMessageResponse set_drive_mode(const SetDriveMode *data);
BootloaderHandleMessageResponse get_drive_mode(const GetDriveMode *data, GetDriveMode_Response *response);
BootloaderHandleMessageResponse set_pwm_frequency(const SetPWMFrequency *data);
BootloaderHandleMessageResponse get_pwm_frequency(const GetPWMFrequency *data, GetPWMFrequency_Response *response);
BootloaderHandleMessageResponse get_power_statistics(const GetPowerStatistics *data, GetPowerStatistics_Response *response);
BootloaderHandleMessageResponse set_thermal_shutdown(const SetThermalShutdown *data);
BootloaderHandleMessageResponse get_thermal_shutdown(const GetThermalShutdown *data, GetThermalShutdown_Response *response);
BootloaderHandleMessageResponse set_gpio_configuration(const SetGPIOConfiguration *data);
BootloaderHandleMessageResponse get_gpio_configuration(const GetGPIOConfiguration *data, GetGPIOConfiguration_Response *response);
BootloaderHandleMessageResponse set_gpio_action(const SetGPIOAction *data);
BootloaderHandleMessageResponse get_gpio_action(const GetGPIOAction *data, GetGPIOAction_Response *response);
BootloaderHandleMessageResponse get_gpio_state(const GetGPIOState *data, GetGPIOState_Response *response);
BootloaderHandleMessageResponse set_error_led_config(const SetErrorLEDConfig *data);
BootloaderHandleMessageResponse get_error_led_config(const GetErrorLEDConfig *data, GetErrorLEDConfig_Response *response);
BootloaderHandleMessageResponse set_cw_led_config(const SetCWLEDConfig *data);
BootloaderHandleMessageResponse get_cw_led_config(const GetCWLEDConfig *data, GetCWLEDConfig_Response *response);
BootloaderHandleMessageResponse set_ccw_led_config(const SetCCWLEDConfig *data);
BootloaderHandleMessageResponse get_ccw_led_config(const GetCCWLEDConfig *data, GetCCWLEDConfig_Response *response);
BootloaderHandleMessageResponse set_gpio_led_config(const SetGPIOLEDConfig *data);
BootloaderHandleMessageResponse get_gpio_led_config(const GetGPIOLEDConfig *data, GetGPIOLEDConfig_Response *response);
BootloaderHandleMessageResponse set_emergency_shutdown_callback_configuration(const SetEmergencyShutdownCallbackConfiguration *data);
BootloaderHandleMessageResponse get_emergency_shutdown_callback_configuration(const GetEmergencyShutdownCallbackConfiguration *data, GetEmergencyShutdownCallbackConfiguration_Response *response);
BootloaderHandleMessageResponse set_velocity_reached_callback_configuration(const SetVelocityReachedCallbackConfiguration *data);
BootloaderHandleMessageResponse get_velocity_reached_callback_configuration(const GetVelocityReachedCallbackConfiguration *data, GetVelocityReachedCallbackConfiguration_Response *response);
BootloaderHandleMessageResponse set_current_velocity_callback_configuration(const SetCurrentVelocityCallbackConfiguration *data);
BootloaderHandleMessageResponse get_current_velocity_callback_configuration(const GetCurrentVelocityCallbackConfiguration *data, GetCurrentVelocityCallbackConfiguration_Response *response);

// Callbacks
bool handle_emergency_shutdown_callback(void);
bool handle_velocity_reached_callback(void);
bool handle_current_velocity_callback(void);
bool handle_gpio_state_callback(void);

#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 4
#define COMMUNICATION_CALLBACK_LIST_INIT \
	handle_emergency_shutdown_callback, \
	handle_velocity_reached_callback, \
	handle_current_velocity_callback, \
	handle_gpio_state_callback, \


#endif
