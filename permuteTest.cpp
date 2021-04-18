#include <cstdio>
#include "PermuteGen.hpp"

double factorial(double n) {
    if (n == 0.0 || n == 1.0)
        return 1.0;
    else return n*factorial(n - 1);
}

int main() {

    PermuteGen permgen(3);

    do {
        permgen.next();
        for (int i = 0; i < permgen.size(); i++)
            printf("%d ", permgen[i]);
        printf("\n");
    } while (permgen.hasNext());

    // Let's compute some derangement statistics
    int dsize = 12;
    PermuteGen deranged(dsize);
    long long numNotDeranged = 0;
    do {
        deranged.next();
        for (int i = 0; i < deranged.size(); i++) {
            if (deranged[i] == i) {
                numNotDeranged += 1;
                break;
            }
        }
    } while (deranged.hasNext());

    double probDeranged = 1.0 - numNotDeranged/factorial(deranged.size());
    printf("prob not deranged = %.16lf = 1/%.16lf\n", probDeranged, 1.0/probDeranged);

    printf("That's all folks!\n");
    return 0;
}