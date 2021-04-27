
// Leds form 2 to 9
const int NUM_LEDS = 8;
const int START_LED = 2;

// Pin for button
const int PIN_BUTTON = 13;

// Time delay
const int DELAY = 100; 

// For check mode_1 and mode_2
bool check = false;

// Turn off all leds
void turnOffAll() {
    for(int led = START_LED; led < START_LED + NUM_LEDS; ++led) {
        digitalWrite(led, LOW);
    }
}

// Check pressed button event
bool isPressed() {
    int value = digitalRead(PIN_BUTTON);
    if(value == HIGH) return true;
    else return false;
}

// Use leds from 2 to 4
void mode_1() {
    int led = START_LED;
    while(true) {
        if(isPressed()) break;
        turnOffAll();
        digitalWrite(led, HIGH);
        ++led;
        if(led >= START_LED + 3) led = 0;
        delay(DELAY);
    }
    mode_2();
}

// Use leds form 2 to 9
void mode_2() {
    int led = START_LED;
    bool is_up = true;
    while(true) {
        if(isPressed()) break;
        digitalWrite(led, HIGH);
        delay(DELAY);
        if(is_up) ++led;
        else --led;
        if(led >= START_LED + NUM_LEDS) {
            led = START_LED + NUM_LEDS - 1;
            is_up = false;
            turnOffAll();
        }
        if(led < START_LED) {
            led = START_LED;
            is_up = true;
            turnOffAll();
        }
    }
    mode_1();
}

// Main code
void setup() {
    pinMode(PIN_BUTTON, INPUT);
    for(int led = START_LED; led < START_LED + NUM_LEDS; ++led) {
        pinMode(led, OUTPUT);
    }
}

void loop() {
    mode_1();
}
