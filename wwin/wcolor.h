#ifndef WCOLOR_H
#define WCOLOR_H

typedef unsigned int WRgb;

#define rgb(r,g,b) (0xff000000 | (r << 16) |  (g << 8) | b)

/*!
 * \brief Класс WColor описывает цвет и предоставляет методы для работы с ним
 */
class WColor
{
public:
    enum Spec{ Invalid, Rgb, Hsv, Cmyk, Hsl };

    WColor();
    WColor(int r, int g, int b, int a = 255);
    WColor(WRgb rgb);

    bool isValid() const;

    void getRgb(int *r, int *g, int *b, int *a = nullptr) const;
    void setRgb(int r, int g, int b, int a = 255);
    void setRgb(WRgb rgb);

    void getHsv(int *h, int *s, int *v, int *a = nullptr) const;
    void setHsv(int h, int s, int v, int a = 255);

    void getCmyk(int *c, int *m, int *y, int *k, int *a = nullptr);
    void setCmyk(int c, int m, int y, int k, int a = 255);

    void getHsl(int *h, int *s, int *l, int *a = nullptr) const;
    void setHsl(int h, int s, int l, int a = 255);

    WColor toHsv() const;
    WColor toRgb() const;
    WColor toHsl() const;
    WColor toCmyk() const;

private:
    Spec _cspec = Spec::Invalid;
    union {
        struct {
            unsigned short alpha;
            unsigned short red;
            unsigned short green;
            unsigned short blue;
            unsigned short pad;
        } argb;
        struct {
            unsigned short alpha;
            unsigned short hue;
            unsigned short saturation;
            unsigned short value;
            unsigned short pad;
        } ahsv;
        struct {
            unsigned short alpha;
            unsigned short cyan;
            unsigned short magenta;
            unsigned short yellow;
            unsigned short black;
        } acmyk;
        struct {
            unsigned short alpha;
            unsigned short hue;
            unsigned short saturation;
            unsigned short lightness;
            unsigned short pad;
        } ahsl;
        unsigned short array[5];
    } _color;
};

inline constexpr int wRed(WRgb rgb){
    return ((rgb >> 16) & 0xff);
}
inline constexpr int wGreen(WRgb rgb){
    return ((rgb >> 8) & 0xff);
}
inline constexpr int wBlue(WRgb rgb){
    return (rgb & 0xff);
}
inline constexpr int wAlpha(WRgb rgb){
    return rgb >> 24;;
}

// Создать WRgb из цветов
inline constexpr WRgb wRgb(int r, int g, int b){
    return (0xffu << 24) | ((r & 0xffu) << 16) | ((g & 0xffu) << 8) | (b & 0xffu);
}
inline constexpr WRgb wRgba(int r, int g, int b, int a){
    return ((a & 0xffu) << 24) | ((r & 0xffu) << 16) | ((g & 0xffu) << 8) | (b & 0xffu);
}

// конвертировать R,G,B в серый от 0 до 255
inline constexpr int wGray(int r, int g, int b){
    return ( r*11 + g*16 + b*5 ) / 32;
}
// конвертировать RGB в серый от 0 до 255
inline constexpr int wGray(WRgb rgb){
    return wGray(wRed(rgb), wGreen(rgb), wBlue(rgb));
}

#endif // WCOLOR_H
