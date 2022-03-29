//6 сортировка BBall'ов 
//теперь и getW() сделал константынм для isGreater(...)
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

    int getW() const
    {
        return w;
    }

    string getColor() const
    {
        return color;
    }

    ~BBall()
    {
        n--;
        //cout << "Deleted ball " << this->color << endl;
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
    bool operator<(const BBall& ball);
    bool operator==(const BBall& ball);
    //вот он
    BBall& operator=(const BBall& ball);
    //
};
int BBall::n = 0;

static bool isGreater(const BBall& b1, const BBall& b2);
void BowlingSort(BBall* arr, int n);

int main()
{

    int n, w;
    string color;
    cin >> n;
    BBall* arr =new BBall[n];
    for (int i = 0; i < n; i++) {
        cin >> w >> color;
        arr[i] = BBall(w, color);
    }
    cout << "\tYour BBalls before sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].getW() << ' ' << arr[i].getColor() << endl;
    }
    BowlingSort(arr, n);
    cout << "\tYour BBalls after sort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].getW() << ' ' << arr[i].getColor() << endl;
    }
    delete[] arr;
    return 0;
}

bool BBall::operator<(const BBall& ball)
{
    return this->w < ball.w;
}

bool BBall::operator==(const BBall& ball)
{
    return (this->w == ball.w) && (this->color == ball.color);
}

BBall& BBall::operator=(const BBall& ball)
{
    this->color = ball.color;
    this->w = ball.w;
    return *this;
}



bool isGreater(const BBall& b1, const BBall& b2)
{
    return b1.getW()>b2.getW() || (b1.getW() == b2.getW() && b1.getColor()<b2.getColor());
}

void BowlingSort(BBall* arr, int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && isGreater(arr[j], arr[j - 1]); j--)
            swap(arr[j - 1], arr[j]);
}
