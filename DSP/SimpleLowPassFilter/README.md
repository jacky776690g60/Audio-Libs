# Simple Low Pass Filter

<h2 style="display: inline-block; padding: 5px 15px; border-radius: 5px; border-bottom: 3px solid #1a252f; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; text-transform: capitalize; letter-spacing: 1.5px; box-shadow: 0px 3px 5px rgba(0,0,0,0.2);">
    Description
</h2>

This is a simple one-pole low-pass filter implemented in JUCE.

`Single-Pole Filter`: A filter characterized by its simplicity, usually with a 6 dB/octave rolloff. The term "pole" is from the world of control theory and signal processing.



<h2 style="display: inline-block; padding: 5px 15px; border-radius: 5px; border-bottom: 3px solid #1a252f; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; text-transform: capitalize; letter-spacing: 1.5px; box-shadow: 0px 3px 5px rgba(0,0,0,0.2);">
    Testing Environmnet
</h2>

- C++ 17
- JUCE 7.07
- macOS (Ventura 13.4.1 (c))
- Studio One 5


<h2 style="display: inline-block; padding: 5px 15px; border-radius: 5px; border-bottom: 3px solid #1a252f; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; text-transform: capitalize; letter-spacing: 1.5px; box-shadow: 0px 3px 5px rgba(0,0,0,0.2);">
    Formula
</h2>

1. The formula for `cutoff frequency`:
    
   - The time constant of an `RC` circuit, which is the basis for this filter design.
   
     `RC circuit`: a circuit that consists of a resistor (R) and a capacitor (C) connected in series or parallel.

     The filter mimics the behavior of a real-world RC circuit in terms of how it responds to different frequencies.
   $$RC = \frac{1} {frequency \times 2\pi}$$
   ---
   - The variable `dt` represents the time between samples, which is the inverse of the sample rate.
   $$dt = \frac{1} {sampleRate}$$
   ---
   - Finally, `α` is a **coefficient** that determines how much of the previous sample's value should be kept versus the current sample.
    
        As `Q` increases, the blend leans more towards the current input sample, resulting in a faster filter response. This causes a more pronounced or "peak" response at the cutoff frequency, giving the effect of resonance.
   $$\alpha = \frac{dt} {RC + dt} \times Q$$

2. The formula for `low-pass filtering`:

   $$\text{lastOutput[channel]} = (1 - \alpha) \times \text{lastOutput[channel]} + \alpha \times sample$$


<h2 style="display: inline-block; padding: 5px 15px; border-radius: 5px; border-bottom: 3px solid #1a252f; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; text-transform: capitalize; letter-spacing: 1.5px; box-shadow: 0px 3px 5px rgba(0,0,0,0.2);">
    References
</h2>

- [RC Circuit Basics - Low & High Pass Filtering & Formulas](https://www.arrow.com/en/research-and-events/articles/rc-circuit-basics-low-high-pass-filtering-and-formulas#:~:text=To%20function%20as%20a%20low,shown%20in%20the%20figure%20above.)
- [Passive Low Pass RC Filters](https://www.electronicshub.org/passive-low-pass-rc-filters/)