/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <Dynamixel2Arduino.h>

// Please modify it to suit your hardware.
 // DYNAMIXELShield UART RX/TX
  #define DXL_SERIAL   Serial
  #define DEBUG_SERIAL soft_serial
  const int DXL_DIR_PIN = 2;
  
  const uint8_t DXL_ID = 10;
  const uint8_t DXL_ID1 = 2;
const float DXL_PROTOCOL_VERSION = 1.0;
int batasats=1200;
int batasbwh=7100;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(115200);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);dxl.ping(DXL_ID1);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  dxl.torqueOn(DXL_ID);

  dxl.torqueOff(DXL_ID1);
  dxl.setOperatingMode(DXL_ID1, OP_POSITION);
  dxl.torqueOn(DXL_ID1); 

  // Limit the maximum velocity in Position Control Mode. Use 0 for Max speed
  dxl.writeControlTableItem(MOVING_SPEED, DXL_ID, 60);
  dxl.writeControlTableItem(MOVING_SPEED, DXL_ID1, 60);
    dxl.writeControlTableItem(CW_ANGLE_LIMIT, DXL_ID, 4095);
  dxl.writeControlTableItem(CCW_ANGLE_LIMIT, DXL_ID, 4095);
  dxl.writeControlTableItem(CW_ANGLE_LIMIT, DXL_ID1, 4095);
  dxl.writeControlTableItem(CCW_ANGLE_LIMIT, DXL_ID1, 4095);
  
}
void turun (){  
  dxl.setGoalPosition(DXL_ID1,-3000);//turun
  dxl.setGoalPosition(DXL_ID,3000);
  delay (10000);
  
  }

  void naik (){
  dxl.setGoalPosition(DXL_ID, -3000);//-428
  dxl.setGoalPosition(DXL_ID1,3000);//400
  delay (10000);
}


void loop() {
  // put your main code here, to run repeatedly:
  turun();
  naik();
  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value. 
  // Set Goal Position in RAW value

}
