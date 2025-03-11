/*
 * usb.h
 *
 *  Created on: Mar 4, 2025
 *      Author: siva
 */

#ifndef SRC_USB_H_
#define SRC_USB_H_


/* private Multi-File Global Variables declaration------------------------*/
extern uint8_t USB_u8_rx_data;
extern bool USB_RX_Cmplt_Flag;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart3;



/*private Multi-File Global Function prototypes---------------------------*/
extern void USB_Init(void);
extern void USB_data_tx(void);
extern void USB_data_reception_mode(void);
extern void USB_data_rx_process(void);







#endif /* SRC_USB_H_ */
