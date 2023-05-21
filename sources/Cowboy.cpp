#include "Cowboy.hpp"

//??????????????????????????????????/
Cowboy::Cowboy(const std::string& name ,const Point& location) 
: Character(location, name, 110), m_bullets(6) {
}



void Cowboy::shoot(Character* enemy) {
    if(enemy->isAlive() == false){
        throw std::runtime_error("enemy is dead");
    }
    if(isAlive() == false){
        throw std::runtime_error("cowboy is dead");
    }
    if(this == enemy){
        throw std::runtime_error("cowboy can't shoot himself");
    }
    if (hasboolets()&& isAlive() && enemy->isAlive()) {
        enemy->hit(10);
        m_bullets--;

    }
    else if(!hasboolets())
    {
       reload();
    }
   
}

bool Cowboy::hasboolets() const {
   // printf("bullets: %d\n",m_bullets);
    return m_bullets > 0;
    
}

void Cowboy::reload() {
    if(!isAlive()){
        throw std::runtime_error("cowboy is dead");
    }
    m_bullets = 6;
}

std::string Cowboy::print() const {
    std::string output = "C  " + Character::print();
    if (isAlive()) {
        output += "bullets left: " + std::to_string(m_bullets) + " ";
    }

    return output;
}
