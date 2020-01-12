#include <cstdio>


/*
void preinit(int argc, char** argv, char** envp) {
    printf("%s\n", __FUNCTION__);
}

void init(int argc, char** argv, char** envp) {
    printf("%s\n", __FUNCTION__);
}

void fini() {
    printf("%s\n", __FUNCTION__);
}

__attribute__((section(".init_array"))) typeof(init)* __init = init;
__attribute__((section(".preinit_array"))) typeof(preinit)* __preinit = preinit;
__attribute__((section(".fini_array"))) typeof(fini)* __fini = fini;
*/

void __attribute__((constructor)) myconstructor()
{
    printf("%s\n", __FUNCTION__);
}




void preinit(int argc, char** argv, char** envp) {
    puts(__FUNCTION__);
}

static void init(int argc, char** argv, char** envp) {
    puts(__FUNCTION__);
}

static void fini(void) {
    puts(__FUNCTION__);
}

/*
__attribute__ 编译属性 可以设置函数属性（Function Attribute ）、变量属性（Variable Attribute ）和类型属性（Type Attribute)等
__attribute__ ((attribute-list))
used的作用是告诉编译器，我声明的这个符号是需要保留的。被used修饰以后，意味着即使函数没有被引用，在Release下也不会被优化。如果不加这个修饰，那么Release环境链接器会去掉没有被引用的段


因为 C++11 把关键字typeof改为decltype了
*/

__attribute__((section(".preinit_array"), used))  decltype(preinit)* preinit_p = preinit;
__attribute__((section(".init_array"), used)) static decltype(init)* init_p = init;
__attribute__((section(".fini_array"), used)) static decltype(fini)* fini_p = fini;


int main()
{
    printf("hello from main!\n");
    return 0;
}

