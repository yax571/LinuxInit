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
__attribute__ �������� �������ú������ԣ�Function Attribute �����������ԣ�Variable Attribute �����������ԣ�Type Attribute)��
__attribute__ ((attribute-list))
used�������Ǹ��߱��������������������������Ҫ�����ġ���used�����Ժ���ζ�ż�ʹ����û�б����ã���Release��Ҳ���ᱻ�Ż����������������Σ���ôRelease������������ȥ��û�б����õĶ�


��Ϊ C++11 �ѹؼ���typeof��Ϊdecltype��
*/

__attribute__((section(".preinit_array"), used))  decltype(preinit)* preinit_p = preinit;
__attribute__((section(".init_array"), used)) static decltype(init)* init_p = init;
__attribute__((section(".fini_array"), used)) static decltype(fini)* fini_p = fini;


int main()
{
    printf("hello from main!\n");
    return 0;
}

