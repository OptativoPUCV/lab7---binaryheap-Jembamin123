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
  return pq->heapArray[0].data;
}

int parent(int i){
  return (i-1)/2;
}

void swap(heapElem* x, heapElem* y){
  heapElem aux=*x;
  *x=*y;
  *y=aux;
}

void heap_push(Heap* pq, void* data, int priority){
  heapElem newElem;
  newElem.data = data;
  newElem.priority = priority;
  if(pq->size != pq->capac){
    pq->capac = (pq->capac*2)+1;
    pq->heapArray = realloc(pq->heapArray, pq->capac*sizeof(heapElem));
  }
  int i=pq->size;
  pq->heapArray[i]=newElem;
  pq->size++;

  while(i!=0&&pq->heapArray[parent(i)].priority < pq->heapArray[i].priority){
    swap(&(pq->heapArray[i]), &(pq->heapArray[parent(i)]));
    i=parent(i);
  }
}



void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* NewHeap= (Heap*)malloc(sizeof(Heap));
  NewHeap->size=0;
  NewHeap->capac=3;
  NewHeap->heapArray=(heapElem*)malloc(NewHeap->capac*sizeof(heapElem));
  return NewHeap;
}
