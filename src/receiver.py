import serial

ser = serial.Serial('/dev/ttyS0', 115200, timeout=1)

def clean_data(data):
    try:
        text = data.decode('utf-8').rstrip()
        if "Dados para o Raspberry Pi" in text:
            return text
        else:
            return None
    except UnicodeDecodeError:
        return None

try:
    while True:
        if ser.in_waiting > 0:
            raw_data = ser.readline()
            cleaned_data = clean_data(raw_data)
            if cleaned_data:
                print(f"Dados recebidos: {cleaned_data}")
            else:
                print(f"Dados não legíveis: {raw_data}")
except KeyboardInterrupt:
    print("Interrompido pelo usuário.")
finally:
    ser.close()