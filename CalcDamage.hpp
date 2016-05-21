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
#include <vector>
#include <cmath>
#include "Types.hpp"

std::vector<double> coef_high_dens_house = {-0.0484, 0.5509, -1.907, 3.5721};
std::vector<double> coef_commercial = {-0.0218, 0.2764, -0.8716, 1.3685};
std::vector<double> coef_low_dens_house = {-0.0271, 0.2921, -0.9387, 1.5621};
std::vector<double> coef_industry = {-0.0305, 0.3870, -1.2202, 1.9159};
double pad_depth = 0.25;

double
damage(double depth, std::vector<double> & coeff);

double
calcNetLosses(DoubleRaster & inundation, IntRaster & mask, IntRaster & landuse, DoubleRaster & loss);

#endif /* CalcDamage_hpp */
