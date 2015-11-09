#ifndef FACTORY_H
#define FACTORY_H

#include <cstdlib>
#include <iostream>
#include <string> 
#include <memory>
#include <map>
#include <iterator>


template <class Object,class Key=std::string> class Factory
{
      static std::map<Key,std::unique_ptr <Object>> m_map;
public:

        static void Register(Key key,Object* obj);
        Object* Create(const Key& key);
};


template <class Object,class Key> std::map<Key,std::unique_ptr<Object>> Factory<Object,Key>::m_map = std::map<Key,std::unique_ptr<Object>>();

template <class Object,class Key> void Factory<Object,Key>::Register(Key key,Object* obj)
{
        if(m_map.find(key)==m_map.end())
        {
               m_map[key]=std::unique_ptr<Object>(obj);
        }
}


template <class Object,class Key> Object* Factory<Object,Key>::Create (const Key& key)
{


                return m_map.at(key) -> clone();
}



#endif