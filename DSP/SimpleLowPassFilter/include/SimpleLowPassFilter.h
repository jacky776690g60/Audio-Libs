/* =================================================================
| SimpleLowPassFilter.h  --  DSP/SimpleLowPassFilter/include/SimpleLowPassFilter.h
|
| Created by Jack on 12/03, 2023
| Copyright © 2023 jacktogon. All rights reserved.
================================================================= */
#pragma once

#include <iostream>

class SimpleLowPassFilter
{
public:
    SimpleLowPassFilter();
    ~SimpleLowPassFilter();

    // Set the cutoff frequency and recalculate coefficients
    void setCutoffFrequency(float frequency, float sampleRate);
    // Process a sample through the filter
    float processSample(float sample, int channel);
    //
    void setQFactor(float qFactor);
    // Reset the filter's internal state
    void reset();
    
    // ==============================
    // Utility
    // ==============================
    static inline float mapAlphaToFrequency(float alpha) {
            const float minFreq = 20.0f;
            const float maxFreq = 20000.0f;
            return minFreq * std::pow(maxFreq / minFreq, alpha);
    };

private:
    float lastOutput[2] = {0.0f, 0.0f}; // stereo, 0: left, 1: right
    float alpha = 1.0f;                 // Coefficient for the filter
    float Q = 10.0f;                     // Quality factor, default to 1.0 for no resonance; control resonance at the cutoff frequency
    inline static constexpr float PI = 3.14159265358979323846f;
};
