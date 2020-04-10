void setup() {
  pinMode(2, OUTPUT);
  pinMode(A4, INPUT);
}

void loop() {
  if (analogRead(A4))
    digitalWrite(2, 1);
   else
    digitalWrite(2, 0);
}
