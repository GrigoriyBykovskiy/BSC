#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSC.h"

int main(int argc, char** argv)
{
    if (argc == 7)
    {
        srand(time(0));
        TChannel* channel = init_tchannel();
        float tmp_pg = atof(argv[1]);
        set_tchannel_pg(channel, tmp_pg);
        float tmp_pb = atof(argv[2]);
        set_tchannel_pb(channel, tmp_pb);
        float tmp_pbb = atof(argv[3]);
        set_tchannel_pbb(channel, tmp_pbb);
        float tmp_pgg = atof(argv[4]);
        set_tchannel_pgg(channel, tmp_pgg);
        unsigned tmp_n = atoi(argv[5]);
        set_tchannel_n(channel, tmp_n);
        unsigned tmp_t = atoi(argv[6]);
        set_tchannel_t(channel, tmp_t);
        print_tchannel(channel);
        fprintf(stdout, "RAND MAX IS %d\n", RAND_MAX);
        simulation_BSC(channel, 100000);
    }
    else
        fprintf(stderr, "ANTA BAKA?! Only 6 parameters are requirted!\n");

    return 0;
}
