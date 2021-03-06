#ifndef UNIT_H
#define UNIT_H

#include "imovable.h"
#include "ifarming.h"
#include "mediator.h"
#include "idrawable.h"

#include <memory>

#include "Field/point2d.h"

#include "Atributes/Armor/armor.h"
#include "Atributes/Weapon/weapon.h"

#include "IObserver/ipublisher.h"


namespace unit {
constexpr const char* CRT_UNIT = "create unit";


class Unit : public IMovable, public IFarming,
        public IPublisher, public IDrawable
{
public:
    explicit Unit(const Point2D& point,
                  std::shared_ptr<Mediator> mediator);
    virtual ~Unit() = default;

    Unit(const Unit& unit);

    int getHealthPoints() const;
    const Point2D& getPosition() const;
    const std::shared_ptr<Armor> getArmor() const;
    const std::shared_ptr<Weapon> getWeapon() const;

    void setWeapon(std::shared_ptr<Weapon> weapon);
    void setArmor(std::shared_ptr<Armor> armor);
    void toHurt(int damage);

    void setMediator(std::shared_ptr<Mediator> mediator);

    virtual bool isFly() const = 0;

    virtual std::shared_ptr<Unit> clone() = 0;

protected:
    void doCopy(const Unit& unit);

protected:
    Point2D position;
    int healthPoints;
    std::shared_ptr<Armor> armor;
    std::shared_ptr<Weapon> weapon;
    std::shared_ptr<Mediator> mediator;
};
}

#endif // UNIT_H
