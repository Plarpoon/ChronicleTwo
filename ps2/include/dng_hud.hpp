#pragma once
#include "common.h"
class CScene;
class TBase { public: virtual int Draw(); virtual void Initialize(); int x; };
class TDerived : public TBase {
public:
    virtual void Draw();
    virtual void Step();
    virtual void Initialize(CScene *scene);
};
void TDerived::Draw() {}
