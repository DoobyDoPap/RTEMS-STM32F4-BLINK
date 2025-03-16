# RTEMS-STM32F4-BLINK 

# Running RTEMS on STM32F407VE

## 1. Build the Toolchain
First, manually build the `arm-rtems-gcc` toolchain. You can refer to the RTEMS Getting Started documentation. Replace `sparc/erc32` with `arm/stm32f4` in the instructions.

## 2. Set Up an Application Folder
Follow the tutorial to create and configure an application folder.

## 3. Convert the Executable to a Binary File
Run the following command to generate a binary file from the compiled executable:

```
arm-rtems7-objcopy path/to/bin/file/hello.exe path/to/bin/file/hello.bin
```

## 4. Flash the Binary to the STM32F407VE
If you're using an ST-Link, use `st-flash` to write the binary to flash memory:

```
st-flash write path/to/bin/file/hello.bin 0x8000000
```

**Note:** If you're not setting up the reset pin, use the `--connect-under-reset` option.

## 5. Debugging with GDB
To debug using GDB, follow these steps:

### Start the ST-Link GDB server in one terminal:
```
st-util
```
This will open a remote debugging session. Copy the port number displayed.

### In another terminal, start GDB and connect to the ST-Link server:
```
arm-rtems7-gdb path/to/bin/file/hello.exe
target extended-remote :<port-number>
