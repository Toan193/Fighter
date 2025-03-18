#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class ThreatObject : public BaseObject
{
public:
    ThreatObject();
    ~ThreatObject();
    void init_asteroid();
    void update_asteroid();

private:
    int speed;
};
#endif // THREAT_OBJECT_H
