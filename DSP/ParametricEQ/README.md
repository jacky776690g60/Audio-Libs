<h1 style="color: white; background: linear-gradient(43deg, #4158D0 0%, #d253c3 58%, #FB5959 100%); text-align: center; padding: 10px; box-shadow: 3px 3px 10px rgba(0,0,0,0.2); font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; border-radius: 5px; text-transform: capitalize;">
    ParametricEQ
</h1>

### Set of Coefficients:
$$b_0 = \frac{(1 - \cos(\omega))}{2}$$
$$b_1 = 1 - \cos(\omega)$$
$$b_2 = \frac{(1 - \cos(\omega))}{2}$$
$$a_0 = 1 + \alpha$$
$$a_1 = -2 \cos(\omega)$$
$$a_2 = 1 - \alpha$$

Explanation:
- `Feedforward coefficients (b's)`: These coefficients work with the input signal. Imagine them as factors that determine how much of the current, previous, and the sample before the last of the input signal respectively affect the output.
  - `b0`: How much of the current input sample affects the output.
  - `b1`: How much of the previous input sample affects the output.
  - `b2`: How much of the input sample before the last affects the output.

- `Feedback coefficients (a's)`: These coefficients work with the output signal. They are responsible for the "recursive" or "feedback" part of IIR filters, hence the name feedback coefficients.
  - `a0`: Generally a normalization coefficient. Most times it's used to ensure the filter remains stable.
  - `a1`: How much of the previous output sample is fed back into the filter. Think of it as mixing some of the previous output back into the system to shape the new output.
  - `a2`: How much of the output sample before the last is fed back into the filter. It's like remembering even further back and letting that older memory also shape the new output.


<h2 style="display: inline-block; padding: 5px 15px; border-radius: 5px; border-bottom: 3px solid #1a252f; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; text-transform: capitalize; letter-spacing: 1.5px; box-shadow: 0px 3px 5px rgba(0,0,0,0.2);">
    Formula
</h2>

### First of all, `biquad`:
- **$\omega$ (omega / Normalized frequency)** represents the normalized frequency and is calculated as:
  $$\omega\ (omega) = \frac{2 \times \pi \times f_0}{sampleRate}$$
  This is essentially the normalized cutoff frequency. By using trigonometric functions like cosine on it, we can exploit periodic properties to determine how the filter behaves at and around the cutoff frequency.

- **$\alpha$ (alpha / sharpness)** is derived from the quality factor Q of the filter and is calculated as:
  $$\alpha = \frac{\sin(\omega)}{2 \times Q}$$
  It relates to the bandwidth or 'sharpness' of the filter. A smaller $\alpha$ (smaller Q) makes the transition from passband to stopband more gradual, while a larger $\alpha$ (larger Q) makes it more sudden or sharp.

- **$A$ (amplitude factor)**: Represents the amount of boost or cut. If the gainDB is positive, it means we're boosting the signal around 
  $f_0$. If negative, we're attenuating or reducing the signal strength around $f_0$.
  $$A = 10^\frac{gainDB}{40}$$

  The base $10$ comes from the decibel's logarithmic definition related to power and amplitude. The factor of $40$ in the denominator is a specific conversion factor for amplitude ratios. If we were considering power ratios, we'd use $20$ instead, as power is proportional to the square of the amplitude.

  For instance, if gainDB were 6:
  $$A = 10^\frac{6}{40} ≈ 2$$

  This result would indicate that you should amplify (increase) the amplitude of the signal by a factor of approximately 2, which is consistent with the intuitive understanding that +6 dB corresponds to doubling the amplitude.

### Secondly
- `Low Pass`: allows frequencies below a certain cutoff frequency (f0 or omega) to pass through while attenuating frequencies above the cutoff frequency.

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = \frac{(1 - \cos(\omega))}{2}$$
  $$b_1 = 1 - \cos(\omega)$$
  $$b_2 = \frac{(1 - \cos(\omega))}{2}$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = 1 + \alpha$$
  $$a_1 = -2 \times \cos(\omega)$$
  $$a_2 = 1 - \alpha$$

- `High Pass`: The mathematics here uses trigonometric functions due to the cyclic nature of audio signals (sine waves). By leveraging the properties of sines and cosines on a normalized frequency spectrum, these formulas efficiently determine how to amplify or attenuate different frequency components to achieve the highpass behavior.

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = \frac{(1 + \cos(\omega))}{2}$$
  $$b_1 = - (1 + \cos(\omega))$$
  $$b_2 = \frac{(1 + \cos(\omega))}{2}$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = 1 + \alpha$$
  $$a_1 = -2 \times \cos(\omega)$$
  $$a_2 = 1 - \alpha$$

- `BandPass`: allows frequencies within a specific range to pass through while attenuating frequencies outside of that range. The essence of a BandPass filter's math lies in the interplay of feedforward and feedback coefficients to amplify a specific frequency range (band) while suppressing others.
  - **Feedforward Coefficients (`b` values):**
  $$b_0 = \alpha$$
  $$b_1 = 0$$
  $$b_2 = -\alpha$$

  - **Feedback Coefficients (`a` values)**
  $$a_0 = 1 + \alpha$$
  $$a_1 = -2 \times \cos(\omega)$$
  $$a_2 = 1 - \alpha$$

- `Notch`: sometimes known as a Band-Stop or Band-Reject filter, is essentially the inverse of a BandPass filter. It's designed to attenuate or "cut out" a narrow frequency band, allowing frequencies both below and above that band to pass through largely unaffected. The essence of a Notch filter is to cut out a specific frequency or range of frequencies.

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = 1$$
  $$b_1 = -2 \times \cos(\omega)$$
  $$b_2 = 1$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = 1 + \alpha$$
  $$a_1 = -2 \times \cos(\omega)$$
  $$a_2 = 1 - \alpha$$


- `Peak`: (also known as a Bell filter or a Parametric EQ) is designed to either boost or cut a frequency band centered around a specified frequency $f_0$ without entirely eliminating it. The boost or cut amount is determined by a gain parameter.
  

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = 1 + \alpha \times A$$
  $$b_1 = -2 \times \cos(\omega)$$
  $$b_2 = 1 - \alpha \times A$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = 1 + \alpha / A$$
  $$a_1 = -2 \times \cos(\omega)$$
  $$a_2 = 1 - \alpha / A$$

- `Low Shelf`: A LowShelf filter will boost or cut frequencies below a specified cutoff frequency $f_0$. It's like a volume control specifically for the low frequencies.

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = A \times ( (A+1) - (A-1) \times \cos(\omega) + 2 \times \sqrt{A} \times \alpha )$$
  $$b_1 = 2 \times A \times ( (A-1) - (A+1) \times \cos(\omega) )$$
  $$b_2 = A \times ( (A+1) - (A-1) \times \cos(\omega) - 2 \times \sqrt{A} \times \alpha )$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = (A+1) + (A-1) \times \cos(\omega) + 2 \times \sqrt{A} \times \alpha $$
  $$a_1 = -2 \times ( (A-1) + (A+1) \times \cos(\omega) ) $$
  $$a_2 = (A+1) + (A-1) \times \cos(\omega) - 2 \times \sqrt{A} \times \alpha $$

  The amplification factor $A$ determines the extent of the boost or cut. If $A$ is greater than 1, there's a boost. If $A$ is less than 1, there's a cut.

- `High Shelf`: A HighShelf filter boosts or cuts frequencies above a specified cutoff frequency $f_0$. It acts as a volume control specifically for the high frequencies.

  - **Feedforward Coefficients (`b` values):**
  $$b_0 = A \times ( (A+1) + (A-1) \times \cos(\omega) + 2 \times \sqrt{A} \times \alpha )$$
  $$b_1 = -2 \times A \times ( (A-1) + (A+1) \times \cos(\omega) )$$
  $$b_2 = A \times ( (A+1) + (A-1) \times \cos(\omega) - 2 \times \sqrt{A} \times \alpha )$$

  - **Feedback Coefficients (`a` values):**
  $$a_0 = (A+1) - (A-1) \times \cos(\omega) + 2 \times \sqrt{A} \times \alpha$$
  $$a_1 = 2 \times ( (A-1) - (A+1) \times \cos(\omega) )$$
  $$a_2 = (A+1) - (A-1) \times \cos(\omega) - 2 \times \sqrt{A} \times \alpha$$

  The amplification factor $A$ is same as Low Shelf.


### Thirdly
The normalization of filter coefficients is a common practice in digital filter design, and here's why:

  **Stability and Precision:**

  - `Stability`: Digital filters need to be stable to avoid unwanted oscillations or even blow-ups. By ensuring $a_0=1$, we're setting a reference point which ensures that the filter's transfer function is set to a predictable and stable form.

  - `Precision`: Floating point numbers (like `float` or `double`) have a finite precision in computers. By normalizing the coefficients around a certain value (in this case, $a_0$), the operations in the filter calculations (like multiplications and additions) can be more accurate. This avoids potential precision issues or rounding errors during processing.

  **Mathematical Convenience:**

  - `Transfer Function Simplification`: When analyzing or representing filters mathematically, having $a_0=1$ simplifies the representation of the filter's transfer function. This makes analysis and transformations (like getting the frequency response) more straightforward.

  - `Form Consistency`: By convention, many filter designs normalize around $a_0$. This means that if you look at different filters or use different tools, you'll often find the same convention used. It helps ensure that when you swap filters or borrow designs, you're always working with the same standard form.

  **Practical Implementation:**

  - `Predictable Gain`: A filter's gain at certain frequencies, especially the DC (0 Hz) component, is often a direct result of the filter coefficients. By normalizing, we ensure that the filter's gain at these frequencies matches our design expectations.

  - `Computational Efficiency`: Knowing that $a_0=1$ can sometimes simplify the real-time computations required when processing samples through the filter, saving a multiplication.



