PROGRAM prog
  VAR
    Plus : BOOL;
  END_VAR
  VAR
    LED AT %QX0.0 : INT;
  END_VAR
  VAR
    Reset : BOOL;
    SetTime : TIME := T#100ms;
    Counter : INT;
    MaxValue : INT := 255;
    CTU0 : CTU;
    TON0 : TON;
    TOF0 : TOF;
    R_TRIG1 : R_TRIG;
  END_VAR

  TON0(IN := NOT(Plus), PT := SetTime);
  TOF0(EN := TON0.ENO, IN := TON0.Q, PT := SetTime);
  Plus := TOF0.Q;
  LED := Counter;
  R_TRIG1(CLK := Plus);
  CTU0(CU := R_TRIG1.Q, R := Reset, PV := MaxValue);
  Counter := CTU0.CV;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : prog;
  END_RESOURCE
END_CONFIGURATION
