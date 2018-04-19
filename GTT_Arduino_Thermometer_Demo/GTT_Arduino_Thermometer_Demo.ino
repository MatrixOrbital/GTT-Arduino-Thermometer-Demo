//GTT Arduino Thermometer Demo
//Arduino Uno with Matrix Orbital GTT70A and DS18S20
//Created by Divino, 19/047/2018
//support@matrixorbital.ca
//www.matrixorbital.ca/appnotes

#include <gtt.h>
#include <gtt_device.h>
#include <gtt_enum.h>
#include <gtt_events.h>
#include <gtt_ext_types.h>
#include <gtt_packet_builder.h>
#include <gtt_parser.h>
#include <gtt_protocol.h>
#include <gtt_text.h>

#include <Wire.h>
#include <OneWire.h>
#include "GTTProject21.c"
#include "GTTProject21.h"

#define I2C_Address 0x28  //Define default 8bit I2C address of 0x50 >> 1 for 7bit Arduino

// Buffer for incoming data
uint8_t rx_buffer[64];

// Buffer for outgoing data
uint8_t tx_buffer[64];


#include <stdlib.h>

OneWire ds18s20(2); //sensor on pin 2
byte addr[8]; //Buffer to store One wire Address
bool probeConnected; //Bool to determine indicate if the DS18S20 is connected
gtt_device gtt; //Declare the GTT device

void setup() {
  //Setup I2C bus  
  gtt.Write = i2cWrite; //Set the write function
  gtt.Read = i2cRead; //Set the read function
  gtt.rx_buffer = rx_buffer; //Declare a buffer for input data
  gtt.rx_buffer_size = sizeof(rx_buffer); //Declare the size of the input buffer
  gtt.tx_buffer = tx_buffer; //Declare a buffer for output data
  gtt.tx_buffer_size = sizeof(tx_buffer); //Declare the size of the output buffer
  Wire.begin(); //Begin I2C communication
  Serial.begin(9600);
  delay(500);  
  resetDisplay();  
  delay(3000);  
  gtt_set_screen1_image_toggle_2_state(&gtt, 1); //If the Arduino can establish communication with the GTT, Arduino connection indicator appropriately      
}

void loop() {
  // put your main code here, to run repeatedly:  
  probeConnected = searchForTempProbe(); //Search for the DS18S20
  if(probeConnected){ //If the probe is connected
   int16_t temp = readTempProbe(); //Read the temperature      
   char buf[] = {0};
   sprintf(buf,"%d",temp); //Convert the temperature value to a string
   gtt_set_screen1_bar_graph_1_value(&gtt, temp); //Update the GTT bar graph
   gtt_set_screen1_dynamic_label_2_text(&gtt, gtt_make_text_ascii(buf)); //Update the GTT label
  }   
  else{ //If the probe isn't connected
   gtt_set_screen1_image_toggle_3_state(&gtt, 0); //Set the probe indicator to "Disconnected"
   gtt_set_screen1_bar_graph_1_value(&gtt, 0); //Set the GTT bar graph appropriately
   gtt_set_screen1_dynamic_label_2_text(&gtt, gtt_make_text_ascii("NA")); //Update the GTT label to "NA"
  }  
}

void resetDisplay() {
  Serial.println("resetting display");
  char command[] = { 254, 1 };
  i2cWrite(&gtt, command, sizeof(command));
}

/* The Code used in the searchorTempProbe and readTempProbe function is 
 * sample code taken from https://playground.arduino.cc/Learning/OneWire */
byte searchForTempProbe(){
  
  ds18s20.reset_search();
  
  if ( !ds18s20.search(addr)) {
    Serial.print("No more addresses.\n");
    ds18s20.reset_search();
    delay(250);
    return 0;
  }
    Serial.print("R=");
  for( byte i = 0; i < 8; i++) {
    Serial.print(addr[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.print("CRC is not valid!\n");
      gtt_set_screen1_image_toggle_3_state(&gtt, 0); //Set the probe indicator to "Disconnected"
      return 0;
  }
  if ( addr[0] == 0x10) {
      Serial.print("Device is a DS18S20 family device.\n");
      gtt_set_screen1_image_toggle_3_state(&gtt, 1); //Set the probe indicator to "Connected"  
      return 1;
  }     
  else {
      Serial.print("Device family is not recognized: 0x");
      Serial.println(addr[0],HEX);
      gtt_set_screen1_image_toggle_3_state(&gtt, 0); //Set the probe indicator to "Disconnected"
      return 0;
  }
}

byte readTempProbe(){
  byte present = 0;
  byte data[12];
  float temp;
   
  ds18s20.reset();
  ds18s20.select(addr);
  ds18s20.write(0x44,1);// start conversion, with parasite power on at the end

  delay(750);// maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds18s20.reset();
  ds18s20.select(addr);    
  ds18s20.write(0xBE);// Read Scratchpad
  
  for ( byte i = 0; i < 9; i++) {// we need 9 bytes
    data[i] = ds18s20.read();
  }  
  temp = ( (data[1] << 8) + data[0] ) * 0.5;    
  temp= (temp * 9/5) + 32;
  Serial.print("Temp = ");  
  Serial.println(temp);
  return temp;
}     

int i2cWrite(gtt_device* gtt_device, char* data, byte data_length) {//Write an array of bytes over i2c
  Wire.beginTransmission(I2C_Address);  
  for (int i = 0; i < data_length; i++) {
    Wire.write(data[i]);        
  }
  Wire.endTransmission();  
  return 0;
}

byte i2cRead(gtt_device* gtt_device) { //Wait for one byte to be read over i2c  
  byte data;
  Wire.beginTransmission(I2C_Address);  
  Wire.requestFrom(I2C_Address, 1);     
  if(Wire.available()<1) 
  {
    return -1;
  }
  else{
    data = Wire.read();  
    Serial.println(data);
    return data;
  } 
}

