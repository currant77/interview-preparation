/**
 * @file IMap.h
 * @author Taylor Curran
 * @brief Minimal map interface
 * @version 0.1
 * @date 2020-06-13
 * 
 */

#ifndef I_MAP_H
#define I_MAP_H

/**
 * @brief A minimal map interface.
 * 
 * @tparam Key 
 * @tparam Value 
 */
template<class Key, class Value>
class IMap
{
    public:
        virtual ~IMap<Key, Value>();

        virtual size_t size() const = 0;

        /**
         * @brief If the map contains the given key, returns
         * true and returns the corresponding value by reference;
         * else returns false.
         */
        virtual bool lookup(const Key& k, Value& v) const = 0;

        /**
         * @brief If the map contains the given key, updated the
         * corresponding value; if not, add the key-value pair.
         */
        virtual void insert(const Key& k, const Value& v) = 0;

        /**
         * @brief If the map contains the given key, removes 
         * it from the map and returns true; if not, returns 
         * false.
         */
        virtual bool remove(const Key& k) = 0;
        
        virtual void clear() = 0;
};

template<class Key, class Value>
IMap<Key, Value>::~IMap()
{

}

#endif