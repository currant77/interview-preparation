/**
 * @file ISet.h
 * @author Taylor Curran
 * @brief Minimal set interface
 * @version 0.1
 * @date 2020-06-12
 */

#ifndef I_SET_H
#define I_SET_H

/**
 * @brief A minimal set interface
 * 
 * @tparam T 
 */
template<class Key>
class ISet
{
    public:
        virtual ~ISet<Key>();

        virtual size_t size() const = 0;
        virtual bool contains(const Key& k) const = 0;
        virtual bool insert(const Key& k) = 0;
        virtual bool remove(const Key& k) = 0;
        virtual void clear() = 0;
};

template<class Key>
ISet<Key>::~ISet()
{

}

#endif


