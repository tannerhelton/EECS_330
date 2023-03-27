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
    return (result >= mersenne_prime) ? (result - mersenne_prime) : result;
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
        std::vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        for (size_t i = 2; i * i <= n; ++i)
        {
            if (sieve[i])
            {
                for (size_t j = i * i; j <= n; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        MyVector<size_t> new_primes;
        for (size_t i = 2; i <= n; ++i)
        {
            if (sieve[i])
            {
                new_primes.push_back(i);
            }
        }
        primes = new_primes;
    }

    // finding the smallest prime that is larger than or equal to n
    // should perform binary search against the private member "primes"
    size_t nextPrime(const size_t n)
    {
        // code begins
        auto it = std::lower_bound(primes.begin(), primes.end(), n);
        if (it == primes.end())
        {
            preCalPrimes(n * 2);
            it = std::lower_bound(primes.begin(), primes.end(), n);
        }
        return *it;
        // code ends
    }

    // finds the MyLinkedList itertor that corresponds to the hashed object that has the specified key
    // returns the end() iterator if not found
    typename MyLinkedList<HashedObj<KeyType, ValueType>>::iterator find(const KeyType &key)
    {
        HashFunc<KeyType> hf;
        size_t index = hf.univHash(key, hash_table.size());
        auto &bucket = *hash_table[index];

        if (bucket.empty())
        { // check if the bucket is empty
            return bucket.end();
        }

        for (auto itr = bucket.begin(); itr != bucket.end(); ++itr)
        {
            if ((*itr).key == key)
            {
                return itr;
            }
        }

        return bucket.end();
    }

    // rehashes all data elements in the hash table into a new hash table with new_size
    // note that the new_size can be either smaller or larger than the existing size
    void rehash(const size_t new_size)
    {
        // code begins
        MyVector<MyLinkedList<HashedObj<KeyType, ValueType>> *> new_table(new_size);
        for (size_t i = 0; i < new_size; ++i)
        {
            new_table[i] = new MyLinkedList<HashedObj<KeyType, ValueType>>;
        }

        HashFunc<KeyType> hf;
        for (auto &old_list : hash_table)
        {
            for (auto &hashed_obj : *old_list)
            {
                size_t index = hf.univHash(hashed_obj.key, new_size);
                new_table[index]->push_back(std::move(hashed_obj));
            }
            delete old_list;
        }
        hash_table = new_table;
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
        preCalPrimes(init_size * 2);
        theSize = 0;
        hash_table.resize(nextPrime(init_size));
        for (size_t i = 0; i < hash_table.size(); ++i)
        {
            hash_table[i] = new MyLinkedList<HashedObj<KeyType, ValueType>>;
        }
        // code ends
    }

    // the default destructor; collect memory if necessary
    ~MyHashTable()
    {
        // code begins
        for (auto &bucket : hash_table)
        {
            delete bucket;
        }
        // code ends
    }

    // checks if the hash tabel contains the given key
    bool contains(const KeyType &key)
    {
        // code begins
        HashFunc<KeyType> hf;
        size_t index = hf.univHash(key, hash_table.size());
        return find(key) != hash_table[index]->end();
        // code ends
    }

    // retrieves the data element that has the specified key
    // returns true if the key is contained in the hash table
    // return false otherwise
    bool retrieve(const KeyType &key, HashedObj<KeyType, ValueType> &data)
    {
        // code begins
        HashFunc<KeyType> hf;
        auto itr = find(key);
        if (itr == hash_table[hf.univHash(key, hash_table.size())]->end())
        {
            return false;
        }
        else
        {
            data = *itr;
            return true;
        }
        // code ends
    }

    // inserts the given data element into the hash table (copy)
    // returns true if the key is not contained in the hash table
    // return false otherwise
    bool insert(const HashedObj<KeyType, ValueType> &x)
    {
        HashFunc<KeyType> hf;
        size_t index = hf.univHash(x.key, hash_table.size());
        auto &bucket = *hash_table[index];

        if (theSize + 1 > hash_table.size())
        {
            doubleTable();
            index = hf.univHash(x.key, hash_table.size()); // re-compute index after doubling the table
            bucket = *hash_table[index];                   // update bucket reference after table doubling
        }
        auto itr = find(x.key);
        if (itr == bucket.end())
        {
            bucket.push_back(x);
            ++theSize;
            return true;
        }
        else
        {
            return false;
        }
    }

    // inserts the given data element into the hash table (move)
    // returns true if the key is not contained in the hash table
    // return false otherwise
    bool insert(HashedObj<KeyType, ValueType> &&x)
    {
        // code begins
        HashFunc<KeyType> hf;
        auto itr = find(x.key);
        size_t index = hf.univHash(x.key, hash_table.size());
        if (itr == hash_table[index]->end())
        {
            hash_table[index]->push_back(std::move(x));
            ++theSize;
            if (theSize > hash_table.size())
            {
                doubleTable();
            }
            return true;
        }
        else
        {
            return false;
        }
        // code ends
    }

    // removes the data element that has the key from the hash table
    // returns true if the key is contained in the hash table
    // returns false otherwise
    bool remove(const KeyType &key)
    {
        HashFunc<KeyType> hf;
        size_t index = hf.univHash(key, hash_table.size());
        auto &bucket = *hash_table[index];

        if (theSize - 1 < hash_table.size() / 4)
        {
            halveTable();
            index = hf.univHash(key, hash_table.size()); // re-compute index after halving the table
            bucket = *hash_table[index];                 // update bucket reference after table halving
        }
        auto itr = find(key);
        if (itr != bucket.end())
        {
            bucket.erase(itr);
            --theSize;
            return true;
        }
        else
        {
            return false;
        }
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
