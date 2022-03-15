#include <iostream>

using namespace std;

class BBall
{
    int w;
    string color;
public:

    static int n;

    BBall()  // = default
    {
        w = 1;
        color = "white";
        n++;
    }

    //BBall(int w, string color) : w(w), color(color) {}
    BBall(int w, string color)
    {
        setW(w);
        setColor(color);
    }

    // BBall(const BBall & other) = delete;
    BBall(const BBall& other)
    {
        w = other.w;
        color = other.color;
        n++;
    }


    bool setW(int w)
    {
        if (w > 0)
        {
            this->w = w;  // (*this).w = w;
            return true;
        }
        return false;
    }

    bool setColor(string color)
    {
        if (color != "")
        {
            this->color = color;
            return true;
        }
        return false;
    }

    int getW()
    {
        return w;
    }

    string getColor()
    {
        return color;
    }

    ~BBall()
    {
        n--;
        cout << "Deleted ball " << this->color << endl;
    }


    BBall& operator++()
    {
        w++;
        return *this;
    }

    BBall operator++(int)
    {
        BBall tmp = *this;
        w++;
        return tmp;
    }

    friend BBall operator+(BBall& ball, int x)
    {
        return BBall(ball.w + x, ball.color);
    }
    friend BBall operator+(int x, BBall& ball)
    {
        return ball + x;
    }
    //вот они
    bool operator<(const BBall& ball);
    bool operator==(const BBall& ball);
    //
};
int BBall::n = 0;


int main()
{

    BBall ball1(5, "yellow");
    BBall ball2(5, "yellow");
    cout << (ball1 == ball2)<<endl;

    return 0;
}

bool BBall::operator<(const BBall& ball)
{
    return this->w<ball.w;
}

bool BBall::operator==(const BBall& ball)
{
    return (this->w==ball.w)&&(this->color==ball.color);
}
