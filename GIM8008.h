/*-------------------------------------------------------------------------------
Created on Sat Feb 27 2021

@Author: Jihwan Lee
@GIT ID: DGIRobo
@E-mail: fist5678@dgist.ac.kr
@Department: Daegu Gyeongbuk Institute of Science and Technology(DGIST) Undergraduate Course
-------------------------------------------------------------------------------*/

#include <CAN.h>
#ifndef _GIM8008_h
#define _GIM8008_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

class GIM8008
{
  public:
    void idChange(unsigned char beforeID, unsigned char afterID); //ID must be 1~256
    void modeChange(unsigned char tarID, int tarMode); //tarMode of Position: 0, tarMode of Speed: 3
    void savingParameter(unsigned char tarID);
    void statusCheck(unsigned char tarID);
    void positionControl(unsigned char tarID, float maxAcc, float maxSpe, float tarPos);
    void speedControl(unsigned char tarID, float tarSpe);
};

#endif
