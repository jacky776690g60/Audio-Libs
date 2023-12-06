/* =================================================================
| Clipping.h  --  DSP/ClippingAlgorithms/Clipping.h
|
| Created by Jack on 05/01, 2023
| Copyright © 2023 jacktogon. All rights reserved.
================================================================= */
#pragma once
#include <iostream>

/** This class contains different clipping algorithms */
class Clipping { 
public:
    static float clamping(float x, float threshold=1.0f) {
        return std::clamp(x, -threshold, threshold);
    }


    static float softClipping(float x, float threshold=.8f) {
        float scaledInput = x / threshold;                                           // Pre-scale the signal according to the threshold
        // ~~~~~~~~ sigmoid-like function for soft clipping ~~~~~~~~
        float clipped = threshold * (scaledInput / (1.0f + std::fabs(scaledInput))); // fabs: floating-point-absolute value
        return clipped;
    }


    static float hardClipping(
        float x, 
        float threshold = .95f, 
        float kneeWidth = .25f
    ) {
        float kneeHalfWidth = kneeWidth / 2.0f;
        float kneeStart = threshold - kneeHalfWidth;
        float kneeEnd = threshold + kneeHalfWidth;

        if (std::abs(x) < kneeStart) {
            // Below knee start, no clipping
            return x;
        } else if (std::abs(x) > kneeEnd) {
            // Above knee end, full clipping
            return (x > 0) ? threshold : -threshold;
        }
        // Within the knee, sigmoid-like transition
        float t = (std::abs(x) - kneeStart) / kneeWidth;
        float smooth_transition = 1.0f / (1.0f + std::exp(-12.0f * (t - 0.5f)));  // Sigmoid-like curve
        float clippedValue = (x > 0) ? threshold : -threshold;
        return smooth_transition * clippedValue + (1.0f - smooth_transition) * x;
    }


    static float tanh(float x) {
        return std::tanh(x);
    }
};

