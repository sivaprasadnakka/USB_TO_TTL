/*
 * usb.c
 *
 *  Created on: Mar 4, 2025
 *      Author: siva
 */

/* Private includes ---------------------------------------------------------*/
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "common.h"
#include "usb.h"

/* private variables declarations----------------------------------------------*/
uint8_t USB_u8_rx_data;
uint8_t USB_u8aa_tx_buff[10];
uint8_t USB_u8aa_rx_buff[10];
uint8_t USB_RX_cnt;
bool USB_RX_Cmplt_Flag;

/* private function prototypes-------------------------------------------------*/
void USB_Init(void);
void USB_data_reception_mode(void);
void USB_data_tx(void);
void USB_data_rx_process(void);

/* private user code-----------------------------------------------------------*/
/**
  * @brief USB Initializations
  */
void USB_Init(void)
{
	HAL_UART_Receive_IT(&huart3, &USB_u8_rx_data, BYTE_1);
}

/**
  * @brief data transmission
  */
void USB_data_tx(void)
{
	USB_u8aa_tx_buff[0] = 0xAA;
	USB_u8aa_tx_buff[9] = 0xBB;
	HAL_UART_Transmit_IT(&huart3, USB_u8aa_tx_buff, 10);
}


/**
  * @brief data Reception Mode
  */
void USB_data_reception_mode(void)
{
	/* Clear RX Buffer */
	memset(USB_u8aa_rx_buff, CLEAR, 10);
	/* setup USART1 to rx callback after Rxbyte_length(1 byte) */
	HAL_UART_Receive_IT(&huart3, &USB_u8_rx_data, BYTE_1);
}


/**
  * @brief data Reception process  */

void USB_data_rx_process(void)
{
	if(USB_RX_cnt < 10)
	{
		USB_u8aa_rx_buff[USB_RX_cnt] = USB_u8_rx_data;
		USB_RX_cnt++;
		if(USB_u8aa_rx_buff[9]== 0xDD)
		{
			USB_RX_Cmplt_Flag = TRUE;
			USB_RX_cnt = 0;
		}
	}
	else
	{
		USB_RX_cnt = CLEAR;
	}
}
