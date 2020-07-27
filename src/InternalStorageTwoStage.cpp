/*
  Copyright (c) 2017 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#if defined(ARDUINO_ARCH_SAMD) || defined(ARDUINO_ARCH_NRF5)

#include <Arduino.h>

#include "InternalStorageTwoStage.h"

	//InternalStorageClass(126976, 135168)

InternalStorageStageOne::InternalStorageStageOne(size_t firstStageSize)
{
	MAX_PARTIONED_SKETCH_SIZE = MAX_FLASH - SKETCH_START_ADDRESS - firstStageSize;
	STORAGE_START_ADDRESS = SKETCH_START_ADDRESS + firstStageSize;
}

InternalStorageStageTwo::InternalStorageStageTwo(size_t firstStageSize) 
{
	MAX_PARTIONED_SKETCH_SIZE = firstStageSize;
	STORAGE_START_ADDRESS = SKETCH_START_ADDRESS + firstStageSize;
}

#endif
