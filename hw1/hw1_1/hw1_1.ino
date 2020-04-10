int hw = 2;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if (hw == 1) hw1();
  else if (hw == 2) hw2();
}

void hw1() {
  digitalWrite(13, 1);
  delay(50);
  digitalWrite(13, 0);
  delay(450);
}

void hw2() {
  for (int i = 0; i < 3; i++) {
    morse(300);
  }
  for (int i = 0; i < 3; i++) {
    morse(600);
  }
  for (int i = 0; i < 3; i++) {
    morse(300);
  }
  delay(500);
}

void morse(int ms) {
    digitalWrite(13, 1);
    delay(ms);
    digitalWrite(13, 0);
    delay(50);
}
