# ThingSpeak-Write-Read-w-ESP8266-ESP32
Code to handle ThingSpeak write and read actions to few fields with Arduino and ESP-based boards.

This is a demo to handle ThingSpeak with Arduino and ESP-based boards. In this demo I used ThingSpeak library for Arduino, although you could use different approach
like (json, xaml, handlind http and headers by hand). In this demo I used 2 different boards:
- Wemos D1 mini (ESP8266 based)
- LilyGo TTGO T-Display (ESP32 based)

to simulate "mesh" IoT network.

One board writes data to ThingSpeak server, and other reads humidity from server.

First board logs following quantities:
- temperature
- soil moisture
- random number

Second board reads soilMoisture and triggers alert using red diode.

ThingSpeak client side looks like this:
![wemos1](https://user-images.githubusercontent.com/56636763/123918423-284d5800-d984-11eb-9353-187894001b06.PNG)
![wemos2](https://user-images.githubusercontent.com/56636763/123918443-2c797580-d984-11eb-8617-c523df7bbbf3.PNG)

And physical connection of first board looks like this:
![WemosSetup1](https://user-images.githubusercontent.com/56636763/123918484-369b7400-d984-11eb-8f00-eca024af138a.jpg)
![WemosSetup2](https://user-images.githubusercontent.com/56636763/123918466-31d6c000-d984-11eb-8d96-5fc92a402054.jpg)
