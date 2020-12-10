#include <iostream>
#include "Squad.hpp"

Squad::Squad(void) : _nbUnits(0), _army(NULL) {}

Squad::Squad(Squad const &src)
{
    *this = src;
    return;
}

Squad::~Squad(void)
{
    this->_deleteArmy();
}

Squad &Squad::operator=(Squad const &rhs)
{
    if (this != &rhs)
    {
        this->_deleteArmy();
        for (int i = 0; i < rhs.getCount(); i++)
            this->push(rhs.getUnit(i)->clone());
    }
    return (*this);
}

int Squad::getCount() const
{
    return (this->_nbUnits);
}

ISpaceMarine *Squad::getUnit(int n) const
{
    t_container *head = this->_army;
    while (n-- && head->next)
        head = head->next;
    return (head->unit);
}

int Squad::push(ISpaceMarine *soldier)
{
    t_container *tmp = new t_container;
    t_container *head = this->_army;

    if (soldier)
    {
        tmp->unit = soldier;
        tmp->next = NULL;
        if (!head)
            this->_army = tmp;
        else
        {
            while (head->next)
            {
                if (head->unit == soldier)
                {
                    delete tmp;
                    return (-1);
                }
                head = head->next;
            }
            head->next = tmp;
        }
        this->_nbUnits += 1;
    }
    return (this->_nbUnits);
}

void Squad::_deleteArmy()
{
    t_container *head = this->_army;
    t_container *tmp;

    while (head)
    {
        delete head->unit;
        tmp = head;
        head = head->next;
        delete tmp;
    }
    this->_army = NULL;
    this->_nbUnits = 0;
}
