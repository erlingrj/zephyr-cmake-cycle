#include <zephyr/kernel.h>

typedef struct {
    struct k_mutex * mutex;
    struct k_condvar condition;
} cond_var_t;

int cond_init(cond_var_t* cond, lf_mutex_t* mutex) {
    cond->mutex = mutex;
    return k_condvar_init(&cond->condition);
}

int cond_broadcast(cond_var_t* cond) {
    k_condvar_broadcast(&cond->condition);
    return 0;
}

int cond_signal(cond_var_t* cond) {
    return k_condvar_signal(&cond->condition);
}

int cond_wait(cond_var_t* cond) {
    return k_condvar_wait(&cond->condition, cond->mutex, K_FOREVER);
}

int test() {
  return 1;
}