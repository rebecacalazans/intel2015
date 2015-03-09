#ifndef UTILS_STEPPABLE_H
#define UTILS_STEPPABLE_H

class Steppable
{
public:
  virtual ~Steppable() {}
  virtual void step() =0;
};

#endif //UTILS_STEPPABLE_H
