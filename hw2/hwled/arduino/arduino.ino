#include <ros.h>
#include <std_msgs/Char.h>
#include <LiquidCrystal.h>

ros::NodeHandle nh;
bool fb;
byte x = 5;
byte y = 1;
byte pseudot[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void messageCb( const std_msgs::Char& msg) {
  moveCursor(msg.data);
}

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);
ros::Subscriber<std_msgs::Char> sub("wasd", &messageCb);

void setup()
{ 
  Serial.begin(9600);
  lcd.begin(16, 2);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  lcd.setCursor(x, y);
  nh.spinOnce();
  delay(1);
}

void moveCursor(char key){
  if (key != 209) {
    if (x == 15) x = 0;
    else x++;
  }
}
