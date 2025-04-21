#ifndef _NEW_H
#define _NEW_H

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @return A pointer to the allocated memory.
 * 
 * User is responsible for handling the returned pointer.
 */
#define unsafe_new_object(T) ({   \
    (T *) calloc(1, sizeof(T));   \
})

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @return A pointer to the allocated memory.
 */
#define new_object(T) ({                \
    T* __ptr = calloc(1, sizeof(T));    \
    if(!__ptr){ exit(EXIT_FAILURE); }   \
    __ptr;                              \
})

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @param ERR Error message.
 * @return A pointer to the allocated memory.
 */
#define new_object_(T, ERR) ({          \
    T* __ptr = calloc(1, sizeof(T));    \
    if(!__ptr) {                        \
        fprintf(stderr, "%s\n", ERR);   \
        exit(EXIT_FAILURE);             \
    }                                   \
    __ptr;                              \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements.
 * @return A pointer to the allocated memory.
 * 
 * User is responsible for handling the returned pointer.
 */
#define unsafe_new(T, N) ({        \
    (T *) calloc(N, sizeof(T));    \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements.
 * @return A pointer to the allocated memory.
 */
#define new(T, N) ({                    \
    T* __ptr = calloc(N, sizeof(T));    \
    if(!__ptr){ exit(EXIT_FAILURE); }   \
    __ptr;                              \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements.
 * @param ERR Error message.
 * @return A pointer to the allocated memory.
 */
#define new_(T, N, ERR) ({              \
    T* __ptr = calloc(N, sizeof(T));    \
    if(!__ptr) {                        \
        fprintf(stderr, "%s\n", ERR);   \
        exit(EXIT_FAILURE);             \
    }                                   \
    __ptr;                              \
})

/**
 * @brief Free a block allocated by `malloc', `realloc' or `calloc'.
 * @param PTR A pointer to a block of memory.
 * 
 * This function free the memory and set @a PTR to NULL.
 */
#define delete(PTR) ({    \
    free(PTR);            \
    PTR = NULL;           \
})

#endif