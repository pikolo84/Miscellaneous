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

#endif /* Miscellaneous_h */
