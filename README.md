# Serial-monitor
Serial monitor for linux.

## FUNCTIONS
For initialization of serial monitor :
```bash
SerialInit();
```

For printing out transmitted data from microcontroler in one line (Input = char):
```bash
serialWrite();
```
For printing out transmitted data from microcontroler in new line (Input = char):
```bash
serialWriteLn();
```

## Screen commands

 First you need to install screen:
```bash

sudo apt install screen

```
To run screen you type:
```bash
screen
```

Attaching COM port to screen:
```bash
screen /dev/PORT
```

Detaching screen:
```bash
Ctrl + a Ctrl + d
```

Terminating screen: 
```bash
screen -X quit
```

Listing all opened screens:
```bash
screen -ls
```
## Makefile

Compile:
```bash
make compile
```

Link:
```bash
make link
```

Flash to microcontroler:
```bash
make flash
```

Turn on COM port monitor:
```bash
make monitor
```

 Removing compiled files and closing monitor:
 ```bash
 make clean
 ```

 Run compile link flash monitor at the same time:
 ```bash
 make default
 ```





