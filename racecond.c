#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10000
pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int * summa = 0;
void * saikeen_koodi(void *v) {
for (int i = 1; i <= N; i++){
summa++;
}
return NULL;
}
int main(int argc, char *argv[]) {
pthread_t saieA, saieB;
pthread_create(&saieA, NULL, saikeen_koodi, NULL);
pthread_create(&saieB, NULL, saikeen_koodi, NULL);
pthread_join(saieA, NULL);
pthread_join(saieB, NULL);
if (summa==20000){
printf("pteradactil");
return 0; // homma toimi
} else {
printf("%d", &summa) ;
return 1; // homma ei toiminut
}
}
