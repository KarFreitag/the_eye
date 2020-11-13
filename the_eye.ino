int x0, y0, x1, y1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x1 = analogRead(1);   // Auslesen des Wertes, der an A1 anliegt.
  y1 = analogRead(A0);  // Auslesen des Wertes, der an A0 anliegt.

  if ((x0 != x1) || (y0 != y1)){
    x0 = x1;
    y0 = y1;
    Serial.print("X: ");      
    Serial.print(x0, DEC);
    Serial.print(" | Y:");
    Serial.print(y0, DEC);
    Serial.print("\n");
  }
}
