#include "main.h"
#include "config.h"
#include "string.h"

const uint8_t configFlash[1024] __attribute__((section("CFGFLASH"), aligned(0x400)));

Config_t config;

void load_config(void) {
	memcpy(&config, (uint8_t*) configFlash, sizeof(Config_t));
	if (config.flaga5a5 != 0xa5a5) {
		config.flaga5a5 = 0xa5a5;
		config.firmware = FIRMWARE_VER;
		config.addr = 0x2a;
		config.baudrate = 3;
		config.parity = 0;
		config.stopbits = 0;
	}
}

void save_config() {
	uint32_t PageError = 0;				                    //设置PageError,如果出现错误这个变量会被设置为出错的FLASH地址
	FLASH_EraseInitTypeDef flashOperate;
	flashOperate.TypeErase = FLASH_TYPEERASE_PAGES;			//标明Flash执行页面只做擦除操作
	flashOperate.PageAddress = (uint32_t)configFlash;           //声明要擦除的地址
	flashOperate.NbPages = 1;
	HAL_FLASH_Unlock();
	HAL_FLASHEx_Erase(&flashOperate, &PageError);

	uint16_t *p_data = (uint16_t*) &config;
	uint32_t p_flash = (uint32_t)configFlash;
	size_t size = sizeof(Config_t);
	for (int i = 0; i < size; i += 2) {
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, p_flash, *p_data) == HAL_OK) {
			p_flash += 2;
			p_data++;
		} else {
			HAL_FLASH_Lock();
			HAL_NVIC_SystemReset();
		}
	}

	HAL_FLASH_Lock();
}



