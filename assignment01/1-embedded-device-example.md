# Problem 1: Embedded device example
Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

Smart washing machines are examples of products that have microprocessors "embedded" in them. A Wi-Fi board, one or more water pressure sensors, an inverter direct drive, and a seven-segment LED are some of the peripherals. Given the complexity of such a system, most likely the tasks are broken down into components such as power on/off, user notification (sound when complete or push notification to user's smart phone), water control (i.e. temperature, volume of water to jets, volume of water pumped out, etc.), and user interaction to allow user to select wash cycle preferences. There are many challenges faced when designing such a system.

* Throughput, an increase in the number of sensors is directly proportional to the amount of data to be processed
* Response, if a user wishes to pause a load of clothes shortly after starting a wash cycle the machine must respond---pause the water jets and check the water level
* Debugability, there should be prototype board that allows engineers to test and ensure that things really work
* Reliability, how does the system ensure there is sufficient water pressure and when there isn't suffice water pressure to function that must be communicated
* Memory Space, there must be sufficient memory to buffer sensor input and the ability to persist Wi-Fi password and SSID values when powered off
* Program Installation, updates may be necessary for such a system
* Power Consumption, handle step down in voltage from 110 volt to modules with lesser power consumption and consider implications of power saver mode for eco-friendly consumers
* Processor Hogs, asynchronous nature of HTTP (i.e. my washer has a HTTP page)
* Cost, minimizing the amount of hardware in such a system seems like a pain...