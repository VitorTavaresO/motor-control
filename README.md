# Motor-Control
This project is part of the TCC(Trabalho de Conclusão de Curso/completion of course work), which is a idea to make a Chevette 1986 became a smart.

This system is part of the Embedded and IoT, using Arduino Mega ADK which haves the function to control:
- Motor Temperature
- Fuel Level
- Oil Temperature
- Motor RPM
- Battery
- ...

## Interaction

Teh base local interactions with this system will be a Raspberry Pi that will have a display created using the framework for Python Kivy and KivyMD, working as a multimedia-center.

Another form of interaction will be through a mobile application, all system information will be sent to a remote server that will use an API to communicate with other devices and enable the possibility of remote control of the vehicle.
