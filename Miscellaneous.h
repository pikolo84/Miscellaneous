#ifndef Miscellaneous_h
#define Miscellaneous_h

class TimerOn
{
  private:
    unsigned long _previousMillis = 0;
    unsigned long _time = 0;
  public:
    void SetTimer(unsigned long time);
    bool Check(bool input = true);
    void Reset(void);
};

class TimerOff
{
  private:
    unsigned long _previousMillis = 0;
    unsigned long _time = 0;
  public:
    void SetTimer(unsigned long time);
    bool Check(bool input = false);
    void Reset(void);
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

#endif /* Miscellaneous_h */
