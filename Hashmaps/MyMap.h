#include <string>
using namespace std;

/* For simlicity, We have fixed key to string only
 * value can be template
 */
template <typename V> // We have fixed key to string only, value can be template
class MapNode {
public:
	string key;
	V value;
	MapNode *next;
	
	MapNode(string key, V value) {
		this -> key = key;
		this -> value = value;
		next = NULL;
	}

	~MapNode() {
		/*This will call next links recursively and delete them before
 deleting the node itself
		*/
		delete next;
	}
};

template <typename V>
class MyMap {
	// Head for each LL will be MapNode<V> *, we need array to store them
	MapNode<V> ** buckets;
	int count;
	int numBuckets;

	void rehash() {
		MapNode<V> ** temp = buckets;
		buckets = new MapNode<V> *[numBuckets*2];

		// Initialize properly with null
		for(int i = 0; i < 2*numBuckets; i++) {
			buckets[i] = NULL;
		}
		
		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0; // Reset count

		for(int i = 0; i < oldBucketCount; i++) {
			MapNode<V> *head = temp[i];
			while(head != NULL) {
				string key = head -> key;
				V value = head -> value;
				insert(key, value); // This is inserting into new buckets **array, with updated numBuckets for compression
				
				// Move head
				head = head -> next;
			}
		}

		// Delete the old bucket array
		for(int i = 0; i < oldBucketCount; i++) {
			MapNode<V> *head = temp[i];
			delete head; // Our LL destructor is recursive, chains will be deleted by just calling at head
		}
	}

public:
	MyMap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V> *[numBuckets];
		// Initialize bucket addresses, otherwise garbage will be there
		for(int i=0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

	// Destructor
	~MyMap() {
		// First delete stored LL in each bukcet
		for(int i=0; i < numBuckets; i++) {
            delete buckets[i]; // This will call MapNode destructor
        }
		// Delete buckeets array
		delete [] buckets;
	}

	int size() {
		return count;
	}	

	// getValue
	V getValue(string key) {
		int bucketIndex = getBucketIndex(key); // Calculate hash Fn to decide function
        // Check if key already has entry
        MapNode<V> *head = buckets[bucketIndex];
		
	    MapNode<V> *temp = head;
        // traverse
        while(temp != NULL) {
			if(temp -> key == key) {
				return temp -> value;
			}
			temp = temp -> next;
		}
		// Return 0 if not found
		return 0; 
	}

	private:
	/* getBucketIndex has two main componets
	 * 1. hasCode
	 *  2. Compression
	 */
	int getBucketIndex(string key) {
		/* Logic:
		 * key -> base p
		 * "abc" -> a*p^2 + b*p^1 + c
		 */
		int hashCode = 0;	
		
		int currentCoeff = 1;
		for(int i = key.length() - 1;i >= 0;i--) {
			hashCode += key[i] * currentCoeff;
			// NOTE: (p * p * p) %r is same as (p%r) * (p%r) *(p%r)
			// We can use this property to keep no.s in check and avoiding OutOf Range issue
			// To avoid hashCode from going OutOfRange of int
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37; // Lets use prime no. 37, p = 37

			// To avoid currentCoeff from going OutOfRange of int
			currentCoeff = currentCoeff % numBuckets;
		}

		// Compression
		return hashCode % numBuckets;
	}

	public:
	double getLoadFactor() {
		return (1.0*count)/numBuckets;
	}

	// Insert
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(key); // Calculate hash Fn to decide function
		// Check if key already has entry
		MapNode<V> *head = buckets[bucketIndex];
		
		MapNode<V> *temp = head;
		// traverse and update if found
		while(temp != NULL) {
			if(temp -> key == key) {
				temp -> value = value;
				return;
			}
			temp = temp -> next;
		}
	
		// If not found, create new node and assign value
		MapNode<V> *new_node = new MapNode<V>(key, value);

		// Update head address of LL in bucket
		new_node -> next = head;
		buckets[bucketIndex] = new_node;	
		
		// Update total no. of entries in map
		count++;

		// Load factor
		// Multiplied by 1.0 to convert to float, otherwise int/int will result in int, precision loss
		double loadFactor = (1.0*count)/numBuckets;
		if(loadFactor > 0.7) {
				rehash();
		}
	}

	// Delete, like pop delete and return value
	V remove(string key) {
		int bucketIndex = getBucketIndex(key);
		MapNode<V> *head = buckets[bucketIndex];

	    MapNode<V> *temp = head;
		MapNode<V> *prev = NULL;

		while(temp != NULL) {
			if(temp -> key == key) {
				if(prev == NULL) { // That means we need to remove head itself
					buckets[bucketIndex] = temp -> next; // temp is head, prev is NULL
				} else {
					prev -> next = temp -> next;
				}
				V value = temp -> value;
				temp -> next = NULL;
				delete temp;
				// Update count
				count--;
				return value;
			}
			prev = temp;
			temp = temp -> next;
		}
		/* If Not found return 0, 
		 *as return type V is template, so it will adjust to NULL 
		 *or other significant value based on actual return type
		*/
		return 0;
		/*First make temp -> next = NULL, 
		 *otherwise delete will call destructor,which we have written to call on next recursively, whole list will be deleted
		 */
		temp -> next;
	}
	
};
