#ifndef Miscellaneous_h
#define Miscellaneous_h

class TimerOn
{
  private:
    unsigned long _previousMillis = 0;
    unsigned long _time = 0;
  public:
    void SetTimer(unsigned long time);
    bool Check(bool input);
};

class TimerOff
{
  private:
    unsigned long _prevsiousMillis = 0;
    unsigned long _time = 0;s
  public:
    void SetTimer(unsigned long time);
    bool Check(bool input);
};

class PosEdge
{
  private:
    bool _lastStatus = false;
  public:
    bool Check (bool);
};

class NegEdge
{
  private:
    bool _lastStatus = true;
  public:
    bool Check (bool);
};

//Debounce es lo proximo

#endif /* Miscellaneous_h */
