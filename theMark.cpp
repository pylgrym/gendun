#include "stdafx.h"
#include "theMark.h"


theMark::theMark()
{
}


theMark::~theMark()
{
}


int rnd(int n) { return rand() % n; }

int rnd(int n1, int n2) { 
  if (n1 == n2) { return n1; }

  return n1 + rand() % (n2 - n1); 
}

