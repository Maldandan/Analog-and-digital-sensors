/* A simple programme that will change the intensity of
 * an LED based  * on the amount of light incident on 
 * the photo resistor.
 * 
 */



//PhotoResistor Pin
//the analog pin the photoresistor is 
                  //connected to
                  //the photoresistor is not calibrated to any units so
                  //this is simply a raw sensor value (relative light)
//LED Pin
int ledPin = 9;   //the pin the LED is connected to
                  //we are controlling brightness so 
                  //we use one of the PWM (pulse width
                  // modulation pins)



       // *********    Challenge:  Use a motor instead of an LED at this pin - light intensity will change motor speed





void setup()
{
  pinMode(ledPin, OUTPUT); //sets the led pin to output
}




void loop()
{
 int lightLevel = analogRead(A0); //Read the amount of light shining on the photoresistor
                                       
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
         //adjust the value 0 to 900 to
         //span 0 to 255



 lightLevel = constrain(lightLevel, 0, 255);//make sure the 
                                           //value is betwween 
                                           //0 and 255
 analogWrite(ledPin, lightLevel);  //write the value
}