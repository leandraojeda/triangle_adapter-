#include <iostream>
#include <cmath>
using namespace std;

class TrianglePeg;  // Declaración adelantada de la clase TrianglePeg

class TriangleHole {
private:
    int base;
    int height;

public:
    TriangleHole(int base, int height) : base(base), height(height) {}

    int getBase() const {
        return base;
    }

    int getHeight() const {
        return height;
    }

    bool fits(const TrianglePeg& peg) const;
};

class SquarePeg {
private:
    int width;

public:
    SquarePeg(int width) : width(width) {}

    int getWidth() const {
        return width;
    }
};

class TrianglePeg {
private:
    int base;
    int height;

public:
    TrianglePeg(int base, int height) : base(base), height(height) {}

    virtual int getBase() const {
        return base;
    }

    virtual int getHeight() const {
        return height;
    }
};

bool TriangleHole::fits(const TrianglePeg& peg) const {
    return (getBase() >= peg.getBase()) && (getHeight() >= peg.getHeight());
}

class SquarePegAdapter : public TrianglePeg {
private:
    class SquarePeg* peg;

public:
    SquarePegAdapter(class SquarePeg* peg) : peg(peg), TrianglePeg(peg->getWidth(), peg->getWidth()) {}

    int getBase() const override {
        // Simula una pieza triangular con la misma base que la pieza cuadrada.
        return TrianglePeg::getBase();
    }

    int getHeight() const override {
        // Simula una pieza triangular con la altura igual a la base de la pieza cuadrada.
        return TrianglePeg::getHeight();
    }
};

int main() {
    TriangleHole hole(10, 10);

    TrianglePeg tpeg(10, 10);
    cout << hole.fits(tpeg) << endl; // T

    SquarePeg small_sqpeg(10);
    SquarePeg large_sqpeg(5);

    SquarePegAdapter small_sqpeg_adapter(&small_sqpeg);
    SquarePegAdapter large_sqpeg_adapter(&large_sqpeg);
    cout << hole.fits(small_sqpeg_adapter) << endl; // True
    cout << hole.fits(large_sqpeg_adapter) << endl; // False

    return 0;
}
