#include <SPI.h>
#include <SparkFunDS3234RTC.h>

// include the SD library:
#include <SPI.h>
#include <SD.h>


// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_SS_PIN
const int chipSelect = 8;
String fileName  = "samples.csv";
File samplesFile;



int SENSOR_POWER_PIN= 4; // Use TIP142T to power the sensor (High will shout it down Low will turn it on)

int MOTOR_PIN = 5; // Use the onboard Uno LED
int WET_PIN = 6; // Use the onboard Uno LED
int DRY_PIN = 7; // Use the onboard Uno LED

int isRaningPin = 4;  // This is our input pin
int rainingAnalogPin = 1;  // This is our input pin for analog data

int isRaining = LOW;  // HIGH MEANS Raining
int rainIntensity = 0;  
int isHatOnWet = LOW; 
int isHatOnDry = LOW; 

int minute_in_mill = 10000; // 60000 * 1; one minute
int start_time; 
  

void setup() {
  pinMode(isRaningPin, INPUT);
  pinMode(WET_PIN, INPUT);
  pinMode(DRY_PIN, INPUT);
  
  pinMode(SENSOR_POWER_PIN, OUTPUT);
  pinMode(isRaningPin, INPUT);
  
  digitalWrite(SENSOR_POWER_PIN,LOW); // sensor is off
  
  Serial.begin(9600);
   /*
  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    // set led to blink red forever
    while(1) {
      
    }
    return;
  }
  Serial.println("initialization done.");
  */

  // setup the machine with hat on wet
  is_hat_on_wet();
  start_time = millis();
}
/**
 *  
 */
void loop() {
  
  // every 1 minute we will take a smaple from the rain maker
  if(start_time+minute_in_mill>=millis()) {
    // fire up rain sensor
    digitalWrite(SENSOR_POWER_PIN,LOW); // turn the sensor off  
    delay(1000);// for sensor pin to load before i take sample
    isRaining = digitalRead(isRaningPin);
    digitalWrite(SENSOR_POWER_PIN,LOW); // turn the sensor off
    
    if (isRaining== HIGH)
    {
      Serial.println("It's raining man....");
      // check if hat in the correct place if not move it
      //is_hat_on_dry();
      
      //// write a sample to the card
      /*
      // take time stemp
      timestemp = 
      // take sample
      rainIntensity = analogRead(rainingAnalogPin);
      
      // write to card
      samplesFile = SD.open(fileName, FILE_WRITE);
      if (samplesFile) {
        myFile.println(timestemp+"," +rainIntensity);
        // close the file:
        samplesFile.close();
      } else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
      }
      */

      
      // 
     
    } else {
      Serial.println("It's not raining man....");
     //is_hat_on_wet();
     // 
    }
    start_time = millis();
  }
  
  
  delay(100);
}


void is_hat_on_dry() {
      isHatOnDry = digitalRead(DRY_PIN);
      if(isHatOnDry==LOW) {
        // move engine to dry stop when hitting switch dry

      }
}


void is_hat_on_wet() {
      isHatOnWet = digitalRead(WET_PIN);
      if(isHatOnWet==LOW) {
        // move engine to wet stop when hitting the 
        
      }
}
