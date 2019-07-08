Just playing around to see if debugging over WiFi via CPP instrumentation might work for ESP32.
See [comment on YouTube: Inline Debugging for ESP32](https://www.youtube.com/watch?v=psMqilqlrRQ&lc=UgyBS25VcM09o2wA-cl4AaABAg.8wWvMzrzboH8wedPOnWeR5) for context (debugging just via JTAG, i.e., extra cables).

Probably better to adjust [gdbstub](https://github.com/espressif/esp-gdbstub).
- Seems to work for ESP8266: [doc](https://arduino-esp8266.readthedocs.io/en/latest/gdb.html)
- But not for ESP32: [issue](https://github.com/espressif/esp-gdbstub/issues/15)

Resources:
- [YouTube: ESP32 Technical Tutorials: Attaching GDB for debugging](https://www.youtube.com/watch?v=p63VEYS7ZUw)
