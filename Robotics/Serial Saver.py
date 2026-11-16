import serial
import csv

port = "COM4"
baud = 115200
file = "Measured File.csv"

ser = serial.Serial(port, baud, timeout=5)

with open(file, mode='w', newline = "") as f:
    writer = csv.writer(f)
    print(f"Listening on {port}. Saving to {file}...")
    try:
        while True:
            line = ser.readline().decode('utf-8', errors = 'ignore').strip()
            if line:
                data = line.split(',')
                writer.writerow(data)
                print(f"Logged: {data}")
    except KeyboardInterrupt:
        print("\nLogging stopped.")
        ser.close()