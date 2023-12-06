<h1 style="color: white; background: linear-gradient(43deg, #4158D0 0%, #d253c3 58%, #FB5959 100%); text-align: center; padding: 10px; box-shadow: 3px 3px 10px rgba(0,0,0,0.2); font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; border-radius: 5px; text-transform: capitalize;">
  RotaryKnob
</h1>

#### Example Usage

```cpp
#include <components/RotaryKnob/include/RotaryKnob.h>

RotaryKnob gainSlider;
gainSlider.setRange(-24.0, 24.0, 0.01);
gainSlider.setKnobImage(
    juce::ImageCache::getFromMemory(BinaryData::jack_burning_icon_png, BinaryData::jack_burning_icon_pngSize), // assume image have been added in Projucer
    50, 50
);
```