//
//  Types.hpp
//  FloodDamageCalc
//
//  Created by a1091793 on 21/05/2016.
//  Copyright © 2016 University of Adelaide and Bushfire and Natural Hazards CRC. All rights reserved.
//

#ifndef Types_h
#define Types_h

#include <blink/raster/utility.h> // To open rasters

namespace raster_util = blink::raster;
typedef raster_util::gdal_raster<double> DoubleRaster;
typedef raster_util::gdal_raster<int> IntRaster;

#endif /* Types_h */
