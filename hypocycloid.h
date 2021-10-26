#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#include <strstream>
#include <cstdio>

namespace hypocyc{
    struct Point{
        double x, y;
        explicit Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
        friend std::ostream& operator<< (std::ostream &out, const Point &p) {
            out << p.x << " " << p.y;
            return out;
        }
    };

    class hypocycloid{
    private:
        Point p;
        double R;
        double r;
        double dist;
    public:
        //конструктор
        explicit hypocycloid();
        explicit hypocycloid(Point start_p, double RAD = 18, double rad = 2, double d = 2);

        hypocycloid& set_R(double R0);
        hypocycloid& set_r(double r0);
        hypocycloid& set_dist(double d0);

        [[nodiscard]] double get_R() const{ return R; }
        [[nodiscard]] double get_r() const{ return r; }
        [[nodiscard]] double get_dist() const{ return dist; }

        [[nodiscard]] Point coordinates(double fi) const;                // 3) Вернуть координаты точки принадлежащей циклоиде в декартовой системе координат от угла поворота луча, соединяющего центр порождающего круга с центром направляющей окружности.
        [[nodiscard]] double radius_of_curvature(double fi) const; // 5) Вернуть радиус кривизны от угла поворота луча, соединяющего центр порождающего круга с центром направляющей окружности.
        [[nodiscard]] int type() const;                            // 6) Вернуть тип гипоциклоиды (обыкновенная, укороченная, удлиненная).
        [[nodiscard]] double sec_square(double fi) const;          // 7) Вернуть секториальную площадь гипоциклоиды относительно начального положения описываемой полярным радиусом.

    };
}

