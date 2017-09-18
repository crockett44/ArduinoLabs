/**
 * Name:
 * 
 * Date:      Period: 
 * 
 * Lab: ArdLab03RGBLED
 * 
 * Description: This is the basic setup for controlling an 
 *              RGB LED.  You can make any color with RGB.
 *              
 *              Note that if you followed the wiring diagram 
 *              from the slide deck, the colors blink in the 
 *              wrong order, find the bug and fix it.
 *              
 *              Re-wire this circuit and Refactor the code 
 *              so that  3 potentiometers to control the
 *              Red Green and Blue values for the LED.
 *              
 *              You need to ensure that the rgbLed() function
 *              is only given values from 0 to 255.  The 
 *              potentiometer's range does not match up.
 *              There is a function called map() that will 
 *              be helpful, documentation can be found at: 
 *              https://www.arduino.cc/en/Reference/Map
 * 
 */

//Global Variables (constants) that specify which pins are used for the LED
//Constants are usually in all CAPS
const int REDPIN = 9, GREENPIN = 6, BLUEPIN = 5;
const int REDPOTPIN = A0;

//create variables to hold the analog value read from the pot
int redPotValue;
int redOutput;

void setup(){
  //initialize the 3 pins as OUTPUT
  pinMode(REDPIN, OUTPUT);    //red 0-255
  pinMode(GREENPIN, OUTPUT);  //green 0-255
  pinMode(BLUEPIN, OUTPUT);   //blue 0-255
  
  Serial.begin(9600);

  // if analog input pin 5 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(5));
}

void loop() {
  //call the RGBLed function defined below.
  //the 3 values determine the how much red, green and blue
  //are mixed together in the LED

  //read the analog value on the potentiometer
  redPotValue = analogRead(REDPOTPIN);
  redOutput = map(redPotValue, 0, 1023, 0, 255);
  
  //print the potvalue to the serial monitor
  Serial.print(redPotValue);
  Serial.print("\t");
  Serial.println(redOutput);
  
  //use the pot value to power the red pin of the LED
  rgbLed(redOutput, 0, 0);

  
//  rgbLed(255,0,0);  //red
//  delay(1000);
//  
//  rgbLed(0,255,0);  //green
//  delay(1000);
//  
//  rgbLed(0,0,255);  //blue
//  delay(1000);
//
//  rgbLed(random(255), random(255), random(255));  //PsuedoRandom color
//  delay(1000);
  
}

/**
 * This method accepts 3 input values ranging from 0 - 255
 * it then displays the RGB color with the LED
 * Note: This method is specific to this program and uses
 * specific global variables (not only local variables)
 */
void rgbLed(int red, int green, int blue){
  analogWrite(REDPIN,red);
  analogWrite(GREENPIN, green);
  analogWrite(BLUEPIN, blue);
}

