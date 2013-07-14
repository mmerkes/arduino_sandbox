// 2-dimensional array of column pin numbers:
const int col[8] = {
  2,3,4,5,A2,A3,A4,A5
};

// 2-dimensional array of row pin numbers:
const int row[8] = {
  6,7,8,9,10,11,12,13
};

unsigned long previousMillis = 0;
long interval = 5000;

// 0 is off, 1 is on
int flower[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,0,1,1,0,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0}
};

int smileyFace[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0}
};

int spaceship[8][8] = {
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,1},
  {0,1,1,0,0,0,1,1},
  {0,1,0,0,0,0,0,1}
};

int house[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {0,1,0,1,1,1,1,0},
  {0,1,1,1,0,0,1,0},
  {0,1,1,1,0,0,1,0},
  {0,1,1,1,0,0,1,0}
};

int archie[8][8] = {
  {0,0,1,0,0,1,0,0},
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0}
};

void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    //take the row pins (i.e. the cathodes) high to ensure LEDs are off
    //digitalWrite(col[thisPin], HIGH);
  }
}

void loop() {
  drawFigure(flower);
  drawFigure(smileyFace);
  drawFigure(spaceship);
  drawFigure(house);
  drawFigure(archie);
}

void drawFigure(int figure[8][8]) {
  //initializes the current milliseconds since the program started
  unsigned long currentMillis = millis();
  
  //repeatedly lights up the LEDs per the predetermined pattern
  //until the milliseconds reaches the interval
  while(currentMillis - previousMillis < interval) {
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++) {   
        //if the row is on, set the column to low
        //and turn switch the LED off after a 1 millisecond delay
        if(figure[i][j] == 1) {
          digitalWrite(col[j], HIGH);
          digitalWrite(row[i], LOW);
          //delay(1);
          digitalWrite(row[i], HIGH);
          digitalWrite(col[j], LOW);
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

