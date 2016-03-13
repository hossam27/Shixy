/*
 * ARM_prog.c
 *
 *  Created on: Mar 9, 2016
 *      Author: 7ossam
 */


#include "Conc.h"
#include "util.h"
#include "Types.h"

#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

static volatile u32* const GPIO_u8ModeAddress[GPIO_u8MAXPORTNUM]={GPIOA_MODE,GPIOB_MODE,GPIOC_MODE,GPIOD_MODE
														  ,GPIOE_MODE,GPIOF_MODE,GPIOG_MODE,GPIOH_MODE
														  ,GPIOI_MODE};

static volatile u32* const GPIO_u8TypeAddress[GPIO_u8MAXPORTNUM]={GPIOA_TYPE,GPIOB_TYPE,GPIOC_TYPE,GPIOD_TYPE
															,GPIOE_TYPE,GPIOF_TYPE,GPIOG_TYPE,GPIOH_TYPE
															,GPIOI_TYPE};

static volatile u32* const GPIO_u8SpeedAddress[GPIO_u8MAXPORTNUM]={GPIOA_SPEED,GPIOB_SPEED,GPIOC_SPEED,GPIOD_SPEED
															,GPIOE_SPEED,GPIOF_SPEED,GPIOG_SPEED,GPIOH_SPEED
															,GPIOI_SPEED};

static volatile u32* const GPIO_u8PupdAddress[GPIO_u8MAXPORTNUM]={GPIOA_PUPD,GPIOB_PUPD,GPIOC_PUPD,GPIOD_PUPD
															,GPIOE_PUPD,GPIOF_PUPD,GPIOG_PUPD,GPIOH_PUPD
															,GPIOI_PUPD};

static volatile u32* const GPIO_u8OutputAddress[GPIO_u8MAXPORTNUM]={GPIOA_OUTPUT,GPIOB_OUTPUT,GPIOC_OUTPUT,GPIOD_OUTPUT
															,GPIOE_OUTPUT,GPIOF_OUTPUT,GPIOG_OUTPUT,GPIOH_OUTPUT
															,GPIOI_OUTPUT};

static volatile u32* const GPIO_u8InputAddress[GPIO_u8MAXPORTNUM]={GPIOA_INPUT,GPIOB_INPUT,GPIOC_INPUT,GPIOD_INPUT
															,GPIOE_INPUT,GPIOF_INPUT,GPIOG_INPUT,GPIOH_INPUT
															,GPIOI_INPUT};

static volatile u32* const GPIO_u8BssrAddress[GPIO_u8MAXPORTNUM]={GPIOA_BSRR,GPIOB_BSRR,GPIOC_BSRR,GPIOD_BSRR
															,GPIOE_BSRR,GPIOF_BSRR,GPIOG_BSRR,GPIOH_BSRR
															,GPIOI_BSRR};

static volatile u32* const GPIO_u8LckrAddress[GPIO_u8MAXPORTNUM]={GPIOA_LCKR,GPIOB_LCKR,GPIOC_LCKR,GPIOD_LCKR
															,GPIOE_LCKR,GPIOF_LCKR,GPIOG_LCKR,GPIOH_LCKR
															,GPIOI_LCKR};

static volatile u32* const GPIO_u8AfrAddress[u8TWO][GPIO_u8MAXPORTNUM]={{GPIOA_AFRL,GPIOB_AFRL,GPIOC_AFRL,GPIOD_AFRL
																,GPIOE_AFRL,GPIOF_AFRL,GPIOG_AFRL,GPIOH_AFRL
																,GPIOI_AFRL}
																,{GPIOA_AFRH,GPIOB_AFRH,GPIOC_AFRH,GPIOD_AFRH
																,GPIOE_AFRH,GPIOF_AFRH,GPIOG_AFRH,GPIOH_AFRH
																,GPIOI_AFRH}};

static  const u32 GPIO_u32PortIntiMode[GPIO_u8MAXPORTNUM]={GPIO_u32PORTA_MODE,GPIO_u32PORTB_MODE,GPIO_u32PORTC_MODE,GPIO_u32PORTD_MODE,
									GPIO_u32PORTE_MODE,GPIO_u32PORTF_MODE,GPIO_u32PORTG_MODE,GPIO_u32PORTH_MODE,GPIO_u32PORTI_MODE};

static  const u32 GPIO_u32PortIntiType[GPIO_u8MAXPORTNUM]={GPIO_u32PORTA_TYPE,GPIO_u32PORTB_TYPE,GPIO_u32PORTC_TYPE,GPIO_u32PORTD_TYPE,
									GPIO_u32PORTE_TYPE,GPIO_u32PORTF_TYPE,GPIO_u32PORTG_TYPE,GPIO_u32PORTH_TYPE,GPIO_u32PORTI_TYPE};

static  const u32 GPIO_u32PortIntiSpeed[GPIO_u8MAXPORTNUM]={GPIO_u32PORTA_SPEED,GPIO_u32PORTB_SPEED,GPIO_u32PORTC_SPEED,GPIO_u32PORTD_SPEED,
									GPIO_u32PORTE_SPEED,GPIO_u32PORTF_SPEED,GPIO_u32PORTG_SPEED,GPIO_u32PORTH_SPEED,GPIO_u32PORTI_SPEED};

static  const u32 GPIO_u32PortIntiPupd[GPIO_u8MAXPORTNUM]={GPIO_u32PORTA_PUPD,GPIO_u32PORTB_PUPD,GPIO_u32PORTC_PUPD,GPIO_u32PORTD_PUPD,
									GPIO_u32PORTE_PUPD,GPIO_u32PORTF_PUPD,GPIO_u32PORTG_PUPD,GPIO_u32PORTH_PUPD,GPIO_u32PORTI_PUPD};

static const u32 GPIO_u32PortIntiAfr[u8TWO][GPIO_u8MAXPORTNUM]={{GPIO_u32PORTA_AFRL,GPIO_u32PORTB_AFRL,GPIO_u32PORTC_AFRL,GPIO_u32PORTD_AFRL,
											GPIO_u32PORTE_AFRL,GPIO_u32PORTF_AFRL,GPIO_u32PORTG_AFRL,GPIO_u32PORTH_AFRL,GPIO_u32PORTI_AFRL},
											{GPIO_u32PORTA_AFRH,GPIO_u32PORTB_AFRH,GPIO_u32PORTC_AFRH,GPIO_u32PORTD_AFRH,GPIO_u32PORTE_AFRH,
												GPIO_u32PORTF_AFRH,GPIO_u32PORTG_AFRH,GPIO_u32PORTH_AFRH,GPIO_u32PORTI_AFRH}};

static u32 const GPIO_u32PortVal[u8TWO]={(u32)GPIO_u16PORTLOW,(u32)GPIO_u16PORTHIGH};
static u8 const Local_u8PinSetReset[u8TWO]={u8SIXTEEN,u8ZERO};
static u32 const GPIO_u32PortMode[u8FOUR]={GPIO_u32PORTINPUT,GPIO_u32PORTOUTPUT,GPIO_u32PORTALT,GPIO_u32PORTANALOG};

/*Comment!: Initialization */
extern u8 GPIO_voidInit(u8 Copy_u8PortIdx,u8 Copy_u8ClkStatus)
{
	u8 Local_u8Error=u8OK;
	u8 Local_u8Counter;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Enable CLK for Port */
		 GPIO_u8AssignPortClk(Copy_u8PortIdx,Copy_u8ClkStatus);
		/* Comment!: Set initial value of pin mode */
		 *GPIO_u8ModeAddress[Copy_u8PortIdx] = GPIO_u32PortIntiMode[Copy_u8PortIdx];
		 /* Comment!: Set initial value of pin type */
		 *GPIO_u8TypeAddress[Copy_u8PortIdx] = GPIO_u32PortIntiType[Copy_u8PortIdx];
		 /* Comment!: Set initial value of pin speed */
		 *GPIO_u8SpeedAddress[Copy_u8PortIdx] = GPIO_u32PortIntiSpeed[Copy_u8PortIdx];
		 /* Comment!: Set initial value of pin PUPD */
		 *GPIO_u8PupdAddress[Copy_u8PortIdx] = GPIO_u32PortIntiPupd[Copy_u8PortIdx];
		for(Local_u8Counter=u8ZERO;Local_u8Counter<u8TWO;Local_u8Counter++){
			/* Comment!: Set initial value of pin Function */
			*GPIO_u8AfrAddress[Local_u8Counter][Copy_u8PortIdx]=GPIO_u32PortIntiAfr[Local_u8Counter][Copy_u8PortIdx];
		}
	}
	return Local_u8Error;
}


/*Comment!: Assign Port CLK */
static u8 GPIO_u8AssignPortClk(u8 Copy_u8PortIdx,u8 Copy_u8ClkStatus)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set Clk to Port */
		*RCC_HB1EN|=((*RCC_HB1EN&(~(u32)(Copy_u8ClkStatus<<Copy_u8PortIdx)))|((u32)Copy_u8ClkStatus<<Copy_u8PortIdx));
	}
	return Local_u8Error;

}

	/*Comment!: Read Port Value */
extern u8 GPIO_ReadOutputDataBit(u8 Copy_u8PinIdx,u16* Copy_u16PtrToVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Read output Pin Value */
		*Copy_u16PtrToVal=GETBIT((u16)*GPIO_u8OutputAddress[Local_u8PortNum],Local_u8PinNum);
	}
	return Local_u8Error;
}

extern u8 GPIO_u8ReadInputDataBit(u8 Copy_u8PinIdx,u16* Copy_u16PtrToVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Read Input Pin Value */
		*Copy_u16PtrToVal=GETBIT(*(GPIO_u8InputAddress[Local_u8PortNum]),Local_u8PinNum);
	}
	return Local_u8Error;
}

	/*Comment!: Write Pin Value */
extern u8 GPIO_u8ReadInputData(u8 Copy_u8PortIdx,u16* Copy_u16PtrToVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
		if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
		{
			Local_u8Error=u8ERROR;
		}
		else{
			/* Comment!: Read Input Port Value */
			*Copy_u16PtrToVal=(u16)*(GPIO_u8InputAddress[Copy_u8PortIdx]);
		}
		return Local_u8Error;
}

	/*Comment!: Write Port Value */
extern u8 GPIO_u8ReadOutputData(u8 Copy_u8PortIdx,u16* Copy_u16PortVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Read Output Port Value */
		*Copy_u16PortVal=(u16)*(GPIO_u8OutputAddress[Copy_u8PortIdx]);
	}
	return Local_u8Error;
}

	/*Comment!: Write Pin Direction */
extern u8 GPIO_u8WriteBit(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Write Value to Output Pin */
		/* Comment!: Increase offset to num of shift
		 *  if we want to set bit Local_u8PinSetReset[1]=(+16)
		 *  if we want to reset bit Local_u8PinSetReset[0]=(+0)*/
		*GPIO_u8BssrAddress[Local_u8PortNum]=(*GPIO_u8BssrAddress[Local_u8PortNum])
						|((u32)1<<(Local_u8PinNum+Local_u8PinSetReset[Copy_u8PinVal]));
	//	ASSIGNBIT(*(GPIO_u8OutputAddress[Local_u8PortNum]),Local_u8PinNum,Copy_u8PinVal);
	}

	return Local_u8Error;
}

	/*Comment!: Write Port Direction */
extern u8 GPIO_u8WritePort(u8 Copy_u8PortIdx,u16 Copy_u16PortVal)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Write Value to Output Port */
		*GPIO_u8OutputAddress[Copy_u8PortIdx]=GPIO_u32PortVal[Copy_u16PortVal];
	}

	return Local_u8Error;
}


extern u8 GPIO_u8LCKRPort(u8 Copy_u8PortIdx)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set Lock port */
		/* Comment!: Set one in bit 16 */
		*GPIO_u8LckrAddress[Copy_u8PortIdx]=((u32)1<<GPIO_u8PORTLCKBIT);
	}
	return Local_u8Error;
}

extern u8 GPIO_u8LCKRPin(u8 Copy_u8PinIdx)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set Lock Pin */
		*GPIO_u8LckrAddress[Local_u8PortNum]=(*GPIO_u8LckrAddress[Local_u8PortNum]
		                                     &(~((u32)1<<Local_u8PinNum)))
		                                     |((u32)1<<Local_u8PinNum);
	}
	return Local_u8Error;
}

extern u8 GPIO_u8AlternatePin(u8 Copy_u8PinIdx,u16 Copy_u16PinAlternate)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8AFRPIN;
	/* Comment!: To know if Pin in low range(0->7) or High range(8->15) */
	u8 Local_u8PinHighOrLow=((Copy_u8PinIdx%GPIO_u8PORTSIZE)/GPIO_u8AFRPIN);
	/* Comment!: Convert Alternate 4-bit value to binary*/
	u8 Local_u8PinAlternate=((Copy_u16PinAlternate/u16THOUSAND)*u8EIGHT)
							+(((Copy_u16PinAlternate%u16THOUSAND)/u8HANDRED)*u8FOUR)
							+((((Copy_u16PinAlternate%u16THOUSAND)%u8HANDRED)/u8TEN)*u8TWO)
							+((((Copy_u16PinAlternate%u16THOUSAND)%u8HANDRED)%u8TEN));
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
	/* Comment!: Set value of Alternate to Pin */
		*GPIO_u8AfrAddress[Local_u8PinHighOrLow][Local_u8PortNum]=(*GPIO_u8AfrAddress[Local_u8PinHighOrLow][Local_u8PortNum]
		                                                          &(~((u32)GPIO_u8FIFTEEN<<(Local_u8PinNum*GPIO_u8FOURBITOFFSET))))
																  |((u32)Local_u8PinAlternate<<(Local_u8PinNum*GPIO_u8FOURBITOFFSET));
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetBitSpeed(u8 Copy_u8PinIdx, u8 Copy_u8Speed)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	u8 Local_u8Speed=(((u8)(Copy_u8Speed/u8TEN))*u8TWO)+(Copy_u8Speed%u8TEN);
	//u8 Local_u8Speed=GETBIT(Copy_u8Speed,u8ZERO)+(GETBIT(Copy_u8Speed,u8ONE)*u8TWO);
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Speed to Pin */
		*GPIO_u8SpeedAddress[Local_u8PortNum]=(*GPIO_u8SpeedAddress[Local_u8PortNum]
		                                     &(~((u32)GPIO_u8THREE<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET))))
												|((u32)Local_u8Speed<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET));
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetPinMode(u8 Copy_u8PinIdx,u8 Copy_u8PinMode)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	//u8 Local_u8PinMode=GETBIT(Copy_u8PinMode,u8ZERO)+(GETBIT(Copy_u8PinMode,u8ONE)*u8TWO);
	u8 Local_u8PinMode=(((u8)(Copy_u8PinMode/u8TEN))*u8TWO)+(Copy_u8PinMode%u8TEN);
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Mode to Pin */
		*GPIO_u8ModeAddress[Local_u8PortNum]=(*GPIO_u8ModeAddress[Local_u8PortNum]
		                                     &(~(u32)(GPIO_u8THREE<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET))))
											|((u32)Local_u8PinMode<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET));
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetPinType(u8 Copy_u8PinIdx,u8 Copy_u8PinType)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Convert Type 2-bit value to binary*/
	u8 Local_u8PinType=(((u8)(Copy_u8PinType/u8TEN))*u8TWO)+(Copy_u8PinType%u8TEN);
	//u8 Local_u8PinType=GETBIT(Copy_u8PinType,u8ZERO)+(GETBIT(Copy_u8PinType,u8ONE)*u8TWO);
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Type to Pin */
		*GPIO_u8TypeAddress[Local_u8PortNum]=((*GPIO_u8TypeAddress[Local_u8PortNum]
		                                    &(~((u32)1<<(Local_u8PinNum))))
										|((u32)Local_u8PinType<<(Local_u8PinNum)));
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetPinPUPD(u8 Copy_u8PinIdx,u8 Copy_u8PinPUPD)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	//u8 Local_u8PinPUPD=GETBIT(Copy_u8PinPUPD,u8ZERO)+(GETBIT(Copy_u8PinPUPD,u8ONE)*u8TWO);
	u8 Local_u8PinPUPD=(((u8)(Copy_u8PinPUPD/u8TEN))*u8TWO)+(Copy_u8PinPUPD%u8TEN);
	/* Comment!: Check if Pin num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Pupd to Pin */
		*GPIO_u8PupdAddress[Local_u8PortNum]=(*GPIO_u8PupdAddress[Local_u8PortNum]
		                                     &(~((u32)GPIO_u8THREE<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET))))
		                                     |((u32)Local_u8PinPUPD<<(Local_u8PinNum*GPIO_u8TWOBITOFFSET));
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetPortMode(u8 Copy_u8PortIdx,u8 Copy_u8PortMode)
{
	u8 Local_u8Error=u8OK;
//	u8 Local_u8PortMode=GETBIT(Copy_u8PortMode,u8ZERO)+(GETBIT(Copy_u8PortMode,u8ONE)*u8TWO);
	u8 Local_u8PortMode=(((u8)(Copy_u8PortMode/u8TEN))*u8TWO)+(Copy_u8PortMode%u8TEN);
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Mode to Port */
		*GPIO_u8ModeAddress[Copy_u8PortIdx]=GPIO_u32PortMode[Local_u8PortMode];
	}
	return Local_u8Error;
}

extern u8 GPIO_u8SetPortType(u8 Copy_u8PortIdx,u8 Copy_u8PortType)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Type to Port */
		*GPIO_u8TypeAddress[Copy_u8PortIdx]=GPIO_u32PortVal[Copy_u8PortType];
	}
	return Local_u8Error;
}
extern u8 GPIO_u8SetPortPUPD(u8 Copy_u8PortIdx,u8 Copy_u8PortPUPD)
{
	u8 Local_u8Error=u8OK;
	//u8 Local_u8PortPUPD=GETBIT(Copy_u8PortPUPD,u8ZERO)+(GETBIT(Copy_u8PortPUPD,u8ONE)*u8TWO);
	u8 Local_u8PortPUPD=(((u8)(Copy_u8PortPUPD/u8TEN))*u8TWO)+(Copy_u8PortPUPD%u8TEN);
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PortIdx>=GPIO_u8MAXPORTNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Set value of Pupd to Port */
		*GPIO_u8PupdAddress[Copy_u8PortIdx]=GPIO_u32PortMode[Local_u8PortPUPD];
	}
	return Local_u8Error;
}
extern u8 GPIO_u8SetOrResetPinBSSR(u8 Copy_u8PinIdx,u8 Copy_u8PinBSSR)
{
	u8 Local_u8Error=u8OK;
	/* Comment!: Get num of Port */
	u8 Local_u8PortNum=(u8)(Copy_u8PinIdx/GPIO_u8PORTSIZE);
	/* Comment!: Get num of Pin Per Port */
	u8 Local_u8PinNum=Copy_u8PinIdx%GPIO_u8PORTSIZE;
	/* Comment!: Check if Port num in Range */
	if(Copy_u8PinIdx>=GPIO_u8MAXPINNUM)
	{
		Local_u8Error=u8ERROR;
	}
	else{
		/* Comment!: Write Value to Output Pin */
		/* Comment!: Increase offset to num of shift
		*  if we want to set bit Local_u8PinSetReset[1]=(+16)
		*  if we want to reset bit Local_u8PinSetReset[0]=(+0)*/
		*GPIO_u8BssrAddress[Local_u8PortNum]=(*GPIO_u8BssrAddress[Local_u8PortNum])
				|((u32)1<<(Local_u8PinNum+Local_u8PinSetReset[Copy_u8PinBSSR]));
	}
	return Local_u8Error;
}
