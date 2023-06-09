#include "Character.hpp"


Character::Character(const Point& location, const std::string& name, int hitPoints) 
: m_location(location), m_name(name), m_hitPoints(hitPoints) {}



//?????????????????????????????????????/
bool Character::isAlive() const {
    return m_hitPoints > 0;
}
double Character::distance(const Character* other) const {
    return m_location.distance(other->getLocation());
}

void Character::hit(int damage) {
    if(damage < 0){
        throw std::invalid_argument("damage is negative");
    }
    m_hitPoints -= damage;
    if (m_hitPoints < 0) {
        m_hitPoints = 0;
    }
}

const std::string& Character::getName() const {
    return m_name;
}

const Point& Character::getLocation() const {
    return m_location;
}
void Character::setLocation(const Point& location) {
    m_location = location;
}

//print all types of characters
std::string Character::print() const {
    std::ostringstream oss;
    
    if (isAlive()) {
        oss << getName() << " HP: " << getHitPoints() << " ";
    } else {
        oss <<"("<< getName() << ")";
    }
    oss <<"Location "<< getLocation().getX() << "," << getLocation().getY() << " ";
    
  
    return oss.str();
}


