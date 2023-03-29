#ifndef __MYHASHTABLE_H__
#define __MYHASHTABLE_H__

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

#include "MyVector_t984h395.h"
#include "MyLinkedList_t984h395.h"

static const long long uh_param_a = 53;                          // universal hash function parameter a
static const long long uh_param_b = 97;                          // universal hash function parameter b
static const long long prime_digits = 19;                        // parameter used for finding a Mersenne prime
static const long long mersenne_prime = (1 << prime_digits) - 1; // the Mersenne prime for universal hashing

// fast calculation of (n modulo mersenne_prime)
long long fastMersenneModulo(const long long n)
{
    // code begins
    long long result = (n & mersenne_prime) + (n >> prime_digits);
    result = (result >= mersenne_prime) ? (result - mersenne_prime) : result;
    return result;
    // code ends
}

// definition of the template hash function class
template <typename KeyType>
class HashFunc
{
public:
    long long univHash(const KeyType key, const long long table_size) const;
};

// the hash function class that supports the hashing of the "long long" data type
template <>
class HashFunc<long long>
{
public:
    long long univHash(const long long key, const long long table_size) const
    {
        long long hv = fastMersenneModulo(static_cast<long long>(uh_param_a * key + uh_param_b));
        hv = hv % table_size;
        return hv;
    }
};

// the has function class that supports the hashing of the "std::string" data type
template <>
class HashFunc<std::string>
{
private:
    const int param_base = 37; // the base used for inflating each character
public:
    long long univHash(const std::string &key, const long long table_size) const
    {
        long long hv = 0;
        for (size_t i = 0; i < key.length(); ++i)
        {
            hv = param_base * hv + static_cast<long long>(key[i]);
        }
        hv = fastMersenneModulo(static_cast<long long>(uh_param_a * hv + uh_param_b));
        hv = hv % table_size;
        return hv;
    }
};

// definition of the template hashed object class
template <typename KeyType, typename ValueType>
class HashedObj
{
public:
    KeyType key;
    ValueType value;

    HashedObj()
    {
        return;
    }

    HashedObj(const KeyType &k, const ValueType &v) : key(k),
                                                      value(v)
    {
        return;
    }

    HashedObj(KeyType &&k, ValueType &&v) : key(std::move(k)),
                                            value(std::move(v))
    {
        return;
    }

    bool operator==(const HashedObj<KeyType, ValueType> &rhs)
    {
        return (key == rhs.key);
    }

    bool operator!=(const HashedObj<KeyType, ValueType> &rhs)
    {
        return !(*this == rhs);
    }
};

template <typename KeyType, typename ValueType>
class MyHashTable
{
private:
    size_t theSize;                                                     // the number of data elements stored in the hash table
    MyVector<MyLinkedList<HashedObj<KeyType, ValueType>> *> hash_table; // the hash table implementing the separate chaining approach
    MyVector<size_t> primes;                                            // a set of precomputed and sorted prime numbers

    // pre-calculate a set of primes using the sieve of Eratosthenes algorithm
    // will be called if table doubling requires a larger prime number for table size
    // expected to update the private member "primes"
    void preCalPrimes(const size_t n)
    {
        // code begins
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (size_t i = 2; i * i <= n; ++i)
        {
            if (is_prime[i])
            {
                for (size_t j = i * i; j <= n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        // Store the prime numbers into the "primes" vector
        primes.resize(0); // Reset the size of the "primes" vector
        for (size_t i = 2; i <= n; ++i)
        {
            if (is_prime[i])
            {
                primes.push_back(i);
            }
        }
        // code ends
    }

    // finding the smallest prime that is larger than or equal to n
    // should perform binary search against the private member "primes"
    size_t nextPrime(const size_t n)
    {
        // code begins
        size_t left = 0;
        size_t right = primes.size();
        while (left < right)
        {
            size_t mid = left + (right - left) / 2;
            if (primes[mid] < n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        // If left is out of bounds, generate more primes
        if (left >= primes.size())
        {
            preCalPrimes(2 * n); // Generate primes up to 2n
            // Repeat binary search
            left = 0;
            right = primes.size();
            while (left < right)
            {
                size_t mid = left + (right - left) / 2;
                if (primes[mid] < n)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        return primes[left];
        // code ends
    }

    // finds the MyLinkedList itertor that corresponds to the hashed object that has the specified key
    // returns the end() iterator if not found
    typename MyLinkedList<HashedObj<KeyType, ValueType>>::iterator find(const KeyType &key)
    {
        // code begins
        HashFunc<KeyType> hashFunc;
        long long hashValue = hashFunc.univHash(key, hash_table.size());
        if (hashValue < 0 || hashValue >= static_cast<long long>(hash_table.size()))
        {
            // Return an end() iterator to indicate not found
            return hash_table.back()->end();
        }
        MyLinkedList<HashedObj<KeyType, ValueType>> *list = hash_table[hashValue];
        return std::find_if(list->begin(), list->end(), [&](const HashedObj<KeyType, ValueType> &obj)
                            { return obj.key == key; });
        // code ends
    }

    // rehashes all data elements in the hash table into a new hash table with new_size
    // note that the new_size can be either smaller or larger than the existing size
    void rehash(const size_t new_size)
    {
        // code begins
        MyVector<MyLinkedList<HashedObj<KeyType, ValueType>> *> new_table(new_size);
        for (size_t i = 0; i < new_size; ++i)
        {
            new_table[i] = new MyLinkedList<HashedObj<KeyType, ValueType>>();
        }

        // Rehash all elements to the new table
        HashFunc<KeyType> hashFunc;
        for (size_t i = 0; i < hash_table.size(); ++i)
        {
            MyLinkedList<HashedObj<KeyType, ValueType>> *list = hash_table[i];
            for (const auto &obj : *list)
            {
                long long new_hashValue = hashFunc.univHash(obj.key, new_size);
                new_table[new_hashValue]->push_back(obj);
            }
            delete list;
        }

        // Swap the old table with the new table
        std::swap(hash_table, new_table);
        // code ends
    }

    // doubles the size of the table and perform rehashing
    // the new table size should be the smallest prime that is larger than the expected new table size (double of the old size)
    void doubleTable()
    {
        size_t new_size = nextPrime(2 * hash_table.size());
        this->rehash(new_size);
        return;
    }

    // halves the size of the table and perform rehahsing
    // the new table size should be the smallest prime that is larger than the expected new table size (half of the old size)
    void halveTable()
    {
        size_t new_size = nextPrime(ceil(hash_table.size() / 2));
        this->rehash(new_size);
        return;
    }

public:
    // the default constructor; allocate memory if necessary
    explicit MyHashTable(const size_t init_size = 3)
    {
        // code begins
        size_t adjusted_size = std::max<size_t>(init_size, 3);

        theSize = 0;
        hash_table.resize(adjusted_size);
        for (size_t i = 0; i < adjusted_size; ++i)
        {
            hash_table[i] = new MyLinkedList<HashedObj<KeyType, ValueType>>();
        }
        preCalPrimes(2 * adjusted_size);
        // code ends
    }

    // the default destructor; collect memory if necessary
    ~MyHashTable()
    {
        // code begins
        for (size_t i = 0; i < hash_table.size(); ++i)
        {
            delete hash_table[i];
        }
        // code ends
    }

    // checks if the hash tabel contains the given key
    bool contains(const KeyType &key)
    {
        // code begins
        HashFunc<KeyType> hashFunc;
        long long hashValue = hashFunc.univHash(key, hash_table.size());
        MyLinkedList<HashedObj<KeyType, ValueType>> *list = hash_table[hashValue];
        for (auto &x : *list)
        {
            if (x.key == key)
            {
                return true;
            }
        }
        return false;
        // code ends
    }

    // retrieves the data element that has the specified key
    // returns true if the key is contained in the hash table
    // return false otherwise
    bool retrieve(const KeyType &key, HashedObj<KeyType, ValueType> &data)
    {
        // code begins
        HashFunc<KeyType> hashFunc;
        auto it = find(key);
        if (it == hash_table[hashFunc.univHash(key, hash_table.size())]->end())
        {
            return false;
        }
        data = *it;
        return true;
        // code ends
    }

    // inserts the given data element into the hash table (copy)
    // returns true if the key is not contained in the hash table
    // return false otherwise
    bool insert(const HashedObj<KeyType, ValueType> &x)
    {
        // code begins
        if (contains(x.key))
        {
            return false;
        }

        // Insert the element
        HashFunc<KeyType> hashFunc;
        long long hashValue = hashFunc.univHash(x.key, hash_table.size());
        hash_table[hashValue]->push_back(x);
        ++theSize;

        // Check if rehashing is needed
        if (static_cast<float>(theSize) / hash_table.size() > 1.0)
        {
            doubleTable();
        }

        return true;
        // code ends
    }

    // inserts the given data element into the hash table (move)
    // returns true if the key is not contained in the hash table
    // return false otherwise
    bool insert(HashedObj<KeyType, ValueType> &&x)
    {
        // code begins
        if (contains(x.key))
        {
            return false;
        }

        // Insert the element
        HashFunc<KeyType> hashFunc;
        long long hashValue = hashFunc.univHash(x.key, hash_table.size());
        hash_table[hashValue]->push_back(std::move(x));
        ++theSize;

        // Check if rehashing is needed
        if (static_cast<float>(theSize) / hash_table.size() > 1.0)
        {
            doubleTable();
        }

        return true;
        // code ends
    }

    // removes the data element that has the key from the hash table
    // returns true if the key is contained in the hash table
    // returns false otherwise
    bool remove(const KeyType &key)
    {
        // code begins
        HashFunc<KeyType> hashFunc;
        long long hashValue = hashFunc.univHash(key, hash_table.size());
        MyLinkedList<HashedObj<KeyType, ValueType>> *list = hash_table[hashValue];
        auto it = find(key);
        if (it == list->end())
        {
            return false; // Key not found
        }

        // Remove the element
        list->erase(it);
        --theSize;

        // Check if rehashing is needed
        if (static_cast<float>(theSize) / hash_table.size() < 0.25)
        {
            halveTable();
        }

        return true;
        // code ends
    }

    // returns the number of data elements stored in the hash table
    size_t size()
    {
        // code begins
        return theSize;
        // code ends
    }

    // returns the capacity of the hash table
    size_t capacity()
    {
        // code begins
        return hash_table.size();
        // code ends
    }
};

#endif // __MYHASHTABLE_H__
