Erstelle eine Datei parameter.h mit folgendem Inhalt:

// Definitionen der variablen Parameter

// WiFi-Anmeldung
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORT"

// IP des RASPIs
#define MQTT_SERVER "192.168.0.100"

// Timer
#define INTERVALL 1000

// ESP Name
#define ESP_NAME "ESP_1"
// #define ESP_NAME "ESP_2"
// #define ESP_NAME "ESP_3"
// #define ESP_NAME "ESP_4"

// PINs der Sensoren am ESP
// ESP 1
#define INFRARED_PIN D0
#define RFID_RST D1
#define RFID_SS D2
#define DISPLAY_SCK D3
#define DISPLAY_SDA D4
#define PIXY_SS D8
#define ULTRA_TRIG 1 // TX -> heißt keine Serial verwenden
#define ULTRA_ECHO 3 // RX -> heißt keine Serial verwenden
#define VOLTAGE A0

// ESP 2
#define PIR_PIN D0
#define TEMP1_PIN A0
// ESP 3
#define FLAME_PIN D0
#define TEMP2_PIN D1
#define GAS_PIN A0
// ESP 4
#define TEMP_HUMIDITY_PIN D0
#define VAPOR_PIN A0

// MQTT-Topics
// ESP 1
#define INFRARED_SEND "infrared/value"
#define RFID_SEND "rfid/uid"
#define PIXY_SEND "pixy/barcode"
#define ULTRA_SEND "ultra/value"
#define VOLTAGE_SEND "voltage/value"
#define DISPLAY_RECEIVE "display/access"
// ESP 2
#define PIR_SEND "pir/value"
#define TEMP1_SEND "temp1/value"
// ESP 3
#define FLAME_SEND "flame/value"
#define TEMP2_SEND "temp2/value"
#define GAS_SEND "gas/value"
// ESP 4
#define TEMP3_SEND "temp3/value"
#define HUMIDITY_SEND "humidity/value"
#define VAPOR_SEND "vapor/value"

// Dies ist nur ein Beispiel, passe die Parameter an