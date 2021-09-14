 /****************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN_private.h
 *
 * Description: Header file for the CAN driver privacy
 *
 * Author: Islam Adel
 *
 * Created on: Sep 10, 2021
 *
 *****************************************************************************/
#ifndef _CAN_PRIVATE_H
#define _CAN_PRIVATE_H


#include "common_macros.h"
#include "std_types.h"
#include "CAN_interface.h"
/*****************************************************************************
*
*********************defines for can register offset************************** 
*
******************************************************************************/

/*CAN Control*/
#define CANCTL 													0x00000000 
/*CAN Status*/
#define CANSTS 													0x00000004
/*CAN  Error Counter*/
#define CANERR 													0x00000008
/*CAN  Bit Timing */
#define CANBIT 													0x0000000C
/*CAN  Interrupt*/
#define CANINT 													0x00000010
/*CAN  Test*/
#define CANTST 													0x00000014
/*CAN Baud Rate Prescaler Extension*/
#define CANBRPE 												0x00000018
/*CAN  IF1 Command Request*/
#define CANIF1CRQ  											0x00000020
/*CAN IF1 Command Mask*/
#define CANIF1CMSK 											0x00000024 
/*CAN  IF1 Mask 1*/
#define CANIF1MSK1 											0x00000028 
/*CAN  IF1 Mask 2*/
#define CANIF1MSK2  										0x0000002C 
/*CAN  IF1 Arbitration 1*/
#define CANIF1ARB1  										0x00000030 
/*CAN  IF1 Arbitration 2*/
#define CANIF1ARB2  										0x00000034 
/*CAN  IF1 Message Control */
#define CANIF1MCTL 											0x00000038
/*CAN  IF1 Data A1 */
#define CANIF1DA1 											0x0000003C  
/*CAN IF1 Data A2*/
#define CANIF1DA2 											0x00000040 
/*CAN  IF1 Data B1*/
#define CANIF1DB1   										0x00000044
/*CAN  IF1 Data B2*/
#define CANIF1DB2 											0x00000048 
/*CAN  IF2 Command Request*/
#define CANIF2CRQ 											0x00000080 
/*CAN IF2 Command Mask*/
#define CANIF2CMSK 											0x00000084
/*CAN  IF2 Mask 1*/
#define CANIF2MSK1											0x00000088 
/*CAN  IF2 Mask 2*/
#define CANIF2MSK2											0x0000008C  
/*CAN  IF2 Arbitration 1 */
#define CANIF2ARB1 											0x00000090 
/*CAN  IF2 Arbitration 2*/
#define CANIF2ARB2											0x00000094 
/*CAN  IF2 Message Control*/
#define CANIF2MCTL  										0x00000098 
/*CAN  IF2 Data A1 */
#define CANIF2DA1  											0x0000009C 
/*CAN  IF2 Data A2*/
#define CANIF2DA2 											0x000000A0 
/*CAN  IF2 Data B1 */
#define CANIF2DB1  											0x000000A4 
/*CAN  IF2 Data B2*/
#define CANIF2DB2 											0x000000A8 
/*CAN  Transmission Request 1 */
#define CANTXRQ1 												0x00000100 
/*CAN Transmission Request 2 */
#define CANTXRQ2 												0x00000104 
/*CAN ew Data 1*/
#define CANNWDA1 												0x00000120 
/*CAN  New Data 2*/
#define CANNWDA2												0x00000124 
/*CAN  Message 1 Interrupt Pending */
#define CANMSG1INT 											0x00000140 
/*CAN  Message 2 Interrupt Pending*/
#define CANMSG2INT 											0x00000144
/*CAN  Message 1 Valid*/
#define CANMSG1VAL 											0x00000160 
/*CAN  Message 2 Valid*/
#define CANMSG2VAL 											0x00000164 

/**********************************************************************/

/* BASE ADDRESS OF CAN0=  0x40040000 */
#define CAN0_BASE_ADDRESS 0x40040000
/***********************************************************************
*
************************Register Definations****************************
*
*************************************************************************/
#define CAN0_CTL 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANCTL))

#define CAN0_STS 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANSTS))

#define CAN0_ERR 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANERR))
	
#define CAN0_BIT 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANBIT))
	
#define CAN0_INT 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANINT))

#define CAN0_TST 				*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANTST))

#define CAN0_BRPE 			*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANBRPE))
	
#define CAN0_IF1CRQ  		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1CRQ ))
	
#define CAN0_IF1CMSK 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1CMSK))
	
#define CAN0_IF1MSK1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1MSK1))
	
#define CAN0_IF1MSK2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1MSK2))
	
#define CAN0_IF1ARB1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1ARB1))
	
#define CAN0_IF1ARB2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1ARB2))
	
#define CAN0_IF1MCTL 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1MCTL))
	
#define CAN0_IF1DA1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1DA1))
	
#define CAN0_IF1DA2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1DA2))
	
#define CAN0_IF1DB1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1DB1))
	
#define CAN0_IF1DB2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1DB2))
	
#define CAN0_IF2CRQ 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2CRQ))
	
#define CAN0_IF2CMSK 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2CMSK))
	
#define CAN0_IF2MSK1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2MSK1))
	
#define CAN0_IF2MSK2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2MSK2))
	
#define CAN0_IF2ARB1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2ARB1))
	
#define CAN0_IF2ARB2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2ARB2))
	
#define CAN0_IF2MCTL 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2MCTL))
	
#define CAN0_IF2DA1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2DA1))
	
#define CAN0_IF2DA2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2DA2))
	
#define CAN0_IF2DB1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2DB1))
	
#define CAN0_IF2DB2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF2DB2))
	
#define CAN0_TXRQ1 			*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANTXRQ1))
	
#define CAN0_TXRQ2 			*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANTXRQ2))
	
#define CAN0_NWDA1 			*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANNWDA1))
	
#define CAN0_NWDA2 			*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANNWDA2))
	
#define CAN0_MSG1INT 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANMSG1INT))
	
#define CAN0_MSG2INT  	*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANMSG2INT ))
	
#define CAN0_MSG1VAL 	 	*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANMSG1VAL))
	
#define CAN0_MSG2VAL 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANMSG2VAL))
	/**********************************************************************/

/* BASE ADDRESS OF CAN1=  0x40041000 */
#define CAN1_BASE_ADDRESS 0x40041000
/***********************************************************************
*
************************Register Definations****************************
*
*************************************************************************/
#define CAN1_CTL 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANCTL))

#define CAN1_STS 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANSTS))

#define CAN1_ERR 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANERR))
	
#define CAN1_BIT 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANBIT))
	
#define CAN1_INT 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANINT))

#define CAN1_TST 				*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANTST))

#define CAN1_BRPE 			*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANBRPE))
	
#define CAN1_IF1CRQ  		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1CRQ ))
	
#define CAN1_IF1CMSK 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1CMSK))
	
#define CAN1_IF1MSK1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1MSK1))
	
#define CAN1_IF1MSK2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1MSK2))
	
#define CAN1_IF1ARB1 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1ARB1))
	
#define CAN1_IF1ARB2 		*((volatile uint32 *)(CAN0_BASE_ADDRESS+CANIF1ARB2))
	
#define CAN1_IF1MCTL 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1MCTL))
	
#define CAN1_IF1DA1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1DA1))
	
#define CAN1_IF1DA2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1DA2))
	
#define CAN1_IF1DB1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1DB1))
	
#define CAN1_IF1DB2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF1DB2))
	
#define CAN1_IF2CRQ 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2CRQ))
	
#define CAN1_IF2CMSK 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2CMSK))
	
#define CAN1_IF2MSK1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2MSK1))
	
#define CAN1_IF2MSK2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2MSK2))
	
#define CAN1_IF2ARB1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2ARB1))
	
#define CAN1_IF2ARB2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2ARB2))
	
#define CAN1_IF2MCTL 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2MCTL))
	
#define CAN1_IF2DA1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2DA1))
	
#define CAN1_IF2DA2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2DA2))
	
#define CAN1_IF2DB1 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2DB1))
	
#define CAN1_IF2DB2 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANIF2DB2))
	
#define CAN1_TXRQ1 			*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANTXRQ1))
	
#define CAN1_TXRQ2 			*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANTXRQ2))
	
#define CAN1_NWDA1 			*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANNWDA1))
	
#define CAN1_NWDA2 			*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANNWDA2))
	
#define CAN1_MSG1INT 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANMSG1INT))
	
#define CAN1_MSG2INT  	*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANMSG2INT ))
	
#define CAN1_MSG1VAL 	 	*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANMSG1VAL))
	
#define CAN1_MSG2VAL 		*((volatile uint32 *)(CAN1_BASE_ADDRESS+CANMSG2VAL))
/*****************************************************************************
*
************** defines for the bit fields in the CAN_CTL register ************
*
*****************************************************************************/
/*     PIN NAME             PIN NUMBER             */

#define CAN_CTL_INIT            0 				 /* Initialization */
#define CAN_CTL_IE              1  				 /* CAN Interrupt Enable */
#define CAN_CTL_SIE             2  				 /* Status Interrupt Enable */
#define CAN_CTL_EIE             3  				 /* Error Interrupt Enable */
#define CAN_CTL_DAR             5  				 /* Disable Automatic-Retransmission */
#define CAN_CTL_CCE             6 				 /* Configuration Change Enable */
#define CAN_CTL_TEST            7 				 /* Test Mode Enable */

/*****************************************************************************
*
************defines for the bit fields in the CAN_TST register**************
*
******************************************************************************/
/*     PIN NAME             		PIN NUMBER             */
#define CAN_TST_BASIC           2 							 /* Basic Mode*/
#define CAN_TST_SILENT          3 							 /* Silent Mode*/
#define CAN_TST_LBACK           4 							 /* Loopback Mode*/


/*****************************************************************************
*
***********defines for the bit fields in the CAN_IF1CMSK register.***********
*
*****************************************************************************/
/*     PIN NAME             		PIN NUMBER             */
#define CAN_IF1CMSK_WRNRD     		  7  											/* Write, Not Read*/
#define CAN_IF1CMSK_MASK        		6  											/* Access Mask Bits*/
#define CAN_IF1CMSK_ARB         		5 	 										/* Access Arbitration Bits*/
#define CAN_IF1CMSK_CONTROL     		4  											/* Access Control Bits*/
#define CAN_IF1CMSK_CLRINTPND   		3  											/* Clear Interrupt Pending Bit*/
#define CAN_IF1CMSK_NEWDAT      		2  											/* Access New Data*/
#define CAN_IF1CMSK_TXRQST      		2  											/* Access Transmission Request*/
#define CAN_IF1CMSK_DATAA       		1  											/* Access Data Byte 0 to 3*/
#define CAN_IF1CMSK_DATAB       		0  											/* Access Data Byte 4 to 7*/

/*****************************************************************************
*
**********defines for the bit fields in the CAN_IF1ARB2 register************
*
******************************************************************************/
/*     PIN NAME             			PIN NUMBER             */
#define CAN_IF1ARB2_MSGVAL      			15  										/*Message Valid*/
#define CAN_IF1ARB2_XTD         			14  										/* Extended Identifier*/
#define CAN_IF1ARB2_DIR         			13  										/* Message Direction*/
/*****************************************************************************
*
***********defines for the bit fields in the CAN_IF2CMSK register.***********
*
*****************************************************************************/

/*     PIN NAME             		PIN NUMBER             */
#define CAN_IF2CMSK_WRNRD     		  7  											/* Write, Not Read*/
#define CAN_IF2CMSK_MASK        		6  											/* Access Mask Bits*/
#define CAN_IF2CMSK_ARB         		5 	 										/* Access Arbitration Bits*/
#define CAN_IF2CMSK_CONTROL     		4  											/* Access Control Bits*/
#define CAN_IF2CMSK_CLRINTPND   		3  											/* Clear Interrupt Pending Bit*/
#define CAN_IF2CMSK_NEWDAT      		2  											/* Access New Data*/
#define CAN_IF2CMSK_TXRQST      		2  											/* Access Transmission Request*/
#define CAN_IF2CMSK_DATAA       		1  											/* Access Data Byte 0 to 3*/
#define CAN_IF2CMSK_DATAB       		0  											/* Access Data Byte 4 to 7*/
/*****************************************************************************
*
***********defines for the bit fields in the CAN_IF2MCTL register.***********
*
*****************************************************************************/
/*     PIN NAME             		PIN NUMBER             */
#define CAN_IF2MCTL_NEWDAT      		15  						/* New Data*/
#define CAN_IF2MCTL_MSGLST      		14  						/* Message Lost*/
#define CAN_IF2MCTL_INTPND      		13  						/* Interrupt Pending*/
#define CAN_IF2MCTL_UMASK       		12  						/* Use Acceptance Mask*/
#define CAN_IF2MCTL_TXIE        		11  						/* Transmit Interrupt Enable*/
#define CAN_IF2MCTL_RXIE        		10  						/* Receive Interrupt Enable*/
#define CAN_IF2MCTL_RMTEN       		9  							/* Remote Enable*/
#define CAN_IF2MCTL_TXRQST      		8  							/* Transmit Request*/
#define CAN_IF2MCTL_EOB         		7  							/* End of Buffer*/

/*****************************************************************************
*
***********defines for the bit fields in the CAN_IF2ARB2 register************
*
*****************************************************************************/
/*     PIN NAME             		PIN NUMBER             */
#define CAN_IF2ARB2_MSGVAL      		15  					/* Message Valid*/
#define CAN_IF2ARB2_XTD         		14  					/* Extended Identifier*/
#define CAN_IF2ARB2_DIR         		13  					/* Message Direction*/

/*****************************************************************************
*
***********defines for the bit fields in the CAN_O_IF2CRQ register***********
*
*****************************************************************************/
/*     PIN NAME             		PIN NUMBER             */
#define CAN_IF2CRQ_BUSY         15  /* Busy Flag*/

/******************************************************************************
*
*****************************function prototype********************************
*
*******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the CAN BitRate.
 * it takes an input structure that containe 4 members:
 * 																										1-BRP
 * 																										2-SJW
 * 																										3-TSEG1
 * 																										4-TSEG2
 *
 */
void Set_BitRate(uint8 CANID, BitRate_Struct_Config*Bit_Rate_Ptr);

#endif


