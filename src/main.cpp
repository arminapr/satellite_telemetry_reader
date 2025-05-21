#include "TelemetryPacket.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./sat_decoder <binary_file>\n";
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    while (file.peek() != EOF) {
        TelemetryPacket packet = TelemetryPacket::fromStream(file);
        packet.print();
    }

    return 0;
}
