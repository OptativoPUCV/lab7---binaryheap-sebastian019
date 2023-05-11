#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq -> size == 0){
    return NULL;
  }
  return pq -> heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq -> capac == pq -> size){
    pq -> capac = pq -> capac *2 + 1;
    pq -> heapArray = realloc(pq -> heapArray, pq -> capac *sizeof(heapElem));
  }
  
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  int i = pq -> size;
  
  while (i > 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority) { 
    heapElem aux = pq -> heapArray[(i-1)/2];
    pq->heapArray[(i-1)/2] = pq->heapArray[i];
    pq-> heapArray[i] = aux;
    i = (i-1)/2;
  }
  pq -> size++;
}


void heap_pop(Heap* pq){
  pq -> heapArray[0] = pq -> heapArray[pq->size-1];
  pq -> size--; 
  int i = 0;
  
  while(2*i+1 < pq -> size){
    int hijo = 2*i+1;
    int hijo2 = 2*i+2, pos = hijo;
  
    if(hijo2 < pq -> size && pq->heapArray[hijo2].priority > pq->heapArray[hijo].priority){
      pos = hijo2;
    }
    if(pq->heapArray[i].priority > pq->heapArray[pos].priority){
      heapElem aux = pq -> heapArray[i];
      pq->heapArray[i] = pq->heapArray[pos];
      pq-> heapArray[pos] = aux;
      i = pos;
    }
    else{
      break;
    }
  }
}

Heap* createHeap(){
  Heap *pqt = (Heap*)malloc(sizeof(Heap));
  pqt -> heapArray = (heapElem*)malloc(3 *sizeof(heapElem));
  pqt -> size = 0;
  pqt -> capac = 3;
  return pqt;
}
