#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "BSC.h"

const float RAND_MAX_F = RAND_MAX;

float get_rand()
{
    return rand() / RAND_MAX_F;
};

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

void print_tchannel(TChannel* tchannel)
{
    fprintf(stdout, "----------------CHANNEL----------------\n");
    fprintf(stdout, "|                                     |\n");
    fprintf(stdout, "|Pg(1)                        %8f|\n", tchannel->Pg);
    fprintf(stdout, "|Pb(1)                        %8f|\n", tchannel->Pb);
    fprintf(stdout, "|P(b|b)                       %8f|\n", tchannel->Pbb);
    fprintf(stdout, "|P(g|g)                       %8f|\n", tchannel->Pgg);
    fprintf(stdout, "|n                            %8u|\n", tchannel->n);
    fprintf(stdout, "|t                            %8u|\n", tchannel->t);
    fprintf(stdout, "|                                     |\n");
};

bool get_BSC_status(TChannel* tchannel)// 0 - bad ; 1 - good
{
    unsigned probability_of_good_status = ((1 - tchannel->Pbb) / (2 - tchannel->Pgg - tchannel->Pbb));
    float rand_number = get_rand();

    if (rand_number > probability_of_good_status)
        return false;
    else
        return true;
};

bool get_BSC_result(TChannel* tchannel, bool tchannel_status)
{
    float rand_number = get_rand();

    if (tchannel_status) // good status
    {
        if (rand_number > tchannel->Pg)//probability_of_error_good_status
            return false;
        else
            return true;
    }
    else // bad status
    {
        if (rand_number > tchannel->Pb)//probability_of_error_bad_status
            return false;
        else
            return true;
    }
};

void simulation_BSC(TChannel* tchannel, unsigned count_of_generations)
{
    unsigned all_errors = 0;
    unsigned errors_per_block = 0;
    unsigned count_of_blocks_with_errors = 0;
    unsigned count_of_bad_blocks = 0;

    for (int i = 0; i < count_of_generations; i++)
    {
        for (int k = 0; k < tchannel->n; k++)
        {
            bool tchannel_status = get_BSC_status(tchannel);
            bool tchannel_result = get_BSC_result(tchannel, tchannel_status);

            if (tchannel_result)
            {
                all_errors++;
                errors_per_block++;
            }
        }
        if (errors_per_block > tchannel->t)
        {
            count_of_bad_blocks++;
            errors_per_block = 0;
        }
        if (errors_per_block <= tchannel->t && errors_per_block != 0)
            count_of_blocks_with_errors++;
    }
    fprintf(stdout, "----------------OUTPUT-----------------\n");
    fprintf(stdout, "|                                     |\n");
    fprintf(stdout, "|Count of generations         %8u|\n", tchannel->n*count_of_generations);
    fprintf(stdout, "|Count of errors              %8u|\n", all_errors);
    fprintf(stdout, "|Count of blocks              %8u|\n", count_of_generations);
    fprintf(stdout, "|Count of blocks with errors  %8u|\n", count_of_blocks_with_errors);
    fprintf(stdout, "|Count of bad blocks          %8u|\n", count_of_bad_blocks);
    fprintf(stdout, "|                                     |\n");
    fprintf(stdout, "-----------------END-------------------\n");
};