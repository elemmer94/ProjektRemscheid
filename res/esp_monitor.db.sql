BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "accessLog" (
	"id"	INTEGER,
	"credential_id"	INTEGER NOT NULL,
	"status"	TEXT NOT NULL CHECK("status" IN ('granted', 'denied')),
	"timestamp"	TEXT DEFAULT (datetime('now')),
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("credential_id") REFERENCES "credential"("id")
);
CREATE TABLE IF NOT EXISTS "alert" (
	"id"	INTEGER,
	"sensor_id"	INTEGER NOT NULL,
	"message"	TEXT NOT NULL,
	"severity"	TEXT NOT NULL CHECK("severity" IN ('info', 'warning', 'critical')),
	"timestamp"	TEXT DEFAULT (datetime('now')),
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("sensor_id") REFERENCES "sensor"("id")
);
CREATE TABLE IF NOT EXISTS "credential" (
	"id"	INTEGER,
	"user_id"	INTEGER NOT NULL,
	"type"	TEXT NOT NULL CHECK("type" IN ('rfid', 'pixy')),
	"value"	TEXT NOT NULL UNIQUE,
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("user_id") REFERENCES "users"("id")
);
CREATE TABLE IF NOT EXISTS "device" (
	"id"	INTEGER,
	"deviceName"	TEXT NOT NULL UNIQUE,
	"ip"	TEXT NOT NULL,
	"mac"	TEXT NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "sensor" (
	"id"	INTEGER,
	"device_id"	INTEGER NOT NULL,
	"type"	TEXT NOT NULL,
	"unit"	TEXT NOT NULL,
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("device_id") REFERENCES "device"("id")
);
CREATE TABLE IF NOT EXISTS "sensorData" (
	"id"	INTEGER,
	"sensor_id"	INTEGER NOT NULL,
	"value"	REAL NOT NULL,
	"timestamp"	TEXT DEFAULT (datetime('now')),
	PRIMARY KEY("id" AUTOINCREMENT),
	FOREIGN KEY("sensor_id") REFERENCES "sensor"("id")
);
CREATE TABLE IF NOT EXISTS "users" (
	"id"	INTEGER,
	"username"	TEXT NOT NULL UNIQUE,
	"password"	TEXT NOT NULL,
	"created_at"	TEXT DEFAULT (datetime('now')),
	PRIMARY KEY("id" AUTOINCREMENT)
);
INSERT INTO "accessLog" VALUES (156,1,'granted','2025-06-12 06:54:20');
INSERT INTO "accessLog" VALUES (157,1,'granted','2025-06-12 08:03:06');
INSERT INTO "accessLog" VALUES (158,2,'granted','2025-06-12 08:03:25');
INSERT INTO "accessLog" VALUES (159,1,'denied','2025-06-12 10:23:32');
INSERT INTO "alert" VALUES (1,7,'Alarm! Flammen erkannt!','critical','2025-06-12 19:37:42');
INSERT INTO "alert" VALUES (2,7,'Alarm! Flammen erkannt!','critical','2025-06-12 19:37:42');
INSERT INTO "alert" VALUES (3,7,'Alarm! Flammen erkannt!','critical','2025-06-12 20:20:55');
INSERT INTO "alert" VALUES (4,7,'Alarm! Flammen erkannt!','critical','2025-06-12 20:20:55');
INSERT INTO "alert" VALUES (5,7,'Alarm! Flammen erkannt!','critical','2025-06-12 20:20:56');
INSERT INTO "alert" VALUES (6,5,'Die Temperatur -3.13°C ist zu gering!','warning','2025-06-13 07:10:37');
INSERT INTO "alert" VALUES (7,5,'Die Temperatur -1.18°C ist zu gering!','warning','2025-06-13 07:11:37');
INSERT INTO "alert" VALUES (8,5,'Alarm! Die Temperatur -7.5°C ist kritisch!','critical','2025-06-13 07:13:02');
INSERT INTO "alert" VALUES (9,5,'Alarm! Die Temperatur -43.74°C ist kritisch!','critical','2025-06-13 07:31:11');
INSERT INTO "alert" VALUES (10,5,'Alarm! Die Temperatur -34.82°C ist kritisch!','critical','2025-06-13 07:32:12');
INSERT INTO "alert" VALUES (11,5,'Alarm! Die Temperatur -5.34°C ist kritisch!','critical','2025-06-13 07:33:12');
INSERT INTO "alert" VALUES (12,5,'Alarm! Die Temperatur -5.55°C ist kritisch!','critical','2025-06-13 07:34:12');
INSERT INTO "alert" VALUES (13,5,'Alarm! Die Temperatur -5.55°C ist kritisch!','critical','2025-06-13 07:35:12');
INSERT INTO "alert" VALUES (14,5,'Alarm! Die Temperatur -5.55°C ist kritisch!','critical','2025-06-13 07:36:12');
INSERT INTO "alert" VALUES (15,5,'Alarm! Die Temperatur -5.34°C ist kritisch!','critical','2025-06-13 07:37:12');
INSERT INTO "alert" VALUES (16,5,'Alarm! Die Temperatur -5.97°C ist kritisch!','critical','2025-06-13 07:38:13');
INSERT INTO "alert" VALUES (17,5,'Alarm! Die Temperatur -5.97°C ist kritisch!','critical','2025-06-13 07:39:13');
INSERT INTO "alert" VALUES (18,5,'Alarm! Die Temperatur -5.97°C ist kritisch!','critical','2025-06-13 07:40:13');
INSERT INTO "alert" VALUES (19,5,'Alarm! Die Temperatur -5.7°C ist kritisch!','critical','2025-06-13 07:41:14');
INSERT INTO "alert" VALUES (20,5,'Alarm! Die Temperatur -5.7°C ist kritisch!','critical','2025-06-13 07:42:28');
INSERT INTO "alert" VALUES (21,5,'Die Temperatur -3.9°C ist zu gering!','warning','2025-06-13 07:43:28');
INSERT INTO "alert" VALUES (22,5,'Die Temperatur -3.9°C ist zu gering!','warning','2025-06-13 07:44:28');
INSERT INTO "alert" VALUES (23,5,'Alarm! Die Temperatur -5.7°C ist kritisch!','critical','2025-06-13 07:45:55');
INSERT INTO "alert" VALUES (24,5,'Die Temperatur -3.9°C ist zu gering!','warning','2025-06-13 07:46:55');
INSERT INTO "alert" VALUES (25,5,'Alarm! Die Temperatur -77.1°C ist kritisch!','critical','2025-06-13 11:50:16');
INSERT INTO "alert" VALUES (26,5,'Alarm! Die Temperatur -76.53°C ist kritisch!','critical','2025-06-13 11:51:16');
INSERT INTO "alert" VALUES (27,5,'Alarm! Die Temperatur -76.53°C ist kritisch!','critical','2025-06-13 11:52:17');
INSERT INTO "alert" VALUES (28,5,'Alarm! Die Temperatur -76.47°C ist kritisch!','critical','2025-06-13 11:53:17');
INSERT INTO "alert" VALUES (29,5,'Alarm! Die Temperatur -76.59°C ist kritisch!','critical','2025-06-13 11:54:17');
INSERT INTO "alert" VALUES (30,5,'Alarm! Die Temperatur -96.17°C ist kritisch!','critical','2025-06-13 11:55:18');
INSERT INTO "alert" VALUES (31,5,'Alarm! Die Temperatur -96.65°C ist kritisch!','critical','2025-06-13 11:56:18');
INSERT INTO "alert" VALUES (32,5,'Alarm! Die Temperatur -80.63°C ist kritisch!','critical','2025-06-13 11:57:18');
INSERT INTO "alert" VALUES (33,5,'Alarm! Die Temperatur -80.63°C ist kritisch!','critical','2025-06-13 11:58:18');
INSERT INTO "alert" VALUES (34,5,'Alarm! Die Temperatur -80.72°C ist kritisch!','critical','2025-06-13 11:59:18');
INSERT INTO "alert" VALUES (35,5,'Alarm! Die Temperatur -80.72°C ist kritisch!','critical','2025-06-13 12:00:19');
INSERT INTO "alert" VALUES (36,5,'Alarm! Die Temperatur -80.72°C ist kritisch!','critical','2025-06-13 12:01:19');
INSERT INTO "alert" VALUES (37,5,'Alarm! Die Temperatur -80.72°C ist kritisch!','critical','2025-06-13 12:02:19');
INSERT INTO "alert" VALUES (38,5,'Alarm! Die Temperatur -80.72°C ist kritisch!','critical','2025-06-13 12:03:20');
INSERT INTO "alert" VALUES (39,5,'Die Temperatur -0.07°C ist zu gering!','warning','2025-06-13 12:04:51');
INSERT INTO "alert" VALUES (40,5,'Die Temperatur 1.94°C ist zu gering!','warning','2025-06-13 12:05:51');
INSERT INTO "alert" VALUES (41,5,'Die Temperatur 1.73°C ist zu gering!','warning','2025-06-13 12:06:52');
INSERT INTO "alert" VALUES (42,5,'Die Temperatur -4.1°C ist zu gering!','warning','2025-06-13 12:09:18');
INSERT INTO "alert" VALUES (43,5,'Die Temperatur -2.4°C ist zu gering!','warning','2025-06-13 12:10:19');
INSERT INTO "alert" VALUES (44,5,'Die Temperatur -2.2°C ist zu gering!','warning','2025-06-13 12:11:19');
INSERT INTO "alert" VALUES (45,5,'Die Temperatur -2.2°C ist zu gering!','warning','2025-06-13 12:12:19');
INSERT INTO "alert" VALUES (46,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:13:19');
INSERT INTO "alert" VALUES (47,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:14:20');
INSERT INTO "alert" VALUES (48,5,'Die Temperatur -3.45°C ist zu gering!','warning','2025-06-13 12:15:20');
INSERT INTO "alert" VALUES (49,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:16:20');
INSERT INTO "alert" VALUES (50,5,'Die Temperatur -2.2°C ist zu gering!','warning','2025-06-13 12:17:21');
INSERT INTO "alert" VALUES (51,5,'Die Temperatur -3.88°C ist zu gering!','warning','2025-06-13 12:18:39');
INSERT INTO "alert" VALUES (52,5,'Die Temperatur -3.88°C ist zu gering!','warning','2025-06-13 12:19:39');
INSERT INTO "alert" VALUES (53,5,'Die Temperatur -2.2°C ist zu gering!','warning','2025-06-13 12:20:40');
INSERT INTO "alert" VALUES (54,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:21:40');
INSERT INTO "alert" VALUES (55,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:22:40');
INSERT INTO "alert" VALUES (56,5,'Die Temperatur -1.99°C ist zu gering!','warning','2025-06-13 12:23:41');
INSERT INTO "alert" VALUES (57,5,'Die Temperatur 30.31°C ist erhöht!','warning','2025-06-13 12:32:17');
INSERT INTO "alert" VALUES (58,5,'Alarm! Die Temperatur -13.8°C ist kritisch!','critical','2025-06-13 12:51:42');
INSERT INTO "alert" VALUES (59,5,'Alarm! Die Temperatur -14.89°C ist kritisch!','critical','2025-06-13 12:52:42');
INSERT INTO "alert" VALUES (60,5,'Alarm! Die Temperatur -13.8°C ist kritisch!','critical','2025-06-13 12:53:42');
INSERT INTO "alert" VALUES (61,5,'Alarm! Die Temperatur -13.8°C ist kritisch!','critical','2025-06-13 12:54:42');
INSERT INTO "alert" VALUES (62,5,'Alarm! Die Temperatur -13.8°C ist kritisch!','critical','2025-06-13 12:55:42');
INSERT INTO "alert" VALUES (63,5,'Alarm! Die Temperatur 212.82°C ist kritisch!','critical','2025-06-13 12:56:43');
INSERT INTO "alert" VALUES (64,5,'Alarm! Die Temperatur 186.88°C ist kritisch!','critical','2025-06-13 12:57:43');
INSERT INTO "alert" VALUES (65,5,'Alarm! Die Temperatur 269.68°C ist kritisch!','critical','2025-06-13 12:58:43');
INSERT INTO "alert" VALUES (66,5,'Die Temperatur 31.37°C ist erhöht!','warning','2025-06-13 13:09:22');
INSERT INTO "alert" VALUES (67,1,'Alarm! Die Spannung 10.02V ist kritisch!','critical','2025-06-13 13:20:15');
INSERT INTO "alert" VALUES (68,1,'Alarm! Die Spannung 10.02V ist kritisch!','critical','2025-06-13 13:21:15');
INSERT INTO "alert" VALUES (69,1,'Alarm! Die Spannung 0.03V ist kritisch!','critical','2025-06-13 13:22:23');
INSERT INTO "alert" VALUES (70,1,'Alarm! Die Spannung 0.03V ist kritisch!','critical','2025-06-13 13:23:23');
INSERT INTO "alert" VALUES (71,1,'Alarm! Die Spannung 0.03V ist kritisch!','critical','2025-06-13 13:24:24');
INSERT INTO "alert" VALUES (72,1,'Alarm! Die Spannung 0.03V ist kritisch!','critical','2025-06-13 13:25:24');
INSERT INTO "alert" VALUES (73,1,'Alarm! Die Spannung 34.28V ist kritisch!','critical','2025-06-13 13:27:10');
INSERT INTO "alert" VALUES (74,7,'Alarm! Flammen erkannt!','critical','2025-06-13 14:05:01');
INSERT INTO "credential" VALUES (1,3,'rfid',' 79 16 AA B2');
INSERT INTO "credential" VALUES (2,3,'rfid',' FA DD 5D 19');
INSERT INTO "credential" VALUES (3,3,'pixy','3');
INSERT INTO "device" VALUES (1,'esp-eingang','192.168.0.101','34:94:54:83:11:AF');
INSERT INTO "device" VALUES (2,'esp-lager1','192.168.0.104','C8:2B:96:2C:F0:F4');
INSERT INTO "device" VALUES (3,'esp-lager2','192.168.0.100','24:A1:60:2A:B2:0B');
INSERT INTO "device" VALUES (4,'esp-lager3','192.168.0.108','24:A1:60:2A:C5:83');
INSERT INTO "sensor" VALUES (1,1,'Spannung','V');
INSERT INTO "sensor" VALUES (2,2,'Ultrasonic','');
INSERT INTO "sensor" VALUES (3,1,'IR','');
INSERT INTO "sensor" VALUES (5,2,'Analoge Temperatur','°C');
INSERT INTO "sensor" VALUES (6,3,'Digitale Temperatur','°C');
INSERT INTO "sensor" VALUES (7,3,'Gas-/Rauchmelder','%');
INSERT INTO "sensor" VALUES (8,3,'Flammenmelder','');
INSERT INTO "sensor" VALUES (9,4,'PIR','');
INSERT INTO "sensor" VALUES (10,4,'VAPOR','%');
INSERT INTO "sensor" VALUES (11,4,'HUMIDITY','%');
INSERT INTO "sensor" VALUES (12,4,'Temperatur','°C');
INSERT INTO "sensorData" VALUES (2,1,0.0,'2025-06-13 18:48:20');
INSERT INTO "sensorData" VALUES (3,5,0.0,'2025-06-13 18:48:20');
INSERT INTO "sensorData" VALUES (4,6,0.0,'2025-06-13 18:48:20');
INSERT INTO "sensorData" VALUES (5,8,0.0,'2025-06-13 18:48:21');
INSERT INTO "sensorData" VALUES (6,10,0.358461538461539,'2025-06-13 18:48:21');
INSERT INTO "sensorData" VALUES (7,12,27.0632478632479,'2025-06-13 18:48:22');
INSERT INTO "sensorData" VALUES (8,11,49.5726495726496,'2025-06-13 18:48:22');
INSERT INTO "users" VALUES (3,'elemmer','Passwort','2025-06-04 15:30:54');
COMMIT;
