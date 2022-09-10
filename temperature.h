#define ThermistorPin A0



class Temp {
  private:
    int pin, samplesLen, R1;
    float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07, &karven, &avg;
    void getAVG();
    void getKarven();
  public:
    Temp(int R1, int pin, int samplesLen);
    float getCelsius();
    float getFehrenhait();
};
