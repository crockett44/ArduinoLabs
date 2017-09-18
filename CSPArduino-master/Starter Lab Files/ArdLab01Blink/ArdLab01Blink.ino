/**
 * Name: Brad Crockett
 * 
 * Date:  9/18          Period: 3
 * 
 * Lab Number/Name: ArdLab01Blink
 * 
 * Purpose: Turns on an LED on for one second, then off for one second, repeatedly.
 * 
 */

//Declare Global Variables

void setup() {
  // put your setup code here, to run once:
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for half a second
}

//Declare Functions Here 

