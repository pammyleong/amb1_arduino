/*
  This sketch demonstrate how to streaming video of usb camera.
  Ameba receive video data from usb port and streaming out on wifi with rtsp protocol.
  User can receive ths streaming data on PC or laptop with rtsp player.

  In this sketch you need:
    Ameba x 1
    usb camera x 1
    OTG wire x 1 (with extra power line on OTG if needed)

  At first Ameba start wifi on AP mode.
  Then Ameba open UVC service.
  User can use mobile phone or laptop connect to Ameba's ssid.
  After UVC service is enabled, user can use rtsp player and open streaming with address:
    rtsp://192.168.1.1/test.sdp

*/

#include <WiFi.h>
#include <UVC.h>

char ssid[] = "yourNetwork";        // Set the AP's SSID
char pass[] = "Password";     // Set the AP's password
char channel[] = "6";         // Set the AP's channel
int status = WL_IDLE_STATUS;  // the Wifi radio's status

void setup() {

  status = WiFi.status();

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.apbegin(ssid, pass, channel);
    if (status == WL_CONNECTED) {
      break;
    }
    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("AP mode already started");

  // Default setting is motion jpeg with 320x240 resolution and frame rate is 30fps
  UVC.begin();
  // Try below setting if you want better resolution
  //UVC.begin(UVC_MJPEG, 640, 480, 30, 0);

  // wait until UVC is ready for streaming
  while (!UVC.available()) {
    delay(100);
  }
  Serial.println("UVC is ready");
  Serial.println("Open your rtsp player with this address:");
  Serial.println("\trtsp://192.168.1.1/test.sdp");
}

void loop() {
  delay(10000);
}
