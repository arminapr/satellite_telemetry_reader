#include "TelemetryPacket.h"
#include <iostream>

// interprets the binary data
TelemetryPacket TelemetryPacket::fromStream(std::ifstream& stream) {
    TelemetryPacket packet;
    stream.read(reinterpret_cast<char*>(&packet.timestamp), sizeof(packet.timestamp));
    stream.read(reinterpret_cast<char*>(&packet.satelliteId), sizeof(packet.satelliteId));
    stream.read(reinterpret_cast<char*>(&packet.latitude), sizeof(packet.latitude));
    stream.read(reinterpret_cast<char*>(&packet.longitude), sizeof(packet.longitude));
    stream.read(reinterpret_cast<char*>(&packet.altitude), sizeof(packet.altitude));
    stream.read(reinterpret_cast<char*>(&packet.temperature), sizeof(packet.temperature));
    stream.read(reinterpret_cast<char*>(&packet.battery), sizeof(packet.battery));
    return packet;
}

// writes to the terminal
void TelemetryPacket::print() const {
    std::cout << "Timestamp: " << timestamp << "\n"
              << "Satellite ID: " << satelliteId << "\n"
              << "Latitude: " << latitude << "\n"
              << "Longitude: " << longitude << "\n"
              << "Altitude: " << altitude << " m\n"
              << "Temperature: " << temperature << " °C\n"
              << "Battery: " << battery << " %\n"
              << "-----------------------------\n";
}
