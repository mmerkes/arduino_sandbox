// 2-dimensional array of column pin numbers:
const int col[8] = {
  2,3,4,5,16,17,18,19
};

// 2-dimensional array of row pin numbers:
const int row[8] = {
  6,7,8,9,10,11,12,13
};



void setup() {
  // initialize the I/O pins as outputs
  // iterate over the pins
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins
    pinMode(col[thisPin], OUTPUT);
    pinMode(col[thisPin], OUTPUT);
    //take the row pins (i.e. the cathodes) high to ensure LEDs are off
    //digitalWrite(col[thisPin], HIGH);
  }
}

void loop() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      digitalWrite(col[i], HIGH);
      digitalWrite(row[j], LOW);
      delay(1000);
      digitalWrite(row[j], HIGH);
    }
    digitalWrite(col[i], LOW);
  } 
};
