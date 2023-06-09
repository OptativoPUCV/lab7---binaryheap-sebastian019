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
  heapElem aux;
  pq -> heapArray[0] = pq -> heapArray[pq->size-1];;
  pq -> size--; 
  
  if(pq -> size == 1){
    pq -> capac = 0;
    return;
  }
  
  for(int i = 0 ; i < pq -> capac ; i++){
    int hijo = 2i+1;
    int hijo2 = 2i+2;
    if(pq->heapArray[hijo].priority > pq->heapArray[hijo2].priority){
      aux = pq -> heapArray[(i-1)/2];
      pq->heapArray[(i-1)/2] = pq->heapArray[hijo];
      pq-> heapArray[hijo] = aux;
    }
    else{
      aux = pq -> heapArray[(i-1)/2];
      pq->heapArray[(i-1)/2] = pq->heapArray[hijo2];
      pq-> heapArray[hijo2] = aux;
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
