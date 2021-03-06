/*
 * BootloaderVrsnControl.h
 *
 *  Created on: May 18, 2018
 *      Author: Muhammad S Khan
 */

#ifndef COMPONENTS_BOOTLOADER_SUBPROJECT_MAIN_BOOTLOADERVRSNCONTROL_H_
#define COMPONENTS_BOOTLOADER_SUBPROJECT_MAIN_BOOTLOADERVRSNCONTROL_H_
#include "esp_attr.h"
#include "sdkconfig.h"

#define MOTHER_SHIP_ESP_IDF_VRSN0	24

#define BOOT_LOADER_VERSION			2		//__MK__: updated Jan 11, 2019 // Ota roll-back capabilities

#define MAX_RST_CNT_2_TRIGGER_FACTORY_BOOT	100
#define STRUCT_INTEGRITY_MAGIC_NUM			15

typedef enum{
	RST_RSN_REGULAR = 0,
	INVALID_PARTITION,
	BUTTON_PUSH,
	RST_COUNTER_TRIGGER
}KICK_FACTORY_REASON_TYPE_t;

typedef enum{
	SELF_TEST_SUCCESS = 0,
	SELF_TEST_INIT,
	SELF_TEST_IN_PROGRESS,
	SELF_TEST_FALILED
}SELF_TEST_STATE_t;

typedef struct {
	int RstCnt2TriggerFactory;

	uint8_t StructIntegrityMagic;
	uint8_t RFU_Data2_1;			//factory kick
	uint8_t RFU_Data2_2;
	uint8_t RFU_Data2_3;

	uint8_t RFU_Data3_1; 			//bootloader version no
	uint8_t RFU_Data3_2;
	uint8_t RFU_Data3_3;
	uint8_t RFU_Data3_4;

	uint8_t isSelfTestReq;
	uint8_t RFU_Data4_2;
	uint8_t RFU_Data4_3;
	uint8_t RFU_Data4_4;

} RTC_NO_INIT_DATA_STRUCT_t;

///*Structure size can not be more than what is defined in the linker (16 bytes)*/
//#if sizeof(RTC_NO_INIT_DATA_STRUCT_t) > 16
//#error "Structure size can not be more than what is defined in the linker (16 bytes)"

#define RTC_NO_INIT_DATA_STRUCT	((RTC_NO_INIT_DATA_STRUCT_t *) (0x50000000 + (CONFIG_ULP_COPROC_RESERVE_MEM)))

#endif /* COMPONENTS_BOOTLOADER_SUBPROJECT_MAIN_BOOTLOADERVRSNCONTROL_H_ */
