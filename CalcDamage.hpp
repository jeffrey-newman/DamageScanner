//
//  CalcDamage.hpp
//  FloodDamageCalc
//
//  Created by a1091793 on 20/05/2016.
//  Copyright © 2016 University of Adelaide and Bushfire and Natural Hazards CRC. All rights reserved.
//

#ifndef CalcDamage_hpp
#define CalcDamage_hpp

#include <stdio.h>
#include "Types.hpp"

double
damage(double depth, std::vector<double> & coeff);

double
calcNetLosses(DoubleRaster & inundation, IntRaster & mask, IntRaster & landuse, DoubleRaster & loss);

#endif /* CalcDamage_hpp */
