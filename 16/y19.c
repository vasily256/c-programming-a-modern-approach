#define N 40

struct pinball_machine {
    char name[N+1];
    int year;
    enum {EM, SS} type;
    int players;
};
