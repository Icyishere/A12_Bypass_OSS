# Client Setup

## Prerequisites

### Python Dependencies
1. Install Python 3 (3.6+).
2. Install `pymobiledevice3`:
   ```bash
   pip3 install pymobiledevice3
   ```
3. (Optional - Linux/macOS) Install `libimobiledevice` (provides `ifuse`).

### C++ Launcher (Optional)
To build the C++ launcher, you need:
- A C++ compiler (GCC, Clang, or MSVC).
- CMake (3.10+).

## Configuration
1. Open `activator.py` in a text editor.
2. Locate the line defining `self.api_url`.
3. Change the IP/URL to match where you deployed the server folder.

## How to Run

### Option 1: Direct Python Script (Cross-Platform)
Run the script directly from the terminal/command prompt.

**Linux/macOS:**
```bash
python3 activator.py
```

**Windows:**
```powershell
python activator.py
```

### Option 2: C++ Launcher
The launcher provides a simple menu interface.

**Building:**
```bash
cd client_gui
cmake .
cmake --build .
```

**Running:**
- **Linux/macOS:** `./activator_launcher`
- **Windows:** `activator_launcher.exe`
