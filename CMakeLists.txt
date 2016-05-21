PROJECT(DamageScannerLite)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)

# find_package(CUDA REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(GDAL)

set(AHHZ_RASTER_UTIL "Not Specified" CACHE PATH "Path to Alex Hagen-Zanker's Raster Utility Include direction (select above blink)")
set(AHHZ_RASTER_ITERATOR "Not Specified" CACHE PATH "Path to Alex Hagen-Zanker's Raster Iterator Include direction (select folder above blink)")

include_directories(${GDAL_INCLUDE_DIR} )
include_directories(${Boost_INCLUDE_DIRS} )
include_directories(${AHHZ_RASTER_UTIL} )
include_directories(${AHHZ_RASTER_ITERATOR} )


SET (Sources
		CalcDamage.cpp
	)

SET (Headers
		CalcDamage.hpp
		Types.hpp
	)

file(GLOB_RECURSE AHHZ_Utils
 "${AHHZ_RASTER_UTIL}/*.h"
 "${AHHZ_RASTER_UTIL}/*.hpp"
 "${AHHZ_RASTER_UTIL}/*.cpp" 
 "${AHHZ_RASTER_ITERATOR}/*.h" 
 "${AHHZ_RASTER_ITERATOR}/*.hpp" 
 "${AHHZ_RASTER_ITERATOR}/*.cpp" 
)

	
#LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_30,code=sm_30)

#cuda_add_executable(cccalcm ${Sources} ${Headers})
	
#set_property(TARGET ccalcm PROPERTY CXX_STANDARD 11)
add_executable(dmgScanLte ${Sources} ${Headers} ${AHHZ_Utils})
target_link_libraries(dmgScanLte ${GDAL_LIBRARY} ${Boost_LIBRARIES})
