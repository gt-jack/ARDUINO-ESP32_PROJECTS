void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
// Define the pins connected to the sensor
const int trigPin = 9;
const int echoPin = 10;

// variables for duration and distance
long duration;
int distanceCm;

 void setup(){
  // Set the trigger pin as an output (to send sound waves)
  pinMode(trigPin, OUTPUT);
  // Set the echo pin as an input (to receive reflected sound waves)
  pinMode(echoPin, INPUT);
  
  // Initialize Serial communication for viewing results
  Serial.begin(9600);
  Serial.println("HC-SR04 Distance Sensor Test");
}

void loop() {
  // --- Part 1: Trigger the sensor to send a sound pulse ---
  // Clear the trigPin by setting it LOW for a moment
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin to HIGH for 10 microseconds to send the pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // --- Part 2: Measure the time duration of the echo ---
  // The 'pulseIn()' function reads the time (in microseconds) it takes 
  // for the sound to travel to the object and return.
  duration = pulseIn(echoPin, HIGH);
  
  // --- Part 3: Calculate the distance ---
  // Speed of sound is approx. 343 meters/second or 0.0343 cm/microsecond.
  // The time is for a round trip (out and back), so we divide by 2.
  // Distance (cm) = (duration * Speed of Sound (cm/us)) / 2
  distanceCm = duration * 0.0343 / 2;
  
  // Print the result to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  // Wait a short period before the next measurement
  delay(500);
}
