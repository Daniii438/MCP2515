// CAN Sleep Example

#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];

#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10);                               // Set CS to pin 10

void setup() {
  Serial.begin(115200);
  initMCP();
  pinMode(CAN0_INT, INPUT); //declare input pin
  delay(1000);              //Wait one second
  Serial.println("MCP2515 Library Sleep Example...");
  CAN0.setMode(MCP_SLEEP);  //Send MCP to sleep!
  delay(1000);              //Wait one second
  initMCP();

}

void initMCP() {
  CAN0.begin(MCP_ANY, CAN_100KBPS, MCP_16MHZ);
  CAN0.setMode(MCP_NORMAL);
}

void loop() {
  //Do nothing
}
