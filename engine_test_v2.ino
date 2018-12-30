const int forwards = 4; // forward is wet
const int backwards = 5;//assign relay INx pin to arduino pin

void setup() {
 
pinMode(forwards, OUTPUT);//set relay as an output
pinMode(backwards, OUTPUT);//set relay as an output

}

void loop() {

digitalWrite(forwards, HIGH);
digitalWrite(backwards, HIGH);//Deactivate both relays to brake the motor
//delay(10000);// wait 10 seconds
/*
 digitalWrite(forwards, HIGH);
 digitalWrite(backwards, LOW);//Activate the relay the dryther direction, they must be different to move the motor
 delay(10000);// wait 10 seconds

 digitalWrite(forwards, LOW);
 digitalWrite(backwards, HIGH);//Activate the relay wet direction, they must be different to move the motor
 delay(100000); // wait 10 seconds

 digitalWrite(forwards, HIGH);
 digitalWrite(backwards, HIGH);//Deactivate both relays to brake the motor
 delay(10000);// wait 10 seconds
*/
}

 
