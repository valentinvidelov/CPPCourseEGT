#ifndef BOX_H
#define BOX_H

class Box{
public:
    Box(int, int, int);
    void setLength(int);
    void setWidth(int);
    void setHeight(int);
    int getLength();
    int getWidth();
    int getHeight();
private:
    int length;
    int width;
    int height;
};

#endif // BOX_H