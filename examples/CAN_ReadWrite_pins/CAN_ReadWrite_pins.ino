// CAN Receive Example
//digitalPin 10 = RX1BF (that is pin 10 on the 18-Lead PDIP/SOIC package and pin 11 on the 20-Lead TSSOP package)
//digitalPin 11 = RX0BF (that is pin 11 on the 18-Lead PDIP/SOIC package and pin 12 on the 20-Lead TSSOP package)
//analogPin 4 = TX0RTS (that is pin 4 on the 18-Lead PDIP/SOIC package and pin 4 on the 20-Lead TSSOP package)
//analogPin 5 = TX1RTS (that is pin 5 on the 18-Lead PDIP/SOIC package and pin 5 on the 20-Lead TSSOP package)
//analogPin 6 = TX2RTS (that is pin 6 on the 18-Lead PDIP/SOIC package and pin 7 on the 20-Lead TSSOP package)

#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10);                               // Set CS to pin 10

void setup() {
  Serial.begin(115200);
  CAN0.begin(MCP_ANY, CAN_100KBPS, MCP_16MHZ);      //Init the mcp2515
  pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input
  CAN0.setMode(MCP_NORMAL);           //Set mode
  CAN0.InitPinIOModes();              //Set Input and output pin registers so that the pins work, DOES NOT WORK WITHOUT IT!!
  pinMode(CAN0_INT, INPUT);           //Declare int pin as input

  Serial.println("MCP2515 Library Receive Example...");
  CAN0.digitalPinWrite(10, 1);              //Write pin 10 on mcp high
  Serial.println(CAN0.digitalPinRead(10));  //read the status
  delay(1000);                              //Wait
  CAN0.digitalPinWrite(10, 0);              //Write pin 10 on mcp low
  Serial.println(CAN0.digitalPinRead(10));  //read the status
}

void loop() {
  //Do something

}
