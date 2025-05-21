cmake_minimum_required(VERSION 3.10)
project(SatelliteTelemetryDecoder)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(sat_decoder
        src/main.cpp
        src/TelemetryPacket.cpp
)