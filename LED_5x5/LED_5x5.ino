int anodes[5] = {8, 9, 10, 11, 12}; //pin numbers
int cathodes[5] = {2, 3, 4, 5, 6}; //pin numbers

void setup() {
  
  //initialize pins
  for(int i = 0; i < 5; i++) {
    pinMode(anodes[i], OUTPUT);
    pinMode(cathodes[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(anodes[i], HIGH);
    for(int j = 0; j < 5; j++) {
      digitalWrite(cathodes[j], LOW);
      delay(200);
      digitalWrite(cathodes[j], HIGH);
    }
    digitalWrite(anodes[i], LOW);
  }
}
