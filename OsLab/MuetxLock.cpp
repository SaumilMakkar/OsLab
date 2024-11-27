//Create a program that simulates a simple bank with multiple accounts and multiple
//clients making deposits (thread1) and withdrawals (thread2) concurrently. The goal is
//to ensure that account balances remain consistent even with concurrent operations. Use
//mutex locks to implement this.//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_Client 5
int account = 500;
pthread_mutex_t lock;
// Thread function to calculate the sum of data
void* Deposit(void* arg) {
int* client_id = (int*)arg;
int amount;
int x;
pthread_mutex_lock(&lock);
printf("\n Enter amount to deposit");
scanf("%d",&amount);
x=account;
x = x + amount;
sleep(3);
account=x;
pthread_mutex_unlock(&lock);
printf("Client %d deposited: %d, Amount after deposit is %d\n", *client_id, amount,
account);

pthread_exit(NULL);
}

void* Withdraw(void* arg) {
int* client_id = (int*)arg;

int amount,x;
pthread_mutex_lock(&lock);
printf("\n Enter amount to withdraw");
scanf("%d",&amount);
x=account;
x = x - amount;
account=x;
pthread_mutex_unlock(&lock);
printf("Client %d withdraw: %d, Amount after withdrawl is %d\n", *client_id, amount,
account);
pthread_exit(NULL);
}

int main() {
pthread_t threads[NUM_Client];
pthread_mutex_init(&lock, NULL);
int client_ids[NUM_Client], i;
// Initialize the data with random values
//data[6] = {45, 56, 78, 32, 9, 5};
for (i = 0; i < NUM_Client; i++) {
client_ids[i] = i;
}
// Create threads to perform different tasks
for(i=0;i<NUM_Client;i++){
if(i%2==0)
pthread_create(&threads[0], NULL, Deposit, &client_ids[i]);
else{
pthread_create(&threads[1], NULL, Withdraw, &client_ids[1]);
}

}
// Main thread waits for these threads to finish
for ( i = 0; i < 3; i++) {
pthread_join(threads[i], NULL);

}

return 0;
}
