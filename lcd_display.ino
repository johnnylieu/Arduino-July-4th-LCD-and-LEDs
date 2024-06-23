#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// LED pins
int LED1 = 4;
int LED2 = 3;
int LED3 = 2;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2); // Initialize LCD: 16 columns, 2 rows

  // Initialize LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Clear initial message space
  lcd.setCursor(0, 0);
  lcd.print("                ");

  delay(1000); // Delay before printing initial message
  lcd.setCursor(0, 0);
  lcd.print("     Wassup   "); // Print initial message
  lcd.setCursor(0, 1);
  lcd.print("   Brain Corp!   ");

  delay(2000); // Delay to see initial message
}

void loop() {
  // Continuous scrolling of both messages
  scrollTopMessage("HAPPY JULY 4TH!");
  scrollBottomMessage("from RAS!");
  flashMessages("HAPPY JULY 4TH!", "from RAS!");
  displayFireworks(); // Display fireworks with LEDs flashing
  displayFinalMessage(); // Display the final message
  delay(5000); // Delay before restarting
}

void scrollTopMessage(String message1) {
  int message1Length = message1.length();
  int scrollLength = message1Length + 16;

  for (int i = 0; i < scrollLength; i++) {
    lcd.clear(); // Clear screen

    int pos1 = 16 - (i % (message1Length + 16));
    lcd.setCursor(pos1 < 0 ? 0 : pos1, 0);
    lcd.print(message1.substring(pos1 < 0 ? -pos1 : 0));

    delay(300); // Adjust delay for slower scrolling
  }
}

void scrollBottomMessage(String message2) {
  int message2Length = message2.length();
  int scrollLength = message2Length + 16;

  for (int i = 0; i < scrollLength; i++) {
    lcd.clear(); // Clear screen

    // Bottom message scrolling from left to right
    int pos2 = i - 16;
    lcd.setCursor(pos2, 1);
    lcd.print(message2.substring(0, 16));

    delay(300); // Adjust delay for slower scrolling
  }
}

void flashMessages(String message1, String message2) {
  int startPos1 = (16 - message1.length()) / 2; // Calculate starting position for message1
  int startPos2 = (16 - message2.length()) / 2; // Calculate starting position for message2

  for (int i = 0; i < 4; i++) { // Flash 4 times
    lcd.clear(); // Clear the screen
    delay(500); // Wait for half a second

    // Display the messages again, centered
    lcd.setCursor(startPos1, 0);
    lcd.print(message1);
    lcd.setCursor(startPos2, 1);
    lcd.print(message2);
    delay(500); // Wait for half a second
  }
}

void displayFireworks() {
  // Fireworks animation loop with LEDs flashing
  for (int i = 0; i < 3; i++) { // Repeat the animation 3 times
    // First fireworks line and LEDs on
    lcd.setCursor(0, 0);
    lcd.print("* * * * * * * * ");
    digitalWrite(LED1, HIGH); // turn on LED1 
    delay(200); // wait for 200ms
    digitalWrite(LED2, HIGH); // turn on LED2
    delay(200); // wait for 200ms       
    digitalWrite(LED3, HIGH); // turn on LED3 
    delay(200); // wait for 200ms

    // Second fireworks line
    lcd.setCursor(0, 1);
    lcd.print(" * * * * * * * *");

    delay(1000); // 1 second delay before next frame

    // Clear the screen for the next frame
    lcd.clear();

    // Second fireworks line and LEDs off
    lcd.setCursor(0, 0);
    lcd.print(" * * * * * * * *");
    digitalWrite(LED1, LOW); // turn off LED1
    delay(300); // wait for 300ms
    digitalWrite(LED2, LOW); // turn off LED2
    delay(300); // wait for 300ms
    digitalWrite(LED3, LOW); // turn off LED3
    delay(300); // wait for 300ms before running program all over again

    // First fireworks line
    lcd.setCursor(0, 1);
    lcd.print("* * * * * * * * ");

    delay(1000); // 1 second delay before next frame

    // Delay between frames
    delay(500); // 0.5 second delay between frames
  }
}

void displayFinalMessage() {
  lcd.clear(); // Clear the screen
  lcd.setCursor(0, 0);
  lcd.print("Iron Man Johnny");
  lcd.setCursor(0, 1);
  lcd.print("loves you all!!!");

  delay(2000); // Display the message for 5 seconds
}