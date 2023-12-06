<h1 style="color: white; background: linear-gradient(43deg, #4158D0 0%, #d253c3 58%, #FB5959 100%); text-align: center; padding: 10px; box-shadow: 3px 3px 10px rgba(0,0,0,0.2); font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; border-radius: 5px; text-transform: capitalize;">
    Distortion Algorithms
</h1>

- `Wave shaping`: Using exponential function, it can create more drastic changes as the input signal increases.
  
$$
f(x) = \text{sign}(x) \times (1 - e^{-|\text{drive} \times x|})
$$

  Increases ***a (coefficient)*** to produce more pronounced distortion.

- `Foldback distortion`: often called "folding" or "mirroring", is a type of non-linear distortion where the amplitude of the audio signal, when exceeding a threshold, is folded back on itself. 

$$
\text{foldedSignal} = 
\begin{cases} 
    \text{threshold} + (1 - \text{ratio}) \times (\text{threshold} - \left| x \right| \bmod (2 \times \text{threshold})) \times \text{sign}(x), & \text{if } \left| x \right| > \text{threshold} \\
    x, & \text{otherwise}
\end{cases}
$$

- `Cubic distortion`: The $x^3$ term introduces harmonic distortion, specifically, non-linear distortion. When $x$ is small, this term doesn't contribute much, so the output is very close to the input (linear region). As $x$ approaches ±1, the cubic term starts having a more pronounced effect, which starts compressing and distorting the waveform.

$$
\begin{cases} 
  y = x - \frac{x^3}{3}, & \text{if -1 < x < 1} \\
  y = -\frac{2}{3},& \text{if x < -1}\\
  y = \frac{2}{3}, & \text{if x > 1}
\end{cases}
$$


- `n-Bit Crushing`: reduce the resolution of the signal. The idea behind bit crushing is to intentionally reduce the bit depth of the audio signal, which will degrade the quality and introduce quantization error (this is the "crushing" part).

  - x: input sample
  - B: (integer) number of bits
  - $\left\lfloor \space \right\rfloor$: flooring
  - sign: store the sign of the number

$$
f(x, B) = \text{sign}(x) \times \left\lfloor \frac{|x| \times (2^{\max(B, 1)} - 1) + 0.5}{2^{\max(B, 1)} - 1} \right\rfloor \text{, then clamp between -1 to 1}
$$
  
- `Overdrive`: softer distortion

  **Characteristics:**

  - **Drive Parameter (`drive`):** Controls the intensity of the overdrive effect. A higher `drive` value increases the distortion level.
  - **Tone Parameter (`tone`):** Allows for tonal adjustments of the signal, affecting the distortion's character.
  - **Non-linear Transformation (`tanh`):** The `tanh` function smoothly distorts the signal, emulating the warm sound of overdriven tube amplifiers.
  - **Normalization:** The output is normalized by dividing it by `tanh(drive + tone)`, ensuring the output remains within a standard range and avoiding excessive amplitude.

$$
\text{overdrive}(x, \text{drive}, \text{tone}) = \frac{\tanh(\text{drive} \cdot x + \text{tone})}{\tanh(\text{drive} + \text{tone})}
$$