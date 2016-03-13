/*
 * GPIO_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: 7ossam
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/***********************************************************/
/******************Public Definitions***********************/
/***********************************************************/

/*Comment!: Pin Index values  */
#define GPIO_u8PIN0				0
#define GPIO_u8PIN1				1
#define GPIO_u8PIN2				2
#define GPIO_u8PIN3				3
#define GPIO_u8PIN4				4
#define GPIO_u8PIN5				5
#define GPIO_u8PIN6				6
#define GPIO_u8PIN7				7
#define GPIO_u8PIN8				8
#define GPIO_u8PIN9				9
#define GPIO_u8PIN10			10
#define GPIO_u8PIN11			11
#define GPIO_u8PIN12			12
#define GPIO_u8PIN13			13
#define GPIO_u8PIN14			14
#define GPIO_u8PIN15			15
#define GPIO_u8PIN16			16
#define GPIO_u8PIN17			17
#define GPIO_u8PIN18			18
#define GPIO_u8PIN19			19
#define GPIO_u8PIN20			20
#define GPIO_u8PIN21			21
#define GPIO_u8PIN22			22
#define GPIO_u8PIN23			23
#define GPIO_u8PIN24			24
#define GPIO_u8PIN25			25
#define GPIO_u8PIN26			26
#define GPIO_u8PIN27			27
#define GPIO_u8PIN28			28
#define GPIO_u8PIN29			29
#define GPIO_u8PIN30			30
#define GPIO_u8PIN31			31
#define GPIO_u8PIN32			32
#define GPIO_u8PIN33			33
#define GPIO_u8PIN34			34
#define GPIO_u8PIN35			35
#define GPIO_u8PIN36			36
#define GPIO_u8PIN37			37
#define GPIO_u8PIN38			38
#define GPIO_u8PIN39			39
#define GPIO_u8PIN40			40
#define GPIO_u8PIN41			41
#define GPIO_u8PIN42			42
#define GPIO_u8PIN43			43
#define GPIO_u8PIN44			44
#define GPIO_u8PIN45			45
#define GPIO_u8PIN46			46
#define GPIO_u8PIN47			47
#define GPIO_u8PIN48			48
#define GPIO_u8PIN49			49
#define GPIO_u8PIN50			50
#define GPIO_u8PIN51			51
#define GPIO_u8PIN52			52
#define GPIO_u8PIN53			53
#define GPIO_u8PIN54			54
#define GPIO_u8PIN55			55
#define GPIO_u8PIN56			56
#define GPIO_u8PIN57			57
#define GPIO_u8PIN58			58
#define GPIO_u8PIN59			59
#define GPIO_u8PIN60			60
#define GPIO_u8PIN61			61
#define GPIO_u8PIN62			62
#define GPIO_u8PIN63			63
#define GPIO_u8PIN64			64
#define GPIO_u8PIN65			65
#define GPIO_u8PIN66			66
#define GPIO_u8PIN67			67
#define GPIO_u8PIN68			68
#define GPIO_u8PIN69			69
#define GPIO_u8PIN70			70
#define GPIO_u8PIN71			71
#define GPIO_u8PIN72			72
#define GPIO_u8PIN73			73
#define GPIO_u8PIN74			74
#define GPIO_u8PIN75			75
#define GPIO_u8PIN76			76
#define GPIO_u8PIN77			77
#define GPIO_u8PIN78			78
#define GPIO_u8PIN79			79
#define GPIO_u8PIN80			80
#define GPIO_u8PIN81			81
#define GPIO_u8PIN82			82
#define GPIO_u8PIN83			83
#define GPIO_u8PIN84			84
#define GPIO_u8PIN85			85
#define GPIO_u8PIN86			86
#define GPIO_u8PIN87			87
#define GPIO_u8PIN88			88
#define GPIO_u8PIN89			89
#define GPIO_u8PIN90			90
#define GPIO_u8PIN91			91
#define GPIO_u8PIN92			92
#define GPIO_u8PIN93			93
#define GPIO_u8PIN94			94
#define GPIO_u8PIN95			95
#define GPIO_u8PIN96			96
#define GPIO_u8PIN97			97
#define GPIO_u8PIN98			98
#define GPIO_u8PIN99			99
#define GPIO_u8PIN100			100
#define GPIO_u8PIN101			101
#define GPIO_u8PIN102			102
#define GPIO_u8PIN103			103
#define GPIO_u8PIN104			104
#define GPIO_u8PIN105			105
#define GPIO_u8PIN106			106
#define GPIO_u8PIN107			107
#define GPIO_u8PIN108			108
#define GPIO_u8PIN109			109
#define GPIO_u8PIN110			110
#define GPIO_u8PIN111			111
#define GPIO_u8PIN112			112
#define GPIO_u8PIN113			113
#define GPIO_u8PIN114			114
#define GPIO_u8PIN115			115
#define GPIO_u8PIN116			116
#define GPIO_u8PIN117			117
#define GPIO_u8PIN118			118
#define GPIO_u8PIN119			119
#define GPIO_u8PIN120			120
#define GPIO_u8PIN121			121
#define GPIO_u8PIN122			122
#define GPIO_u8PIN123			123
#define GPIO_u8PIN124			124
#define GPIO_u8PIN125			125
#define GPIO_u8PIN126			126
#define GPIO_u8PIN127			127
#define GPIO_u8PIN128			128
#define GPIO_u8PIN129			129
#define GPIO_u8PIN130			130
#define GPIO_u8PIN131			131
#define GPIO_u8PIN132			132
#define GPIO_u8PIN133			133
#define GPIO_u8PIN134			134
#define GPIO_u8PIN135			135
#define GPIO_u8PIN136			136
#define GPIO_u8PIN137			137
#define GPIO_u8PIN138			138
#define GPIO_u8PIN139			139


/*Comment!: Port Index Values  */
#define GPIO_u8PORTA		0
#define GPIO_u8PORTB		1
#define GPIO_u8PORTC		2
#define GPIO_u8PORTD		3
#define GPIO_u8PORTE		4
#define GPIO_u8PORTF		5
#define GPIO_u8PORTG		6
#define GPIO_u8PORTH		7
#define GPIO_u8PORTI		8


/*Comment!: Digital I/O Value  */
#define GPIO_u8HIGH 		1
#define GPIO_u8LOW 			0

#define GPIO_u16PORTHIGH 			0xFFFF
#define GPIO_u16PORTLOW 			0x0000


/*Comment!: Enable or Disable CLK */
#define GPIO_CLK_DISABLE                		0
#define	GPIO_CLK_ENABLE	                		1

#define GPIO_LOW								0
#define GPIO_HIGH								1

/*Comment!: Modes of Pin */
#define	GPIO_Mode_IN   							00    /*!< GPIO Pin as General Purpose Input */
#define	GPIO_Mode_OUT  							01    /*!< GPIO Pin as General Purpose Output */
#define	GPIO_Mode_AF   							10    /*!< GPIO Pin as Alternate Function */
#define	GPIO_Mode_AN   							11    /*!< GPIO Pin as Analog */

/*Comment!: Types of Pin */
#define	GPIO_OType_PP   						0    /*!< GPIO Output Type Push-Pull */
#define	GPIO_OType_OD   						1    /*!< GPIO Output Type Open-Drain */

/*Comment!: Speed of Pin */
#define	GPIO_Speed_Low    						00    /*!< GPIO Speed Low */
#define	GPIO_Speed_Medium 						01    /*!< GPIO Speed Medium */
#define	GPIO_Speed_Fast   						10    /*!< GPIO Speed Fast */
#define	GPIO_Speed_High   						11    /*!< GPIO Speed High */

/*Comment!: Pull up or Pull down of Pin */
#define	GPIO_PuPd_NOPULL 						00    /*!< No pull resistor */
#define	GPIO_PuPd_UP     						01    /*!< Pull up resistor enabled */
#define	GPIO_PuPd_DOWN   						10    /*!< Pull down resistor enabled */

/*Comment!: Functions of Pin */
#define	GPIO_AFR_Sys 							0000	  /*!< System */
#define	GPIO_AFR_TIM1_To_TIM2     				0001      /*!< Timer1 to Timer2 */
#define	GPIO_AFR_TIM3_To_TIM5   				0010      /*!< Timer3 to Timer5 */
#define	GPIO_AFR_TIM8_To_TIM11					0011	  /*!< Timer8 to Timer11 */
#define	GPIO_AFR_I2C1_To_I2C3					0100	  /*!< I2C to I2C3 */
#define	GPIO_AFR_SPI1_To_SPI6					0101	  /*!< SPI1 to SPI6 */
#define	GPIO_AFR_SPI2_SPI3_SAI1					0110	  /*!< SPI2 to SPI3 and SAI1 */
#define	GPIO_AFR_UART1_To_UART3					0111	  /*!< UART1 to UART3 */
#define	GPIO_AFR_UART4_To_UART8					1000	  /*!< UART4 to UART8 */
#define	GPIO_AFR_CAN1_CAN2_LTCD_TIM12_To_TIM14	1001	  /*!< CAN1 CAN2 LTCD TIM12 To TIM14 */
#define	GPIO_AFR_OTGFS_OTGHS					1010	  /*!< OTG_FS OTG_HS */
#define	GPIO_AFR_ETH							1011	  /*!< ETH */
#define	GPIO_AFR_FMC_SDIO_OTGHS					1100 	  /*!< FMC_SDIO_OTGHS */
#define	GPIO_AFR_DCMI							1101	  /*!< DCMI */
#define	GPIO_AFR_LTCD							1110	  /*!< LTCD */
#define	GPIO_AFR_EVENTOUT						1111	  /*!< EVENTOUT */

/*Comment!: Value of Ports */
#define GPIO_u32PORTINPUT						0x00000000
#define GPIO_u32PORTOUTPUT						0x55555555
#define GPIO_u32PORTALT							0xAAAAAAAA
#define GPIO_u32PORTANALOG						0xFFFFFFFF


#define GPIO_u32PORTPUSHPULL					0x0000
#define GPIO_u32PORTOPENDRAIN					0xFFFF


	/***********************************************************/
	/******************Public Functions*************************/
	/***********************************************************/



	/*Comment!: Initialization */
	extern u8 GPIO_voidInit(u8 Copy_u8PortIdx,u8 Copy_u8ClkStatus);

	/*Comment!: Read Input Pin Value */
	extern u8 GPIO_u8ReadInputDataBit(u8 Copy_u8PinIdx,u16* Copy_u8PtrToVal);

	/*Comment!: Write Input Port Value */
	extern u8 GPIO_u8ReadInputData(u8 Copy_u8PORTIdx,u16* Copy_u8PinVal);

	/*Comment!: Read Output Port Value */
	extern u8 GPIO_ReadOutputDataBit(u8 Copy_u8PortIdx,u16* Copy_u8PtrToVal);

	/*Comment!: Write Output Port Value */
	extern u8 GPIO_u8ReadOutputData(u8 Copy_u8PortIdx,u16* Copy_u8PortVal);

	/*Comment!: Write Pin Val */
	extern u8 GPIO_u8WriteBit(u8 Copy_u8PinIdx,u8 Copy_u8PinVal);

	/*Comment!: Write Port Val */
	extern u8 GPIO_u8WritePort(u8 Copy_u8PortIdx,u16 Copy_u16PortVal);

	/*Comment!: Set Speed Pin*/
	extern u8 GPIO_u8SetBitSpeed(u8 Copy_u8PinIdx, u8 Copy_u8Speed);

	/*Comment!: Lock Port Configuration*/
	extern u8 GPIO_u8LCKRPort(u8 Copy_u8PortIdx);

	/*Comment!: Lock Pin Configuration*/
	extern u8 GPIO_u8LCKRPin(u8 Copy_u8PinIdx);

	/*Comment!: Set Mode Pin*/
	extern u8 GPIO_u8SetPinMode(u8 Copy_u8PinIdx,u8 Copy_u8PinMode);

	/*Comment!: Set Type Pin*/
	extern u8 GPIO_u8SetPinType(u8 Copy_u8PinIdx,u8 Copy_u8PinType);

	/*Comment!: Set Pull up or Pull down Pin*/
	extern u8 GPIO_u8SetPinPUPD(u8 Copy_u8PinIdx,u8 Copy_u8PinPUPD);

	/*Comment!: Set Mode of Port*/
	extern u8 GPIO_u8SetPortMode(u8 Copy_u8PortIdx,u8 Copy_u8PortMode);

	/*Comment!: Set Type Port*/
	extern u8 GPIO_u8SetPortType(u8 Copy_u8PortIdx,u8 Copy_u8PortType);

	/*Comment!: Set Pull up or Pull down Port*/
	extern u8 GPIO_u8SetPortPUPD(u8 Copy_u8PortIdx,u8 Copy_u8PortPUPD);

	/*Comment!: Set Function of Pin*/
	extern u8 GPIO_u8AlternatePin(u8 Copy_u8PinIdx,u16 Copy_u16PinAlternate);

	/*Comment!: Set Reset or Set Pin*/
	extern u8 GPIO_u8SetOrResetPinBSSR(u8 Copy_u8PinIdx,u8 Copy_u8PinBSSR);

#endif /* GPIO_INTERFACE_H_ */
