#include "BSC.h"
#include <stdlib.h>

TChannel* init_tchannel()
{
    TChannel* c = NULL;
    c = (TChannel*)malloc(sizeof(TChannel));

    if (c != NULL)
    {
        c->Pg = 0;
        c->Pb = 0;
        c->Pbb = 0;
        c->Pgg = 0;
        c->n = 0;
        c->t = 0;
    }
    else
    {
        free(c);
        c = NULL;
    }
    return c;
};
void set_tchannel_pg(TChannel* tchannel, float pg)
{
    tchannel->Pg = pg;
};

void set_tchannel_pb(TChannel* tchannel, float pb)
{
    tchannel->Pb = pb;
};
void set_tchannel_pbb(TChannel* tchannel, float pbb)
{
    tchannel->Pbb = pbb;
};

void set_tchannel_pgg(TChannel* tchannel, float pgg)
{
    tchannel->Pgg = pgg;
};

void set_tchannel_n(TChannel* tchannel, unsigned n)
{
    tchannel->n = n;
};

void set_tchannel_t(TChannel* tchannel, unsigned t)
{
    tchannel->t = t;
};
