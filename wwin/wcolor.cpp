#include "wcolor.h"

WColor::WColor()
{
    _cspec = Spec::Rgb;
    _color.argb.alpha = 255;
    _color.argb.red   = 0;
    _color.argb.green = 0;
    _color.argb.blue  = 0;
    _color.argb.pad   = 0;
}

WColor::WColor(int r, int g, int b, int a)
{
    _cspec = Spec::Rgb;
    _color.argb.alpha = 255;
    _color.argb.red   = r;
    _color.argb.green = g;
    _color.argb.blue  = b;
    _color.argb.pad   = 0;
}

WColor::WColor(WRgb rgb)
{
    _cspec = Spec::Rgb;
    _color.argb.alpha = 255;
    _color.argb.red   = wRed(rgb);
    _color.argb.green = wGreen(rgb);
    _color.argb.blue  = wBlue(rgb);
    _color.argb.pad   = 0;
}

void WColor::setRgb(int r, int g, int b, int a)
{
    _cspec = Spec::Rgb;
    _color.argb.alpha = a;
    _color.argb.red   = r;
    _color.argb.green = g;
    _color.argb.blue  = b;
    _color.argb.pad   = 0;
}

void WColor::setHsv(int h, int s, int v, int a)
{
    _cspec = Spec::Hsv;
    _color.ahsv.alpha      = a;
    _color.ahsv.hue        = h;
    _color.ahsv.saturation = s;
    _color.ahsv.value      = v;
    _color.ahsv.pad        = 0;
}

void WColor::setCmyk(int c, int m, int y, int k, int a)
{
    _cspec = Spec::Cmyk;
    _color.acmyk.alpha   = a;
    _color.acmyk.cyan    = c;
    _color.acmyk.magenta = m;
    _color.acmyk.yellow  = y;
    _color.acmyk.black   = k;
}

void WColor::setHsl(int h, int s, int l, int a)
{
    _cspec = Spec::Hsl;
    _color.ahsl.alpha      = a;
    _color.ahsl.hue        = h;
    _color.ahsl.saturation = s;
    _color.ahsl.lightness  = l;
    _color.ahsl.pad        = 0;
}

