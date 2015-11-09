#ifndef COLOR_H
#define COLOR_H

#include <inttypes.h>

class Color {
public:
    Color(unsigned long value) : _value(value) { }
    Color(uint16_t red, uint16_t green, uint16_t blue) {
        _value = rgbToHex(red, green, blue);
    }
    uint16_t getRed() {
        return (_value & 0xFF0000) >> 16;
    }
    uint16_t getGreen() {
        return (_value & 0x00FF00) >> 8;
    }
    uint16_t getBlue() {
        return _value & 0x0000FF;
    }
    uint16_t getValue() {
        return _value;
    }
    static unsigned long rgbToHex(uint16_t red, uint16_t green, uint16_t blue) {
        return (red << 16) + (green << 8) + blue;
    }
    static Color gradedValue(Color beginColor, Color endColor, float percent) {
        uint16_t red = beginColor.getRed() + (uint16_t)(percent * (endColor.getRed() - beginColor.getRed()));
        uint16_t blue = beginColor.getBlue() + (uint16_t)(percent * (endColor.getBlue() - beginColor.getBlue()));
        uint16_t green = beginColor.getGreen() + (uint16_t)(percent * (endColor.getGreen() - beginColor.getGreen()));
        return Color(red, green, blue);
    }
private:
    unsigned long _value;
};

#endif COLOR_H