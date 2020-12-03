#ifndef COIN_H
#define COIN_H

class Coin
{
    private:
        int sideUp;
    public:
        Coin();
        void toss(int);
        int getSideUp() const;
};

#endif // COIN_H