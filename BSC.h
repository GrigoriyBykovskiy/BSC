#include <stdbool.h>
#ifndef BSC_BSC_H
#define BSC_BSC_H

typedef struct{
    float Pg;
    float Pb;
    float Pbb;
    float Pgg;
    unsigned n; // length of the block
    unsigned t; // number of correctable errors in the block
}TChannel;

TChannel* init_tchannel();
void set_tchannel_pg(TChannel* tchannel, float pg);
void set_tchannel_pb(TChannel* tchannel, float pb);
void set_tchannel_pbb(TChannel* tchannel, float pbb);
void set_tchannel_pgg(TChannel* tchannel, float pgg);
void set_tchannel_n(TChannel* tchannel, unsigned n);
void set_tchannel_t(TChannel* tchannel, unsigned t);
void print_tchannel(TChannel* tchannel);
bool get_BSC_status(TChannel* tchannel);
bool get_BSC_result(TChannel* tchannel, bool tchannel_status);
void simulation_BSC(TChannel* tchannel, unsigned count_of_generations);

#endif //BSC_BSC_H