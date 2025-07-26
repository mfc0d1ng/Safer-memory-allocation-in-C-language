/**
 * A set of macro functions for safer memory allocation C.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * 
 * @file new.h
 * 
 * Written by Mohamed fareed
 **/

#ifndef NEW_H
#define NEW_H

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @return A pointer to the allocated memory.
 * 
 * User is responsible for handling the returned pointer.
 */
#define unsafe_new(T) ({  \
    calloc(1, sizeof(T)); \
})

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @return A pointer to the allocated memory.
 */
#define new(T) ({                       \
    void* __ptr = calloc(1, sizeof(T)); \
    if(!__ptr){ exit(EXIT_FAILURE); }   \
    __ptr;                              \
})

/**
 * @brief Allocates memory for an object of type T.
 * @param T Data type.
 * @param ERR Error message.
 * @return A pointer to the allocated memory.
 */
#define _new(T, ERR) ({                 \
    void* __ptr = calloc(1, sizeof(T)); \
    if(!__ptr) {                        \
        fprintf(stderr, "%s\n", ERR);   \
        exit(EXIT_FAILURE);             \
    }                                   \
    __ptr;                              \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements required.
 * @return A pointer to the allocated memory.
 * 
 * User is responsible for handling the returned pointer.
 */
#define unsafe_new_block(T, N) ({ \
     calloc(N, sizeof(T));        \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements required.
 * @return A pointer to the allocated memory.
 */
#define new_block(T, N) ({              \
    void* __ptr = calloc(N, sizeof(T)); \
    if(!__ptr){ exit(EXIT_FAILURE); }   \
    __ptr;                              \
})

/**
 * @brief Allocates a block of memory for N elements of type T.
 * @param T Data type.
 * @param N Number of elements required.
 * @param ERR Error message.
 * @return A pointer to the allocated memory.
 */
#define _new_block(T, N, ERR) ({        \
    void* __ptr = calloc(N, sizeof(T)); \
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
#define delete(PTR) ({ \
    free(PTR);         \
    PTR = NULL;        \
})

#endif
