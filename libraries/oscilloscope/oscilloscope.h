/*
 * oscilloscope.h
 *
 * Gives a visual rendering of a value (typically analog pin 0) in realtime.
 * 
 * This is an object-oriented version of the Poorman's oscilloscope as explained here:
 * http://accrochages.drone.ws/node/90
 * 
 * (c) 2008 Sofian Audry | info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OSCILLOSCOPE_INC
#define OSCILLOSCOPE_INC

#include "Arduino.h"

void writeOscilloscope(int value) {
  Serial.write( 0xff );                // send init byte
  Serial.write( (value >> 8) & 0xff); // send first part
  Serial.write( value & 0xff );        // send second part
}

#endif