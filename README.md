# CLM-LLR-Firmware
Firmware for the UofA C3 board's XInC2 processor. Implements 2 features for a custom OS in the form of 2 modules - a Command Line Module (CLM) and a Low-level Routine (LLR) Module. For a brief project overview, please check out our [GitHub wiki](https://github.com/G13-capstone/CLM-LLR-Firmware/wiki)!

## Required Software for Building
Please ensure that the following are installed with the "path" option enabled and "long path names" option disabled:
- cmake-3.17.0-rc1-win64-x64.msi
- mingw-17.1.exe
- python-3.8.2-amd64.exe
- sxc-022420-win64.exe

Also ensure that you remember the location in which you installed the above as it will be important in the next section.

## How to Build Firmware Files
1. Open the "open_distro_window.bat" batch file, which is located in the MinGW folder. This will open a terminal window.
   * Note that the location of the MinGW folder is user-defined during installation.
2. Run the below commands in the terminal window. They will install the Python modules required for the build process.
   * ```pip3 install cogapp```
   * ```pip3 install pip```
3. Navigate to the folder containing the firmware code.
4. Run the below commands in the terminal window. They will create the required build folder and preliminary build files required for the firmware.
   * ```mkdir build```
   * ```cd build```
   * ```cmake -G "MinGW Makefiles" ..```
5. Run the command ```make``` while still in the build folder to build the firmware.

## How to Run Firmware Files
These steps assume you have the C3 board set up with an XPD board and a computer with the firmware.
1. In the build folder, run the command ```sxc-xdt --hid -t --hex minimal.hex```
2. Power cycle the C3 board to begin downloading the firmware to it.
3. Once "Download Succeeded" is shown in the terminal, the firmware will now run on the C3 board.
