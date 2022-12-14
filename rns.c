#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "node.h"
#define BUFF_SIZE 1024
#define ARR_SIZE 100

int main(int argc, char **argv)
{

    FILE *fp = NULL;
    FILE *sim = NULL;
    char buffer[BUFF_SIZE];
    Node nodeList[ARR_SIZE];
    Log simList[ARR_SIZE];
    Rep repList[ARR_SIZE];
    int opt;

    fp = fopen(argv[2], "r");
    sim = fopen(argv[4], "r");

    parseCMDLine(argc, *argv);

    while ((opt = getopt(argc, argv, "s:n:h")) != -1)
    {
        switch (opt)
        {
        case 'n':
            if (fp == NULL)
            {
                perror("Error opening file");
                exit(1);
            }
            else
            {
                buildNode(nodeList, buffer, fp);
                fclose(fp);
                free(nodeList->conList);
            }
            break;
        case 's':
            if (sim == NULL)
            {
                perror("Error opening file");
                exit(1);
            }
            else
            {
                build_sim(simList, repList, buffer, sim);
                fclose(sim);
            }
            break;
        case 'h':
            printHelp();
            return 0;
        case '?':
            fprintf(stderr, "Unrecognized option -%c\n", optopt);
            return 0;
        default:
            printHelp();
            return 0;
        }
    }
    return 0;
}
