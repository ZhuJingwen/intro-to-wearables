int ledPin = 10;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {

  if (brightness < 255) {
    brightness++;
  } else {
    brightness = 0;
  }

  analogWrite(ledPin, brightness);
}
