#ifndef CAKEMAKER_RECIPECAKE_H
#define CAKEMAKER_RECIPECAKE_H


#include <string>

class RecipeCake final {
private:
    std::string name;
    int time;

public:
    RecipeCake(const std::string& name, int time);

    const std::string& getName() const;

    int getTime() const;

    bool operator==(const RecipeCake& other) const;

    friend std::ostream& operator<<(std::ostream& os, const RecipeCake& rc);

};


#endif //CAKEMAKER_RECIPECAKE_H
