                            //  Storage     Scope   Linkage
                            //  class

extern float a;             //  static      file    external 

void f(register double b)   //  automatic   block   no
{
    static int c;           //  static      block   no
    auto char d;            //  automatic   block   no
}
