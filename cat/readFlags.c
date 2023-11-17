#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

#include "headers.h"

Flags readFlags(int argc, char* argv[]) {
    struct option longOptions[] = {
        {"number-nonblank", 0, NULL, 'b'},
        {"number", 0, NULL, 'n'},
        {"squeeze-blank", 0, NULL, 's'},
        {NULL, 0, NULL, 0}
    };

    int curFlag = getopt_long(argc, argv, "bnseEtTv", longOptions, NULL);

    Flags flags = {false,false,false,false,false,false};

    for(;curFlag != -1; curFlag = getopt_long(argc, argv, "bnseEtTv", longOptions, NULL)) {
        switch (curFlag) {
            case 'b':
                flags.numberNonBlank = true;
                break;
            case 'n':
                flags.numberAll = true;
                break;
            case 's':
                flags.squeezeStr = true;
                break;
            case 'e':
                flags.markEndStr = true;
                flags.printNonPrintable = true;
                break;
            case 'E':
                flags.markEndStr = true;
                flags.printNonPrintable = true;
                break;
            case 'v':
                flags.printNonPrintable = true;
                break;
            case 't':
                flags.tabStr = true;
                flags.printNonPrintable = true;
                break;
            case 'T':
                flags.tabStr = true;
                flags.printNonPrintable = true;
                break;
        }
    }
    return flags;
}