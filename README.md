# Serial-monitor
Serial monitor and plotter for linux

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
 Clean:
 ```bash
 make clean
 ```

 Run compile link flash clean at the same time:
 ```bash
 make default
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




