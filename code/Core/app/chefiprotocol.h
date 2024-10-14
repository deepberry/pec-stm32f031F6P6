#ifndef CHEFIPROTOCOL_H
#define CHEFIPROTOCOL_H

#include <stdint.h>

enum {
  CHEFI_ACK = 						0x22,
  CHEFI_CMD_SERIAL =                0x40, // passes commands for cmdSerial
  CHEFI_CMD_PAIR =                  0x44,
  CHEFI_CMD_SET_SAMPLING_TIME =     0x50,
  CHEFI_CMD_BLINK_LED =             0x51,
  CHEFI_CMD_CALIBRATE =             0x52,
  CHEFI_CMD_SET_RADIO_POWER_LOW =   0x53,
  CHEFI_CMD_SET_RADIO_POWER_HIGH =  0x54,
  CHEFI_CMD_RESET_NODE_CONFIG =     0x55,
  CHEFI_CMD_SET_RADIO_POWER_AUTO =  0x56,
  CHEFI_CMD_UNPAIR =                0x66,
  CHEFI_CMD_UNPAIR_SIGROW =         0xEE,
};

enum {
  MSG_SCOTA_ACK =       			2, // ACK for SCotA node
  MSG_SCOTA_FORWARD =               3, // commands for SCotA
  MSG_SCOTA_RESPONSE =       		4, // response for SCotA
  MSG_MEASUREMENT_AIR =             11,
  MSG_MEASUREMENT_SOIL =            12,
  MSG_MEASUREMENT_AIR_CO2 =         13,
  MSG_MEASUREMENT_SCALES4 =         14, // old HW, B07 board + external board + lot of wires, 2x AA battery
  MSG_MEASUREMENT_COMBI =           15,
  MSG_MEASUREMENT_WATERMELON =      16,
  MSG_MEASUREMENT_SPECTRO =         18,
  MSG_MEASUREMENT_SOIL_SERIAL =    	22,
  MSG_MEASUREMENT_SCALES4_BOARD =   24, // new HW, Scales 1.2C board, 1x 18650 battery
  MSG_MEASUREMENT_SCALES4_HIGH_BOARD =   25, // new HW, Scales 1.2C board, 1x 18650 battery, 100kg load cells
  MSG_MEASUREMENT_DRY_LEAF =    	40,
  MSG_MEASUREMENT_PIXEL = 			51,
  MSG_MEASUREMENT_DEBUG =           67,
  MSG_MEASUREMENT_RADIOMETER =      72,
  MSG_MEASUREMENT_AIR_PLUS_NIGHT = 	110, // runs the fan also when PAR=0 and when PAR<100
  MSG_MEASUREMENT_WATERLEMON_DEBUG = 212, // waterlemon ADC voltage upload, 3 channels
  MSG_MEASUREMENT_SOIL_SERIAL_CALIB = 220, // soil mini in calibration chamber (PAR calibration)
  MSG_MEASUREMENT_CNR4 = 240,
};

enum {
  WEIGHT_UNAVAILABLE =  0,
  WEIGHT_MAX =          +32768,
  WEIGHT_MIN =          -32767, // negative values allowed
  WEIGHT_MAX_HIGH =     +2147483648, // high load scales
  WEIGHT_MIN_HIGH =     -2147483647, // negative values allowed
};

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
} msg_header_t;

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	uint16_t ir;
} msg_air_t;

_Static_assert(sizeof(msg_air_t) == 20, "msg_air_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	uint16_t ir;
	int16_t pixel_ambient_temp;
	int16_t pixel_object1_temp;
	int16_t pixel_object2_temp;
} msg_pixel_t;

_Static_assert(sizeof(msg_pixel_t) == 26, "msg_pixel_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	uint16_t co2;
} msg_air_co2_t;

_Static_assert(sizeof(msg_air_co2_t) == 20, "msg_air_co2_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	uint16_t leaf_free1;
	int16_t leaf_temp;
	uint16_t leaf_free2;

} msg_dry_leaf_t;

_Static_assert(sizeof(msg_dry_leaf_t) == 24, "msg_dry_leaf_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	uint16_t soil_hum;
	int16_t soil_temp;
	uint16_t soil_ec;
} msg_soil_t;

_Static_assert(sizeof(msg_soil_t) == 24, "msg_soil_t size mismatch");

typedef struct __attribute__ ((packed))
{
  uint16_t msg_type;
  uint16_t central_id;
  uint16_t remote_id;
  uint16_t batt;
  int16_t rssi;
  uint16_t tsample;
  uint16_t par;
  int16_t temp;
  int16_t weight[4];
  int16_t soil_temp;
  uint16_t wlevel;
} msg_scales4_t;

_Static_assert(sizeof(msg_scales4_t) == 28, "msg_scales4_t size mismatch");

typedef struct __attribute__ ((packed))
{
  uint16_t msg_type;
  uint16_t central_id;
  uint16_t remote_id;
  uint16_t batt;
  int16_t rssi;
  uint16_t tsample;
  uint16_t par;
  int16_t temp;
  int32_t weight[4];
  int16_t soil_temp;
  uint16_t wlevel;

} msg_scales4_high_t;

_Static_assert(sizeof(msg_scales4_high_t) == 36, "msg_scales4_high_t size mismatch");

typedef struct __attribute__ ((packed))
{
  uint16_t msg_type;
  uint16_t central_id;
  uint16_t remote_id;
  uint16_t batt;
  int16_t rssi;
  uint16_t tsample;
  uint16_t par; // not in use
  int16_t temp;	// cpu temperature
  int16_t cnr4_microvolts[4]; // CNR4 analog voltage in uV
  int16_t soil_temp; // not used
  uint16_t wlevel; // not used
} msg_cnr4_t;

_Static_assert(sizeof(msg_cnr4_t) == 28, "msg_cnr4_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	uint16_t par;
	int16_t temp;
	uint16_t humid;
	int16_t rad_top;
	uint16_t gnd_ref;
	uint16_t adc_ref;
} msg_radiometer_t;

_Static_assert(sizeof(msg_radiometer_t) == 24, "msg_radiometer_t size mismatch");

//typedef struct __attribute__ ((packed))
//{
//	uint16_t msg_type;
//	uint16_t central_id;
//	uint16_t remote_id;
//	uint16_t batt;
//	int16_t rssi;
//	uint16_t tsample;
//	uint16_t par;
//	int16_t temp;
//	uint16_t humid;
//	uint16_t ir;
//} msg_air_plus_night_t;
//
//_Static_assert(sizeof(msg_air_plus_night_t) == 20, "msg_air_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t msg_type;
	uint16_t central_id;
	uint16_t remote_id;
	uint16_t batt;
	int16_t rssi;
	uint16_t tsample;
	int16_t temp;
	uint16_t humid;
	uint16_t spectro[18];
	uint16_t co2;
} msg_spectro_t;

_Static_assert(sizeof(msg_spectro_t) == 54, "msg_spectro_t size mismatch");

typedef struct __attribute__ ((packed))
{
	uint16_t remote_id;
	uint16_t central_id;
	uint16_t command;
} msg_res_header_t;

_Static_assert(sizeof(msg_res_header_t) == 6, "msg_res_header_t size mismatch");

enum {
  MSG_TYPE_DEEPBERRY_SOIL =       			2000,
};

#endif
