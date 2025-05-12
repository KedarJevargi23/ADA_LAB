#include <stdio.h>

int n = 3;
int p[10] = {60, 100, 120}; // values
int w[10] = {10, 20, 30};   // weights
int W = 50;                 // bag capacity

int main() {
    int cur_w = W;
    float tot_v = 0.0;
    int i, maxi;
    int used[10];

    for (i = 0; i < n; ++i)
        used[i] = 0;

    while (cur_w > 0) {
        maxi = -1;
        for (i = 0; i < n; ++i)
            if (!used[i] &&
               (maxi == -1 || (float)p[i]/w[i] > (float)p[maxi]/w[maxi]))
                maxi = i;

        used[maxi] = 1;

        if (w[maxi] <= cur_w) {
            cur_w -= w[maxi];
            tot_v += p[maxi];
            printf("Added object %d (%d, %d) completely in  the bag. Space left: %d.\n",
                   maxi + 1, p[maxi], w[maxi], cur_w);
        } else {
            float fraction = (float)cur_w / w[maxi];
            tot_v += p[maxi] * fraction;
            printf("Added %d%% (%d, %d) of object %d in the bag.\n",
                   (int)(fraction * 100), p[maxi], w[maxi], maxi + 1);
            cur_w = 0;
        }
    }

    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    return 0;
}
