int leds[] = {3, 5, 6, 9, 10, 11};
int ledsState[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long intervals[] = {15625, 31250, 62500, 125000, 250000, 500000};
unsigned long previousIntervals[] = {0, 0, 0, 0, 0, 0};
unsigned long currentTime;

void setup() {
  for (int ledN = 0; ledN < 6; ledN++)
  {
    pinMode(leds[ledN], OUTPUT);
  }
}

void loop() {
  for (int ledN = 0; ledN < 6; ledN++)
  {    
    currentTime = micros();
    if (currentTime - previousIntervals[ledN] >= intervals[ledN]) {
      previousIntervals[ledN] = currentTime;

      ledsState[ledN] = !ledsState[ledN];
      digitalWrite(leds[ledN], ledsState[ledN]);
    }
  }
}
