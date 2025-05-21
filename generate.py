import struct

with open("data/sample_telemetry.bin", "wb") as f:
    for i in range(5):
        packet = struct.pack(
            "<Q I f f f f f",  # < = little endian
            1650000000 + i,    # timestamp
            1000 + i,          # satellite ID
            37.7749 + i,       # lat
            -122.4194 + i,     # lon
            400.0 + i * 10,    # altitude
            22.5 + i,          # temperature
            98.0 - i           # battery
        )
        f.write(packet)
