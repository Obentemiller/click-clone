# click-clone

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Parameters](#parameters)
- [Contribution](#contribution)
- [License](#license)

## Introduction

**Click Clone** allows you to record mouse movements and clicks with precision, and then replay them automatically. It is useful for repetitive tasks, automating simple actions, or for studying automation on Windows.

## Requirements

- Operating System: Windows
- Compiler: `g++` or `cl.exe` (Visual Studio)
- Library: `windows.h`

## Installation

1. Compile the program:
   - Using `g++`:
     ```bash
     g++ click_clone.cpp -o click_clone -lgdi32
     ```
   - Using `cl.exe` (Visual Studio):
     ```bash
     cl click_clone.cpp /link gdi32.lib
     ```

## Usage

1. Run the compiled program.
2. Set the event capture precision:
   - Precision is the time interval between mouse event captures, in milliseconds. The minimum recommended value is **20 ms** for higher precision, and the maximum is **50 ms** for less frequent captures.
3. Press `q` to start recording mouse events.
4. Move the mouse and click as needed. To stop recording, press `ESC`.
5. After recording, press `ENTER` to start playing back the recorded events.

## Parameters

- `int precision`: Defines the time interval between mouse event captures (in milliseconds). Smaller values provide higher precision, while larger values reduce CPU load.

## Example Usage

When you start the program, you will see the following message:

```bash
  _  ___  __    _ _      _          _                  
 | |/ / |/ /   | (_)    | |        | |                 
 | ' /| ' / ___| |_  ___| | __  ___| | ___  _ __   ___ 
 |  ; |  ; / __| | |/ __| |/ / / __| |/ _ \| '_ \ / _ \
 | . \| . \ (__| | | (__|   ; | (__| | (_) | | | |  __/
 |_|\_\_|\_\___|_|_|\___|_|\_\ \___|_|\___/|_| |_|\___|
    @github Obentemiller                                          
```

1. Set the precision (e.g., `20` ms).
2. Press `q` to start recording mouse movements.
3. To stop, press `ESC`.
4. To replay the movements, press `ENTER`.

## Contribution

Contributions are welcome! Follow the steps below to contribute:

1. Fork the project.
2. Create a branch for your changes:
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. Commit your changes:
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. Push to the original branch:
   ```bash
   git push origin feature/AmazingFeature
   ```
5. Open a Pull Request.

## License

Distributed under the MIT License. See `LICENSE` for more information.

---

This guide provides a full structure, leaving out unnecessary steps like downloading the program.
