project(gama_tts_vtm_plugin_example)
cmake_minimum_required(VERSION 3.12)

if(UNIX)
    if(APPLE)
        set(CMAKE_CXX_FLAGS "-std=c++17 -stdlib=libc++")
    else()
        set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -march=native -fvisibility=hidden")
    endif()
endif()

set(LIBRARY_FILES
    src/vtm/BandpassFilter.h
    src/vtm/Butterworth1LowpassFilter.h
    src/vtm/Butterworth2LowpassFilter.h
    src/vtm/DifferenceFilter.h
    src/vtm/ConfigurationData.cpp
    src/vtm/ConfigurationData.h
    src/vtm/Exception.h
    src/vtm/Log.cpp
    src/vtm/Log.h
    src/vtm/NoiseSource.h
    src/vtm/ParameterLogger.h
    src/vtm/PoleZeroRadiationImpedance.h
    src/vtm/RosenbergBGlottalSource.h
    src/vtm/SampleRateConverter.h
    src/vtm/VocalTractModel.h
    src/vtm/VocalTractModel5.h
    src/vtm/VTMUtil.h

    src/vtm_gama_tts.cpp
    src/vtm_gama_tts.h
)

add_library(vtm_gama_tts_5 MODULE ${LIBRARY_FILES})
target_include_directories(vtm_gama_tts_5 PRIVATE
    src
    src/vtm
)
