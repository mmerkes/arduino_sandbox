int rows[5] = {8, 9, 10, 11, 12}; //pin numbers
int cols[5] = {2, 3, 4, 5, 6}; //pin numbers

//0 is off, 1 is on
//a sketch for a smiley face
int smileyFace[5][5] = {
  {0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0}
};

int sadFace[5][5] = {
  {1, 0, 0, 0, 1},
  {0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 1, 1, 1, 0},
  {1, 0, 0, 0, 1}
};

int heart[5][5] = {
  {0, 1, 0, 1, 0},
  {1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {0, 1, 1, 1, 0},
  {0, 0, 1, 0, 0}
};

int alligator[5][5] = {
  {0, 1, 1, 1, 0},
  {1, 1, 0, 1, 1},
  {0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1},
  {0, 1, 1, 1, 0}
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
  drawFigure(smileyFace);
}

void drawFigure(int figure[5][5]) {
  //initializes the current milliseconds since the program started
  unsigned long currentMillis = millis();
  
  //repeatedly lights up the LEDs per the predetermined pattern
  //until the milliseconds reaches the interval
  while(currentMillis - previousMillis < interval) {
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++) {   
        //if the row is on, set the column to low
        //and turn switch the LED off after a 1 millisecond delay
        if(figure[i][j] == 1) {
          digitalWrite(rows[i], HIGH);
          digitalWrite(cols[j], LOW);
          delay(1);
          digitalWrite(cols[j], HIGH);
          digitalWrite(rows[i], LOW);
        }
      }
    }
    //reset current milliseconds
    currentMillis = millis();
  }
  
  //reset the previous milliseconds to in order to
  //draw another figure.
  previousMillis = currentMillis;
}

void drawInverseFigure(int figure[5][5]) {
  //initializes the current milliseconds since the program started
  unsigned long currentMillis = millis();
  
  //repeatedly lights up the LEDs per the predetermined pattern
  //until the milliseconds reaches the interval
  while(currentMillis - previousMillis < interval) {
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++) {
        //if the row is on, set the column to low
        //and turn switch the LED off after a 1 millisecond delay
        if(figure[i][j] == 0) {
          digitalWrite(rows[i], HIGH);
          digitalWrite(cols[j], LOW);
          delay(1);
          digitalWrite(cols[j], HIGH);
          digitalWrite(rows[i], LOW);
        }
      }
    }
    //reset current milliseconds
    currentMillis = millis();
  }
  
  //reset the previous milliseconds to in order to
  //draw another figure.
  previousMillis = currentMillis;
}
