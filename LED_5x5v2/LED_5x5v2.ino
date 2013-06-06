int rows[5] = {8, 9, 10, 11, 12}; //pin numbers
int cols[5] = {2, 3, 4, 5, 6}; //pin numbers

int smiley[5][5] = {
  {LOW, HIGH, LOW, HIGH, LOW},
  {LOW, LOW, LOW, LOW, LOW},
  {LOW, LOW, HIGH, LOW, LOW},
  {HIGH, LOW, LOW, LOW, HIGH},
  {LOW, HIGH, HIGH, HIGH, LOW}
};

long previousMillis = 0;
long interval = 1000;

void setup() {
  
  //initialize pins
  for(int i = 0; i < 5; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
  }
}

void loop() {
  drawFigure(smiley);
}

void drawFigure(int figure[5][5]) {
  unsigned long currentMillis = millis();
  
  while(currentMillis - previousMillis > interval) {
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++) {
        digitalWrite(rows[i], figure[i][j]);
        if(figure[i][j] == HIGH) {
          digitalWrite(cols[j], LOW);
          delay(1);
          digitalWrite(cols[j], HIGH);
          digitalWrite(rows[i], LOW);
        }
      }
    }
  }
  
  previousMillis = currentMillis;
}
