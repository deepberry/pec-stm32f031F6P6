#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define FIRMWARE_VER 1

typedef struct {
	uint16_t flaga5a5;
	uint16_t firmware;
	uint16_t addr;
	uint16_t baudrate;
	uint16_t parity;
	uint16_t stopbits;
	uint16_t user1;
	uint16_t user2;
	uint16_t restart;
} Config_t;

extern Config_t config;

void load_config();
void save_config();

#endif /* APP_CONFIG_H_ */
