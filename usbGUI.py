import serial
import serial.tools.list_ports
import json
import threading
from pynput.keyboard import Controller, Key
import tkinter as tk
from tkinter import messagebox, filedialog

CONFIG_FILE = 'key_mappings.json'
BAUD_RATE = 2400

keyboard = Controller()
ser = None  # Serial object
running = False  # Flag to indicate whether the serial loop is running

def map_key_action(action):
    """Maps action strings to pynput keys or characters."""
    if action == 'up':
        return Key.up
    elif action == 'down':
        return Key.down
    elif action == 'left':
        return Key.left
    elif action == 'right':
        return Key.right
    elif action == 'space':
        return Key.space
    else:
        return action  # Return character as is

def load_key_mappings():
    """Loads key mappings from a JSON configuration file."""
    try:
        with open(CONFIG_FILE, 'r') as file:
            key_mappings = json.load(file)
            print(f"Loaded mappings from {CONFIG_FILE}: {key_mappings}")
            return key_mappings
    except FileNotFoundError:
        print(f"{CONFIG_FILE} not found. Loading default mappings.")
        return apply_default_mappings()

def save_key_mappings(key_mappings):
    """Saves key mappings to a JSON configuration file."""
    with open(CONFIG_FILE, 'w') as file:
        json.dump(key_mappings, file, indent=4)
        print(f"Mappings saved to {CONFIG_FILE}.")

def apply_default_mappings():
    # Default mappings
    return {
        '11': 'up',
        '10': 'up_release',
        '22': 'down',
        '20': 'down_release',
        '33': 'left',
        '30': 'left_release',
        '44': 'right',
        '40': 'right_release',
        '55': 'k',
        '50': 'k_release',
        '66': 'l',
        '60': 'l_release',
        '77': 'm',
        '70': 'm_release'
    }

def handle_key_event(data, keyboard, key_mappings):
    if data in key_mappings:
        action = key_mappings[data]
        if action.endswith('_release'):
            key = map_key_action(action.replace('_release', ''))
            keyboard.release(key)
        else:
            key = map_key_action(action)
            keyboard.press(key)

def start_serial():
    """Automatically detects the suitable serial port and starts the communication."""
    global ser, running
    try:
        ports = list(serial.tools.list_ports.comports())
        for port in ports:
            try:
                ser = serial.Serial(port.device, BAUD_RATE)
                print(f"Connected to {port.device}")
                running = True  # Set the flag to indicate that the serial loop is running
                threading.Thread(target=serial_loop, daemon=True).start()
                return
            except Exception as e:
                print(f"Failed to connect to {port.device}: {e}")
        messagebox.showerror("Error", "No suitable serial port found.")
    except Exception as e:
        messagebox.showerror("Error", f"Could not detect serial ports: {e}")

def stop_serial():
    """Stops the serial communication."""
    global ser, running
    if ser:
        running = False  # Clear the flag to stop the loop
        ser.close()
        ser = None
        print("Serial communication stopped.")

def serial_loop():
    """Main loop to process serial data."""
    global running
    while running:
        try:
            if ser and ser.in_waiting > 0:
                data = ser.read().hex()  # Read data and convert to hex string
                print(f"Received: {data}")
                handle_key_event(data, keyboard, key_mappings)
        except serial.SerialException:
            print("Serial port exception occurred. Stopping serial loop.")
            running = False

def open_config_file():
    """Opens a file dialog to select a configuration file."""
    global CONFIG_FILE
    CONFIG_FILE = filedialog.askopenfilename(filetypes=[("JSON files", "*.json")])
    if CONFIG_FILE:
        load_key_mappings()

def update_mappings_window():
    """Creates a new window for updating key mappings."""
    def save_new_mappings():
        """Saves the mappings input by the user."""
        new_mappings = {
            '11': k1_var.get(),
            '10': k1_var.get() + '_release',
            '22': k2_var.get(),
            '20': k2_var.get() + '_release',
            '33': up_var.get(),
            '30': up_var.get() + '_release',
            '44': down_var.get(),
            '40': down_var.get() + '_release',
            '55': left_var.get(),
            '50': left_var.get() + '_release',
            '66': right_var.get(),
            '60': right_var.get() + '_release',
            '77': center_var.get(),
            '70': center_var.get() + '_release'
        }
        key_mappings.update(new_mappings)
        save_key_mappings(key_mappings)
        messagebox.showinfo("Info", "Mappings updated.")
        update_window.destroy()

    update_window = tk.Toplevel()
    update_window.title("Update Key Mappings")

    # Variables for user input
    k1_var = tk.StringVar(value=key_mappings.get('11', ''))
    k2_var = tk.StringVar(value=key_mappings.get('22', ''))
    up_var = tk.StringVar(value=key_mappings.get('33', ''))
    down_var = tk.StringVar(value=key_mappings.get('44', ''))
    left_var = tk.StringVar(value=key_mappings.get('55', ''))
    right_var = tk.StringVar(value=key_mappings.get('66', ''))
    center_var = tk.StringVar(value=key_mappings.get('77', ''))

    # Create input fields for each button
    fields = [
        ('K1 Press (11)', k1_var),
        ('K2 Press (22)', k2_var),
        ('Up Press (33)', up_var),
        ('Down Press (44)', down_var),
        ('Left Press (55)', left_var),
        ('Right Press (66)', right_var),
        ('Center Press (77)', center_var)
    ]

    for i, (label_text, var) in enumerate(fields):
        tk.Label(update_window, text=label_text).grid(row=i, column=0, padx=5, pady=5, sticky='e')
        tk.Entry(update_window, textvariable=var).grid(row=i, column=1, padx=5, pady=5)

    save_button = tk.Button(update_window, text="Save", command=save_new_mappings)
    save_button.grid(row=len(fields), column=0, columnspan=2, pady=10)

def create_ui():
    """Creates the UI using Tkinter."""
    window = tk.Tk()
    window.title("Serial to Keyboard Mapper")

    frame = tk.Frame(window)
    frame.pack(padx=10, pady=10)

    load_button = tk.Button(frame, text="Load Mappings", command=open_config_file)
    load_button.grid(row=0, column=0, padx=5, pady=5)

    save_button = tk.Button(frame, text="Save Mappings", command=lambda: save_key_mappings(key_mappings))
    save_button.grid(row=0, column=1, padx=5, pady=5)

    update_button = tk.Button(frame, text="Update Mappings", command=update_mappings_window)
    update_button.grid(row=1, column=0, padx=5, pady=5)

    start_button = tk.Button(frame, text="Start Serial", command=start_serial)
    start_button.grid(row=2, column=0, padx=5, pady=5)

    stop_button = tk.Button(frame, text="Stop Serial", command=stop_serial)
    stop_button.grid(row=2, column=1, padx=5, pady=5)

    window.mainloop()

# Initialize key mappings
key_mappings = load_key_mappings()

# Create and run the UI
create_ui()
