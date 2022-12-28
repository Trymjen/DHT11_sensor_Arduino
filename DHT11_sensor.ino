#include "DHT.h" //Setup for the DHT library
#define DHTPIN 2 //Sensor connected to pin 2
#define DHTTYPE DHT11 //Sensor type
DHT dht(DHTPIN, DHTTYPE); //Initialize DHT sensor

int tempPin = 3;
int humidityPin = 4;

void setup() {
  Serial.begin(9600); // For display
  Serial.println("Humidity and Temperature"); //print the prompt
  dht.begin(); //start the sensor

  // Set LED pins as outputs
  pinMode(tempPin, OUTPUT);
  pinMode(humidityPin, OUTPUT);
}

void loop() {
  delay(2000); //wait 2sec
  int h = dht.readHumidity();//data for humidity
  float t = dht.readTemperature(); //data for temperature
  
  //Display all the data
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.println("C");

  // Set LED states based on temperature and humidity thresholds
  if (temperature > 23) {
    digitalWrite(tempPin, HIGH);
  } else {
    digitalWrite(tempPin, LOW);
  }
  
  if (humidity > 50) {
    digitalWrite(humidityPin, HIGH);
  } else {
    digitalWrite(humidityPin, LOW);
  }
}
