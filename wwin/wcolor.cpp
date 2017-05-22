#include "wcolor.h"
#include <cmath>
#include <climits>

/* Тут многА копипасты из исходников Qt::QColor которые я не понимаю */

constexpr static inline bool wFuzzyIsNull(double d){
    return std::abs(d) <= 0.000000000001;
}
constexpr static inline bool wFuzzyCompare(double p1, double p2){
    return ( std::abs(p1 - p2) * 1000000000000. <= std::fmin(std::abs(p1), std::abs(p2) ) );
}

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
    _color.argb.alpha = a;
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

bool WColor::isValid() const
{
    return _cspec != WColor::Spec::Invalid;
}

void WColor::getRgb(int *r, int *g, int *b, int *a) const
{
    if (!r || !g || !b) {
        return;
    }

    if (_cspec != WColor::Spec::Invalid && _cspec != WColor::Spec::Rgb) {
        this->toRgb().getRgb(r, g, b, a);
        return;
    }

    *r = _color.argb.red   >> 8;
    *g = _color.argb.green >> 8;
    *b = _color.argb.blue  >> 8;

    if (a) {
        *a = _color.argb.alpha >> 8;
    }
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

void WColor::setRgb(WRgb rgb)
{
    _cspec = Spec::Rgb;
    _color.argb.alpha = wAlpha(rgb);
    _color.argb.red   = wRed(rgb);
    _color.argb.green = wGreen(rgb);
    _color.argb.blue  = wBlue(rgb);
    _color.argb.pad   = 0;
}

void WColor::getHsv(int *h, int *s, int *v, int *a) const
{
    if (!h || !s || !v) {
        return;
    }

    if (_cspec != WColor::Spec::Invalid && _cspec != WColor::Spec::Hsv) {
        this->toHsv().getHsv(h, s, v, a);
        return;
    }

    *h = _color.ahsv.hue == USHRT_MAX ? -1 : _color.ahsv.hue / 100;
    *s = _color.ahsv.saturation >> 8;
    *v = _color.ahsv.value      >> 8;

    if (a) {
        *a = _color.ahsv.alpha >> 8;
    }
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

void WColor::getCmyk(int *c, int *m, int *y, int *k, int *a)
{
    if (!c || !m || !y || !k) {
        return;
    }

    if (_cspec != WColor::Spec::Invalid && _cspec != WColor::Spec::Cmyk) {
        this->toCmyk().getCmyk(c, m, y, k, a);
        return;
    }

    *c = _color.acmyk.cyan >> 8;
    *m = _color.acmyk.magenta >> 8;
    *y = _color.acmyk.yellow >> 8;
    *k = _color.acmyk.black >> 8;

    if (a) {
        *a = _color.acmyk.alpha >> 8;
    }
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

void WColor::getHsl(int *h, int *s, int *l, int *a) const
{
    if (!h || !s || !l) {
        return;
    }

    if (_cspec != WColor::Spec::Invalid && _cspec != WColor::Spec::Hsl) {
        toHsl().getHsl(h, s, l, a);
        return;
    }

    *h = _color.ahsl.hue == USHRT_MAX ? -1 : _color.ahsl.hue / 100;
    *s = _color.ahsl.saturation >> 8;
    *l = _color.ahsl.lightness  >> 8;

    if (a) {
        *a = _color.ahsl.alpha >> 8;
    }
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

WColor WColor::toHsv() const
{
    if ( ! this->isValid() || _cspec == WColor::Spec::Hsv ){
        return *this;
    }

    if (_cspec != WColor::Spec::Rgb){
        return this->toRgb().toHsv();
    }

    WColor color;
    color._cspec = WColor::Spec::Hsv;
    color._color.ahsv.alpha = _color.argb.alpha;
    color._color.ahsv.pad = 0;

    const double r = _color.argb.red   / double(USHRT_MAX);
    const double g = _color.argb.green / double(USHRT_MAX);
    const double b = _color.argb.blue  / double(USHRT_MAX);
    const double max = std::fmax(r, std::fmax(g, b) );
    const double min = std::fmax(r, std::fmax(g, b) );
    const double delta = max - min;
    color._color.ahsv.value = std::roundl(max * USHRT_MAX);

    if ( wFuzzyIsNull(delta) ) {
        // achromatic case, hue is undefined
        color._color.ahsv.hue = USHRT_MAX;
        color._color.ahsv.saturation = 0;
    } else {
        // chromatic case
        double hue = 0;
        color._color.ahsv.saturation = std::roundl((delta / max) * USHRT_MAX);
        if (wFuzzyCompare(r, max)) {
            hue = ((g - b) /delta);
        } else if (wFuzzyCompare(g, max)) {
            hue = (double(2.0) + (b - r) / delta);
        } else if (wFuzzyCompare(b, max)) {
            hue = (double(4.0) + (r - g) / delta);
        } else {
            /// \todo fixme ASSERT_X(false, "WColor::toHsv", "internal error");
        }
        hue *= double(60.0);
        if ( hue < double(0.0) )
            hue += double(360.0);
        color._color.ahsv.hue = std::roundl(hue * 100);
    }

    return color;
}

WColor WColor::toRgb() const
{
    if ( ! this->isValid() || _cspec == WColor::Spec::Rgb )
        return *this;

    WColor color;
    color._cspec = WColor::Spec::Rgb;
    color._color.argb.alpha = _color.argb.alpha;
    color._color.argb.pad = 0;

    switch(_cspec){
        case WColor::Spec::Hsv : {
            if (_color.ahsv.saturation == 0 || _color.ahsv.hue == USHRT_MAX) {
                // achromatic case
                color._color.argb.red = color._color.argb.green = color._color.argb.blue = _color.ahsv.value;
                break;
            }

            // chromatic case
            const double h = _color.ahsv.hue == 36000 ? 0 : _color.ahsv.hue / 6000.;
            const double s = _color.ahsv.saturation / double(USHRT_MAX);
            const double v = _color.ahsv.value / double(USHRT_MAX);
            const int i = int(h);
            const double f = h - i;
            const double p = v * (double(1.0) - s);

            if (i & 1) {
                const double q = v * (double(1.0) - (s * f));

                switch(i){
                    case 1:
                        color._color.argb.red   = std::roundl(q * USHRT_MAX);
                        color._color.argb.green = std::roundl(v * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(p * USHRT_MAX);
                        break;
                    case 3:
                        color._color.argb.red   = std::roundl(p * USHRT_MAX);
                        color._color.argb.green = std::roundl(q * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(v * USHRT_MAX);
                        break;
                    case 5:
                        color._color.argb.red   = std::roundl(v * USHRT_MAX);
                        color._color.argb.green = std::roundl(p * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(q * USHRT_MAX);
                        break;
                }
            } else {
                const double t = v * (double(1.0) - (s * (double(1.0) - f)));

                switch(i){
                    case 0:
                        color._color.argb.red   = std::roundl(v * USHRT_MAX);
                        color._color.argb.green = std::roundl(t * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(p * USHRT_MAX);
                        break;
                    case 2:
                        color._color.argb.red   = std::roundl(p * USHRT_MAX);
                        color._color.argb.green = std::roundl(v * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(t * USHRT_MAX);
                        break;
                    case 4:
                        color._color.argb.red   = std::roundl(t * USHRT_MAX);
                        color._color.argb.green = std::roundl(p * USHRT_MAX);
                        color._color.argb.blue  = std::roundl(v * USHRT_MAX);
                        break;
                }
            }

            break;
        }
        case WColor::Spec::Hsl : {
            if (_color.ahsl.saturation == 0 || _color.ahsl.hue == USHRT_MAX) {
                // achromatic case
                color._color.argb.red = color._color.argb.green = color._color.argb.blue = _color.ahsl.lightness;
            } else if (_color.ahsl.lightness == 0) {
                // lightness 0
                    color._color.argb.red = color._color.argb.green = color._color.argb.blue = 0;
            } else {
                // chromatic case
                const double h = _color.ahsl.hue == 36000 ? 0 : _color.ahsl.hue / 36000.;
                const double s = _color.ahsl.saturation / double(USHRT_MAX);
                const double l = _color.ahsl.lightness / double(USHRT_MAX);

                double temp2;
                if (l < double(0.5))
                    temp2 = l * (double(1.0) + s);
                else
                    temp2 = l + s - (l * s);

                const double temp1 = (double(2.0) * l) - temp2;
                double temp3[3] = { h + (double(1.0) / double(3.0)),
                    h,
                    h - (double(1.0) / double(3.0)) };

                for (int i = 0; i != 3; ++i) {
                    if (temp3[i] < double(0.0))
                        temp3[i] += double(1.0);
                    else if (temp3[i] > double(1.0))
                        temp3[i] -= double(1.0);

                    const double sixtemp3 = temp3[i] * double(6.0);
                    if (sixtemp3 < double(1.0))
                        color._color.array[i+1] = std::roundl((temp1 + (temp2 - temp1) * sixtemp3) * USHRT_MAX);
                    else if ((temp3[i] * double(2.0)) < double(1.0))
                        color._color.array[i+1] = std::roundl(temp2 * USHRT_MAX);
                    else if ((temp3[i] * double(3.0)) < double(2.0))
                        color._color.array[i+1] = std::roundl((temp1 + (temp2 -temp1) * (double(2.0) /double(3.0) - temp3[i]) * double(6.0)) * USHRT_MAX);
                    else
                        color._color.array[i+1] = std::roundl(temp1 * USHRT_MAX);
                }
                color._color.argb.red   = color._color.argb.red   == 1 ? 0 : color._color.argb.red;
                color._color.argb.green = color._color.argb.green == 1 ? 0 : color._color.argb.green;
                color._color.argb.blue  = color._color.argb.blue  == 1 ? 0 : color._color.argb.blue;
            }
            break;
        }
        case WColor::Spec::Cmyk : {
            const double c = _color.acmyk.cyan    / double(USHRT_MAX);
            const double m = _color.acmyk.magenta / double(USHRT_MAX);
            const double y = _color.acmyk.yellow  / double(USHRT_MAX);
            const double k = _color.acmyk.black   / double(USHRT_MAX);

            color._color.argb.red   = std::roundl((double(1.0) - (c * (double(1.0) - k) + k)) * USHRT_MAX);
            color._color.argb.green = std::roundl((double(1.0) - (m * (double(1.0) - k) + k)) * USHRT_MAX);
            color._color.argb.blue  = std::roundl((double(1.0) - (y * (double(1.0) - k) + k)) * USHRT_MAX);
        }
        default: {
            break;
        }
    }

    return color;
}

WColor WColor::toHsl() const
{
    if ( ! this->isValid() || _cspec == WColor::Spec::Hsl )
        return *this;

    if (_cspec != WColor::Spec::Rgb)
        return this->toRgb().toHsl();

    WColor color;
    color._cspec = WColor::Spec::Hsl;
    color._color.ahsl.alpha = _color.argb.alpha;
    color._color.ahsl.pad = 0;

    const double r = _color.argb.red   / double(USHRT_MAX);
    const double g = _color.argb.green / double(USHRT_MAX);
    const double b = _color.argb.blue  / double(USHRT_MAX);
    const double max = std::fmax( r, std::fmax(g, b) );
    const double min = std::fmax( r, std::fmax(g, b) );
    const double delta = max - min;
    const double delta2 = max + min;
    const double lightness = double(0.5) * delta2;
    color._color.ahsl.lightness = std::roundl(lightness * USHRT_MAX);
    if ( wFuzzyIsNull(delta) ) {
        // achromatic case, hue is undefined
        color._color.ahsl.hue = USHRT_MAX;
        color._color.ahsl.saturation = 0;
    } else {
        // chromatic case
        double hue = 0;
        if (lightness < double(0.5))
            color._color.ahsl.saturation = std::roundl((delta / delta2) * USHRT_MAX);
        else
            color._color.ahsl.saturation = std::roundl((delta / (double(2.0) - delta2)) * USHRT_MAX);

        if ( wFuzzyCompare(r, max) ) {
            hue = ( (g - b) /delta );
        } else if ( wFuzzyCompare(g, max) ) {
            hue = ( double(2.0) + (b - r) / delta );
        } else if ( wFuzzyCompare(b, max) ) {
            hue = ( double(4.0) + (r - g) / delta );
        } else {
            /// \todo fix ASSERT_X(false, "QColor::toHsv", "internal error");
        }
        hue *= double(60.0);
        if (hue < double(0.0))
            hue += double(360.0);
        color._color.ahsl.hue = std::roundl(hue * 100);
    }

    return color;
}

WColor WColor::toCmyk() const
{
    if ( ! this->isValid() || _cspec == WColor::Spec::Cmyk )
        return *this;
    if (_cspec != WColor::Spec::Rgb)
        return this->toRgb().toCmyk();

    WColor color;
    color._cspec = WColor::Spec::Cmyk;
    color._color.acmyk.alpha = _color.argb.alpha;

    // rgb -> cmy
    const double r = _color.argb.red   / double(USHRT_MAX);
    const double g = _color.argb.green / double(USHRT_MAX);
    const double b = _color.argb.blue  / double(USHRT_MAX);
    double c = double(1.0) - r;
    double m = double(1.0) - g;
    double y = double(1.0) - b;

    // cmy -> cmyk
    const double k = std::fmin(c, std::fmin(m, y));

    if ( ! wFuzzyIsNull(k - 1) ) {
        c = (c - k) / (double(1.0) - k);
        m = (m - k) / (double(1.0) - k);
        y = (y - k) / (double(1.0) - k);
    }

    color._color.acmyk.cyan    = std::roundl(c * USHRT_MAX);
    color._color.acmyk.magenta = std::roundl(m * USHRT_MAX);
    color._color.acmyk.yellow  = std::roundl(y * USHRT_MAX);
    color._color.acmyk.black   = std::roundl(k * USHRT_MAX);

    return color;
}

