#ifndef _DATO_INCLUDED
#define _DATO_INCLUDED

#define MAXC 35

typedef struct item* Item;
typedef char *Key;

Item ITEMscan(void);
int ITEMgetValue(Item item);
Item ITEMcreate(char* name,int value);
void ITEMshow(Item data);
int ITEMcheckvoid(Item data);
Item ITEMsetvoid(void);
int ITEMless(Item data1, Item data2);
Key KEYscan(void);
int KEYcompare(Key k1, Key k2);
Key KEYget(Item data);
#endif
