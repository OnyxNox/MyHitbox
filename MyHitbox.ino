#include <Keyboard.h>

#define UP_BUTTON_PIN      16
#define DOWN_BUTTON_PIN     9
#define LEFT_BUTTON_PIN    10
#define RIGHT_BUTTON_PIN    8
#define X_BUTTON_PIN        3
#define Y_BUTTON_PIN        2
#define A_BUTTON_PIN        7
#define B_BUTTON_PIN        6
#define R1_BUTTON_PIN       0
#define R2_BUTTON_PIN       5
#define L1_BUTTON_PIN       1
#define L2_BUTTON_PIN       4
#define EXTRA_1_BUTTON_PIN 19
#define EXTRA_2_BUTTON_PIN 20
#define EXTRA_3_BUTTON_PIN 21

#define UP_BUTTON_ASCII      119  // w
#define DOWN_BUTTON_ASCII    115  // s
#define LEFT_BUTTON_ASCII     97  // a
#define RIGHT_BUTTON_ASCII   100  // d
#define X_BUTTON_ASCII       117  // u
#define Y_BUTTON_ASCII       105  // i
#define A_BUTTON_ASCII       106  // j
#define B_BUTTON_ASCII       107  // k
#define R1_BUTTON_ASCII      111  // o
#define R2_BUTTON_ASCII      108  // l
#define L1_BUTTON_ASCII      112  // p
#define L2_BUTTON_ASCII       59  // ;
#define EXTRA_1_BUTTON_ASCII  10  // (enter) line feed
#define EXTRA_2_BUTTON_ASCII  92  // (\) backslash
#define EXTRA_3_BUTTON_ASCII   8  // backspace

#define LOG_THRESHOLD_MS 5000

struct Button
{
    unsigned int Pin;
    unsigned int AsciiOutput;
    unsigned int State;
    unsigned int PreviousState;
};

Button buttons[15] =
{
    { UP_BUTTON_PIN     , UP_BUTTON_ASCII     , HIGH, HIGH },
    { DOWN_BUTTON_PIN   , DOWN_BUTTON_ASCII   , HIGH, HIGH },
    { LEFT_BUTTON_PIN   , LEFT_BUTTON_ASCII   , HIGH, HIGH },
    { RIGHT_BUTTON_PIN  , RIGHT_BUTTON_ASCII  , HIGH, HIGH },
    { X_BUTTON_PIN      , X_BUTTON_ASCII      , HIGH, HIGH },
    { Y_BUTTON_PIN      , Y_BUTTON_ASCII      , HIGH, HIGH },
    { A_BUTTON_PIN      , A_BUTTON_ASCII      , HIGH, HIGH },
    { B_BUTTON_PIN      , B_BUTTON_ASCII      , HIGH, HIGH },
    { R1_BUTTON_PIN     , R1_BUTTON_ASCII     , HIGH, HIGH },
    { R2_BUTTON_PIN     , R2_BUTTON_ASCII     , HIGH, HIGH },
    { L1_BUTTON_PIN     , L1_BUTTON_ASCII     , HIGH, HIGH },
    { L2_BUTTON_PIN     , L2_BUTTON_ASCII     , HIGH, HIGH },
    { EXTRA_1_BUTTON_PIN, EXTRA_1_BUTTON_ASCII, HIGH, HIGH },
    { EXTRA_2_BUTTON_PIN, EXTRA_2_BUTTON_ASCII, HIGH, HIGH },
    { EXTRA_3_BUTTON_PIN, EXTRA_3_BUTTON_ASCII, HIGH, HIGH },
};

unsigned int buttonsCount;

Button* upButtonPtr    = &buttons[0];
Button* downButtonPtr  = &buttons[1];
Button* leftButtonPtr  = &buttons[2];
Button* rightButtonPtr = &buttons[3];

unsigned int tempLeftButtonState = HIGH;

void setup()
{
    buttonsCount = sizeof(buttons) / sizeof(buttons[0]);

    for (unsigned int i = 0; i < buttonsCount; ++i)
    {
        pinMode(buttons[i].Pin, INPUT_PULLUP);
    }

    Keyboard.begin();
    Serial.begin(9600);
}

void loop()
{
    // set all buttons current state
    for (unsigned int i = 0; i < buttonsCount; i++)
    {
        buttons[i].State = digitalRead(buttons[i].Pin);
    }

    // vertical Simultaneous Opposing Cardinal Directions (SOCD) filter
    downButtonPtr->State = downButtonPtr->State == LOW && upButtonPtr->State == HIGH ? LOW : HIGH;

    // horizontal SOCD filter
    tempLeftButtonState = leftButtonPtr->State == LOW && rightButtonPtr->State == LOW
        ? HIGH : leftButtonPtr->State;
    rightButtonPtr->State = rightButtonPtr->State == LOW && leftButtonPtr->State == LOW
        ? HIGH : rightButtonPtr->State;
    leftButtonPtr->State = tempLeftButtonState;

    for (unsigned int i = 0; i < buttonsCount; i++)
    {
        if (buttons[i].State == LOW && buttons[i].State != buttons[i].PreviousState)
        {
            Keyboard.press(buttons[i].AsciiOutput);
        }
        else if (buttons[i].State == HIGH)
        {
            Keyboard.release(buttons[i].AsciiOutput);
        }
    }

    // set all buttons previous state
    for (unsigned int i = 0; i < buttonsCount; i++)
    {
        buttons[i].PreviousState = buttons[i].State;
    }
}
