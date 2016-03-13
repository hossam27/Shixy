#ifndef _CONC_H_
#define _CONC_H_

#define CONC32(A31,A30,A29,A28,A27,A26,A25,A24		\
			,A23,A22,A21,A20,A19,A18,A17,A16		\
			,A15,A14,A13,A12,A11,A10,A9 ,A8			\
			,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			CONC_HELP32(A31,A30,A29,A28,A27,A26,A25,A24		\
																 ,A23,A22,A21,A20,A19,A18,A17,A16		\
																 ,A15,A14,A13,A12,A11,A10,A9 ,A8		\
																 ,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 )
#define CONC_HELP32(A31,A30,A29,A28,A27,A26,A25,A24	\
			     ,A23,A22,A21,A20,A19,A18,A17,A16	\
			     ,A15,A14,A13,A12,A11,A10,A9 ,A8	\
			     ,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			(0b##A31##A30##A29##A28##A27##A26##A25##A24    \
															   ##A23##A22##A21##A20##A19##A18##A17##A16    \
															   ##A15##A14##A13##A12##A11##A10##A9 ##A8     \
															   ##A7 ##A6 ##A5 ##A4 ##A3 ##A2 ##A1 ##A0 )

#define CONC16(A15,A14,A13,A12,A11,A10,A9 ,A8			\
			  ,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			CONC_HELP16(A15,A14,A13,A12,A11,A10,A9 ,A8		\
																 	   ,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 )
#define CONC_HELP16(A15,A14,A13,A12,A11,A10,A9 ,A8	\
			       ,A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			(0b##A15##A14##A13##A12##A11##A10##A9 ##A8     \
															       ##A7 ##A6 ##A5 ##A4 ##A3 ##A2 ##A1 ##A0 )

#define CONC8(A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			CONC_HELP8(A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 )
#define CONC_HELP8(A7 ,A6 ,A5 ,A4 ,A3 ,A2 ,A1 ,A0 ) 			(0b##A7 ##A6 ##A5 ##A4 ##A3 ##A2 ##A1 ##A0 )

#endif
