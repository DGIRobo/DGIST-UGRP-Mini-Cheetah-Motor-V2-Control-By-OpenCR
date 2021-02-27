/*-------------------------------------------------------------------------------
Created on Sat Feb 27 2021

@Author: Jihwan Lee
@GIT ID: DGIRobo
@E-mail: fist5678@dgist.ac.kr
@Department: Daegu Gyeongbuk Institute of Science and Technology(DGIST) Undergraduate Course
-------------------------------------------------------------------------------*/


/*--header files in here.------------------------------------------------------*/
#include <CAN.h>
#include "GIM8008.h"
/*--Set delay of sending.------------------------------------------------------*/
#define SEND_INTERVAL_MS 1000
/*--Set CANbus messages.-------------------------------------------------------*/
uint32_t t_time, id, i;
can_message_t tx_msg, rx_msg;
GIM8008 Motor;
/*--Set data names.------------------------------------------------------------*/
unsigned char tarID, tarPos, actTor8, maxAcc16, maxSpe16, tarPos16a, tarPos16b, tarPos16;
signed short actSpe8, actPos8;
float maxSpe, maxAcc, actpos, actSpe, actTor;
int Spe, Acc, del;
/*-----------------------------------------------------------------------------*/
void setup()
{
  /*--Serial connection setting.-----------------------------------------------*/
  Serial.begin(115200);
  Serial.println("============================");
  Serial.println("=== Motor Control Start! ===");
  delay(1000);
  /*--CANbus connection setting.-----------------------------------------------*/
  while (CanBus.begin(CAN_BAUD_1000K, CAN_STD_FORMAT) == false)
  {
    Serial.println("CAN open fail!!");
    Serial.println("Init CAN BUS again");
    delay(100);
  }
  Serial.println("CAN BUS init ok!");
  /*--CANbus message init.-----------------------------------------------------*/
  CanBus.configFilter(0x00, 0, CAN_STD_FORMAT);
}

/*-----------------------------------------------------------------------------*/
void loop()
{
  t_time = ((float) millis()) / 1000;
  float Start = t_time;

  tarID = 1;
  tarPos = 8.34;
  maxSpe = 10; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(50);

  tarID = 1;
  tarPos = 13.34;
  maxSpe = 10; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(50);

  tarID = 1;
  tarPos = 18.35;
  maxSpe = 10; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  delay(50);

  tarID = 1;
  tarPos = 22.60;
  maxSpe = 10; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(50);

  tarID = 1;
  tarPos = 26.86;
  maxSpe = 10; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(100);

  tarID = 1;
  tarPos = 24.86;
  maxSpe = 7; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(200);

  tarID = 1;
  tarPos = 22.86;
  maxSpe = 5; 
  maxAcc = 1;
  Motor.positionControl(tarID, maxAcc, maxSpe, tarPos);
  Serial.println(1);
  delay(170);
    
  float Final = t_time;
}
