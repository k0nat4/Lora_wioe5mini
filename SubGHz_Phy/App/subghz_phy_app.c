/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    subghz_phy_app.c
  * @author  MCD Application Team
  * @brief   Application of the SubGHz_Phy Middleware
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "platform.h"
#include "sys_app.h"
#include "subghz_phy_app.h"
#include "radio.h"

/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"

/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

#define RF_FREQUENCY 925010203

#define TX_OUTPUT_POWER 22
#define LORA_BANDWIDTH 2 // 0:125khz;1:250khz;2:500khz;3:reserved
#define LORA_SPREADING_FACTOR 7
#define LORA_CODINGRATE                             1         // [1: 4/5,
//  2: 4/6,
//  3: 4/7,
//  4: 4/8]
#define LORA_PREAMBLE_LENGTH                        8         // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT                         5         // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON	false
#define LORA_CRC_ON true
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* Radio events function pointer */
static RadioEvents_t RadioEvents;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/*!
 * @brief Function to be executed on Radio Tx Done event
 */
static void OnTxDone(void);

/**
  * @brief Function to be executed on Radio Rx Done event
  * @param  payload ptr of buffer received
  * @param  size buffer size
  * @param  rssi
  * @param  LoraSnr_FskCfo
  */
static void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t LoraSnr_FskCfo);

/**
  * @brief Function executed on Radio Tx Timeout event
  */
static void OnTxTimeout(void);

/**
  * @brief Function executed on Radio Rx Timeout event
  */
static void OnRxTimeout(void);

/**
  * @brief Function executed on Radio Rx Error event
  */
static void OnRxError(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Exported functions ---------------------------------------------------------*/
void SubghzApp_Init(void)
{
  /* USER CODE BEGIN SubghzApp_Init_1 */

  /* USER CODE END SubghzApp_Init_1 */

  /* Radio initialization */
  RadioEvents.TxDone = OnTxDone;
  RadioEvents.RxDone = OnRxDone;
  RadioEvents.TxTimeout = OnTxTimeout;
  RadioEvents.RxTimeout = OnRxTimeout;
  RadioEvents.RxError = OnRxError;

  Radio.Init(&RadioEvents);

  /* USER CODE BEGIN SubghzApp_Init_2 */
  Radio.SetChannel(RF_FREQUENCY);

  Radio.SetTxConfig(
      MODEM_LORA,
      TX_OUTPUT_POWER, // dBm
      0,  // only for fsk
      LORA_BANDWIDTH,
      LORA_SPREADING_FACTOR,
      LORA_CODINGRATE,
	  LORA_PREAMBLE_LENGTH,
	  LORA_FIX_LENGTH_PAYLOAD_ON,
	  LORA_CRC_ON,  // CRC
      0,
      false,
      3000); // 发射超时 ms

  Radio.SetRxConfig(
      MODEM_LORA,
      LORA_BANDWIDTH_500,
      LORA_SPREADING_FACTOR_7,
      LORA_CODINGRATE_4_5,
      0,
      8,     // 前导码
      0,
      false,
      0,
      true,  // CRC
      0,
      false,
      true); // continuous mode

  /* USER CODE END SubghzApp_Init_2 */
}

/* USER CODE BEGIN EF */
void PacketSendCallbackRegister(PacketSendCallback callback) {

	packetSendCallback = callback;

}

void PacketRecviceCallbackRegister(PacketRecviceCallback callback) {

	packetRecviceCallback = callback;

}

void SubghzApp_Sleep() {

	Radio.Sleep();

}

void SubghzApp_TX(uint8_t *payload, uint8_t payload_size) {

	Radio.Send(payload, payload_size);

}

void SubghzApp_RX(uint16_t timeout) {

	rx_rssi = 0;
	rx_snr = 0;
	radio_rx_buffer_size = 0;
	memset(radio_rx_buffer, 0x00, sizeof(radio_rx_buffer));

	Radio.Rx(timeout);

}
/* USER CODE END EF */

/* Private functions ---------------------------------------------------------*/
static void OnTxDone(void)
{
  /* USER CODE BEGIN OnTxDone */
  /* USER CODE END OnTxDone */
}

static void OnRxDone(uint8_t *payload, uint16_t size, int16_t rssi, int8_t LoraSnr_FskCfo)
{
  /* USER CODE BEGIN OnRxDone */
  /* USER CODE END OnRxDone */
}

static void OnTxTimeout(void)
{
  /* USER CODE BEGIN OnTxTimeout */
  /* USER CODE END OnTxTimeout */
}

static void OnRxTimeout(void)
{
  /* USER CODE BEGIN OnRxTimeout */
  /* USER CODE END OnRxTimeout */
}

static void OnRxError(void)
{
  /* USER CODE BEGIN OnRxError */
  /* USER CODE END OnRxError */
}

/* USER CODE BEGIN PrFD */

/* USER CODE END PrFD */
