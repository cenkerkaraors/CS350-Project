int sensorPin = A0; // hum
int sensorPin2 = A1; // temp
int sensorPin3 = A2; // light
int sensorValue = 0;
int percent = 0;
float temp;
int light = 0;
int lightValue = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin,INPUT);
  pinMode(sensorPin2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  percent = convertToPercent(sensorValue);
  printValuesToSerial();

  //temp
  temp = analogRead(sensorPin2);
  temp = (temp*500)/2026;// 1023
  printTempValuesToSerial();

  //Light
  light = analogRead(sensorPin3);
  lightValue = map(light, 100, 0, 0, 100);
  printLightToSerial();
  printError();

  
  delay(3000);
  

}
int convertToPercent(int value)
{
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}

void printValuesToSerial()
{
  //Serial.print("1/1/00/Analog Value: ");
  Serial.print("1/1/00/");
  //Serial.print(sensorValue);
  //Serial.print("/");
  Serial.print(percent);
  Serial.print("/");
  Serial.print("Percent");
  Serial.print("/");
  Serial.print("%\n");
}
void printTempValuesToSerial()
{
  Serial.print("1/1/01/");
  Serial.print(temp);
  Serial.print("/");
  Serial.print("Celsius");
  Serial.print("/");
  Serial.print("*C\n");
}
void printLightToSerial()
{
  Serial.print("1/1/10/");
  Serial.print(lightValue);
  Serial.print("/");
  Serial.print("NMeter");
  Serial.print("/");
  Serial.print("nm\n");
}
void printError()
{
  if(temp >= 60) {
    Serial.print("1/0/00/");
    Serial.print(temp);
    Serial.print("\n");
    }
  if(percent >= 20 ) {
    Serial.print("1/0/00/");
    Serial.print(temp);
    Serial.print("\n");
    }
}
