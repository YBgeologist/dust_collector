// Test Engine

// Switches are always ON at 1023, when hat marks switch that means under 1000

//const int analogDry =  1;// on wet switch
const int analogDry =  0;// on dry switch

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(9600);
     
}

// the loop function runs over and over again forever
void loop() {
    
  int sensorValue = analogRead(analogDry);
  Serial.println(sensorValue);
 
}

