#include <Keyboard.h>

#define UP_BUTTON_PIN       2
#define DOWN_BUTTON_PIN     3
#define LEFT_BUTTON_PIN     4
#define RIGHT_BUTTON_PIN    5
#define X_BUTTON_PIN        6
#define Y_BUTTON_PIN        7
#define A_BUTTON_PIN        8
#define B_BUTTON_PIN        9
#define R1_BUTTON_PIN      10
#define R2_BUTTON_PIN      11
#define L1_BUTTON_PIN      12
#define L2_BUTTON_PIN      13
#define EXTRA_1_BUTTON_PIN 14
#define EXTRA_2_BUTTON_PIN 15
#define EXTRA_3_BUTTON_PIN 16


void setup()
{
    pinMode(UP_BUTTON_PIN     , INPUT_PULLUP);
    pinMode(DOWN_BUTTON_PIN   , INPUT_PULLUP);
    pinMode(LEFT_BUTTON_PIN   , INPUT_PULLUP);
    pinMode(RIGHT_BUTTON_PIN  , INPUT_PULLUP);
    pinMode(X_BUTTON_PIN      , INPUT_PULLUP);
    pinMode(Y_BUTTON_PIN      , INPUT_PULLUP);
    pinMode(A_BUTTON_PIN      , INPUT_PULLUP);
    pinMode(B_BUTTON_PIN      , INPUT_PULLUP);
    pinMode(R1_BUTTON_PIN     , INPUT_PULLUP);
    pinMode(R2_BUTTON_PIN     , INPUT_PULLUP);
    pinMode(L1_BUTTON_PIN     , INPUT_PULLUP);
    pinMode(L2_BUTTON_PIN     , INPUT_PULLUP);
    pinMode(EXTRA_1_BUTTON_PIN, INPUT_PULLUP);
    pinMode(EXTRA_2_BUTTON_PIN, INPUT_PULLUP);
    pinMode(EXTRA_3_BUTTON_PIN, INPUT_PULLUP);

    Keyboard.begin();

    Serial.begin(9600);
    Serial.println("Board has been initialized.");
}

void loop()
{
    // vertical Simultaneous Opposing Cardinal Directions (SOCD) filter
    if (digitalRead(UP_BUTTON_PIN) == LOW)
    {
        Keyboard.write('w');
    }
    else if (digitalRead(DOWN_BUTTON_PIN) == LOW)
    {
        Keyboard.write('s');
    }

    // horizontal SOCD filter
    if (digitalRead(LEFT_BUTTON_PIN) == LOW && digitalRead(RIGHT_BUTTON_PIN) == HIGH)
    {
        Keyboard.write('a');
    }

    // horizontal SOCD filter
    if (digitalRead(RIGHT_BUTTON_PIN) == LOW && digitalRead(LEFT_BUTTON_PIN) == HIGH)
    {
        Keyboard.write('d');
    }

    if (digitalRead(X_BUTTON_PIN) == LOW)
    {
        Keyboard.write('u');
    }

    if (digitalRead(Y_BUTTON_PIN) == LOW)
    {
        Keyboard.write('i');
    }

    if (digitalRead(A_BUTTON_PIN) == LOW)
    {
        Keyboard.write('j');
    }

    if (digitalRead(B_BUTTON_PIN) == LOW)
    {
        Keyboard.write('k');
    }

    if (digitalRead(R1_BUTTON_PIN) == LOW)
    {
        Keyboard.write('o');
    }

    if (digitalRead(R2_BUTTON_PIN) == LOW)
    {
        Keyboard.write('l');
    }

    if (digitalRead(L1_BUTTON_PIN) == LOW)
    {
        Keyboard.write('p');
    }

    if (digitalRead(L2_BUTTON_PIN) == LOW)
    {
        Keyboard.write(';');
    }

    if (digitalRead(L2_BUTTON_PIN) == LOW)
    {
        Keyboard.write(';');
    }

    if (digitalRead(EXTRA_1_BUTTON_PIN) == LOW)
    {
        // press Enter key
        Keyboard.println();
    }

    if (digitalRead(EXTRA_2_BUTTON_PIN) == LOW)
    {
        Keyboard.write('\\');
    }

    if (digitalRead(EXTRA_3_BUTTON_PIN) == LOW)
    {
        // backspace ASCII code
        Keyboard.write(8);
    }
}
