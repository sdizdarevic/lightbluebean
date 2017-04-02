/* Photoresistor sketch. 
Analog voltage reading method
Connect one end of the photocell to Vcc, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground. 
 
 */
 
int photocellPin = 0;     // the photocellcell and 10K pulldown are connected to analog port a0
int photocellReading;     // the analog reading from the sensor  
 void setup(void) {
  // Send debugging information via the Serial monitor
  Serial.begin(9600);   
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  
  delay(100);
}