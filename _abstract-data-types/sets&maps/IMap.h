/**
 * @file IMap.h
 * @author Taylor Curran
 * @brief Minimal map interface
 * @version 0.1
 * @date 2020-06-13
 * 
 * @copyright Copyright (c) 2020
 *
 */

#ifndef I_MAP_H
#define I_MAP_H

#include <exception>    // std::invalid_argument
#include <functional>   // std::equal_to

template<class Key, class Value, class Equal_To = std::equal_to<Key>>
class IMap
{
    public:
        virtual ~IMap<Key, Value, Equal_To>();

        /**
         * @brief Returns the number of key-value pairs in the map
         * 
         * @return size_t Number of key-value pairs in the map
         */
        virtual size_t size() const noexcept = 0;

        /**
         * @brief Returns a reference to the value corresponding to \p key, 
         * which must be a member of the map
         * 
         * @param key 
         * @throw std::invalid_argument if \p key is not a member of the map
         * @return Value& Reference to the value corresponding to \p key in 
         * the map
         */
        virtual Value& get(const Key& key) = 0;

         /**
         * @brief Returns a const reference to the value corresponding to 
         * \p key, which must be a member of the map
         * 
         * @param key 
         * @throw std::invalid_argument if \p key is not a member of the map
         * @return Value& Const reference to the value corresponding to \p key 
         * in the map
         */
        virtual const Value& get(const Key& key) const = 0;

        /**
         * 
         * @brief If \p key is not a member of the map, insert \p key and 
         * \p value as a new key-value pair; if \p key is a member, sets
         * the corresponding value to equal \p value
         * 
         * @param key 
         * @param value 
         */
        virtual void insert(const Key& key, const Value& value) noexcept = 0;

        /**
         * @brief If \p key is a member of the map, removes the corresponding
         * key-value pair
         * 
         * @param key 
         */
        virtual void remove(const Key& key) noexcept = 0;

        /**
         * @brief Removes all the key-value pairs from the map
         * 
         */
        virtual void clear() noexcept = 0;
};

template<class Key, class Value, class Equal_To>
IMap<Key, Value, Equal_To>::~IMap()
{

}

#endif