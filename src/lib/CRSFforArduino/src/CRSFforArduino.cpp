/**
 * @file CRSFforArduino.cpp
 * @author Cassandra "ZZ Cat" Robinson (nicad.heli.flier@gmail.com)
 * @brief CRSF for Arduino facilitates the use of ExpressLRS RC receivers in Arduino projects.
 * @version 0.4.0
 * @date 2023-08-08
 *
 * @copyright Copyright (c) 2023, Cassandra "ZZ Cat" Robinson. All rights reserved.
 *
 * @section License GNU General Public License v3.0
 * This source file is a part of the CRSF for Arduino library.
 * CRSF for Arduino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CRSF for Arduino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CRSF for Arduino.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "CRSFforArduino.h"

namespace sketchLayer
{
    CRSFforArduino::CRSFforArduino()
    {
        _serialReceiver = new SerialReceiver();
    }

    CRSFforArduino::CRSFforArduino(uint8_t rxPin, uint8_t txPin)
    {
        _serialReceiver = new SerialReceiver(rxPin, txPin);
    }

    CRSFforArduino::~CRSFforArduino()
    {
        delete _serialReceiver;
    }

    bool CRSFforArduino::begin()
    {
        return _serialReceiver->begin();
    }

    void CRSFforArduino::end()
    {
        _serialReceiver->end();
    }

    void CRSFforArduino::update()
    {
        _serialReceiver->processFrames();
    }

    uint16_t CRSFforArduino::readRcChannel(uint8_t channel, bool raw)
    {
        return _serialReceiver->readRcChannel(channel - 1, raw);
    }

    uint16_t CRSFforArduino::getChannel(uint8_t channel)
    {
        return _serialReceiver->getChannel(channel - 1);
    }

    uint16_t CRSFforArduino::rcToUs(uint16_t rc)
    {
        return _serialReceiver->rcToUs(rc);
    }

    void CRSFforArduino::telemetryWriteGPS(float latitude, float longitude, float altitude, float speed, float groundCourse, uint8_t satellites)
    {
        _serialReceiver->telemetryWriteGPS(latitude, longitude, altitude, speed, groundCourse, satellites);
    }
} // namespace sketchLayer
