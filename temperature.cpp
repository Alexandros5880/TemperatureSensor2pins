#include "Arduino.h"
#include "temperature.h"

Temp::Temp(int R1, int pin, int samplesLen) {
  this->pin = pin;
  this->R1 = R1;
  this->samplesLen = samplesLen;
}

void Temp::getAVG() {
  float sum = 0.0;
  for (int i = 0; i < this->samplesLen; i++) {
    sum += analogRead(this->pin);
  }
  this->avg = sum / this->samplesLen;
}

void Temp::getKarven() {
  this->getAVG();
  float R2 = this->R1 * (1023.0 / this->avg - 1.0);
  float logR2 = log(R2);
  float T = (1.0 / (this->c1 + this->c2*logR2 + this->c3*logR2*logR2*logR2));
  this->karven = T;
  return T;
}

float Temp::getCelsius() {
  this->getKarven();
  float Tc = this->karven - 273.15;
  return Tc;
}

float Temp::getFehrenhait() {
  float celsius = this->getCelsius();
  float Tf = (celsius * 9.0)/ 5.0 + 32.0;
  return Tf;
}
