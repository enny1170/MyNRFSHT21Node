
/*
NodeManager is intended to take care on your behalf of all those common tasks a MySensors node has to accomplish, speeding up the development cycle of your projects.
NodeManager includes the following main components:
- Sleep manager: allows managing automatically the complexity behind battery-powered sensors spending most of their time sleeping
- Power manager: allows powering on your sensors only while the node is awake
- Battery manager: provides common functionalities to read and report the battery level
- Remote configuration: allows configuring remotely the node without the need to have physical access to it
- Built-in personalities: for the most common sensors, provide embedded code so to allow their configuration with a single line 
Documentation available on: https://github.com/mysensors/NodeManager
*/

 
// load user settings
#include "config.h"

// include supporting libraries
#ifdef MY_GATEWAY_ESP8266
  #include <ESP8266WiFi.h>
#endif
// load MySensors library
#include <MySensors.h>
// load NodeManager library
#include "NodeManager.h"
// #define MY_SIGNAL_REPORT_ENABLED
// create a NodeManager instance
NodeManager nodeManager;

// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);  
  /*
   * Register below your sensors
  */
  nodeManager.setReportIntervalMinutes(2);
  nodeManager.registerSensor(SENSOR_SHT21,-1,1);
  // LDR Port A0
  // pinMode(A0,INPUT);
  // nodeManager.registerSensor(SENSOR_LDR,A0,3);
  // Relais Ports 4,5
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  nodeManager.registerSensor(SENSOR_RELAY,4,4);
  nodeManager.registerSensor(SENSOR_RELAY,5,5);
  // Switch Ports 2,3 for use with interrupt
  // pinMode(2,INPUT);
  // pinMode(3,INPUT);
  // nodeManager.registerSensor(SENSOR_SWITCH,2,6);
  // nodeManager.registerSensor(SENSOR_SWITCH,3,7);

  /*
   * Register above your sensors
  */
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();
}

// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
  //digitalWrite(8,HIGH);
}

// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}
