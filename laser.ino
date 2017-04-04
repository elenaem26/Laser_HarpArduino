#include <SoftwareSerial.h>

int laserPin0 = 7;
int laserPin1 = 8;  
int laserPin2 = 9;  
int laserPin3 = 10;
int laserPin4 = 11;  
int laserPin5 = 12;  
int res0 = 0;
int res1 = 1;
int res2 = 2;
int res3 = 3;
int res4 = 4;
int res5 = 5;

bool sended[5] = {false, false, false, false, false};


SoftwareSerial bluetooth(2, 3);

void setup () {   
   Serial.begin(9600);
   bluetooth.begin(9600);
   pinMode (laserPin0, OUTPUT); 
   pinMode (laserPin1, OUTPUT);  
   pinMode (laserPin2, OUTPUT);  
   pinMode (laserPin3, OUTPUT);  
   pinMode (laserPin4, OUTPUT);  
   pinMode (laserPin5, OUTPUT);   
}  
void loop () {  
  digitalWrite (laserPin0, HIGH);  
  digitalWrite (laserPin1, HIGH);  
  digitalWrite (laserPin2, HIGH);  
  digitalWrite (laserPin3, HIGH); 
  digitalWrite (laserPin4, HIGH);  
  digitalWrite (laserPin5, HIGH); 
  
  for (int i = 0; i < 5; i++) {
    int value = analogRead(i);
    Serial.print(value);
    Serial.print("   ");
  }
  Serial.println("");
  
  if (isSendedEdit()) {
    setSendedMass();
  }
}

void setSendedMass() {
  for (int i = 0; i < 5; i++) {
    int value = analogRead(i);
    bool b = i == 3 ? value < 200 : i == 4 ? value < 100 : value > 100;
    sended[i] = b;
  }
  printSended();
}

bool isSendedEdit() {
  for (int i = 0; i < 5; i++) {
    int value = analogRead(i);
    bool b = i == 3 ? value < 200 : i == 4 ? value < 100 : value > 100;
    if (sended[i] != b) {
      return true;
    }
  }
  return false;
}

void printSended() {
  for (byte  i = 0; i < 5; i++) {
    if (sended[i]) {
      bluetooth.println(String(i));
    }
  }
}

