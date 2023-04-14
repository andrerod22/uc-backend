/* 
struct UC_TYPEDEF(point) {
    UC_PRIMITIVE(int) UC_VAR(x);
    UC_PRIMITIVE(int) UC_VAR(y);

    // Constructor for explicit initialization
    UC_TYPEDEF(point)(UC_PRIMITIVE(int) x, UC_PRIMITIVE(int) y)
    : UC_VAR(x)(x), UC_VAR(y)(y) {}

    // Constructor for default initialization
    UC_TYPEDEF(point)()
    : UC_VAR(x)(), UC_VAR(y)() {}

    // Equality comparison operator
    UC_PRIMITIVE(boolean) operator==(const UC_TYPEDEF(point) &rhs) const {
        return UC_VAR(x) == rhs.UC_VAR(x) && UC_VAR(y) == rhs.UC_VAR(y);
    }

    // Inequality comparison operator
    UC_PRIMITIVE(boolean) operator!=(const UC_TYPEDEF(point) &rhs) const {
        return !(*this == rhs);
    }
};*/

struct point{
    int x;
    int y;

    // Constructor for explicit initialization
    point(int x, int y)
    : x(x), y(y) {}

    // Constructor for default initialization
    point()
    : x(), y() {}

    // Equality comparison operator
    bool operator==(const point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    // Inequality comparison operator
    bool operator!=(const point &rhs) const {
        return !(*this == rhs);
    }
};