//
//  CalcDamage.cpp
//  FloodDamageCalc
//
//  Created by a1091793 on 20/05/2016.
//  Copyright © 2016 University of Adelaide and Bushfire and Natural Hazards CRC. All rights reserved.
//

#include "CalcDamage.hpp"

#include <stdio.h>
#include <vector>
#include <cmath>

std::vector<double> coef_high_dens_house = {-0.0484, 0.5509, -1.907, 3.5721};
std::vector<double> coef_commercial = {-0.0218, 0.2764, -0.8716, 1.3685};
std::vector<double> coef_low_dens_house = {-0.0271, 0.2921, -0.9387, 1.5621};
std::vector<double> coef_industry = {-0.0305, 0.3870, -1.2202, 1.9159};
double pad_depth = 0.25;

double
damage(double depth, std::vector<double> & coeff)
{
    return (coeff[0]*std::pow(depth, 4)
            + coeff[1]*std::pow(depth, 3)
            + coeff[2]*std::pow(depth, 2)
            + coeff[3]*depth);
}

double
calcNetLosses(DoubleRaster & inundation, IntRaster & mask, IntRaster & landuse, DoubleRaster & loss)
{
    //    double net_loss = 0;
    auto zip = raster_util::make_zip_range(std::ref(inundation), std::ref(mask), std::ref(landuse), std::ref(loss));
    for (auto i : zip)
    {
        const double & v_inundation = std::get<0>(i);
        const int & v_mask = std::get<1>(i);
        const int & v_landuse = std::get<2>(i);
        auto & loss = std::get<3>(i);
        
        
        if (v_mask != 0)
        {
            if (v_landuse == 0 ) // High residential
            {
                loss = damage(v_inundation - pad_depth, coef_high_dens_house);
            }
            if (v_landuse == 1) //Low residential
            {
                loss = damage(v_inundation - pad_depth, coef_low_dens_house)
            }
            if (v_landuse == 2) //Industrial
            {
                loss = damage(v_inundation - pad_depth, coef_industry)
            }
            if (v_inundation == 3) //Commercial
            {
                loss = damage(v_inundation - pad_depth, coef_commercial)
            }
        }
        
        //        net_loss += loss;
    }
    
    
    
}

#endif /* CalcDamage_hpp */
