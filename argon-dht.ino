#include "Adafruit_DHT.h"

// Written by ladyada, public domain

#define DHTPIN 10  
#define DHTTYPE DHT11		

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
	float humidity = dht.getHumidity();
	float tempCelsius = dht.getTempCelcius();

    // API call.
    Particle.publish("temp", String(tempCelsius), PRIVATE);
	
	// Waiting 30 seconds until we take readings and publish.
	delay(30000);
}

