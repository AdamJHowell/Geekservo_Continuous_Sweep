cmake_minimum_required( VERSION 3.23 )
project( Geekservo_Continuous_Sweep )

set( CMAKE_CXX_STANDARD 14 )

include_directories( .
		C:/Users/Adam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.5/cores/arduino/
		C:/Code/Arduino/libraries/
		C:/Code/Arduino/libraries/Servo/src/
		C:/Users/Adam/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/3.0.2/libraries/Wire/
		C:/Users/Adam/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/3.0.2/libraries/ESP8266WiFi/src/
		C:/Users/Adam/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/
		C:/Code/Arduino/libraries/ArduinoJson/
		C:/Code/Arduino/libraries/ArduinoJson/src/
		C:/Code/Arduino/libraries/PubSubClient/src/
		C:/Code/Arduino/libraries/Adafruit_PWM_Servo_Driver_Library/
		"C:/Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino/"
		"C:/Program Files (x86)/Arduino/hardware/tools/avr/lib/gcc/avr/7.3.0/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/cores/esp32/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/libraries/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/libraries/ArduinoOTA/src/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/libraries/ESPmDNS/src/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/libraries/Update/src/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/libraries/WiFi/src/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp_common/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp_rom/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp_wifi/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp32-camera/driver/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/log/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/spi_flash/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/qspi_qspi/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/variants/esp32/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/gcc8_4_0-esp-2021r2-patch3/xtensa-esp32-elf/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/gcc8_4_0-esp-2021r2-patch3/xtensa-esp32-elf/include/c++/8.4.0/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/tools/xtensa-esp32-elf-gcc/gcc8_4_0-esp-2021r2-patch3/xtensa-esp32-elf/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/freertos/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/freertos/include/freertos/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp_system/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/hal/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/hal/esp32/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp32/include/rom/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp32/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/soc/esp32/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/qio_qspi/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/driver/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp32-camera/conversions/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/esp_hw_support/include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/newlib/platform_include/"
		"C:/Users/Adam Howell/AppData/Local/Arduino15/packages/esp32/hardware/esp32/2.0.4/tools/sdk/esp32/include/freertos/include/esp_additions/freertos/"
		"C:/Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino/"
		"C:/Program Files (x86)/Arduino/hardware/tools/avr/lib/gcc/avr/7.3.0/include/"
		)

add_executable( Geekservo_Continuous_Sweep
		Geekservo_Continuous_Sweep.ino
		privateInfo.h )

set_target_properties( Geekservo_Continuous_Sweep PROPERTIES LINKER_LANGUAGE CXX )

# use the following two targets for building and uploading sketches from clion.
# select "verify" for just building, select "upload" for building and uploading.
# make sure you have selected the correct board and port in the arduino IDE before building this target!
# instead, you can also use --board and --port arguments here. for the m0, --board arduino:samd:mzero_bl
# see https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc for arduino cmd options
add_custom_target( upload ALL ${ARDUINO_CMD} --upload --preserve-temp-files --verbose Geekservo_Continuous_Sweep.ino WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} )
add_custom_target( verify ALL ${ARDUINO_CMD} --verify --preserve-temp-files --verbose Geekservo_Continuous_Sweep.ino WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} )
