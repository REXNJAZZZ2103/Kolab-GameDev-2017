#ifndef listvillage_H
#define listvillage_H

#include "boolean.h"
#include "village.h"
#include "mesinkata.h"

#define Nil NULL


typedef struct tElmtlistV *addressV;
typedef struct tElmtlistV { 
	Village infoV;
	addressV nextV;
} ElmtListV;
typedef struct {
	addressV FirstV;
} ListV;

#endif