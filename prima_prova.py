from nanpy import ArduinoApi
from nanpy import SerialManager

connection = SerialManager(device='/dev/ttyACM0')
arduinoObject = ArduinoApi(connection=connection)
arduinoObject.digitalWrite(5, arduinoObject.HIGH)
arduinoObject.digitalWrite(3, arduinoObject.HIGH)
arduinoObject.digitalWrite(4, arduinoObject.HIGH)
