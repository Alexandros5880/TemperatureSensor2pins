#include "temperature.h"

int R1 = 14777;
int pin = A0;
int sampleLen = 77;
Temp * temp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  temp = new Temp(R1, pin, sampleLen);
  float Tc = temp->getCelsius();
  float Tf = temp->getFehrenhait(); 

  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  delay(33);
  delete temp;
}
