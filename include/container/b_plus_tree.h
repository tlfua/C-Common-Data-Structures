

#ifndef _TREE_MAP_H_
#define _TREE_MAP_H_

#include "../util.h"

#ifdef __cplusplus
extern "C" {
#endif

/** BPlusTreeData is the data type for the container private information. */
typedef struct _BPlusTreeData BPlusTreeData;
    
typedef struct _BPlusTree {
    /** The container private information */
    BPlusTreeData *data;


} BPlusTree;


/*===========================================================================*
 *             Definition for the exported member operations                 *
 *===========================================================================*/
/**
 * @brief The constructor for BPlusTree.
 *
 * @retval obj          The successfully constructed B+ tree
 * @retval NULL         Insufficient memory for map construction
 */
BPlusTree* BPlusTreeInit();

/**
 * @brief The destructor for BPlusTree.
 *
 * @param obj           The pointer to the to be destructed B+ tree
 */
void BPlusTreeDeinit(BPlusTree* obj);

/**
 * @brief Insert a key value pair into the map.
 *
 * This function inserts a key value pair into the B+ tree. 
 * Also, the cleanup functions are invoked for that replaced pair.
 *
 * @param self          The pointer to TreeMap structure
 * @param key           The designated key
 * @param value         The designated value
 *
 * @retval true         The pair is successfully inserted
 * @retval false        The pair cannot be inserted due to insufficient memory
 */
bool BPlusTreePut(BPlusTree* self, void* key, void* value);

/**
 * @brief Retrieve the value corresponding to the designated key.
 *
 * @param self          The pointer to BPlusTree structure
 * @param key           The designated key
 *
 * @retval value        The corresponding value
 * @retval NULL         The key cannot be found
 */
void* BPlusTreeEqualitySearch(BPlusTree* self, void* key);

/**
 * @brief Check if the B+ tree contains the designated key.
 *
 * @param self          The pointer to BPlusTree structure
 * @param key           The designated key
 *
 * @retval true         The key can be found
 * @retval false        The key cannot be found
 */
void BPlusTreeFind(BPlusTree* self, void* key);

/**
 * @brief Retrieve the values corresponding to the interval [key_1, key_2]
 * 
 * @param self          The pointer to BPlusTree structure
 * @param key_1         The lower bound of key to search
 * @param key_2         The upper bound of key to search
 * 
 * @retval values       The corresponding values
 * @retval NULL         The keys can not be found
*/
void BPlusTreeRangeSearch(BPlusTree* self, void* key_1, void* key_2);

/**
 * @brief Retrieve the values corresponding to the upper bound key
 * 
 * @param self          The pointer to BPlusTree structure
 * @param key           The upper bound key to search
 * 
 * @retval values       The corresponding values
 * @retval NULL         The keys can not be found
*/
void BPlusTreeRangeSearchLessThan(BPlusTree* self, void* key);

/**
 * @brief Retrieve the values corresponding to the lower bound key
 * 
 * @param self          The pointer to BPlusTree structure
 * @param key           The lower bound key to search
 * 
 * @retval values       The corresponding values
 * @retval NULL         The keys can not be found
*/
void BPlusTreeRangeSearchGreaterThan(BPlusTree* self, void* key);

/**
 * @brief Remove the key value pair corresponding to the designated key.
 *
 * This function removes the key value pair corresponding to the designated key.
 * Also, the cleanup functions are invoked for that removed pair.
 *
 * @param self          The pointer to BPlusTree structure
 * @param key           The designated key
 *
 * @retval true         The pair is successfully removed
 * @retval false        The key cannot be found
 */
void BPlusTreeRemove(BPlusTree* self, void* key);

/**
 * @brief Return the number of stored key value pairs.
 *
 * @param self          The pointer to BPlusTree structure
 *
 * @retval size         The number of stored pairs
 */
unsigned BPlusTreeSize(BPlusTree* self);

#ifdef __cplusplus
}
#endif

#endif