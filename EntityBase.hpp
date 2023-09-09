#ifndef ENTITY_BASE_HPP
#define ENTITY_BASE_HPP

#include <string>

class EntityBase {

    public:

        virtual void create() = 0;
        virtual void destroy() = 0;
        virtual void update() = 0;

        virtual std::string getEntityName() const = 0;

    private:

        std::string _entityName;

};

class User : public EntityBase
{
    public:

        User(const std::string entityName): _entityName(entityName) {}

        ~User() {}

        void create()
        {
            
        }
        
        void destroy()
        {

        }
        
        void update()
        {

        }

        std::string getEntityName() const 
        {
            return _entityName;
        }

    private:

        std::string _entityName;

};





#endif