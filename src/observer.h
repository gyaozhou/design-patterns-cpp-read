//
// Created by Jennica on 2017/1/2.
//

#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

#include <string>
#include <vector>

class Notifier;

// zhou: interface of subject, should be derived by concrete client observer.
class Observer {
public:
  Observer() {}
  Observer(std::string);
  virtual ~Observer() {}
  void SetNotifier(Notifier *);
  // zhou: every derived class must implement it to handle subject changes.
  virtual void Update() = 0;

protected:
  std::string name_;
  // zhou: used to deregister
  Notifier *notifier_;
};

// zhou: one client observer
class StockObserver: public Observer {
public:
  StockObserver() {}
  StockObserver(std::string);
  void Update();
};

// zhou: one client observer
class NbaObserver: public Observer {
public:
  NbaObserver() {}
  NbaObserver(std::string);
  void Update();
};


////////////////////////////////////////////////////////////////////////////////

// zhou: interface of subject, should be derived by concrete subjects.
class Notifier {
public:
  virtual ~Notifier() {}

  // zhou: only operate "Observer". These two function could be implemented in
  //       super class or derived class, depending on requirement.
  void Attach(Observer *);
  void Detach(Observer *);

  // zhou: these two functions should be virtual, must be implemented by derived
  //       class.
  //       Or else, these functions should be defined in derived class?
  void SetState(std::string);
  std::string GetState();

  void Notify();

protected:
  std::vector <Observer*> observers_;
  std::string state_;
};

// zhou: one subject implementation
class Secretary: public Notifier {
};

// zhou: one subject implementation
class Boss: public Notifier {
};


#endif //DESIGN_PATTERNS_OBSERVER_H
