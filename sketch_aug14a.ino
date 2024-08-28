// Pin Definitions
const int ledPin = LED_BUILTIN;  // Pin for the built-in LED
const int buttonPin = 2;         // Pin for the push button

// Morse code timing constants (in milliseconds)
const int dotDuration = 200;      // Duration of a dot
const int dashDuration = dotDuration * 3; // Duration of a dash
const int letterSpace = dotDuration * 3;  // Space between letters
const int wordSpace = dotDuration * 7;    // Space between words

// Morse code for the name "Anmol_Bhutani"
String morseCode = ".- -. -- --- .-.. _ -... .... ..- - .- -. ..";  
String name = "Anmol_Bhutani"; 

// Variables to track the button state
bool buttonState = LOW;            // Current state of the button
bool lastButtonState = LOW;        // Previous state of the button

void setup() {
  pinMode(ledPin, OUTPUT);         // Set the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as an input
  Serial.begin(9600);              // Initialize serial monitor at 9600 baud
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the current state of the button
  
  // Check if the button was pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Name: " + name);       // Print the name to the serial monitor
    Serial.println("Morse Code: " + morseCode); // Print the Morse code to the serial monitor
    
    // Loop through each character in the Morse code string
    for (int i = 0; i < morseCode.length(); i++) {
      if (morseCode[i] == '.') {
        blinkDot();   // Blink the LED for a dot
      } else if (morseCode[i] == '-') {
        blinkDash();  // Blink the LED for a dash
      } else if (morseCode[i] == ' ') {
        delay(letterSpace); // Wait for the space between letters
      }

      // Check if the button is pressed again during the blinking sequence
      if (digitalRead(buttonPin) == LOW) {
        i = -1; // Reset the loop index to start over from the beginning
      }
    }
  }

  lastButtonState = buttonState; // Update the last button state
}

// Function to blink the LED for a dot
void blinkDot() {
  digitalWrite(ledPin, HIGH);  // Turn on the LED
  delay(dotDuration);          // Wait for the dot duration
  digitalWrite(ledPin, LOW);   // Turn off the LED
  delay(dotDuration);          // Wait before the next signal
}

// Function to blink the LED for a dash
void blinkDash() {
  digitalWrite(ledPin, HIGH);  // Turn on the LED
  delay(dashDuration);         // Wait for the dash duration
  digitalWrite(ledPin, LOW);   // Turn off the LED
  delay(dotDuration);          // Wait before the next signal
}