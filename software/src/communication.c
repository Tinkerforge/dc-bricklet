/* performance-dc-bricklet
 * Copyright (C) 2020-2021 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/hal/system_timer/system_timer.h"

#include "drv8701.h"
#include "configs/config_drv8701.h"
#include "voltage.h"
#include "configs/config_voltage.h"
#include "gpio.h"
#include "configs/config_gpio.h"

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_SET_ENABLED: return set_enabled(message);
		case FID_GET_ENABLED: return get_enabled(message, response);
		case FID_SET_VELOCITY: return set_velocity(message);
		case FID_GET_VELOCITY: return get_velocity(message, response);
		case FID_GET_CURRENT_VELOCITY: return get_current_velocity(message, response);
		case FID_SET_MOTION: return set_motion(message);
		case FID_GET_MOTION: return get_motion(message, response);
		case FID_FULL_BRAKE: return full_brake(message);
		case FID_SET_DRIVE_MODE: return set_drive_mode(message);
		case FID_GET_DRIVE_MODE: return get_drive_mode(message, response);
		case FID_SET_PWM_FREQUENCY: return set_pwm_frequency(message);
		case FID_GET_PWM_FREQUENCY: return get_pwm_frequency(message, response);
		case FID_GET_POWER_STATISTICS: return get_power_statistics(message, response);
		case FID_SET_THERMAL_SHUTDOWN: return set_thermal_shutdown(message);
		case FID_GET_THERMAL_SHUTDOWN: return get_thermal_shutdown(message, response);
		case FID_SET_GPIO_CONFIGURATION: return set_gpio_configuration(message);
		case FID_GET_GPIO_CONFIGURATION: return get_gpio_configuration(message, response);
		case FID_SET_GPIO_ACTION: return set_gpio_action(message);
		case FID_GET_GPIO_ACTION: return get_gpio_action(message, response);
		case FID_GET_GPIO_STATE: return get_gpio_state(message, response);
		case FID_SET_ERROR_LED_CONFIG: return set_error_led_config(message);
		case FID_GET_ERROR_LED_CONFIG: return get_error_led_config(message, response);
		case FID_SET_CW_LED_CONFIG: return set_cw_led_config(message);
		case FID_GET_CW_LED_CONFIG: return get_cw_led_config(message, response);
		case FID_SET_CCW_LED_CONFIG: return set_ccw_led_config(message);
		case FID_GET_CCW_LED_CONFIG: return get_ccw_led_config(message, response);
		case FID_SET_GPIO_LED_CONFIG: return set_gpio_led_config(message);
		case FID_GET_GPIO_LED_CONFIG: return get_gpio_led_config(message, response);
		case FID_SET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION: return set_emergency_shutdown_callback_configuration(message);
		case FID_GET_EMERGENCY_SHUTDOWN_CALLBACK_CONFIGURATION: return get_emergency_shutdown_callback_configuration(message, response);
		case FID_SET_VELOCITY_REACHED_CALLBACK_CONFIGURATION: return set_velocity_reached_callback_configuration(message);
		case FID_GET_VELOCITY_REACHED_CALLBACK_CONFIGURATION: return get_velocity_reached_callback_configuration(message, response);
		case FID_SET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION: return set_current_velocity_callback_configuration(message);
		case FID_GET_CURRENT_VELOCITY_CALLBACK_CONFIGURATION: return get_current_velocity_callback_configuration(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}


BootloaderHandleMessageResponse set_enabled(const SetEnabled *data) {
	drv8701.enabled = data->enabled;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_enabled(const GetEnabled *data, GetEnabled_Response *response) {
	response->header.length = sizeof(GetEnabled_Response);
	response->enabled       = drv8701.enabled;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_velocity(const SetVelocity *data) {
	drv8701.velocity   = data->velocity;
	drv8701.full_brake = false;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_velocity(const GetVelocity *data, GetVelocity_Response *response) {
	response->header.length = sizeof(GetVelocity_Response);
	response->velocity      = drv8701.velocity;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_current_velocity(const GetCurrentVelocity *data, GetCurrentVelocity_Response *response) {
	response->header.length = sizeof(GetCurrentVelocity_Response);
	response->velocity      = drv8701.velocity_current_high_res/1000;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_motion(const SetMotion *data) {
	drv8701.acceleration = data->acceleration;
	drv8701.deceleration = data->deceleration;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_motion(const GetMotion *data, GetMotion_Response *response) {
	response->header.length = sizeof(GetMotion_Response);
	response->acceleration  = drv8701.acceleration;
	response->deceleration  = drv8701.deceleration;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse full_brake(const FullBrake *data) {
	drv8701.full_brake = true;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse set_drive_mode(const SetDriveMode *data) {
	if(data->mode > PERFORMANCE_DC_DRIVE_MODE_DRIVE_COAST) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	drv8701.drive_mode = data->mode;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_drive_mode(const GetDriveMode *data, GetDriveMode_Response *response) {
	response->header.length = sizeof(GetDriveMode_Response);
	response->mode          = drv8701.drive_mode;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_pwm_frequency(const SetPWMFrequency *data) {
	drv8701.pwm_frequency = data->frequency;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_pwm_frequency(const GetPWMFrequency *data, GetPWMFrequency_Response *response) {
	response->header.length = sizeof(GetPWMFrequency_Response);
	response->frequency     = drv8701.pwm_frequency;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_power_statistics(const GetPowerStatistics *data, GetPowerStatistics_Response *response) {
	response->header.length = sizeof(GetPowerStatistics_Response);
	response->voltage       = voltage.voltage;
	response->current       = voltage.current;
	response->temperature   = voltage.temperature;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_thermal_shutdown(const SetThermalShutdown *data) {
	drv8701.thermal_shutdown_temperature = data->temperature;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_thermal_shutdown(const GetThermalShutdown *data, GetThermalShutdown_Response *response) {
	response->header.length = sizeof(GetThermalShutdown_Response);
	response->temperature   = drv8701.thermal_shutdown_temperature;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_gpio_configuration(const SetGPIOConfiguration *data) {
	if(data->channel >= GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	gpio.debounce[data->channel]          = data->debounce;
	gpio.stop_deceleration[data->channel] = data->stop_deceleration;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_gpio_configuration(const GetGPIOConfiguration *data, GetGPIOConfiguration_Response *response) {
	if(data->channel >= GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->header.length     = sizeof(GetGPIOConfiguration_Response);
	response->debounce          = gpio.debounce[data->channel];
	response->stop_deceleration = gpio.stop_deceleration[data->channel];

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_gpio_action(const SetGPIOAction *data) {
	if(data->channel >= GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	gpio.action[data->channel] = data->action;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_gpio_action(const GetGPIOAction *data, GetGPIOAction_Response *response) {
	if(data->channel >= GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->header.length = sizeof(GetGPIOAction_Response);
	response->action        = gpio.action[data->channel];

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_gpio_state(const GetGPIOState *data, GetGPIOState_Response *response) {
	response->header.length = sizeof(GetGPIOState_Response);
	response->gpio_state[0] = (gpio.last_interrupt_value[0] << 0) | (gpio.last_interrupt_value[1] << 1);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_error_led_config(const SetErrorLEDConfig *data) {
	if(data->config > PERFORMANCE_DC_ERROR_LED_CONFIG_SHOW_ERROR) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	drv8701.error_led_flicker_state.config = data->config;
	switch(data->config) {
		case PERFORMANCE_DC_ERROR_LED_CONFIG_OFF:
			XMC_GPIO_SetOutputHigh(DRV8701_LED_ERROR_PIN);
			break;

		case PERFORMANCE_DC_ERROR_LED_CONFIG_ON:
			XMC_GPIO_SetOutputLow(DRV8701_LED_ERROR_PIN);
			break;

		default: break;
	}
	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_error_led_config(const GetErrorLEDConfig *data, GetErrorLEDConfig_Response *response) {
	response->header.length = sizeof(GetErrorLEDConfig_Response);
	response->config        = drv8701.error_led_flicker_state.config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_cw_led_config(const SetCWLEDConfig *data) {
	if(data->config > PERFORMANCE_DC_CW_LED_CONFIG_SHOW_CW_AS_BACKWARD) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	drv8701.cw_led_flicker_state.config = data->config;
	switch(data->config) {
		case PERFORMANCE_DC_CW_LED_CONFIG_OFF:
			XMC_GPIO_SetOutputHigh(DRV8701_LED_CW_PIN);
			break;

		case PERFORMANCE_DC_CW_LED_CONFIG_ON:
			XMC_GPIO_SetOutputLow(DRV8701_LED_CW_PIN);
			break;

		default: break;
	}

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_cw_led_config(const GetCWLEDConfig *data, GetCWLEDConfig_Response *response) {
	response->header.length = sizeof(GetCWLEDConfig_Response);
	response->config        = drv8701.cw_led_flicker_state.config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_ccw_led_config(const SetCCWLEDConfig *data) {
	if(data->config > PERFORMANCE_DC_CCW_LED_CONFIG_SHOW_CCW_AS_BACKWARD) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	drv8701.ccw_led_flicker_state.config = data->config;
	switch(data->config) {
		case PERFORMANCE_DC_CCW_LED_CONFIG_OFF:
			XMC_GPIO_SetOutputHigh(DRV8701_LED_CCW_PIN);
			break;

		case PERFORMANCE_DC_CCW_LED_CONFIG_ON:
			XMC_GPIO_SetOutputLow(DRV8701_LED_CCW_PIN);
			break;

		default: break;
	}
	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_ccw_led_config(const GetCCWLEDConfig *data, GetCCWLEDConfig_Response *response) {
	response->header.length = sizeof(GetCCWLEDConfig_Response);
	response->config        = drv8701.ccw_led_flicker_state.config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_gpio_led_config(const SetGPIOLEDConfig *data) {
	if(data->config > PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_GPIO_ACTIVE_LOW) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	if(data->channel > GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	gpio.gpio_led_flicker_state[data->channel].config = data->config;
	switch(data->config) {
		case PERFORMANCE_DC_GPIO_LED_CONFIG_OFF:
			if(data->channel == 0) {
				XMC_GPIO_SetOutputHigh(GPIO_0_LED_PIN);
			} else {
				XMC_GPIO_SetOutputHigh(GPIO_1_LED_PIN);
			}
			break;

		case PERFORMANCE_DC_GPIO_LED_CONFIG_ON:
			if(data->channel == 0) {
				XMC_GPIO_SetOutputLow(GPIO_0_LED_PIN);
			} else {
				XMC_GPIO_SetOutputLow(GPIO_1_LED_PIN);
			}
			break;

		case PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_GPIO_ACTIVE_HIGH:
			if(data->channel == 0) {
				if(gpio.last_interrupt_value[0])	{
					XMC_GPIO_SetOutputLow(GPIO_0_LED_PIN);
				} else {
					XMC_GPIO_SetOutputHigh(GPIO_0_LED_PIN);
				}
			} else {
				if(gpio.last_interrupt_value[1])	{
					XMC_GPIO_SetOutputLow(GPIO_1_LED_PIN);
				} else {
					XMC_GPIO_SetOutputHigh(GPIO_1_LED_PIN);
				}
			}
			break;

		case PERFORMANCE_DC_GPIO_LED_CONFIG_SHOW_GPIO_ACTIVE_LOW:
			if(data->channel == 0) {
				if(gpio.last_interrupt_value[0])	{
					XMC_GPIO_SetOutputHigh(GPIO_0_LED_PIN);
				} else {
					XMC_GPIO_SetOutputLow(GPIO_0_LED_PIN);
				}
			} else {
				if(gpio.last_interrupt_value[1])	{
					XMC_GPIO_SetOutputHigh(GPIO_1_LED_PIN);
				} else {
					XMC_GPIO_SetOutputLow(GPIO_1_LED_PIN);
				}
			}
			break;
		default: break;
	}

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_gpio_led_config(const GetGPIOLEDConfig *data, GetGPIOLEDConfig_Response *response) {
	response->header.length = sizeof(GetGPIOLEDConfig_Response);
	if(data->channel > GPIO_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->header.length = sizeof(GetGPIOLEDConfig_Response);
	response->config        = gpio.gpio_led_flicker_state[data->channel].config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}


BootloaderHandleMessageResponse set_emergency_shutdown_callback_configuration(const SetEmergencyShutdownCallbackConfiguration *data) {
	drv8701.cb_emergency_shutdown_enabled = data->enabled;
	drv8701.thermal_shutdown              = false;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_emergency_shutdown_callback_configuration(const GetEmergencyShutdownCallbackConfiguration *data, GetEmergencyShutdownCallbackConfiguration_Response *response) {
	response->header.length = sizeof(GetEmergencyShutdownCallbackConfiguration_Response);
	response->enabled       = drv8701.cb_emergency_shutdown_enabled;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_velocity_reached_callback_configuration(const SetVelocityReachedCallbackConfiguration *data) {
	drv8701.cb_velocity_reached_enabled = data->enabled;
	drv8701.velocity_reached            = false;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_velocity_reached_callback_configuration(const GetVelocityReachedCallbackConfiguration *data, GetVelocityReachedCallbackConfiguration_Response *response) {
	response->header.length = sizeof(GetVelocityReachedCallbackConfiguration_Response);
	response->enabled       = drv8701.cb_velocity_reached_enabled;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_current_velocity_callback_configuration(const SetCurrentVelocityCallbackConfiguration *data) {
	drv8701.cb_curent_velocity_period               = data->period;
	drv8701.cb_current_velocity_value_has_to_change = data->value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_current_velocity_callback_configuration(const GetCurrentVelocityCallbackConfiguration *data, GetCurrentVelocityCallbackConfiguration_Response *response) {
	response->header.length       = sizeof(GetCurrentVelocityCallbackConfiguration_Response);
	response->period              = drv8701.cb_curent_velocity_period;
	response->value_has_to_change = drv8701.cb_current_velocity_value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}


bool handle_emergency_shutdown_callback(void) {
	static bool is_buffered = false;
	static EmergencyShutdown_Callback cb;

	if(!is_buffered) {
		if(drv8701.thermal_shutdown) {
			tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(EmergencyShutdown_Callback), FID_CALLBACK_EMERGENCY_SHUTDOWN);
			drv8701.thermal_shutdown = false;
		} else {
			return false;
		}
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(EmergencyShutdown_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_velocity_reached_callback(void) {
	static bool is_buffered = false;
	static VelocityReached_Callback cb;

	if(!is_buffered) {
		if(drv8701.velocity_reached) {
			tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(VelocityReached_Callback), FID_CALLBACK_VELOCITY_REACHED);
			cb.velocity = drv8701.velocity_current_high_res/1000;
			drv8701.velocity_reached = false;
		} else {
			return false;
		}
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(VelocityReached_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_current_velocity_callback(void) {
	static bool is_buffered = false;
	static CurrentVelocity_Callback cb;
	static uint32_t last_time = 0;
	static int16_t velocity = 0;

	if(!is_buffered) {
		if((drv8701.cb_curent_velocity_period == 0) || !system_timer_is_time_elapsed_ms(last_time, drv8701.cb_curent_velocity_period)) {
			return false;
		}

		const int16_t velocity_current = drv8701.velocity_current_high_res/1000;
		if(drv8701.cb_current_velocity_value_has_to_change && (velocity == velocity_current)) {
			return false;
		}

		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(CurrentVelocity_Callback), FID_CALLBACK_CURRENT_VELOCITY);
		cb.velocity = velocity_current;

		velocity    = velocity_current;
		last_time   = system_timer_get_ms();
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(CurrentVelocity_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_gpio_state_callback(void) {
	static bool is_buffered = false;
	static GPIOState_Callback cb;

	if(!is_buffered) {
		if(!gpio.new_callback) {
			return false;
		}

		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(GPIOState_Callback), FID_CALLBACK_GPIO_STATE);
		cb.gpio_state[0]  = (gpio.last_interrupt_value[0] << 0) | (gpio.last_interrupt_value[1] << 1);
		gpio.new_callback = false;
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(GPIOState_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}


void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	communication_callback_init();
}
