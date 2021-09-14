 /****************************************************************************
 *
 * Module: CAN
 *
 * File Name: CAN_interface.h
 *
 * Description: Header file for the CAN driver interface
 *
 * Author: Islam Adel
 *
 * Created on: Sep 10, 2021
 *
 *****************************************************************************/
#ifndef _CAN_INTERFACE_H
#define _CAN_INTERFACE_H

#include "common_macros.h"
#include "std_types.h"

/* MACROS for CANID */
#define CAN0   		0
#define CAN1 			1

/*MACROS FOR CAN MODES*/

#define SILENT_MODE     0
#define LOOPBACK_MODE   1
#define BASIC_MODE      2
/* bit rate configration */
/* it just for make user configer bit ratr by him self it is fault to do this but iam sorry */
typedef struct{
	uint8 BRP;
	uint8 SJW;
	uint8 TSEG1;
	uint8 TSEG2;
}BitRate_Struct_Config;
/* CAN structure */  
typedef struct{
  uint8 	CANID  ; 
  uint8   MODE   ;
  uint32  BitRate;
}CAN_Struct_Congfig;
/* Message object structure*/
typedef struct{
  uint32 MsgID;
  uint8  MsgObjectNumber;
  uint8  MsgIDExtension ;
  uint8  MsgLen;
	uint32 MsgIDMask;
}CAN_Msg_Object;
/******************************************************************************
*
*****************************function prototype********************************
*
*******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the CAN driver.
 * it takes an input structure that containe 3 members:
 *																											- CANID 	{CAN0,CAN1}
 *																											- MODE		{SILENT_MODE ,LOOPBACK_MODE ,BASIC_MODE}
 *																											- BitRate 
 *																											- BitRate Configration " this input just for config BitRate by user"
 */
void CAN_Init( const CAN_Struct_Congfig * ConfigPtr,BitRate_Struct_Config*Bit_Rate_Ptr );
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
 
void CAN_Transmit_SetObject(uint8 CANID,  CAN_Msg_Object*  MsgObject);
/*
 * Description :
 * Function responsible for configer transmite message object .
 * it takes 3 inputs:
 *									1- CANID 	{CAN0,CAN1}
 *									2- Message Object Number ** should be from 1 to 32**
 *									3- DATA 
 */
void CAN_Transmit_Object( uint8 CANID , uint8  MsgObjNum, uint8* data_ptr);
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
void CAN_Receive_SetObject(uint8 CANID, CAN_Msg_Object*  MsgObject);
/*
 * Description :
 * Function responsible for configer transmite message object .
 * it takes 2 inputs:
 *									1- CANID 	{CAN0,CAN1}
 *									2- Message Object Number ** should be from 1 to 32**
 *									3- DATA 
 */
uint8* CAN_Receive_Object( uint8 CANID , uint8 MsgObjNum);



#endif
