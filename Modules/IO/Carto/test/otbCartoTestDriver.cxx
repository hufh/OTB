/*
 * Copyright (C) 2005-2017 Centre National d'Etudes Spatiales (CNES)
 *
 * This file is part of Orfeo Toolbox
 *
 *     https://www.orfeo-toolbox.org/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "otbTestMain.h"

void RegisterTests()
{
  REGISTER_TEST(otbMapFileProductWriterNew);
  REGISTER_TEST(otbImageToOSMVectorDataGeneratorNew);
  REGISTER_TEST(otbImageToOSMVectorDataGenerator);
  REGISTER_TEST(otbMapFileProductWriter);
  REGISTER_TEST(otbOSMToVectorDataGeneratorNew);
  REGISTER_TEST(otbOSMToVectorDataGeneratorTest);
  REGISTER_TEST(otbOSMToVectorDataGeneratorByName);
  REGISTER_TEST(otbCoordinateToNameTest);
}
