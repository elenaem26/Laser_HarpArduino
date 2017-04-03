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
int sended = -1;
void setup () {   
   Serial.begin(9600);
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
  if (areAllNotChecked()) {
    sended = -1;
  }
  if (analogRead(res0) > 100) {
    if (sended != 0) {
      Serial.println("0");
      sended = 0;
    }
  }
  if (analogRead(res1) > 100) {
    if (sended != 1) {
      Serial.println("1");
      sended = 1;
    }
  }
  if (analogRead(res2) > 100) {
    if (sended != 2) {
      Serial.println("2");
      sended = 2;
    }
  }
//   if (analogRead(res3) > 100) {
//    //if (sended != 3) {
//      Serial.println("3");
//      //sended = 3;
//    //}
//  }
//   if (analogRead(res4) > 100) {
//    //if (sended != 4) {
//      Serial.println("4");
//      //sended = 4;
//    //}
//  }
//   if (analogRead(res5) > 100) {
//    //if (sended != 5) {
//      Serial.println("5");
//      //sended = 5;
//    //}
//  }
} 

bool areAllNotChecked() {
  //TODO write the others
  return analogRead(res0) <= 100 && analogRead(res1) <= 100 && analogRead(res2) <= 100;
}

