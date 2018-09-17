int main(void)
{
    {
        // (a) char (*x[10])(int);
        typedef char Fcn(int);
        typedef Fcn *Fcn_ptr;
        typedef Fcn_ptr Fcn_ptr_array[10];
        typedef Fcn_ptr_array x;
    }
    {
        // (b) int (*x(int))[5];
        typedef int Array[5];
        typedef Array *Array_ptr;
        typedef Array_ptr Array_ptr_fcn(int);
        typedef Array_ptr_fcn x;
    }
    {
        // (c) float *(*x(void))(int);
        typedef float *Ptr;
        typedef Ptr Ptr_fcn(int);
        typedef Ptr_fcn *Ptr_fcn_ptr;
        typedef Ptr_fcn_ptr Ptr_fcn_ptr_fcn(void);
        typedef Ptr_fcn_ptr_fcn x;
    }
    {
        // (d) void (*x(int, void (*y)(int)))(int);
        typedef void Fcn(int);
        typedef Fcn *Fcn_ptr;
        typedef void Fcn2(int);
        typedef Fcn2 *Fcn2_ptr;
        typedef Fcn_ptr Fcn_ptr_fcn2_ptr(int, Fcn2_ptr);
        typedef Fcn_ptr_fcn2_ptr x;
    }
    return 0;
}
