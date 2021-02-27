/*-------------------------------------------------------------------------------
Created on Sat Feb 27 2021

@Author: Jihwan Lee
@GIT ID: DGIRobo
@E-mail: fist5678@dgist.ac.kr
@Department: Daegu Gyeongbuk Institute of Science and Technology(DGIST) Undergraduate Course
-------------------------------------------------------------------------------*/

#include <CAN.h>
#include "GIM8008.h"

void GIM8008::idChange(unsigned char beforeID, unsigned char afterID) //ID must be 1~256
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;
  
  tx_msg.id = beforeID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x06; //function code
  tx_msg.data[2] = 0x15; //register address
  tx_msg.data[3] = 0x01; //data length
  tx_msg.data[4] = afterID;
  tx_msg.data[5] = 0x00; //Retain
  tx_msg.data[6] = 0x00;
  tx_msg.data[7] = 0x00;

  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  delay(1000);
  /*-----------------------------------------------------------------------------*/
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[4] == afterID)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/ 
        Serial.println("ID of the motor changed successfully!");
      }
    }
  }
}

void GIM8008::modeChange(unsigned char tarID, int tarMode) //tarMode of Position: 0, tarMode of Speed: 3
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;
  
  tx_msg.id = tarID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x06; //function code
  tx_msg.data[2] = 0x19; //register address
  tx_msg.data[3] = 0x01; //data length
  tx_msg.data[4] = tarMode;
  tx_msg.data[5] = 0x00; //Retain
  tx_msg.data[6] = 0x00;
  tx_msg.data[7] = 0x00;

  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  /*-----------------------------------------------------------------------------*/
  delay(1000);
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[4] == tarMode)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.println("The mode of motor changed successfully!");
      }
    }
  }
}

void GIM8008::savingParameter(unsigned char tarID)
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;
  
  tx_msg.id = tarID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x06; //function code
  tx_msg.data[2] = 0x14; //Register address
  tx_msg.data[3] = 0x01; //data length
  tx_msg.data[4] = 0x01; //execute save command
  tx_msg.data[5] = 0x00; //retain
  tx_msg.data[6] = 0x00;
  tx_msg.data[7] = 0x00;

  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  delay(2000);
  /*-----------------------------------------------------------------------------*/
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[4] == 0x01)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.println("Successfully Saved Revised parameters of the motor");
      }
    }
  }
}

void GIM8008::statusCheck(unsigned char tarID)
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;
  
  tx_msg.id = tarID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x02; //function code
  tx_msg.data[2] = 0x00; //retain
  tx_msg.data[3] = 0x00; //retain
  tx_msg.data[4] = 0x00; //retain
  tx_msg.data[5] = 0x00; //retain
  tx_msg.data[6] = 0x00; //retain
  tx_msg.data[7] = 0x00; //retain

  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  /*-----------------------------------------------------------------------------*/
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[0] == tarID)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Torque : ");
        if (rx_msg.data[2] == 0x00)
        {
          Serial.print("+");
        }
        else if (rx_msg.data[2] == 0x01)
        {
          Serial.print("-");
        }
        unsigned char actTor8 = (unsigned char) rx_msg.data[3];
        float actTor = (float) actTor8;
        Serial.print(actTor);
        Serial.print("Nm");
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.print("Current temperature : ");
        unsigned char actTem8 = (unsigned char) rx_msg.data[4];
        float actTem = (float) actTem8;
        Serial.print(actTem);
        Serial.println("Celcius");
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Position : ");
        signed short actPos8 = (signed short) ((unsigned char) rx_msg.data[6]) + 256 * ((unsigned char)rx_msg.data[7]);
        float actPos = ((float) actPos8) / 100;
        Serial.print(actPos);
        Serial.println("deg");
        Serial.println();
        /*-----------------------------------------------------------------------------*/
      }
    }
  }
}

void GIM8008::positionControl(unsigned char tarID, float maxAcc, float maxSpe, float tarPos)
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;
  
  unsigned char maxAcc16 = (unsigned char) maxAcc*10;
  unsigned char maxSpe16 = (unsigned char) maxSpe;
  unsigned char tarPos16a = (unsigned char) ((int) tarPos*100) % 256;
  unsigned char tarPos16b = (unsigned char) ((int) tarPos*100 / 256);
  
  tx_msg.id = tarID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x01; //function code
  tx_msg.data[2] = 0x00; //retain
  tx_msg.data[3] = maxAcc16; //max acceleration
  tx_msg.data[4] = 0x00; //retain
  tx_msg.data[5] = maxSpe16; //max speed
  tx_msg.data[6] = tarPos16a; //position low bit
  tx_msg.data[7] = tarPos16b; //position high bit

  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  /*-----------------------------------------------------------------------------*/
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[1] == 0x01)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Torque : ");
        if (rx_msg.data[2] == 0x00)
        {
          Serial.print("+");
        }
        else if (rx_msg.data[2] == 0x01)
        {
          Serial.print("-");
        }
        unsigned char actTor8 = ((unsigned char) rx_msg.data[3]);
        float actTor = (float) actTor8;
        Serial.print(actTor);
        Serial.print("Nm");
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Speed : ");
        signed short actSpe8 = (signed short) (((unsigned char) rx_msg.data[4]) + 256 * ((unsigned char)rx_msg.data[5]));
        float actSpe = (float) actSpe8;
        Serial.print(actSpe);
        Serial.println("RPM");
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Position : ");
        signed short actPos8 = (signed short) ((unsigned char) rx_msg.data[6]) + 256 * ((unsigned char)rx_msg.data[7]);
        float actPos = ((float) actPos8) / 100;
        Serial.print(actPos);
        Serial.println("deg");
        Serial.println();
        /*-----------------------------------------------------------------------------*/
      }
    }
  }
}

void GIM8008::speedControl(unsigned char tarID, float tarSpe)
{
  uint32_t t_time = ((float) millis()) / 1000;
  uint32_t i;
  can_message_t tx_msg, rx_msg;

  unsigned char tarSpe16 = (unsigned char) tarSpe;

  tx_msg.id = tarID;
  tx_msg.format = CAN_STD_FORMAT;
  tx_msg.data[0] = 0xFF; //id of host
  tx_msg.data[1] = 0x06; //function code
  tx_msg.data[2] = 0x02; //register
  tx_msg.data[3] = 0x01; //data length
  tx_msg.data[4] = tarSpe16; //data low 8bit
  tx_msg.data[5] = 0x00; //data high 8bit
  tx_msg.data[6] = 0x00;
  tx_msg.data[7] = 0x00;
  
  tx_msg.length = 0x08;
  CanBus.writeMessage(&tx_msg);
  /*-----------------------------------------------------------------------------*/
  if (CanBus.avaliableMessage())
  {
    if (CanBus.readMessage(&rx_msg))
    {
      Serial.print("ID : ");
      Serial.print(rx_msg.id, HEX);
      Serial.print(", Length : ");
      Serial.print(rx_msg.length);
      Serial.print(", Data : ");
      for (i = 0; i < rx_msg.length; i++)
      {
        Serial.print(rx_msg.data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      /*-----------------------------------------------------------------------------*/
      if (rx_msg.data[1] == 0x06)
      {
        Serial.print("time : ");
        Serial.print(t_time);
        Serial.println();
        /*-----------------------------------------------------------------------------*/
        Serial.print("Actual Speed : ");
    
          signed short actSpe8 = (signed short) ((unsigned char) rx_msg.data[4]);
          float actSpe = (float) actSpe8;
          Serial.print(actSpe);
          Serial.println("RPM");
        }


        /*-----------------------------------------------------------------------------*/
      }
    }
  }
