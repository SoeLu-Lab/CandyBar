# CandyBar

Firmware für einen ESP32 mit 48 LED-Ringen à 12 WS2812-LEDs (GPIO 5), einem Taster (GPIO 12), WLAN und ArduinoOTA.

Das GitHub-Projekt enthält zusätzlich `firmware.bin`, `version.txt` und `index.html` für den bisherigen Firmware-Download. Der Sketch-Quellcode liegt im Repository-Root; `CandyBar.ino` ist der Arduino-Einstiegspunkt.

## Funktionen

- Im Normalbetrieb leuchten alle LEDs blau (Helligkeit 20/255).
- Ein Tastendruck startet einen kurzen, zufälligen weißen Ringeffekt und kehrt anschließend zu Blau zurück.
- Der Taster wird entprellt; OTA und Tasterabfrage bleiben während des Effekts ansprechbar.
- WLAN-Anmeldung mit lokalen Zugangsdaten; bei fehlenden Zugangsdaten oder Verbindungsfehler startet der Einrichtungs-AP `CandyBar-Setup` (Passwort `CandyBar123`).
- OTA-Hostname: `candybar`.

## Hardware

| Funktion | ESP32 GPIO | Hinweise |
|---|---:|---|
| WS2812 Daten | 5 | Gemeinsame Masse; Pegelanpassung und passende Versorgung beachten |
| Taster | 12 | Zwischen GPIO 12 und GND; interner Pull-up |

Die Versorgung muss für bis zu 576 LEDs ausgelegt sein. LED-Versorgung und ESP32 benötigen eine gemeinsame Masse. GPIO 12 ist bei vielen ESP32-Modulen ein Strapping-Pin; die Beschaltung darf den Startpegel nicht ungünstig beeinflussen.

## Einrichtung und Upload

1. Arduino IDE installieren und das passende ESP32-Boardpaket auswählen.
2. Bibliothek **FastLED** installieren. `WiFi` und `ArduinoOTA` kommen aus dem ESP32-Boardpaket.
3. `secrets.example.h` als `secrets.h` kopieren und WLAN-Name sowie Passwort eintragen. `secrets.h` wird nicht versioniert.
4. `CandyBar.ino` öffnen, Board und Port wählen, kompilieren und per USB hochladen.
5. Wenn keine Routerverbindung möglich ist, mit `CandyBar-Setup` verbinden. OTA funktioniert nur im erreichbaren selben Netzwerk.

## Konfiguration

Pinbelegung, LED-Anzahl, Grundhelligkeit und Effektzeiten stehen in `effekte.h` und `button.h`. SSID und WLAN-Passwort stehen lokal in `secrets.h`; AP-Zugangsdaten stehen in `wifisetup.h`.

## Versionshinweis

`version.txt` beschreibt die veröffentlichte Binärdatei des Download-Bereichs. Beim Erstellen und Veröffentlichen einer neuen Firmware müssen Binärdatei und Versionsdatei gemeinsam aktualisiert werden. Der hier eingecheckte Sketch ist der dokumentierte Quellcode-Arbeitsstand; die bestehende Binärdatei wurde aus der Remote-Historie übernommen und nicht aus diesem Quellstand neu gebaut.

## Lizenz

Die Lizenz ist noch nicht festgelegt. Vor einer öffentlichen Weitergabe des Quellcodes sollte eine passende Lizenz ergänzt werden.
