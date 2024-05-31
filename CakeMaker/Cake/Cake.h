#ifndef CAKEMAKER_CAKE_H
#define CAKEMAKER_CAKE_H


#include <string>

class Cake final {
private:
    std::string name;

public:
    explicit Cake(const std::string& name);

    Cake(const Cake& cake);

    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Cake& c);

};


#endif //CAKEMAKER_CAKE_H
