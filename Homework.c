#include <stdio.h>

int convert(int y) {
    if (y < 2) 
        return y;
    else
        return convert(y / 2) * 10 + y % 2;
}

int degree(int a, int b) { // a - число, b - степень
    int res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

int rec_degree(int a, int b){ // a - число, b - степень
    return b == 1 ? a : a * rec_degree(a , b - 1);
}

int rec_degree_par(int a, int b) {
    if (b == 0)
    return 1;
    int c = rec_degree_par(a, b / 2);
    if (b % 2 == 0)
    return c * c;
    else
    return a * c * c;
}

int routers_counter(int x, int y) {
    int counts = 0;
    if (x == 0 && y == 0)
        return 0;
    if (x == 0 ^ y == 0)
        return 1;
    else
        return routers_counter(x, y - 1) + routers_counter(x - 1, y);

}
int main(const int argc, const char** argv) {

printf("%d", convert(10));
printf("\n");
printf("%d", degree(3, 2));
printf("\n");
printf("%d", rec_degree(3, 3));
printf("\n");
printf("%d", rec_degree_par(4, 4));
printf("\n");
const int sizeX = 4;
const int sizeY = 4;
for (int y = 0; y < sizeY; ++y) {
    for (int x = 0; x < sizeX; ++x) {
        printf("%5d", routers_counter(x, y));
    }
    printf("\n");
}
printf("%d", routers_counter(sizeX, sizeY));
    return 0;
}