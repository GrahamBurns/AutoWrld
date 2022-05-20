#include "CameraControl.h"

float CameraControl::getX()
{
    return x;
}

float CameraControl::getY()
{
    return y;
}

void CameraControl::CameraMoveW()
{
    y--;
}

void CameraControl::CameraMoveA()
{
    x--;
}

void CameraControl::CameraMoveD()
{
    x++;
}

void CameraControl::CameraMoveS()
{
    y++;
}
