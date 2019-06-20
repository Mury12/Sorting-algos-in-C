#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define _HEIGHT_ 50
#define _BULLET_WEIGHT_ 1
#define _SHIELD_WEIGHT_ 200
#define _DISTANCE_ 1000
#define _GRAVITY_ 9.8

double getTime(int ang, int spd)
{
    //calcula o tempo pra chegar em 1000 metros
    return (_DISTANCE_/(spd*cos(ang)));
}

double distHit(int ang, int spd)
{
    double seno2t = sin(2*ang);
    double t = getTime(ang, spd);
    //calcula a distância maxima
    double r = (pow(spd, 2)*pow(seno2t, 2)) / _GRAVITY_;

    return r;
}

double heightHit(int ang, int spd)
{
    double seno = sin(ang);
    //calcula a altura máxima
    double r = (pow(spd, 2)*pow(seno, 2)) / (_GRAVITY_ * 2);

    return r;
}
int hit(int ang, int spd)
{
    double coseno = cos(ang);
    double y = heightHit(ang, spd);
    double x = distHit(ang, spd);

    if((y>=_HEIGHT_ && y<= _HEIGHT_ * 1.2) && (x >= _DISTANCE_ && x <= _DISTANCE_ * 1.2)){
        printf("Você acertou!\n");
    }else{
        printf("Você errou!\n");
    }
    printf("Distância do tiro: %lf metros\n", x);
    printf("Altura do tiro: %lf\n metros\n", y);
    return 0;
}

int shoot(int ang, int spd)
{
    return hit(ang, spd);
}


int main()
{
    shoot(35, 200);

    return 1;
}