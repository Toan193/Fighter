#include "ThreatObject.h"

ThreatObject::ThreatObject()
{
    desRect.w = THREAT_SIZE;
    desRect.h = THREAT_SIZE;
    desRect.x = rand() % (SCREEN_WIDTH - THREAT_SIZE);
    desRect.y = - (rand() % SCREEN_HEIGHT);
    speed = speed_threat_min + rand() % (speed_threat_max - speed_threat_min + 1);
}

void ThreatObject::update_asteroid()
{
    desRect.y += speed;
    // Nếu thiên thạch rơi khỏi màn hình, reset lại vị trí
    if (desRect.y > SCREEN_HEIGHT) {
        desRect.x = rand() % (SCREEN_WIDTH - THREAT_SIZE);
        desRect.y = -THREAT_SIZE;
        speed = speed_threat_min + rand() % (speed_threat_max - speed_threat_min + 1);
    }
}

void ThreatObject::delete_asteroid()
{
    desRect.x = rand() % (SCREEN_WIDTH - THREAT_SIZE);
    desRect.y = -THREAT_SIZE;
    speed = speed_threat_min + rand() % (speed_threat_max - speed_threat_min + 1);
}
