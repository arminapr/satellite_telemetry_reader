#pragma once
#include <cstdint>
#include <fstream>

// defines the telemetry packet datatype
struct TelemetryPacket {
    uint64_t timestamp;
    uint32_t satelliteId;
    float latitude;
    float longitude;
    float altitude;
    float temperature;
    float battery;

    static TelemetryPacket fromStream(std::ifstream& stream);
    void print() const;
};
