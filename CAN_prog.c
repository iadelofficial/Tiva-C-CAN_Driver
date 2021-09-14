 /****************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN_program.c
 *
 * Description: source file for the CAN driver program
 *
 * Author: Islam Adel
 *
 * Created on: Sep 10, 2021
 *
 *****************************************************************************/

 #include "CAN_interface.h"
 #include "CAN_config.h"
 #include "CAN_private.h"
/********************************************************************/
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
void Set_BitRate( uint8 CANID,BitRate_Struct_Config*Bit_Rate_Ptr)
{
	if (CANID==CAN0)
	{
		
	     CAN0_BIT=(( Bit_Rate_Ptr->TSEG2 & 0x7) << 12) | ( Bit_Rate_Ptr->TSEG1 &0x0F << 8)| ( Bit_Rate_Ptr->SJW & 0x03 << 6)  | (Bit_Rate_Ptr->BRP & 0x3F);
		
		CAN0_BRPE=(Bit_Rate_Ptr->BRP & 0x3C0) >> 6;
	}
	else if (CANID==CAN1)
	{
		CAN1_BIT=(( Bit_Rate_Ptr->TSEG2 & 0x7) << 12) | ( Bit_Rate_Ptr->TSEG1 &0x0F << 8)| ( Bit_Rate_Ptr->SJW & 0x03 << 6)  | (Bit_Rate_Ptr->BRP & 0x3F);
		
		CAN1_BRPE=(Bit_Rate_Ptr->BRP & 0x3C0) >> 6;
	
	}

}

/*
 * Description :
 * Function responsible for initialize the CAN driver.
 * it takes an input structure that containe 3 members:
 *																											- CANID 	{CAN0,CAN1}
 *																											- MODE		{SILENT_MODE ,LOOPBACK_MODE ,BASIC_MODE}
 *																											- BitRate 
 */
void CAN_Init( const CAN_Struct_Congfig * ConfigPtr,BitRate_Struct_Config*Bit_Rate_Ptr )
{
	/* first thing we should enable CAN clock from RCGC0 register 
	 * because this task i donot write RCC Driver so i will define 
	 * the register her but if we write driver we donot want this comming lines */

	#define RCGC0 *((volatile uint32 *)(0x400FE634))
		/*to enble CAN clock you should set pin 24 for CAN0 and pin 25 for CAN1*/
	if (ConfigPtr->CANID==CAN0)
	{
		/* that mean i wanna enable CAN0*/
		
		/* so i will set pin 24 in RCGC0 register*/
		SET_BIT(RCGC0, 24 );
		/* set init pin in CANCTL register */
		SET_BIT(CAN0_CTL, CAN_CTL_INIT );
		/*******************mode***********/
		if (ConfigPtr->MODE==SILENT_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN0_CTL,CAN_CTL_TEST);
			/* set SILENT bit to enable silent mode */
			SET_BIT(CAN0_STS,CAN_TST_SILENT);

		}
		else if (ConfigPtr->MODE==LOOPBACK_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN0_CTL,CAN_CTL_TEST);
			/* set LOOPBACK bit to enable LOOPBACK mode */
			SET_BIT(CAN0_STS,CAN_TST_LBACK);
		
		}
		else if (ConfigPtr->MODE==BASIC_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN0_CTL,CAN_CTL_TEST);
			/* set BASIC bit to enable BASIC mode */
			SET_BIT(CAN0_STS,CAN_TST_BASIC);
		}

	}
	else if (ConfigPtr->CANID==CAN1)
	{
		/* that mean i wanna enable CAN1*/
		
		/* so i will set pin 25 in RCGC0 register*/
		SET_BIT(RCGC0, 25 );
		/* set init pin in CANCTL register */
		SET_BIT(CAN1_CTL, CAN_CTL_INIT );
		/***************mode***************/
		if (ConfigPtr->MODE==SILENT_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN1_CTL,CAN_CTL_TEST);
			/* set SILENT bit to enable silent mode */
			SET_BIT(CAN1_STS,CAN_TST_SILENT);

		}
		else if (ConfigPtr->MODE==LOOPBACK_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN1_CTL,CAN_CTL_TEST);
			/* set LOOPBACK bit to enable LOOPBACK mode */
			SET_BIT(CAN1_STS,CAN_TST_LBACK);
		
		}
		else if (ConfigPtr->MODE==BASIC_MODE)
		{
			/* Set test bit to enable test mode */
			SET_BIT(CAN1_CTL,CAN_CTL_TEST);
			/* set BASIC bit to enable BASIC mode */
			SET_BIT(CAN1_STS,CAN_TST_BASIC);
		}

		
	}
	Set_BitRate( ConfigPtr->CANID,Bit_Rate_Ptr);
}
/********************************END CAN INITILIZATION******************************/
/*
 * Description :
 * Function responsible for configer transmite message object .
 * it takes 2 inputs:
 *									 1- CANID 	{CAN0,CAN1}
 *									 2-Message object structure that contain :
 *																														1-Message ID 								(MsgID)
 *																														2-Message Number						(MsgObjectNumber)
 *																														4-Messagr ID Extention 			(MsgIDExtension)
 *																														5-Message Length 						(MsgLen)
 *																											 
 */
void CAN_Transmit_SetObject(uint8 CANID,  CAN_Msg_Object*  MsgObject)
{
	/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
	if (CANID==CAN0)
	{
		/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_WRNRD);
		/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_ARB);
		/*Set CONTROL bit to transfer control bits to interface registers */
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_CONTROL);
		/* i should set this bits DATAA ,DATAB to access data */
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_DATAA);
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_DATAB);
		/*Set DIR bit in CANIF1ARB2 to Transmit. When the TXRQST bit in the CANIFnMCTL register is set*/
		SET_BIT(CAN0_IF2ARB2,CAN_IF1ARB2_DIR);
		/* check for 11-bit or 29 bit identifier */
		if (MsgObject->MsgIDExtension)
		{
			/* if messege id extention not equal zero so itis 29-bit identifier */
			/* so i should set XTD bit in CANIFnARB2 register */
			SET_BIT(CAN0_IF1ARB2,CAN_IF1ARB2_XTD);
			CAN0_IF1ARB1|=(MsgObject->MsgID&0xFFFF); 
			CAN0_IF1ARB1|=((MsgObject->MsgID)>>16);
	
		}
		else 
		{
			/* 11-bit identifier */
			/* so i should Clear XTD bit in CANIFnARB2 register */
			CLEAR_BIT(CAN0_IF1ARB2,CAN_IF1ARB2_XTD);
			/*[2:12] in CANIFnARB2*/
			CAN0_IF1ARB2|=((MsgObject->MsgID)>>2);
	
		}
		/* store number of bytes of data */
		CAN0_IF1MCTL|=MsgObject->MsgLen;
		SET_BIT(CAN0_IF1ARB1,CAN_IF1CMSK_WRNRD);
		/* set message number */
		CAN0_IF1CRQ|=MsgObject->MsgObjectNumber;
		
		

	}
	else if (CANID==CAN1)
	{
		/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_WRNRD);
		/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_ARB);
		/*Set CONTROL bit to transfer control bits to interface registers */
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_CONTROL);
		/* i should set this bits DATAA ,DATAB to access data */
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_DATAA);
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_DATAB);
		/*Set DIR bit in CANIF1ARB2 to Transmit. When the TXRQST bit in the CANIFnMCTL register is set*/
		SET_BIT(CAN1_IF2ARB2,CAN_IF1ARB2_DIR);
		/* check for 11-bit or 29 bit identifier */
				
		if (MsgObject->MsgIDExtension)
		{
			/* if messege id extention not equal zero so itis 29-bit identifier */
			/* so i should set XTD bit in CANIFnARB2 register */
			SET_BIT(CAN0_IF1ARB2,CAN_IF1ARB2_XTD);
			CAN1_IF1ARB1|=(MsgObject->MsgID&0xFFFF); 
			CAN1_IF1ARB1|=((MsgObject->MsgID)>>16);
	
		}
		else 
		{
			/* 11-bit identifier */
			/* so i should Clear XTD bit in CANIFnARB2 register */
			CLEAR_BIT(CAN1_IF1ARB2,CAN_IF1ARB2_XTD);
			/*[2:12] in CANIFnARB2*/
			CAN1_IF1ARB2|=((MsgObject->MsgID)>>2);
	
		}
		/* store number of bytes of data */
		CAN1_IF1MCTL|=MsgObject->MsgLen;
		SET_BIT(CAN1_IF1ARB1,CAN_IF1CMSK_WRNRD);
		/* set message number */
		CAN1_IF1CRQ|=MsgObject->MsgObjectNumber;

	}

}
/*******************END SET MESSAGE OBJECT***************************************/
/*
 * Description :
 * Function responsible for configer transmite message object .
 * it takes 3 inputs:
 *									1- CANID 	{CAN0,CAN1}
 *									2- Message Object Number   ** should be from 1 to 32**
 *									3- DATA 
 */
void CAN_Transmit_Object( uint8 CANID , uint8  MsgObjNum, uint8* data_ptr)
{
	if (CANID==CAN0)
	{
		/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_WRNRD);
		/* i should set this bits DATAA ,DATAB to access data */
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_DATAA);
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_DATAB);
		/* enter first 2 bytes in CANIF1DA1 register */
		CAN0_IF1DA1|=data_ptr[0]|(data_ptr[1]>>8);
		/* enter second 2 bytes in CANIF1DA2 register */
		CAN0_IF1DA2|=data_ptr[3]|(data_ptr[4]>>8);
		/* enter third 2 bytes in CANIF1DB1 register */
		CAN0_IF1DB1|=data_ptr[5]|(data_ptr[6]>>8);
		/* enter fourth 2 bytes in CANIF1DB2 register */
		CAN0_IF1DB2|=data_ptr[7]|(data_ptr[8]>>8);
		/*Set message number */
		CAN0_IF1CRQ|=MsgObjNum;
		/* Set TXRQST Bit to request a transmission */
		SET_BIT(CAN0_IF1CMSK,CAN_IF1CMSK_TXRQST);
		
		
	
	}
	else if (CANID==CAN1)
	{
		/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_WRNRD);
		/* i should set this bits DATAA ,DATAB to access data */
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_DATAA);
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_DATAB);		
		/* enter first 2 bytes in CANIF1DA1 register */
		CAN1_IF1DA1|=data_ptr[0]|(data_ptr[1]>>8);
		/* enter second 2 bytes in CANIF1DA2 register */
		CAN1_IF1DA2|=data_ptr[3]|(data_ptr[4]>>8);
		/* enter third 2 bytes in CANIF1DB1 register */
		CAN1_IF1DB1|=data_ptr[5]|(data_ptr[6]>>8);
		/* enter fourth 2 bytes in CANIF1DB2 register */
		CAN1_IF1DB2|=data_ptr[7]|(data_ptr[8]>>8);
		/*Set message number */
		CAN1_IF1CRQ|=MsgObjNum;
		/* Set TXRQST Bit to request a transmission */
		SET_BIT(CAN1_IF1CMSK,CAN_IF1CMSK_TXRQST);

	}

}
/*******************END TRANSMITION OF MESSAGE OBJECT***************************************/
/*
 * Description :
 * Function responsible for configer receive message object .
 * it takes 2 inputs:
 *									 1- CANID 	{CAN0,CAN1}
 *									 2-Message object structure that contain :
 *																														1-Message ID 								(MsgID)
 *																														2-Message Number						(MsgObjectNumber)
 *																														4-Messagr ID Extention 			(MsgIDExtension)
 *																														5-Message Length 						(MsgLen)
 *																											 
 */
void CAN_Receive_SetObject(uint8 CANID, CAN_Msg_Object*  MsgObject)
{
	/* same configration if transmition but for CANIF2CMSK register*/
	/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
	if (CANID==CAN0)
	{
		/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
		SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_WRNRD);
		/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
		SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_ARB);
		/*Set CONTROL bit to transfer control bits to interface registers */
		SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_CONTROL);
		/* i should set this bits DATAA ,DATAB to access data */
		SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_DATAA);
		SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_DATAB);
		/* set  UMASK bit in the CANIFnMCTL register for acceptance filtering*/
		SET_BIT(CAN0_IF2MCTL,CAN_IF2MCTL_UMASK);

		/* check for 11-bit or 29 bit identifier */
		if (MsgObject->MsgIDExtension)
		{
			/* if messege id extention not equal zero so itis 29-bit identifier */
			
			/**********************SET MASK ***************************************/
			/*When using a 29-bit identifier, these bits are used for bits [15:0] of the
			*ID. The MSK field in the CANIFnMSK2 register are used for bits [28:16]
			*of the ID. When using an 11-bit identifier, these bits are ignored.*/
			
			/*When using a 29-bit identifier, these bits are used for bits [28:16] of the
			*ID. The MSK field in the CANIFnMSK1 register are used for bits [15:0]
			*of the ID. When using an 11-bit identifier, MSK[12:2] are used for bits
			*[10:0] of the ID.*/

			CAN0_IF2MSK1|=MsgObject->MsgIDMask & 0xFFFF;/* this mask to make sure that other bits donot change*/
			CAN0_IF2MSK2|=(MsgObject->MsgIDMask>>16)&0x1FFF;
			/*************************SET MESSAGE ID**********************************/
			/* so i should set XTD bit in CANIFnARB2 register */
			SET_BIT(CAN0_IF2ARB2,CAN_IF2ARB2_XTD);
			CAN0_IF2ARB1|=(MsgObject->MsgID&0xFFFF); 
			CAN0_IF2ARB1|=((MsgObject->MsgID)>>16);
			
			
		}
		else 
		{
			/* 11-bit identifier */
			
			/***************************SET MASK ******************************/
			
			/*When using a 29-bit identifier, these bits are used for bits [15:0] of the
			*ID. The MSK field in the CANIFnMSK2 register are used for bits [28:16]
			*of the ID. When using an 11-bit identifier, these bits are ignored.*/
			
			/*When using a 29-bit identifier, these bits are used for bits [28:16] of the
			*ID. The MSK field in the CANIFnMSK1 register are used for bits [15:0]
			*of the ID. When using an 11-bit identifier, MSK[12:2] are used for bits
			*[10:0] of the ID.*/		
			CAN0_IF2MSK2|=(MsgObject->MsgIDMask>>2);
			/*************************SET MESSAGE ID**********************************/
			/* so i should Clear XTD bit in CANIFnARB2 register */
			CLEAR_BIT(CAN0_IF2ARB2,CAN_IF2ARB2_XTD);
			/* adding mwssage id */
			CAN0_IF2ARB2|=((MsgObject->MsgID)>>2);
		}
		/* set MSGVAL bit in CANIF2ARB2 register */
		SET_BIT(CAN0_IF2ARB2,CAN_IF2ARB2_MSGVAL);
		/* set DIR bit CANIF2ARB2 register to receive */
		CLEAR_BIT(CAN0_IF2ARB2,CAN_IF2ARB2_DIR);
		/*set EOB Single message object or last message object of a FIFOBuffer. */
		SET_BIT(CAN0_IF2MCTL,CAN_IF2MCTL_EOB);
		/* store number of bytes of data */
		CAN0_IF2MCTL|=MsgObject->MsgLen;
		/* set message number */
		CAN0_IF2CRQ|=MsgObject->MsgObjectNumber;
		
		

	}
	else if (CANID==CAN1)
	{
			{
			/* Set the bit WRNRD in CANIFnCMASK rgister to write in Message RAM*/
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_WRNRD);
			/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_ARB);
			/*Set CONTROL bit to transfer control bits to interface registers */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_CONTROL);
			/* i should set this bits DATAA ,DATAB to access data */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_DATAA);
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_DATAB);
			/* set  UMASK bit in the CANIFnMCTL register for acceptance filtering*/
			SET_BIT(CAN1_IF2MCTL,CAN_IF2MCTL_UMASK);

			/* check for 11-bit or 29 bit identifier */
			if (MsgObject->MsgIDExtension)
			{
				/* if messege id extention not equal zero so itis 29-bit identifier */
				
				/**********************SET MASK ***************************************/
				/*When using a 29-bit identifier, these bits are used for bits [15:0] of the
				*ID. The MSK field in the CANIFnMSK2 register are used for bits [28:16]
				*of the ID. When using an 11-bit identifier, these bits are ignored.*/
				
				/*When using a 29-bit identifier, these bits are used for bits [28:16] of the
				*ID. The MSK field in the CANIFnMSK1 register are used for bits [15:0]
				*of the ID. When using an 11-bit identifier, MSK[12:2] are used for bits
				*[10:0] of the ID.*/

				CAN1_IF2MSK1|=MsgObject->MsgIDMask & 0xFFFF;/* this mask to make sure that other bits donot change*/
				CAN1_IF2MSK2|=(MsgObject->MsgIDMask>>16)&0x1FFF;
				/*************************SET MESSAGE ID**********************************/
				/* so i should set XTD bit in CANIFnARB2 register */
				SET_BIT(CAN1_IF2ARB2,CAN_IF2ARB2_XTD);
				CAN1_IF2ARB1|=(MsgObject->MsgID&0xFFFF); 
				CAN1_IF2ARB1|=((MsgObject->MsgID)>>16);
				
				
			}
			else 
			{
				/* 11-bit identifier */
				
				/***************************SET MASK ******************************/
				
				/*When using a 29-bit identifier, these bits are used for bits [15:0] of the
				*ID. The MSK field in the CANIFnMSK2 register are used for bits [28:16]
				*of the ID. When using an 11-bit identifier, these bits are ignored.*/
				
				/*When using a 29-bit identifier, these bits are used for bits [28:16] of the
				*ID. The MSK field in the CANIFnMSK1 register are used for bits [15:0]
				*of the ID. When using an 11-bit identifier, MSK[12:2] are used for bits
				*[10:0] of the ID.*/		
				CAN1_IF2MSK2|=(MsgObject->MsgIDMask>>2);
				/*************************SET MESSAGE ID**********************************/
				/* so i should Clear XTD bit in CANIFnARB2 register */
				CLEAR_BIT(CAN1_IF2ARB2,CAN_IF2ARB2_XTD);
				/* adding mwssage id */
				CAN1_IF2ARB2|=((MsgObject->MsgID)>>2);
			}
			/* set MSGVAL bit in CANIF2ARB2 register */
			SET_BIT(CAN1_IF2ARB2,CAN_IF2ARB2_MSGVAL);
			/* set DIR bit CANIF2ARB2 register to receive */
			CLEAR_BIT(CAN1_IF2ARB2,CAN_IF2ARB2_DIR);
			/*set EOB Single message object or last message object of a FIFOBuffer. */
			SET_BIT(CAN1_IF2MCTL,CAN_IF2MCTL_EOB);
			/* store number of bytes of data */
			CAN1_IF2MCTL|=MsgObject->MsgLen;
			/* set message number */
			CAN1_IF2CRQ|=MsgObject->MsgObjectNumber;
			
		}
		
	}

}
/*******************END RECEIVE OF SET MESSAGE OBJECT***************************************/
/*
 * Description :
 * Function responsible for configer transmite message object .
 * it takes 2 inputs:
 *									1- CANID 	{CAN0,CAN1}
 *									2- Message Object Number ** should be from 1 to 32**
 *									
 */
uint8* CAN_Receive_Object( uint8 CANID , uint8 MsgObjNum)
{
	static uint8 Data_Receive[8];
	/* poling to make sure reception is done */
	while (BIT_IS_SET(CAN0_IF2CRQ,CAN_IF2CRQ_BUSY));
	if (CANID==CAN0)
	{
			/* poling to make sure reception is done */
			while (BIT_IS_SET(CAN0_IF2CRQ,CAN_IF2CRQ_BUSY));
			/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
			SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_ARB);
			/*Set CONTROL bit to transfer control bits to interface registers */
			SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_CONTROL);
			/* i should set this bits DATAA ,DATAB to access data */
			SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_DATAA);
			SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_DATAB);
			/*set mask bir in CANIF2CMSK register */
			SET_BIT(CAN0_IF2CMSK,CAN_IF2CMSK_MASK);
			/* set message number */
			CAN0_IF2CRQ|=MsgObjNum;
		
		/* check if NEWDAT bit  is set*/
		if (BIT_IS_SET(CAN0_IF2MCTL,CAN_IF2MCTL_NEWDAT))
		{
			Data_Receive[0] = ( (CAN0_IF2DA1) & 0x00FF);			
      Data_Receive[1] = (( (CAN0_IF2DA1) & 0xFF00) >> 8);
      Data_Receive[2] = ((CAN0_IF2DA2) & 0x00FF);
      Data_Receive[3] = (((CAN0_IF2DA2) & 0xFF00) >> 8);
      Data_Receive[4] = ((CAN0_IF2DB1) & 0x00FF);
      Data_Receive[5] = (((CAN0_IF2DB1) & 0xFF00) >> 8);
      Data_Receive[6] = ((CAN0_IF2DB2) & 0x00FF);
      Data_Receive[7] = (((CAN0_IF2DB2) & 0xFF00) >> 8);
		
		}
		if(BIT_IS_SET(CAN0_IF2MCTL,CAN_IF2MCTL_MSGLST))
		{
			/* Clear MSGLST BIT*/
			CLEAR_BIT(CAN0_IF2MCTL,CAN_IF2MCTL_MSGLST);
		
		}

		
	}
	else if (CANID=CAN1)
	{
		
			/* poling to make sure reception is done */
			while (BIT_IS_SET(CAN1_IF2CRQ,CAN_IF2CRQ_BUSY));
			/*Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_ARB);
			/*Set CONTROL bit to transfer control bits to interface registers */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_CONTROL);
			/* i should set this bits DATAA ,DATAB to access data */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_DATAA);
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_DATAB);
			/*set mask bir in CANIF2CMSK register */
			SET_BIT(CAN1_IF2CMSK,CAN_IF2CMSK_MASK);
			/* set message number */
			CAN1_IF2CRQ|=MsgObjNum;
		
		/* check if NEWDAT bit  is set*/
		if (BIT_IS_SET(CAN1_IF2MCTL,CAN_IF2MCTL_NEWDAT))
		{
			Data_Receive[0] = ( (CAN1_IF2DA1) & 0x00FF);			
      Data_Receive[1] = (( (CAN1_IF2DA1) & 0xFF00) >> 8);
      Data_Receive[2] = ((CAN1_IF2DA2) & 0x00FF);
      Data_Receive[3] = (((CAN1_IF2DA2) & 0xFF00) >> 8);
      Data_Receive[4] = ((CAN1_IF2DB1) & 0x00FF);
      Data_Receive[5] = (((CAN1_IF2DB1) & 0xFF00) >> 8);
      Data_Receive[6] = ((CAN1_IF2DB2) & 0x00FF);
      Data_Receive[7] = (((CAN1_IF2DB2) & 0xFF00) >> 8);
		
		}
		if(BIT_IS_SET(CAN1_IF2MCTL,CAN_IF2MCTL_MSGLST))
		{
			/* Clear MSGLST BIT*/
			CLEAR_BIT(CAN1_IF2MCTL,CAN_IF2MCTL_MSGLST);
		
		}

		
	}
		/* return data */
		return Data_Receive;	
}
int main ()
{
	return 0;
}
