# Save this as gen_file.py
with open("input80.bin", "wb") as f:
    f.write(bytes(range(1, 81)))  # Writes 70 bytes: 1, 2, 3, ..., 70
