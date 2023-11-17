#ifndef HEADERS_H
#define HEADERS_H

typedef struct {
    bool numberNonBlank;
    bool markEndStr;
    bool numberAll;
    bool squeezeStr;
    bool tabStr;
    bool printNonPrintable;
}Flags;

void catSetTable(const char* table[static 256]);
void catSetEndl(const char* table[static 256]);
void catSetTab(const char *table[static 256]);
void catSetNonPrintable (const char *table[static 256]);

Flags readFlags(int argc, char* argv[]);
void catRead(FILE *file, Flags flags, const char *table[static 256]);
void catOpen(int argc, char* argv[], Flags flags, const char* table[static 256]);


#endif