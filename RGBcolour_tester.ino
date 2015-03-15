#include <RGBcolour.h>
#include "Arduino.h"
#include <Bridge.h>
#include <Console.h>





#include "Tlc5940.h"




RGBcolour myColour(1500,1000,100);
int flashled = 13;


void setup() {
  pinMode(flashled, OUTPUT);
  ledSignal(1000, false);
  
  Serial.begin(9600);
  printMessage("Building bridge");
  //Bridge.begin();
  printMessage("Bridge built!");
  delay(3000);
  //if (Console) Console.println("Lightman tester console");
  printMessage("(RGBcolour tester console)");
  
  Tlc.init(4000);
  Tlc.update(); 
  
  
  
  delay(4000);
  Tlc.setAll(0); 
  Tlc.update(); 
  
  
  
  
  int iDummy;
  
  printMessage("constants from library");
  printMessage(String(myColour.iRED));
  printMessage(String(myColour.iBLUE));
  printMessage(String(myColour.iGREEN));
  
  ledSignal(500,true);
  
  
  
}

void loop() {
  
  
  Tlc.set(1, myColour.Red());
  Tlc.set(17, myColour.Blue());
  Tlc.set(33, myColour.Green());
  
  Tlc.update();
  delay(5000);
  
  Tlc.setAll(0);
  Tlc.update();
  delay(5000);
 // *myColour = new RGBcolour(230,255,10);
  
  
}

void forLoop() {
  printMessage("starting for loop");
  
  int li;
  int colour;
  int R;
  int G;
  int B;
  
  
  for (colour = 0; colour <=2; colour+=1){
   R = colour==0;
   G = colour==1;
   B = colour==2;
     
    for (li = 0; li <= 15; li +=1){
    //larray.set_light(li,R*4000,G*4000,B*4000);
    printMessage("light: " + String(li));
    delay(1000);
    Tlc.update(); 
   }
  }    
  

  //Tlc.init(0);
  Tlc.update(); 
}



void printMessage(String msg) {
  if (Console) Console.println("C: " + msg);
  if (Serial) Serial.println("S: " + msg);
}
String doubletostring (double number){
  char tempChar[32];
  dtostrf(number,4,2,tempChar);
  String tempString;
  tempString = String(tempChar);
  return tempString;
}  

void ledSignal(int gap, bool endHigh){
  
  delay(gap);
  
  digitalWrite(flashled, HIGH);
  delay(gap);
  digitalWrite(flashled, LOW);
  delay(gap);
  digitalWrite(flashled, HIGH);
  delay(gap);
  digitalWrite(flashled, LOW);
  if (endHigh){ delay(gap); digitalWrite(flashled, HIGH);}
  
  printMessage("loop");
 

}





