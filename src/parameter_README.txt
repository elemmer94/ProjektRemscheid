// Erstelle eine Datei parameter.h mit folgendem Inhalt:

// Definitionen der variablen Parameter

// ANPASSEN!!!
// -----------------------------------------------------
// WiFi-Anmeldung
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORT"

// IP RASPI
#define RASPI_IP "192.168.0.100"

// ESP Daten
#define ESP_NAME "ESP_1"
#define ESP_LASTWILL "esp/eingang/status"
#define ESP_IP "esp/eingang/ip"
#define ESP_MAC "esp/eingang/mac"
// -----------------------------------------------------

// Timer
#define INTERVALL 10000

// PINs der Sensoren am ESP
// ESP 1
#define INFRARED_PIN D0
#define RFID_SS D8
#define DISPLAY_SCK D4
#define DISPLAY_SDA D2
#define PIXY_SS D1
#define RELAIS D3
#define VOLTAGE A0
// ESP 2
#define PIR_PIN D0
#define TEMP1_PIN A0
#define ULTRA_TRIG D6
#define ULTRA_ECHO D7
// ESP 3
#define FLAME_PIN D0
#define TEMP2_PIN D1
#define GAS_PIN A0
// ESP 4
#define TEMP_HUMIDITY_PIN D0
#define VAPOR_PIN A0

// MQTT-Topics
// ESP 1
#define INFRARED_SEND "eingang/infrared"
#define RFID_SEND "eingang/rfid"
#define PIXY_SEND "eingang/pixy"
#define VOLTAGE_SEND "eingang/voltage"
#define DISPLAY_ACCESS "eingang/display/access"
// ESP 2
#define TEMP1_SEND "lager1/temp1"
#define ULTRA_SEND "lager1/ultra"
// ESP 3
#define FLAME_SEND "lager2/flame"
#define TEMP2_SEND "lager2/temp2"
#define GAS_SEND "lager2/gas"
// ESP 4
#define TEMP3_SEND "lager3/temp3"
#define HUMIDITY_SEND "lager3/humidity"
#define VAPOR_SEND "lager3/vapor"
#define PIR_SEND "lager3/pir"

// Dies ist nur ein Beispiel, passe die Parameter an