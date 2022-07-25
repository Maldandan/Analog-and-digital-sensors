int lamp = 13;                // the pin that the lamp is atteched to
int sensor = 3;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int sensorValue = 0;                 // variable to store the sensor status (sensorValueue)

int timer = 0;
long timerThreshold = 5; 	// if motion stopped, keep the lamp on for this time period (seconds)
							// it is needed to avoid immediate power off when motion stops


void setup() {
  Serial.println("Starting...");
  pinMode(lamp, OUTPUT);      // initalize lamp as output
  pinMode(sensor, INPUT);    // initialize sensor as input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  
  sensorValue = digitalRead(sensor);   // read sensor sensorValueue
  
  if (sensorValue == HIGH) {           // check if the sensor is HIGH
    Serial.println("Sensor is HIGH");
    timer = 0;
    
    if (state == LOW) {
      Serial.println("Turning light ON!"); 
      state = HIGH;       // update variable state to HIGH
      digitalWrite(lamp, HIGH);   // turn lamp ON      
    }

  } else {      
      
    if(timer >= timerThreshold) {
      timer = 0;  
      if(state == HIGH){
        Serial.println("Turning light OFF!"); 
        state = LOW;
        digitalWrite(lamp, LOW); // turn lamp OFF
      }
    }
  }

  timer+=1;
  delay(1000);
  Serial.println(timer);

}