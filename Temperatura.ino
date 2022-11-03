#include <Adafruit_Sensor.h>
 
#include <Wire.h>
#include <DHT.h>
 
//pin digital donde se conecta el sensor
#define DHTPIN 2
//especificamos el tipo de sensor
#define DHTTYPE DHT11
 
 
//iniciamos el sensor dht
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  #ifdef _DEBUG_
    Serial.begin(9600); //activamos la comunicación serie
  #endif
 
  // Iniciar sensor al que se pasa la dirección I2C
  // Por defecto es un número de 7-bit 1000000 que
  // equivale al 40 en hexadecimal
  // Por defecto la precisión es de 14-bit para temperatura y humedad
  dht.begin(0x40);
 
  #ifdef _DEBUG_
    Serial.println("");
    Serial.println("Inicado sensor dht");
  #endif
 
}
void loop() {
 
  // Leemos temperatura (en grados centigrados) y humedad del sensor
  double temperatura = dht.readTemperature();
  double humedad = dht.readHumidity();
 
  if(isnan(humedad) || isnan(temperatura) ) {// manejo de errores
    Serial.println("Error obteniendo los datos del sensor dht");
    return;
  }
 
  double indice_de_calor = dht.computeHeatIndex(temperatura, humedad, false);
 
  #ifdef _DEBUG_
    // Mostrar datos en el monitor serie
    Serial.print("Temperatura: "+temperatura+", humedad: "+humedad+,", sens. termica: "+indice_de_calor);
  #endif
 
  delay(3000); //esperamos 3 segundos entre cada medición
 
}
