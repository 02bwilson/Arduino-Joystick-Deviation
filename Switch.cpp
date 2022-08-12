// Define the pins for the Joystick
#define VRX A5
#define VRY A4
#define SW A3

// Base readings of the joystick
const int XBASE = 511;
const int YBASE = 507;
const int SWBASE = 390;
// % that joystick must move to trigger deviation condition
const double DEVIATION = .10;

int xRead;
int yRead;
int swRead;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);
  xRead = analogRead(VRX);
  yRead = analogRead(VRY);
  swRead = analogRead(SW);
  // Determine if X is past deviation
  if(XBASE * (1.0 - DEVIATION >= xRead || XBASE * (1.0 + DEVIATION) <= xRead)){
    Serial.println("X PAST DEVIATION: READING: " + static_cast<String>(xRead));
  }
  // Determine if Y is past deviation
  if(YBASE * (1.0 - DEVIATION >= yRead || YBASE * (1.0 + DEVIATION) <= yRead)){
    Serial.println("Y PAST DEVIATION: READING: " + static_cast<String>(yRead));
  }
  Serial.println("TICK END");
}
