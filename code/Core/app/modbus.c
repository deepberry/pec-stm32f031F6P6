#include "main.h"

#include "mb.h"
#include "mbport.h"
#include "config.h"

#define REG_INPUT_START 2000
#define REG_INPUT_NREGS (1)

static USHORT usRegInputStart = REG_INPUT_START;
static USHORT usRegInputBuf[REG_INPUT_NREGS];

void modbusInit(void)
{
  eMBErrorCode eStatus = eMBInit( MB_RTU, config.addr, 3, 19200, MB_PAR_NONE );
  eStatus = eMBEnable();
}

uint32_t dwPolynomial = 0x91;
uint32_t calculate_crc32(uint8_t *buff, int len){
	uint32_t xbit,data,crc;
	crc = 0xffffffff;
	while(len--){
		data = *buff++;
		xbit = 1 << 31;
		for(int bits = 0; bits < 32; bits++){
			if(crc & 0x80000000){
				crc <<= 1;
				crc ^= dwPolynomial;
			}else{
				crc <<= 1;
			}
			if(data & xbit)
				crc ^= dwPolynomial;
			xbit >>=1;
		}
	}
	return crc;
}

eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT _usAddress, USHORT usNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;
    USHORT usAddress = _usAddress - 1;

    if( ( usAddress == REG_INPUT_START )
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
    {
    	extern uint16_t ISRCNT;
    	usRegInputBuf[0] = ISRCNT;
        iRegIndex = ( int )( usAddress - usRegInputStart );
        while( usNRegs > 0 )
        {
            *pucRegBuffer++ =
                ( unsigned char )( usRegInputBuf[iRegIndex] >> 8 );
            *pucRegBuffer++ =
                ( unsigned char )( usRegInputBuf[iRegIndex] & 0xFF );
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT _usAddress, USHORT usNRegs,
                 eMBRegisterMode eMode )
{
	eMBErrorCode    eStatus = MB_ENOERR;
	int             iRegIndex;
	USHORT usAddress = _usAddress - 1;

	if ( MB_REG_READ == eMode ){
		if( ( usAddress >= 0 ) && ( usAddress + usNRegs <= 9 ) )
		{
			uint16_t *pread = (uint16_t *)&config;
			pread += usAddress;
			while( usNRegs > 0 )
			{
				*pucRegBuffer++ =
					( unsigned char )( *pread >> 8 );
				*pucRegBuffer++ =
					( unsigned char )( *pread & 0xFF );
				pread++;
				usNRegs--;
			}
		}else{
			eStatus = MB_ENOREG;
		}
	}else{
//		if( ( usAddress >= 2 ) && ( usAddress + usNRegs <= 9 ) )
//		{
//			uint16_t *pw = (uint16_t *)&config;
//			pw += usAddress;
//			USHORT bkN = usNRegs;
//			while( usNRegs > 0 )
//			{
//				*pw = (uint16_t)((*pucRegBuffer++) << 8) + (uint8_t)(*pucRegBuffer++);
//				pw++;
//				usNRegs--;
//			}
//			save_config();
//			if( (usAddress + bkN >= 9) && (config.restart==0xffff) )
//				HAL_NVIC_SystemReset();
//
//		}else{
			eStatus = MB_ENOREG;
//		}
	}

	return eStatus;
}


eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
               eMBRegisterMode eMode )
{
    return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    return MB_ENOREG;
}

