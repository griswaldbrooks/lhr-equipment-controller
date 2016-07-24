// Igor firmware

// #include "DHT.h"

// #define DHTTYPE DHT22 // DHT 22  (AM2302)

// #define DHTPIN A0
// DHT dht(DHTPIN, DHTTYPE);

// #define DHTPIN2 A3
// DHT dht2(DHTPIN2, DHTTYPE);

#define INCUBATOR_LIGHT_PIN A1
#define TRANSILUMINATOR_UV_PIN A2
#define IGOR_LIGHT_PIN 2
#define SHAKER 3
#define GEL 4
#define CENTRIFUGE_PIN 5
#define TRANSILUMINATOR_LIGHT_PIN 6
#define SHAKER_INCUBATOR_LIGHT 7

void setup() 
{    
    // pin setup
    pinMode(INCUBATOR_LIGHT_PIN, OUTPUT);
    pinMode(TRANSILUMINATOR_UV_PIN, OUTPUT);
    pinMode(IGOR_LIGHT_PIN, OUTPUT);
    pinMode(SHAKER, OUTPUT);
    pinMode(GEL, OUTPUT);
    pinMode(CENTRIFUGE_PIN, OUTPUT);
    pinMode(TRANSILUMINATOR_LIGHT_PIN, OUTPUT);
    pinMode(SHAKER_INCUBATOR_LIGHT, OUTPUT);
 
    //starts with the incubator light on
    digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);

    // starts with the transiluminator uv light off
    digitalWrite(TRANSILUMINATOR_UV_PIN, LOW);
        
    // starts with igor light on
    digitalWrite(IGOR_LIGHT_PIN, HIGH);

    // starts with the shaker off
    digitalWrite(SHAKER, LOW);

    // starts with the gel off
    digitalWrite(GEL, LOW);
    
    // starts with the centrifuge off  
    digitalWrite(CENTRIFUGE_PIN, LOW);

    // starts with the transiluminator light off  
    digitalWrite(TRANSILUMINATOR_LIGHT_PIN, LOW);

    // starts with the shaker incubator light off  
    digitalWrite(SHAKER_INCUBATOR_LIGHT, HIGH);
    
    // serial handshake
    Serial.begin(9600);

    // starts the incubator temperature sensor
    // dht.begin();
    // starts the shaker incubator temperature sensor
    // dht2.begin();
}

char buffer[64];
size_t len = 0;

void loop() 
{  
    // clean the serial buffer
    memset(buffer,0,sizeof(buffer));
   
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    // float h = dht.readHumidity();
    // float t = dht.readTemperature();

    // float h2 = dht2.readHumidity();
    // float t2 = dht2.readTemperature();
    
    // implement serial read bytes and read command
    if (Serial.available()) {
      len = Serial.readBytes(buffer, 1);
      if (len > 0) {
        if (buffer[0] == '0') {
          // turn the transiluminator UV light off
          digitalWrite(TRANSILUMINATOR_UV_PIN, LOW);
          Serial.println("0");
        }
        if (buffer[0] == '1') {
          // turn the transiluminator UV light ON
          digitalWrite(TRANSILUMINATOR_UV_PIN, HIGH);
          Serial.println("1");
        }
        if (buffer[0] == '2') {
          // check if returns are valid, if they are NaN (not a number) then something went wrong!
          if (isnan(t) || isnan(h)) 
          {
            Serial.println("Failed to read from DHT");
          } else {
            Serial.print("Humidity: "); 
            Serial.print(h);
            Serial.print("% ");
            Serial.print("Temperature: "); 
            Serial.print(t);
            Serial.println("C");
          }      
        }
        if (buffer[0] == '3') {
          // turn igor light off.
          digitalWrite(IGOR_LIGHT_PIN, LOW);
          Serial.println("3");
        }
        if (buffer[0] == '4') {
          // turn igor light on
          digitalWrite(IGOR_LIGHT_PIN, HIGH);
          Serial.println("4");
        }
        if (buffer[0] == '5') {
          // turn the centrifuge on
          digitalWrite(CENTRIFUGE_PIN, HIGH);
          Serial.println("5");
        }
        if (buffer[0] == '6') {
          // turn the centrifuge off
          digitalWrite(CENTRIFUGE_PIN, LOW);
          Serial.println("6");
        }
        if (buffer[0] == '7') {
          // turn the shaker on
          digitalWrite(SHAKER, HIGH);
          Serial.println("7");
        }
        if (buffer[0] == '8') {
          // turn the shaker off
          digitalWrite(SHAKER, LOW);
          Serial.println("8");
        }
        if (buffer[0] == '9') {
          // turn the gel on
          digitalWrite(GEL, HIGH);
          Serial.println("9");
        }
        if (buffer[0] == 'A') {
          // turn the gel off
          digitalWrite(GEL, LOW);
          Serial.println("A");
        }
        if (buffer[0] == 'B') {
          // turn the transiluminator normal light on
          digitalWrite(TRANSILUMINATOR_LIGHT_PIN, HIGH);
          Serial.println("B");
        }
        if (buffer[0] == 'C') {
          // turn the transiluminator normal light off
          digitalWrite(TRANSILUMINATOR_LIGHT_PIN, LOW);
          Serial.println("C");
        }
        if (buffer[0] == 'D') {
          // check if returns are valid, if they are NaN (not a number) then something went wrong!
          if (isnan(t2) || isnan(h2)) 
          {
            Serial.println("Failed to read from DHT");
          } else {
            Serial.print("Humidity: "); 
            Serial.print(h2);
            Serial.print("% ");
            Serial.print("Temperature: "); 
            Serial.print(t2);
            Serial.println("C");
          }      
        }
      }
    }
  
    // if (t < 37) {
    //   //turn incubator light on
    //   digitalWrite(INCUBATOR_LIGHT_PIN, HIGH);
    // } else {
    //   //turn incubator light off
    //   digitalWrite(INCUBATOR_LIGHT_PIN, LOW);
    // }

    // if (t2 < 37) {
    //   //turn incubator light on
    //   digitalWrite(SHAKER_INCUBATOR_LIGHT, HIGH);
    // } else {
    //   //turn incubator light off
    //   digitalWrite(SHAKER_INCUBATOR_LIGHT, LOW);
    // }
    
}
